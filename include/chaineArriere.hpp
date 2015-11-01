#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
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
		Structure s;
		vector<Fait> base_fait;
		fileGeneration gen;
		vector<Fait> but;
			
public:
	chaineArriere();
	void runChaineArriere();
	bool Demo(Fait &but, vector<Fait> &base_fait,vector<Regle> &base_regle);
	bool verif(vector<Fait> &ensemble_but, vector<Fait> &base_fait,vector<Regle> &base_regle);
	Regle getBestRegle(vector<Regle> base_regle);
};
