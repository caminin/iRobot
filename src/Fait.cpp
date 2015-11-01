#include "../include/Fait.hpp"

using namespace std;

void Fait::initString()
{
	jeVeux = ( "je veux ");
	jeVais = ("je vais ");
	ilVa=("il va");
	ilPrend = ("il prend ");
	jePrends = ("je prends ");
	comparaison = ("==");
	jeJoue= ("je joue ");
	jAi= ("je suis en ");
	affectation=("=");
	comparaison =("==");
}

std::string myreplace(std::string &s,std::string toReplace,std::string replaceWith)
{
    return(s.replace(s.find(toReplace), toReplace.length(), replaceWith));
}

Fait::Fait(string regle)
{
	MyRegle = regle;
	initRegex();
	if (regle.find(jeVeux)!=string::npos)
	{
		type="je veux ";
		valeur=myreplace(regle,jeVeux,"");
		
		if(strcmp(valeur.c_str(),"PERSO")==0)// si o=c'est un fait ne contenant pas de valeur, on met juste le type'
		{
			variable="PERSO";
		}
		else if(strcmp(valeur.c_str(),"POSTE")==0)
		{
			variable="POSTE";
		}
		else 
		{
			champion *c= new champion;
			if(!getPerso(valeur,c))
			{
				type_poste p;
				if(!verifPoste(valeur,p))
				{
					cerr << "Le poste n'est pas reconnu sur un fait de type : " << type << " de valeur : "<< valeur <<endl;
				}
				else
				{
					variable="POSTE";
				}
			}
			else
			{
				variable="PERSO";
			}
		}
	}
	else if (regle.find(jeVais)!=string::npos)
	{
		type="je vais ";
		variable="POSTE";
		valeur=myreplace(regle,jeVais,"");
	}
	else if (regle.find(ilVa)!=string::npos)
	{
		type="il va ";
		variable="POSTE";
		valeur=myreplace(regle,ilVa,"");
	}
	else if (regle.find(ilPrend)!=string::npos){
		type="il prend ";
		variable="PERSO";
		valeur=myreplace(regle,ilPrend,"");
	}
	else if (regle.find(jePrends)!=string::npos)
	{
		type="je prends ";
		variable="PERSO";
		valeur=myreplace(regle,jePrends,"");
	}
	else if (regle.find(comparaison)!=string::npos)
	{
		//variable="ARGUMENT,VALEUR";
		string fonction = regle.substr(0,regle.find("==")-1); 
		
		string res_fonction = regle.substr(regle.find("==")+2);
		
		if (regle.find("MoiIndecis")!=string::npos)
		{
			type="comparaison ";
			variable="MoiIndecis(POSTE)";
			fonction = myreplace(fonction,"MoiIndecis(","");
			fonction = myreplace(fonction, ")","");
			valeur=fonction+","+res_fonction;
		}
		else if (regle.find("LibrePoste")!=string::npos)
		{
			type="comparaison ";
			variable="LibrePoste(POSTE)";
			fonction = myreplace(fonction,"LibrePoste(","");
			fonction = myreplace(fonction, ")","");
			valeur=fonction+","+res_fonction;
		}
		else
		{
			cerr << "comparaison non reconnue" << endl;
		}
		
		//cout << type << variable<<" " << valeur<<endl;
	}
	else if (regle.find(jeJoue)!=string::npos)
	{
		type=jeJoue;
		variable="FACON_DE_JOUER";
		valeur=myreplace(regle,jeJoue,"");
	}
	else if (regle.find(jAi)!=string::npos)
	{
		type=jAi;
		variable="AV_ou_DEV";
		valeur=myreplace(regle,jAi,"");
	}
	else if (regle.find("MoiIndecis")!=string::npos)
	{
		type="indecis";
		variable="POSTE";
		valeur="POSTE";
	}
	else if (regle.find(jAi)!=string::npos)
	{
		type=jAi;
		variable="AV_ou_DEV";
		valeur=myreplace(regle,jAi,"");
	}
	else if (regle.find(affectation)!=string::npos)
	{
		regex fin_cmp;
		fin_cmp = (" = [()[:alpha:] ]+");
		string specialisation_comp=regex_replace(regle,fin_cmp,"");
		type = "affectation ";
				
		variable = regle.substr(0,regle.find("=")-1); 
		
		valeur = regle.substr(regle.find("=")+2);
		
		//cout << type << variable<<" " << valeur<<endl;
	}
	else
	{
		cout << "Regle que je connais pas " <<MyRegle << " | fin règle"<< endl;
	}
}


