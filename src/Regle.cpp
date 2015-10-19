#include "../include/Regle.hpp"


vector<Fait> Regle::getAntecedents(){
	return antecedents;
}

Fait Regle::getConsequence(){
	return consequence;
}
