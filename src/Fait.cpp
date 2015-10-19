#include "../include/Fait.hpp"

using namespace std;

void Fait::initRegex()
{
	jeVeux = "je veux [:alpha:]+";
	jeVais = "jevais[[:alpha:]]+";
	ilVa = "il va [:alpha:]";
	ilPrend = "il prend [:alpha:]";
	comparaison = "[:alpha:]([:alpha:])==[:alpha:]";
}

Fait::Fait(string regle)
{
	if (regex_search(regle,jeVais))
		cout << "Regex type jeVais" << endl;
	else 
		cout << "Nope." << endl;
	regex pattern { "a" };
 cout << "'a' match with 'ab': " << boolalpha << 
     regex_match("ab", pattern) << endl;

 cout << "search 'a' in 'ab': " << boolalpha << 
     regex_search("ab", pattern) << endl;
}

bool Fait::demandable()
{
	return true;
}

string Fait::toString()
{
	return type+" "+variable+" "+valeur;
}
