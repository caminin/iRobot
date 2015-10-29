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

champion Structure::getCounter(champion* aCounter)
{
	for (int i = 0; i < 15; ++i)
	{
		if (tab_counter[i].champion_a_counter == *aCounter)
		{
			cout << "j'ai trouvé un counter" << endl;			
			return tab_counter[i].champion_qui_counter;
		}
	}
	
	cout << "Counter non trouvé dans Strcture.cpp" << endl;
	return GAREN;
}