////////////////////////////////////////////////////CONSTRUCTEUR
Fait::Fait(string regle,Structure &struc_stockage_fait)
{
	MyRegle = regle;
	initRegex();
	if (regle.find(jeVeux)!=string::npos)
	{
		type="je veux ";
		valeur=myreplace(regle,jeVeux,"");
		
		if(strcmp(valeur.c_str(),"PERSO")==0)// si o=c'est un fait ne contenant pas de valeur, on met juste le type'
		{
			variable="PERSO";
		}
		else if(strcmp(valeur.c_str(),"POSTE")==0)
		{
			variable="POSTE";
		}
		else 
		{
			struc_stockage_fait.stockage_champion_pref= new champion;
			if(!getPerso(valeur,struc_stockage_fait.stockage_champion_pref))
			{
				struc_stockage_fait.stockage_champion_pref=nullptr;
				if(!verifPoste(valeur,struc_stockage_fait.moi.poste_souhaite))
				{
					cerr << "Le poste n'est pas reconnu sur un fait de type : " << type << " de valeur : "<< valeur <<endl;
				}
				else
				{
					variable="POSTE";
				}
			}
			else
			{
				variable="PERSO";
			}
		}
		cout << type << variable<<" " << valeur<<endl;
		
	}
	else if (regle.find(jeVais)!=string::npos)
	{
		type="je vais ";
		variable="POSTE";
		valeur=myreplace(regle,jeVais,"");
		
		if(!verifPoste(valeur,struc_stockage_fait.moi.poste_pris))//si on arrive pas à trouver un poste
		{
			struc_stockage_fait.moi.poste_pris=struc_stockage_fait.moi.poste_souhaite;//on prend le poste préféré
			valeur=getNomPoste(struc_stockage_fait.moi.poste_souhaite);
		}
		cout << type << variable<<" " << valeur<<endl;
	}
	else if (regle.find(ilVa)!=string::npos)
	{
		type="il va ";
		variable="POSTE";
		valeur=myreplace(regle,ilVa,"");
		if(!verifPoste(valeur,struc_stockage_fait.adversaire.son_poste))
		{
			cerr << "Le poste n'est pas reconnu sur un fait de type : " << " de valeur : "<< valeur <<endl;
		}
	}
	else if (regle.find(ilPrend)!=string::npos){
		type="il prend ";;
		variable="PERSO";
		valeur=myreplace(regle,ilPrend,"");
		
		
		if (valeur.find("Counter(")!=string::npos)
		{
			valeur = myreplace(valeur,"Counter(","");
			valeur = myreplace(valeur, ")","");

			// recherche du counter de valeur
			
			champion* champ=new champion;
			if(getPerso(valeur,champ))
			{
				struc_stockage_fait.adversaire.son_champion=new champion;
				*struc_stockage_fait.adversaire.son_champion=*champ;
				valeur=getNomPerso(getCounter(champ));	
			}
			else if(struc_stockage_fait.moi.champion_pris!=nullptr)
			{
				struc_stockage_fait.adversaire.son_champion=new champion;
				*(struc_stockage_fait.adversaire.son_champion)=getCounter(struc_stockage_fait.moi.champion_pris);
				cout << "j'ai trouvé " << *struc_stockage_fait.adversaire.son_champion << endl;
				valeur = getNomPerso(*struc_stockage_fait.adversaire.son_champion);
			}
			else
				cerr << "On ne peut pas prendre le counter d'un perso qui n'existe pas" << endl;

		}
		else
		{
			struc_stockage_fait.adversaire.son_champion=new champion;
			if(!getPerso(valeur,struc_stockage_fait.adversaire.son_champion))
			{
				struc_stockage_fait.adversaire.son_champion=nullptr;
				cerr << "Le perso n'est pas reconnu sur un fait de type : " <<type << " de valeur : "<< valeur <<endl;
			}
		} 
	}
	else if (regle.find(jePrends)!=string::npos)
	{
		type="je prends ";;
		variable="PERSO";
		valeur=myreplace(regle,jePrends,"");
		if (valeur.find("Counter(")!=string::npos)
		{
			valeur = myreplace(valeur,"Counter(","");
			valeur = myreplace(valeur, ")","");

			// recherche du counter de valeur
			
			champion* champ=new champion;
			if(getPerso(valeur,champ))
			{
				struc_stockage_fait.moi.champion_pris=new champion;
				*struc_stockage_fait.moi.champion_pris=*champ;
				valeur=getNomPerso(getCounter(champ));
				
			}
			else if(struc_stockage_fait.adversaire.son_champion!=nullptr)
			{
				struc_stockage_fait.moi.champion_pris=new champion;
				*(struc_stockage_fait.moi.champion_pris)=getCounter(struc_stockage_fait.adversaire.son_champion);
				cout << "j'ai trouvé " << *struc_stockage_fait.moi.champion_pris << endl;
				valeur = getNomPerso(*struc_stockage_fait.moi.champion_pris);
			}
			else
				cerr << "On ne peut pas prendre le counter d'un perso qui n'existe pas" << endl;

		}
		else if (valeur.find("Pref(")!=string::npos)
		{
			valeur = myreplace(valeur,"Pref(","");
			valeur = myreplace(valeur, ")","");
			
			type_poste poste;
			if(!verifPoste(valeur,poste))
			{
				cerr << "aucun poste n'a été trouvé avec verifPoste dans pref'" << endl;
			}

			// recherche du perso prefere pour valeur
			if(struc_stockage_fait.moi.champion_souhaite!=nullptr)
			{
				struc_stockage_fait.moi.champion_pris=new champion;
				*(struc_stockage_fait.moi.champion_pris)=getCounter(struc_stockage_fait.moi.champion_souhaite[poste]);
				valeur = getNomPerso(*struc_stockage_fait.moi.champion_pris);
			}
			
			cout << "je dois chercher le perso préféré pour " << valeur << endl;
		}
		else if (valeur.find("Random(")!=string::npos)
		{
			srand(time(NULL));
			valeur = myreplace(valeur,"Random(","");
			valeur = myreplace(valeur, ")","");
			int random=rand()%3;
			
			type_poste poste;
			if(!verifPoste(valeur,poste))
			{
				poste=struc_stockage_fait.moi.poste_pris;
			}
			
			switch(poste)
			{
				case TOP : break;
				case MID : random+=3;break;
				case ADC : random+=6;break;
				case SUPPORT : random+=9;break;
				case JUNGLE :random+=12; break;
				default : cerr<< "le poste dans random est incorret, peut-être avez-vous oubliez de précisez une préférence"<<endl;break;
			}	
			
			champion new_champ=(champion)random;
			
			struc_stockage_fait.moi.champion_pris=new champion;
			*(struc_stockage_fait.moi.champion_pris)=new_champ;
			valeur=getNomPerso(new_champ);	
			
			
		}
		else
		{
			struc_stockage_fait.moi.champion_pris=new champion;
			if(!getPerso(valeur,struc_stockage_fait.moi.champion_pris))
			{
				struc_stockage_fait.moi.champion_pris=nullptr;
				cerr << "Le perso n'est pas reconnu sur un fait de type : " <<type << " de valeur : "<< valeur <<endl;
			}
		}
		cout << type << variable<<" " << valeur<<endl;
	}
	else if (regle.find(comparaison)!=string::npos)
	{
		//variable="ARGUMENT,VALEUR";
		string fonction = regle.substr(0,regle.find("==")-1); 
		
		string res_fonction = regle.substr(regle.find("==")+2);
		
		if (regle.find("MoiIndecis")!=string::npos)
		{
			type="comparaison ";
			variable="MoiIndecis(POSTE)";
			fonction = myreplace(fonction,"MoiIndecis(","");
			fonction = myreplace(fonction, ")","");
			valeur=fonction+","+res_fonction;
		}
		else if (regle.find("LibrePoste")!=string::npos)
		{
			type="comparaison ";
			variable="LibrePoste(POSTE)";
			fonction = myreplace(fonction,"LibrePoste(","");
			fonction = myreplace(fonction, ")","");
			valeur=fonction+","+res_fonction;
		}
		else
		{
			cerr << "comparaison non reconnue" << endl;
		}
		
		//cout << type << variable<<" " << valeur<<endl;
	}
	else if (regle.find(jeJoue)!=string::npos)
	{
		type=jeJoue;
		variable="FACON_DE_JOUER";
		valeur=myreplace(regle,jeJoue,"");
	}
	else if (regle.find(jAi)!=string::npos)
	{
		type=jAi;
		variable="AV_ou_DEV";
		valeur=myreplace(regle,jAi,"");
		
		if(strcmp(valeur.c_str(),"AVANTAGE")==0)
		{
			struc_stockage_fait.moi.ma_situation=AVANTAGE;
		}
		else if(strcmp(valeur.c_str(),"DESAVANTAGE")==0)
		{
			struc_stockage_fait.moi.ma_situation=DESAVANTAGE;
		}
		else 
		{
			cerr << "Cette valeur est anormale"<< endl;
		}
	}
	else if (regle.find(affectation)!=string::npos)
	{
		type = "affectation ";

		//variable="ARGUMENT,VALEUR";
		variable="Pref("+getNomPoste(struc_stockage_fait.moi.poste_souhaite)+")";

		valeur=getNomPerso(*struc_stockage_fait.stockage_champion_pref);
		
		struc_stockage_fait.moi.champion_souhaite[struc_stockage_fait.moi.poste_souhaite]=new champion;
		*struc_stockage_fait.moi.champion_souhaite[struc_stockage_fait.moi.poste_souhaite]=*struc_stockage_fait.stockage_champion_pref;
		
		struc_stockage_fait.stockage_champion_pref=nullptr;
		//cout << type << variable<<" " << valeur<<endl;
	}
	
	else
	{
		cout << "Regle que je connais pas " <<MyRegle << " | fin règle"<< endl;
	}
	//cout <<"Fait à partir de "<< type+variable << " et de valeur " << valeur << endl;
}

