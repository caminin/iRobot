#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ostream>
#include <algorithm>
#include <string>
#include "struct.hpp"
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
		counter* getStructFile(counter* tab_counter);
};


