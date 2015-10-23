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
public:
	bool runChaineArriere(Fait &but, vector<Fait> &base_fait);
	bool verif(vector<Fait> &ensemble_but, vector<Fait> &base_fait);
};
