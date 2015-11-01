#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <string.h>
#include <string>
#include <unistd.h>
#include <utility>
#include <vector>
#include "Structure.hpp"
#include "Fait.hpp"
#include "Regle.hpp"
#include "../include/fileGeneration.hpp"

using namespace std;

extern string pathBaseFait;
extern string pathBaseConnaissance;



class chaineAvant
{
public:
//lance le chainage avant
	void runChaineAvant(int);
};
