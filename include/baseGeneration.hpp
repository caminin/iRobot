#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ostream>
#include <algorithm>
#include <string.h>
#include "../include/lectureFichier.hpp"
#include "../include/struct.hpp"
using namespace std;

class baseGeneration
{
	public :
		bool myfind(vector<std::string> *myvector,string &ligne);
		void generationBaseFait();
		void afficheBaseFait();
		void structGeneration();
};


