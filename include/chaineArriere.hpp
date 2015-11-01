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
	int step;
	Structure s;
	vector<Fait> base_fait;
	fileGeneration gen;
	vector<Fait> but;
			
public:
	chaineArriere();
	void runChaineArriere(int);
	bool Demo(Fait &but, vector<Fait> &base_fait,vector<Regle> &base_regle);
	bool verif(vector<Fait> &ensemble_but, vector<Fait> &base_fait,vector<Regle> &base_regle);
	Regle getBestRegle(vector<Regle> base_regle);
};
