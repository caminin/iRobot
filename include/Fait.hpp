#ifndef FAIT
#define FAIT


#include <cstdio>
#include <string>
#include <regex>
#include <iostream>
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
};

#endif