bool Fait::demandable()
{
	return true;
}

string Fait::toString()
{
	string res=type+" ["+variable+"] "+valeur;
	return res;
}

bool Fait::memeValeur(Fait& other,Structure &struc_stockage_fait)
{
	cout << "je regarde la catégorie" << endl;
	bool res=false;
	if((strcmp((other.type).c_str(),type.c_str())==0) && (strcmp((other.variable).c_str(),variable.c_str())==0))
	{
		
		if(strcmp(valeur.c_str(),"Counter(PERSO)")==0)
		{
			if(type.find(jePrends)!=string::npos)
			{
				string qui_counter=getNomPerso(getCounter(struc_stockage_fait.adversaire.son_champion));
				string a_counter=other.valeur;
				cout << "je compare " << a_counter << " et "<< qui_counter << endl;
				res=(strcmp(a_counter.c_str(),qui_counter.c_str())==0);
			}
			else if(type.find(ilPrend)!=string::npos)
			{
				string qui_counter=getNomPerso(getCounter(struc_stockage_fait.moi.champion_pris));
				string a_counter=other.valeur;
				cout << "je compare " << a_counter << " et "<< qui_counter << endl;
				res=(strcmp(a_counter.c_str(),qui_counter.c_str())==0);
			}
		}
		else if(strcmp(other.valeur.c_str(),"Counter(PERSO)")==0)
		{
			if(other.type.find(jePrends)!=string::npos)
			{
				string qui_counter=getNomPerso(getCounter(struc_stockage_fait.adversaire.son_champion));
				string a_counter=valeur;
				cout << "je compare " << a_counter << " et "<< qui_counter << endl;
				res=(strcmp(a_counter.c_str(),qui_counter.c_str())==0);
			}
			else if(other.type.find(ilPrend)!=string::npos)
			{
				string qui_counter=getNomPerso(getCounter(struc_stockage_fait.moi.champion_pris));
				string a_counter=valeur;
				cout << "je compare " << a_counter << " et "<< qui_counter << endl;
				res=(strcmp(a_counter.c_str(),qui_counter.c_str())==0);
			}
		}
		else if(strcmp(other.type.c_str(),"je suis en ")==0)
		{
			res=(strcmp(valeur.c_str(),other.valeur.c_str())==0);
		}
		else if(strcmp(other.type.c_str(),"comparaison ")==0)
		{
			if(strcmp(other.variable.c_str(),"LibrePoste(POSTE)")==0)
			{
				string valeur_res=valeur.substr(valeur.find(",")+1);
				res=(strcmp(valeur_res.c_str()," true")==0);
				
			}
			else if(strcmp(other.variable.c_str(),"MoiIndecis(POSTE)")==0)
			{
				string valeur1=valeur.substr(0,valeur.find(","));
				string valeur2=valeur.substr(valeur.find(",")+1);
				string other_valeur2=other.valeur.substr(other.valeur.find(",")+1);
				
				if((strcmp(valeur2.c_str(),other_valeur2.c_str())==0))
				{
				
					if(strcmp(valeur2.c_str()," true")==0)
					{
						type_poste poste;
						if(!verifPoste(valeur1,poste))
						{
							cerr << "je n'ai pas trouvé le poste dans memecategorie'"<<endl;
						}
						else
						{
							res=(struc_stockage_fait.moi.champion_souhaite[poste]==nullptr);
						}
					}
					else if(strcmp(valeur2.c_str()," false")==0)
					{
						type_poste poste;
						if(!verifPoste(valeur1,poste))
						{
							cerr << "je n'ai pas trouvé le poste dans memecategorie'"<<endl;
						}
						else
						{
							res=(struc_stockage_fait.moi.champion_souhaite[poste]!=nullptr);
						}
					}
				}
				else
				{
					res=false;
				}
			}
			else
			{
				cerr << "comparaison non reconnue dans meme catégorie"<< endl;
			}
		}
		else
		{
			res=true;
		}
	}
	else
	{
		res=false;
	}
	return res;
}

