#include "../include/Structure.hpp"
#include "../include/fileGeneration.hpp"

Structure::Structure()
{
	fileGeneration gen;
	for(int i=0;i<5;i++)
		tab_allie[i]=false;
	for(int i=0;i<5;i++)
		tab_adversaire[i]=nullptr;
	moi.champion_souhaite=nullptr;
	moi.champion_pris=nullptr;
	gen.getStructFile(tab_counter);
	
	
}




