#include <cstdio>
#include <string.h>
#include <iostream>
#include "../include/chaineAvant.hpp"
#include "../include/chaineArriere.hpp"
using namespace std;

string pathBaseFait = "./base/baseFait.txt";
string pathBaseConnaissance = "./base/baseDeRegle.txt";
string pathBaseChampion = "./base/baseChampion.txt";


string init(int argc, char *argv[])
{
	if(argc<2)
		return "Arguments insuffisants";
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
	        return "";
		}
		else if(strcmp(argv[1],"basegen")==0)
		{
			fileGeneration base;
			base.generationBaseFait();
			base.afficheBaseFait();
		}
		else if(strcmp(argv[1],"structgen")==0)
		{
			fileGeneration file;
			file.generationStructFile();
			
		}
		else if(strcmp(argv[1],"ch_avant")==0)
		{
			chaineAvant chainage;
			chainage.runChaineAvant();
		}
		else if(strcmp(argv[1],"ch_arriere")==0)
		{
			chaineArriere chainage("je joue OFFENSIF");
			
			chainage.runChaineArriere();
		}
		else if(strcmp(argv[1],"doIt")==0)
		{
			fileGeneration base;
			base.generationBaseFait();
			base.afficheBaseFait();

			fileGeneration file;
			file.generationStructFile();

			chaineAvant chainage;
			chainage.runChaineAvant();
		}
		else {
			return "Arguments incorrect";
		}
	}
	return "Initialisation réussie";
}

int main(int argc, char* argv[])
{
	cout << init(argc, argv) << endl;

	return 0;
}


