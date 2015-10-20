#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ostream>
#include <algorithm>
#include <string.h>
#include "../include/struct.hpp"
#include "Fait.hpp"

class Regle {
	vector<Fait> antecedents;
	Fait consequence;
	
	public:
		Regle();
		vector<Fait> getAntecedents();
		Fait getConsequence();
		void addCons(Fait& cons);
		void addAnt(Fait& ant);
};
