#include <algorithm>
#include <fstream>
#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <vector>
#include "Structure.hpp"
#include "Fait.hpp"
#include "Regle.hpp"
#include "fileGeneration.hpp"

using namespace std;

extern string pathBaseFait;
extern string pathBaseConnaissance;



class chaineArriere
{
private:
	// Stockage pour les bases
	int step;
	Structure s;
	vector<Fait> base_fait;
	fileGeneration gen;
	vector<Fait> but;
			
public:
	// constructeur
	chaineArriere();
	
	//Lance le chainage arrière
	void runChaineArriere(int step);
	
	//vérifie si un but est dans la base, sinon cherche avec une règle
	bool Demo(Fait &but, vector<Fait> &base_fait,vector<Regle> &base_regle);
	
	//applique démo à tous les buts
	bool verif(vector<Fait> &ensemble_but, vector<Fait> &base_fait,vector<Regle> &base_regle);
	
	//récupère la meilleure règle à appliquer
	Regle getBestRegle(vector<Regle> base_regle);
};
