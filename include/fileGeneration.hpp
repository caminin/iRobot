#ifndef FILEGENERATION
#define FILEGENERATION

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ostream>
#include <algorithm>
#include <string>
#include "Structure.hpp"
#include "Regle.hpp"
#include "Fait.hpp"
using namespace std;

class fileGeneration
{
	public :
		bool myfind(vector<std::string> *myvector,string &ligne);
		void generationBaseFait();
		void afficheBaseFait();
		void generationStructFile();
		void generationSortsFile();
		void getStructFile(counter* tab_counter);
		void getBaseRegle(vector<Regle>& base_regle);
		void getBaseFait(vector<Fait>& base_fait);
};

#endif
