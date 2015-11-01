#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ostream>
#include <algorithm>
#include <string.h>
#include <unistd.h>
#include <map>
#include "Structure.hpp"
#include "Fait.hpp"
#include "Regle.hpp"
#include <utility>
#include "../include/fileGeneration.hpp"

using namespace std;

extern string pathBaseFait;
extern string pathBaseConnaissance;



class chaineAvant
{
public:
//lance le chainage avant
	void runChaineAvant();
};
