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
		//perosnnage de trouver un string dans un vector
		bool myfind(vector<std::string> *myvector,string &ligne);
		
		//génère un fichier contenant tous les faits différents
		void generationBaseFait();
		
		//affiche la base de fait à partir du fihcier créé
		void afficheBaseFait();
		
		//génère un fichier avec les counter en binaire 
		void generationStructFile();
		
		//récupère le fichier binaire
		void getStructFile(counterType* tab_counter);
		
		//récupère la base de règles, la parse et créé les faits
		void getBaseRegle(vector<Regle>& base_regle);
		
		//récupère la base de faits, la parse et créé les faits
		void getBaseFait(vector<Fait>& base_fait,Structure &struc_stockage_fait);
		
		//retourne la base de but
		void getBut(vector<Fait> &but);
};

#endif
