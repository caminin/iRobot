#include "../include/chaineAvant.hpp"

using namespace std;



void chaineAvant::runChaineAvant(){
	vector<Regle> tab_regle;//contient la base de regles
	vector<Fait> base_fait;//contient la base des fait
	int nbInference=0;//nombre de fois qu'on applique une des regles
	map<Regle,int> memoriserRegleUtilisee;//memorise quand une regle est utilise
	
	bool resteAuMoinsUneRegle=true;//verifie s'il reste au moins une regle a utilise'
	bool auMoinsUneInference=true;//vérifie si au moins une regle est utilise
	while(auMoinsUneInference)//tant qu'on applique au moins une regle
	{
		auMoinsUneInference=false;
		while(resteAuMoinsUneRegle)
		{
			vector<Fait> antecedent=tab_regle[i].antecendent();
			bool antecedentDansBaseFait=true;
			int j=0;
			while(antecedentDansBaseFait && j<antecedent.size())//on regarde dans tous les antecedents du fait
			{
				vector<Fait>::interator it_fait=find(base_fait.begin(),base_fait.end(),antecedent[j]);
				bool estDansBaseFait=(it_fait!=base_fait.end());//regarde si l'antécédent est dans la base de fait'
				if(estDansBaseFait){//si un antécédent est dans la base de fait
					if(base_fait[it_fait].memeCategorie(antecedent[j])){//si l'antécédent est de même catégorie'
						antecedentDansBaseFait=true;// on continue
					}
					else{//si l'antécédent n'est pas de même catégorie
						antecedentDansBaseFait=false;//on s'arrête'
					}
				}
				else{
					antecedentDansBaseFait=false;//tous les antecedent ne sont pas dans la base de fait donc on s'arrête
				}
				j++;//on parcours tous les antécédent grâce à cet itérateur
			}
		
			if(antecedentDansBaseFait)//si tous les antecendent sont dans la base de fait
			{
				base_fait.push_back(tab_regle[i].consequence())//on save le nouveau fait
				
				nbInference++;//une inférence en plus
				memoriserRegleUtilisee.insert(pair(tab_regle[i],nbInference));//on memorise la regle et le moment ou on l'a utilisée
				auMoinsUneInference=true;//il y a eu au moins une regle utilise
				
				tab_regle.delete(myvector.begin()+(i-1));//supprime le ieme element du vector
			}
		
			if(tab_regle.size()==0)//s'il ne reste pas de regle'
			{
				resteAuMoinsUneRegle=false;//on met fin a la boucle
			}
		}
	}
}



