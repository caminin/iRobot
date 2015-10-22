#include <cstdio>
#include <string.h>
#include <iostream>
#include "../include/chaineAvant.hpp"
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
			file.generationSortsFile();
			
		}
		else if(strcmp(argv[1],"ch_avant")==0)
		{
<<<<<<< HEAD
			chaineAvant ch;
			ch.runChaineAvant();
=======
			chaineAvant chainage;
			chainage.runChaineAvant();
>>>>>>> f3b1e8cda6d334e2db07f87bc882cb0010a8c101
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


