#ifndef FAITCLASSE
#define FAITCLASSE


#include <cstdio>
#include <string>
#include <regex>
#include <iostream>
#include "Structure.hpp"
using namespace std;


class Fait
{
private:
	string type;
	string variable;
	string valeur;

	regex jeVeux;
	regex jeVais;
	regex ilVa;
	regex ilPrend;
	regex comparaison;
	regex jePrends;

public:
	void initRegex();
	Fait();
	Fait(string regle);
	bool demandable();
	string toString();
	bool memeCategorie(Fait &other);
	Fait& operator=(const Fait& other);
	bool operator==(const Fait& other);
	void interpretation(Structure &struct_stockage);
};

#endif
