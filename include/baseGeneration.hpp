#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ostream>
#include <algorithm>
#include <string.h>

class baseGeneration
{
	public :
		bool myfind(std::vector<std::string> *myvector,std::string &ligne);
		void creerBaseFaitUnique();//go find baseDeConnaissance and make a baseFait
		void afficheBaseFait();
};


