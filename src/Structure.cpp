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
/*
string getCounter(string aCounter)
{
	for (int i = 0; i < 15; ++i)
	{
		if (tab_counter[i].champion_a_counter == champion_a_counter)
			return tab_counter[i].champion_qui_counter;
	}
}

void addAdversaire(string champ)
{
	int i=0;
	while(tab_adversaire[i]!==nullptr)
		i++;
	if (champ.find("GAREN")!=string::npos)
		tab_adversaire[i]=GAREN;
}*/
