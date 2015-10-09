#include "../../../../../../usr/include/c++/5.1.1/iostream"
#include "../../../../../../usr/include/c++/5.1.1/string"
#include "../../../../../../usr/include/c++/5.1.1/fstream"
#include "../../../../../../usr/include/c++/5.1.1/vector"
#include "../../../../../../usr/include/c++/5.1.1/ostream"
#include "../../../../../../usr/include/c++/5.1.1/algorithm"
#include <string.h>

class baseGeneration
{
	public :
		bool myfind(std::vector<std::string> *myvector,std::string &ligne);
		void creerBaseFaitUnique();//go find baseDeConnaissance and make a baseFait
		void afficheBaseFait();
};


