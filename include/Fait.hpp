#ifndef FAITCLASSE
#define FAITCLASSE


#include <cstdio>
#include <string>
#include <iostream>
#include <regex>
#include <stdlib.h>
#include <time.h> 
#include "Structure.hpp"
using namespace std;


class Fait
{
private:
	/*
		Stockage des chaines de caractères utiles pour l'interprétation'
	
	*/
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
	string affectation;
	

public:
	//Initialise les chaines de caractères
	void initString();
	
	//Constructeur qui interpréte
	Fait(string regle,Structure &struc_stockage_fait);
	
	//Constructeur qui charge juste les faits (utilisé notamment par règle pour stocker les faits sans les utiliser)
	Fait(string regle);
	
	//retourne le fait en chaine de caractères
	string toString();
	
	//retourne si les faits sont équivalents
	bool memeValeur(Fait &other,Structure &struc_stockage_fait);
	
	// affecte un faits
	Fait& operator=(const Fait& other);
	
	//retourne si deux faits sont de même nature
	bool operator==(const Fait& other);
	
	//interprète le fait (regarde le fait, puis stocke les données déduites dans Structure)
	void interpretation(Structure &struct_stockage);
	
	//vérifie si une chaine de caractère correspond à un poste 
	bool verifPoste(string valeur,type_poste& poste_vise);
	
	//vérifie si uune chaine de caractère correspond à un personnage
	bool getPerso(string valeur, champion *perso);
	
	//retourne le nom en chaine de caractères d'un champion
	string getNomPerso(champion champ);
	
	//retourne le champion fort contre un autre champion
	champion getCounter(champion* aCounter);
	
	//retourne le nom du poste donnée en paramètre
	string getNomPoste(type_poste poste);
	
	//retourne la règle stockée utilisée pour ce fait
	string getRegle(){return MyRegle;};
};

#endif
