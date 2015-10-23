#ifndef FAITCLASSE
#define FAITCLASSE


#include <cstdio>
#include <string>
#include <iostream>
#include "Structure.hpp"
using namespace std;


class Fait
{
private:
	string type;
	string variable;
	string valeur;

	string jeVeux;
	string jeVais;
	string ilVa;
	string ilPrend;
	string comparaison;
	string jePrends;

public:
	void initRegex();
	Fait();
	Fait(string regle);
	Fait(string regle,Structure &struc_stockage_fait);
	bool demandable();
	string toString();
	bool memeCategorie(Fait &other);
	Fait& operator=(const Fait& other);
	bool operator==(const Fait& other);
	void interpretation(Structure &struct_stockage);
};

#endif
