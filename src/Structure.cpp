#include "../include/Structure.hpp"


Structure::Structure
{
	fileGeneration gen;
	for(int i=0;i<5;i++)
		TabAllies[i]=false;
	for(int i=0;i<5;i++)
		poste[i]=false;
	gen(tab_counter);
	
}


