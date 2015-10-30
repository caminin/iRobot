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
	string jeJoue;
	string jAi;

public:
	void initRegex();
	Fait(string regle,Structure &struc_stockage_fait);
	Fait(string regle);
	bool demandable();
	string toString();
	bool memeCategorie(Fait &other,Structure &struc_stockage_fait);
	Fait& operator=(const Fait& other);
	bool operator==(const Fait& other);
	void interpretation(Structure &struct_stockage);
	bool verifPoste(string valeur,type_poste& poste_vise);
	bool getPerso(string valeur, champion *perso);
	string getNomPerso(champion champ);
	champion getCounter(champion* aCounter);
	
	string getRegle(){return MyRegle;};
};

#endif
