#include "../include/Regle.hpp"


vector<Fait> Regle::getAntecedents(){
	return antecedents;
}

Regle::Regle(){
	consequence=nullptr;
}

Fait Regle::getConsequence(){
	return *consequence;
}

void Regle::addAnt(Fait& ant)
{
	antecedents.push_back(ant);
}

void Regle::addCons(Fait& cons)
{
	consequence=new Fait(cons);
}

bool Regle::operator==(const Regle& other)
{
	return (consequence==other.consequence);
}

string Regle::toString()
{
	string res="Antecents : ";
	for(Fait fait:antecedents)
	{
		res=res+"\n\t"+fait.toString();
	}
	res=res+"\nConsequence : "+consequence->toString();
	return res;
	cout << endl;
}
