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
		Fait *fait;
			
public:
	chaineArriere(string regle);
	void runChaineArriere();
	bool Demo(Fait &but, vector<Fait> &base_fait);
	bool verif(vector<Fait> &ensemble_but, vector<Fait> &base_fait);
};
