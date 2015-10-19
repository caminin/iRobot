#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include "../include/struct.hpp"

using namespace std;

extern string pathBaseFait;
extern string pathBaseConnaissance;



class chaineArriere
{
public:
	void runChaineArriere(vector<Fait> but, vector<Fait> base_fait);
	bool verif(vector<Fait> but, vector<Fait> base_fait);
};
