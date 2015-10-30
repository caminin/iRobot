#include "../include/Structure.hpp"
#include "../include/fileGeneration.hpp"

Structure::Structure()
{
	fileGeneration gen;
	for(int i=0;i<5;i++)
		tab_allie[i]=false;
	adversaire.son_champion= nullptr;
	moi.champion_souhaite= nullptr;
	moi.champion_pris=nullptr;
	moi.ma_situation=EGALITE;
	tab_counter = new counterType[15];
	gen.getStructFile(tab_counter);
	
	
	
}

