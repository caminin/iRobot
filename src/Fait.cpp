#include "../include/Fait.hpp"

using namespace std;

void Fait::initRegex()
{
	jeVeux = ( "je veux ");
	jeVais = ("je vais ");
	ilVa = ( "il va ");
	ilPrend = ("il prend ");
	jePrends = ("je prends ");
	comparaison = ("==");
}

Fait::Fait(){
	
}

////////////////////////////////////////////////////AUTRE CONSTRUCTEUR
Fait::Fait(string regle,Structure &struc_stockage_fait)
{
	initRegex();
	if (regle.find(jeVeux)!=string::npos)
	{
		type="je veux ";
		variable="PERSO";
		valeur=regex_replace(regle,jeVeux,"");
		
	}
	else if (regle.find(jeVais)!=string::npos)
	{
		type="je vais ";
		variable="POSTE";
		valeur=regex_replace(regle,jeVais,"");
		if(!valeur.find(nonFonction)!=string::npos)
		{
			if(valeur.find("Pref(")!=string::npos)
			{
				cout << "je suis dans pref2" << endl;
								
			}
		}
	}
	else if (regle.find(ilVa)!=string::npos)
	{
		type="il va ";
		variable="POSTE";
		valeur=regex_replace(regle,ilVa,"");
	}
	else if (regle.find(ilPrend)!=string::npos){
		type="il prend ";;
		variable="PERSO";
		valeur=regex_replace(regle,ilPrend,"");
	}
	else if (regle.find(jePrends)!=string::npos)
	{
		type="je prends ";;
		variable="PERSO";
		valeur=regex_replace(regle,jePrends,"");
	}
	else if (regle.find(comparaison)!=string::npos)
	{
		regex fin_cmp;
		fin_cmp = (" == [()[:alpha:] ]+");
		string specialisation_comp=regex_replace(regle,fin_cmp,"");
		
		type=("comparaison : "+specialisation_comp);;
		
		regex v1;
		v1 = (" == ");
		valeur=regex_replace(regle,v1,",");

		variable="UNITE1,VALEUR";
		cout << type << variable<<" " << valeur<<endl;
	}
	else
	{
		cout << "Regle que je connais pas " <<regle << endl;
	}
	//cout <<"Fait à partir de "<< type+variable << " et de valeur " << valeur << endl;
	
}

bool Fait::demandable()
{
	return true;
}

string Fait::toString()
{
	return type+" "+variable+" "+valeur;
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

/*
int main(){
	Fait f("avoirChoix(CHOIX) == false");
}*/