Fait& Fait::operator=(const Fait& other){
	type=other.type;
	valeur=other.valeur;
	variable=other.variable;
	
	return *this;
}

bool Fait::operator==(const Fait& other)
{
	bool res;
	if((strcmp(type.c_str(),other.type.c_str())==0))
	{
		if((strcmp(variable.c_str(),other.variable.c_str())==0))
		{
			if(strcmp(type.c_str(),"je suis en ")==0)
			{
				if(strcmp(valeur.c_str(),other.valeur.c_str())==0)
				{
					res=true;
				}
				else
				{
					res=false;
				}
			}
			else
			{
				res=true;
			}
		}
		else 
		{
			res=false;
		}
	}
	else
	{
		res=false;
	}
	
	return res;
}

bool Fait::verifPoste(string valeur,type_poste& poste_vise)
{
	bool res=false;
	if(valeur.find("top")!=string::npos){
		poste_vise=TOP;
		res=true;
	}
	else if(valeur.find("mid")!=string::npos)
	{
		poste_vise=MID;
		res=true;
	}
	else if(valeur.find("jungle")!=string::npos)
	{
		poste_vise=JUNGLE;
		res=true;
	}
	else if(valeur.find("support")!=string::npos)
	{
		poste_vise=TOP;
		res=true;
	}
	else if(valeur.find("adc")!=string::npos)
	{
		poste_vise=ADC;
		res=true;
	}
	return res;
}

