#include <cstdio>
#include <string.h>
#include <iostream>
#include "../include/baseGeneration.hpp"
using namespace std;


int main(int argc, char* argv[])
{
	if(argc<2)
		return 0;
	else 
	{
		if(strcmp(argv[1],"help")==0)
		{
			ifstream fichier("./.help");
        if(!fichier) 
        {
            cerr << "Le fichier help n'existe pas" << endl;
        }
        else
        {
            string line;
            while(getline(fichier,line))
            {
                cout << line << endl;
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
