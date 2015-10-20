#include "../include/Regle.hpp"


vector<Fait> Regle::getAntecedents(){
	return antecedents;
}

Regle::Regle(){
	
}

Fait Regle::getConsequence(){
	return consequence;
}

void Regle::addAnt(Fait& ant)
{
	antecedents.push_back(ant);
}

void Regle::addCons(Fait& cons)
{
	consequence=cons;
}