string Fait::getNomPoste(type_poste poste)
{
	string res;
	switch(poste)
	{
		case TOP : res="top";break;
		case MID : res="mid";break;
		case JUNGLE : res="jungle";break;
		case ADC : res="adc";break;
		case SUPPORT : res="support";break;
	}
	return res;
}

bool Fait::getPerso(string valeur, champion *perso)
{
	bool res=false;
	champion new_perso;
	if(valeur.find("GAREN")!=string::npos){
		new_perso=GAREN;
		res=true;
	}
	else if(valeur.find("LULU")!=string::npos){
		new_perso=LULU;
		res=true;
	}
	else if(valeur.find("DARIUS")!=string::npos){
		new_perso=DARIUS;
		res=true;
	}
	else if(valeur.find("LEBLANC")!=string::npos){
		new_perso=LEBLANC;
		res=true;
	}
	else if(valeur.find("MORGANA")!=string::npos){
		new_perso=MORGANA;
		res=true;
	}
	else if(valeur.find("AHRI")!=string::npos){
		new_perso=AHRI;
		res=true;
	}
	else if(valeur.find("EZREAL")!=string::npos){
		new_perso=EZREAL;
		res=true;
	}
	else if(valeur.find("CAITLYN")!=string::npos){
		new_perso=CAITLYN;
		res=true;
	}
	else if(valeur.find("VAYNE")!=string::npos){
		new_perso=VAYNE;
		res=true;
	}
	else if(valeur.find("NAMI")!=string::npos){
		new_perso=NAMI;
		res=true;
	}
	else if(valeur.find("LEONA")!=string::npos){
		new_perso=LEONA;
		res=true;
	}
	else if(valeur.find("NAUTILUS")!=string::npos){
		new_perso=NAUTILUS;
		res=true;
	}
	else if(valeur.find("LEE")!=string::npos){
		new_perso=LEE;
		res=true;
	}
	else if(valeur.find("SHACO")!=string::npos){
		new_perso=SHACO;
		res=true;
	}
	else if(valeur.find("FIDDLE")!=string::npos){
		new_perso=FIDDLE;
		res=true;
	}
	else
	{
		new_perso=CHAMPION_INCONNU;
	}
	if(perso==nullptr)
	{
		cerr << "Pointeur non initialisé avec getPerso" << endl;
	}
	else
	{
		*perso=new_perso;
	}
	return res;
}

