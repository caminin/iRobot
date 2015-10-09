#include <stdio.h>
#include <string.h>
#include "../include/baseGeneration.hpp"


int main(int argc, char* argv[])
{
	if(argc<2)
		return 0;
	else 
	{
		if(strcmp(argv[1],"help")==0)
		{
			std::ifstream fichier("./.help");
        if(!fichier) 
        {
            std::cerr << "Le fichier help n'existe pas" << std::endl;
        }
        else
        {
            std::string line;
            while(std::getline(fichier,line))
            {
                std::cout << line << std::endl;
            }
        }
		}
		if(strcmp(argv[1],"basegen")==0)
		{
			baseGeneration base;
			base.creerBaseFaitUnique();
			base.afficheBaseFait();
		}
		else {
			return 0;
		}
	}
	return 0;
}
