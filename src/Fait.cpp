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
		variable="PERSO";
		valeur=myreplace(regle,jeVeux,"");
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
		else if(verifPoste(valeur,struc_stockage_fait.moi.poste_pris))
		{
			
		}
		cout << type << variable<<" " << valeur<<endl;
	}
	else if (regle.find(ilVa)!=string::npos)
	{
		type="il va ";
		variable="POSTE";
		valeur=myreplace(regle,ilVa,"");
		if(verifPoste(valeur,struc_stockage_fait.moi.poste_pris))
		{
			
		}
		cout << type << variable<<" " << valeur<<endl;
	}
	else if (regle.find(ilPrend)!=string::npos){
		type="il prend ";;
		variable="PERSO";
		valeur=myreplace(regle,ilPrend,"");
		if (valeur.find("NON_CHOISI")!=string::npos)
		{
			//struc_stockage_fait.moi.champion_pris = champ;
		}
		cout << type << variable<<" " << valeur<<endl;
	}
	else if (regle.find(jePrends)!=string::npos)
	{
		type="je prends ";;
		variable="PERSO";
		valeur=myreplace(regle,jePrends,"");
		if (valeur.find("Counter(")!=string::npos)
		{
			//string v = myreplace(valeur,"Counter(","");
			cout << "je dois chercher le counter de " << valeur << endl;
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
	return ((strcmp(type.c_str(),other.type.c_str())==0));//||(strcmp(valeur.c_str(),other.valeur.c_str())==0)||(strcmp(variable.c_str(),other.variable.c_str())==0));
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

bool Fait::verifPerso(string valeur, champion *perso)
{
	bool res=false;
	if(valeur.find("GAREN")!=string::npos){
		perso=new champion;
		*perso=GAREN;
		res=true;
	}
	else if(valeur.find("LULU")!=string::npos){
		perso=new champion;
		*perso=LULU;
		res=true;
	}
	else if(valeur.find("DARIUS")!=string::npos){
		perso=new champion;
		*perso=DARIUS;
		res=true;
	}
	else if(valeur.find("LEBLANC")!=string::npos){
		perso=new champion;
		*perso=LEBLANC;
		res=true;
	}
	else if(valeur.find("MORGANA")!=string::npos){
		perso=new champion;
		*perso=MORGANA;
		res=true;
	}
	else if(valeur.find("AHRI")!=string::npos){
		perso=new champion;
		*perso=AHRI;
		res=true;
	}
	else if(valeur.find("EZREAL")!=string::npos){
		perso=new champion;
		*perso=EZREAL;
		res=true;
	}
	else if(valeur.find("CAITLYN")!=string::npos){
		perso=new champion;
		*perso=CAITLYN;
		res=true;
	}
	else if(valeur.find("VAYNE")!=string::npos){
		perso=new champion;
		*perso=VAYNE;
		res=true;
	}
	else if(valeur.find("NAMI")!=string::npos){
		perso=new champion;
		*perso=NAMI;
		res=true;
	}
	else if(valeur.find("LEONA")!=string::npos){
		perso=new champion;
		*perso=LEONA;
		res=true;
	}
	else if(valeur.find("NAUTILUS")!=string::npos){
		perso=new champion;
		*perso=NAUTILUS;
		res=true;
	}
	else if(valeur.find("LEE")!=string::npos){
		perso=new champion;
		*perso=LEE;
		res=true;
	}
	else if(valeur.find("SHACO")!=string::npos){
		perso=new champion;
		*perso=SHACO;
		res=true;
	}
	else if(valeur.find("FIDDLE")!=string::npos){
		perso=new champion;
		*perso=FIDDLE;
		res=true;
	}
	
	return res;
}
/*
int main(){
	Fait f("avoirChoix(CHOIX) == false");
}*/
