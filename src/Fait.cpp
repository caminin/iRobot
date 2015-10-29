#include "../include/Fait.hpp"

using namespace std;

void Fait::initRegex()
{
	jeVeux = ( "je veux ");
	jeVais = ("je vais ");
	ilVa=("il va");
	ilPrend = ("il prend ");
	jePrends = ("je prends ");
	comparaison = ("==");
	jeJoue= ("je joue ");
	jAi= ("je suis en ");
}

std::string myreplace(std::string &s,std::string toReplace,std::string replaceWith)
{
    return(s.replace(s.find(toReplace), toReplace.length(), replaceWith));
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
			variable=valeur;
		}
		else if(strcmp(valeur.c_str(),"POSTE")==0)
		{
			variable=valeur;
		}
		else 
		{
			struc_stockage_fait.adversaire.son_champion= new champion;
			if(!getPerso(valeur,struc_stockage_fait.adversaire.son_champion))
			{
				struc_stockage_fait.adversaire.son_champion=nullptr;
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
		if(valeur.find("Pref(")!=string::npos)
		{
			struc_stockage_fait.moi.poste_pris=struc_stockage_fait.moi.poste_souhaite;
		}
		else if(!verifPoste(valeur,struc_stockage_fait.moi.poste_pris))
		{
			cerr << "Le poste n'est pas reconnu sur un fait de type : " << " de valeur : "<< valeur <<endl;
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
		
		
		struc_stockage_fait.adversaire.son_champion= new champion;
		if (valeur.find("Counter(")!=string::npos)
		{
			valeur = myreplace(valeur,"Counter(","");
			valeur = myreplace(valeur, ")","");

			// recherche du counter de valeur
			
			cout << "je dois chercher le counter de " << valeur << endl;
			
			if(struc_stockage_fait.moi.champion_pris!=nullptr)
			{
				struc_stockage_fait.adversaire.son_champion=new champion;
				*(struc_stockage_fait.adversaire.son_champion)=struc_stockage_fait.getCounter(struc_stockage_fait.moi.champion_pris);
				cout << "j'ai trouvé " << *struc_stockage_fait.adversaire.son_champion << endl;
				valeur = getNomPerso(*struc_stockage_fait.adversaire.son_champion);
			}
			else
				cerr << "On ne peut pas prendre le counter d'un perso qui n'existe pas" << endl;

		}
		else if(!getPerso(valeur,struc_stockage_fait.adversaire.son_champion))
		{
			struc_stockage_fait.adversaire.son_champion=nullptr;
			cerr << "Le perso n'est pas reconnu sur un fait de type : " <<type << " de valeur : "<< valeur <<endl;
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
			
			cout << "je dois chercher le counter de " << valeur << endl;
			
			if(struc_stockage_fait.adversaire.son_champion!=nullptr)
			{
				struc_stockage_fait.moi.champion_pris=new champion;
				*(struc_stockage_fait.moi.champion_pris)=struc_stockage_fait.getCounter(struc_stockage_fait.adversaire.son_champion);
				cout << "j'ai trouvé " << *struc_stockage_fait.moi.champion_pris << endl;
				valeur = getNomPerso(*struc_stockage_fait.moi.champion_pris);
			}
			else
				cerr << "On ne peut pas prendre le counter d'un perso qui n'existe pas" << endl;

		}
		if (valeur.find("Pref(")!=string::npos)
		{
			valeur = myreplace(valeur,"Pref(","");
			valeur = myreplace(valeur, ")","");

			// recherche du perso prefere pour valeur

			cout << "je dois chercher le perso préféré pour " << valeur << endl;
		}
		cout << type << variable<<" " << valeur<<endl;
	}
	else if (regle.find(comparaison)!=string::npos)
	{
		regex fin_cmp;
		fin_cmp = (" == [()[:alpha:] ]+");
		string specialisation_comp=regex_replace(regle,fin_cmp,"");
		
		//type=("comparaison : "+specialisation_comp);;
		type = "comparaison ";
				
		//variable="ARGUMENT,VALEUR";
		variable = regle.substr(0,regle.find("==")-1); 
		
		//valeur=myreplace(regle," == ",",");
		valeur = regle.substr(regle.find("==")+2);
		
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

bool Fait::memeCategorie(Fait& other){
	return (strcmp((other.type).c_str(),type.c_str())==0);
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
			if(strcmp(type.c_str(),"comparaison ")==0)
			{
				if(strcmp(valeur.c_str(),other.valeur.c_str())==0)
				{
					res=true;
				}
				else
				{
					res=false;
				}
				cout << "c'est uen comparaison" << endl;
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
/*
int main(){
	Fait f("avoirChoix(CHOIX) == false");
}*/
