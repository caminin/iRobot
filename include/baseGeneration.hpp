#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ostream>
#include <algorithm>
#include <string.h>
using namespace std;

class baseGeneration
{
	public :
		bool myfind(vector<std::string> *myvector,string &ligne);
		void creerBaseFaitUnique();//go find baseDeConnaissance and make a baseFait
		void afficheBaseFait();
};


