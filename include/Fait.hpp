#ifndef FAITCLASSE
#define FAITCLASSE


#include <cstdio>
#include <string>
#include <iostream>
#include <regex>
#include "Structure.hpp"
using namespace std;


class Fait
{
private:
	string type="";
	string variable="";
	string valeur="";

	string MyRegle="default";

	string jeVeux;
	string jeVais;
	string ilVa;
	string ilPrend;
	string comparaison;
	string jePrends;

public:
	void initRegex();
	Fait(string regle,Structure &struc_stockage_fait);
	bool demandable();
	string toString();
	bool memeCategorie(Fait &other);
	Fait& operator=(const Fait& other);
	bool operator==(const Fait& other);
	void interpretation(Structure &struct_stockage);
	bool verifPoste(string valeur,type_poste& poste_vise);
	bool verifPerso(string valeur, champion *perso);
	
	string getRegle(){return MyRegle;};
};

#endif
