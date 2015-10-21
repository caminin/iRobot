#include "../include/Fait.hpp"

using namespace std;

void Fait::initRegex()
{
	jeVeux.assign( "je veux ");
	jeVais.assign("je vais ");
	ilVa.assign( "il va ");
	ilPrend.assign("il prend ");
	jePrends.assign("je prends ");
	comparaison.assign("[()[:alpha:]]+ == [()[:alpha:]]+");
}

Fait::Fait(){
	
}

Fait::Fait(string regle)
{
	initRegex();
	if (regex_search(regle,jeVeux)){
		type="je veux ";
		variable="PERSO";
		valeur=regex_replace(regle,jeVeux,"");
	}
	else if (regex_search(regle,jeVais)){
		type="je vais ";
		variable="PERSO";
		valeur=regex_replace(regle,jeVais,"");
	}
	else if (regex_search(regle,ilVa)){
		type="il va ";
		variable="PERSO";
		valeur=regex_replace(regle,ilVa,"");
	}
	else if (regex_search(regle,ilPrend)){
		type="il prend ";;
		variable="PERSO";
		valeur=regex_replace(regle,ilPrend,"");
	}
	else if (regex_search(regle,jePrends)){
		type="je prends ";;
		variable="PERSO";
		valeur=regex_replace(regle,jePrends,"");
	}
	else if (regex_search(regle,comparaison)){
		type="comparaison ";
		variable="PERSO";
		valeur=regex_replace(regle,comparaison,"");
		cout << "plop";
	}
	else{
		
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
	return ((strcmp(type.c_str(),other.type.c_str())==0)||(strcmp(valeur.c_str(),other.valeur.c_str())==0)||(strcmp(variable.c_str(),other.variable.c_str())==0));
}
/*
int main(){
	Fait f("plop() == plop");
}*/
