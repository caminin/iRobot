#include "../include/Fait.hpp"

using namespace std;

void Fait::initRegex()
{
	jeVeux.assign( "je veux ");
	jeVais.assign("je vais ");
	ilVa.assign( "il va ");
	ilPrend.assign("il prend ");
	jePrends.assign("je prends ");
	comparaison.assign("[()[:alpha:] ]+ == [ [:alpha:]()]+");
	nonFonction.assign("[[:alpha:] ]+");
}

Fait::Fait(){
	
}

Fait::Fait(string regle)
{
	initRegex();
	if (regex_search(regle,jeVeux))
	{
		type="je veux ";
		variable="PERSO";
		valeur=regex_replace(regle,jeVeux,"");
		
	}
	else if (regex_search(regle,jeVais))
	{
		type="je vais ";
		variable="POSTE";
		valeur=regex_replace(regle,jeVais,"");
	}
	else if (regex_search(regle,ilVa))
	{
		type="il va ";
		variable="POSTE";
		valeur=regex_replace(regle,ilVa,"");
	}
	else if (regex_search(regle,ilPrend)){
		type="il prend ";;
		variable="PERSO";
		valeur=regex_replace(regle,ilPrend,"");
	}
	else if (regex_search(regle,jePrends))
	{
		type="je prends ";;
		variable="PERSO";
		valeur=regex_replace(regle,jePrends,"");
	}
	else if (regex_search(regle,comparaison))
	{
		regex fin_cmp;
		fin_cmp.assign(" == [()[:alpha:] ]+");
		string specialisation_comp=regex_replace(regle,fin_cmp,"");
		
		type=("comparaison : "+specialisation_comp);;
		
		regex v1;
		v1.assign(" == ");
		valeur=regex_replace(regle,v1,",");

		variable="UNITE1,VALEUR";
		cout << type << variable<<" " << valeur<<endl;
	}
	else
	{
		//cout << "Regle que je connais pas " <<regle << endl;
	}
	//cout << type << variable<<" " << valeur<<endl;
}
////////////////////////////////////////////////////AUTRE CONSTRUCTEUR
Fait::Fait(string regle,Structure &struc_stockage_fait)
{
	initRegex();
	if (regex_search(regle,jeVeux))
	{
		type="je veux ";
		variable="PERSO";
		valeur=regex_replace(regle,jeVeux,"");
		
	}
	else if (regex_search(regle,jeVais))
	{
		type="je vais ";
		variable="POSTE";
		valeur=regex_replace(regle,jeVais,"");
		if(!regex_search(valeur,nonFonction))
		{
			if(regex_search(valeur,regex("Pref(")))
			{
				cout << "je suis dans pref" << endl;
				
				
			}
		}
	}
	else if (regex_search(regle,ilVa))
	{
		type="il va ";
		variable="POSTE";
		valeur=regex_replace(regle,ilVa,"");
	}
	else if (regex_search(regle,ilPrend)){
		type="il prend ";;
		variable="PERSO";
		valeur=regex_replace(regle,ilPrend,"");
	}
	else if (regex_search(regle,jePrends))
	{
		type="je prends ";;
		variable="PERSO";
		valeur=regex_replace(regle,jePrends,"");
	}
	else if (regex_search(regle,comparaison))
	{
		regex fin_cmp;
		fin_cmp.assign(" == [()[:alpha:] ]+");
		string specialisation_comp=regex_replace(regle,fin_cmp,"");
		
		type=("comparaison : "+specialisation_comp);;
		
		regex v1;
		v1.assign(" == ");
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
<<<<<<< HEAD
}
=======
}

/*
int main(){
	Fait f("avoirChoix(CHOIX) == false");
}*/
>>>>>>> b88ba6f1f337f882a552f2a1287757221347f3d9
