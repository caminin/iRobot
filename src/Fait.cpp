#include <cstdio>
#include <string>
#include <regex>
#include <iostream>
using namespace std;

class Fait
{
private:
	string type;
	string variable;
	string valeur;

	regex jeVeux;
	regex jeVais;
	regex ilVa;
	regex ilPrend;
	regex comparaison;

public:
	void initRegex()
	{
		jeVeux = "je veux [:alpha:]+";
		jeVais = "jevais[[:alpha:]]+";
		ilVa = "il va [:alpha:]";
		ilPrend = "il prend [:alpha:]";
		comparaison = "[:alpha:]([:alpha:])==[:alpha:]";
	}

	Fait(string regle)
	{
		if (regex_search(regle,jeVais))
			cout << "Regex type jeVais" << endl;
		else 
			cout << "Nope." << endl;
		std::regex pattern { "a" };
    std::cout << "'a' match with 'ab': " << std::boolalpha << 
        std::regex_match("ab", pattern) << std::endl;
 
    std::cout << "search 'a' in 'ab': " << std::boolalpha << 
        std::regex_search("ab", pattern) << std::endl;
	}

	~Fait()
	{

	}
};

int main(int argc, char* argv[])
{
	Fait f("jevaismid");

	return 0;
}