string Fait::getNomPerso(champion champ)
{
	string res;
	switch(champ)
	{
		case GAREN : res="GAREN";break;
		case LULU : res="LULU";break;
		case DARIUS : res="DARIUS";break;
		case LEBLANC : res="LEBLANC";break;
		case MORGANA : res="MORGANA";break;
		case AHRI : res="AHRI";break;
		case EZREAL : res="EZREAL";break;
		case CAITLYN : res="CAITLYN";break;
		case VAYNE : res="VAYNE";break;
		case NAMI : res="NAMI";break;
		case LEONA : res="LEONA";break;
		case LEE : res="LEE";break;
		case SHACO : res="SHACO";break;
		case FIDDLE : res="FIDDLE";break;
		case NAUTILUS : res="NAUTILUS";break;
		case CHAMPION_INCONNU : res="FIDDLE"; cout << "On récupère le nom d'un champion inconnu"<< endl;break;
	}
	return res;
}

champion Fait::getCounter(champion* aCounter)
{
	Structure s;
	for (int i = 0; i < 15; ++i)
	{
		if (s.tab_counter[i].champion_a_counter == *aCounter)
		{
			cout << "j'ai trouvé un counter" << endl;			
			return s.tab_counter[i].champion_qui_counter;
		}
	}
	
	cout << "Counter non trouvé dans Strcture.cpp" << endl;
	return GAREN;
}

/*
int main(){
	Fait f("avoirChoix(CHOIX) == false");
}*/
