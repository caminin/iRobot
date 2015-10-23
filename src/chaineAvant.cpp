#include "../include/chaineAvant.hpp"

using namespace std;


void chaineAvant::runChaineAvant(){
	fileGeneration file;
	Structure struc_stockage_fait;
	vector<Regle> base_regle;
	file.getBaseRegle(base_regle);//contient la base des règles
	vector<Fait> base_fait;
	file.getBaseFait(base_fait,struc_stockage_fait);//contient la base des fait
	//for(Regle reg:base_regle)
	//	cout << reg.toString()<<endl;
	int nbInference=0;//nombre de fois qu'on applique une des regles
	map<Regle,int> memoriserRegleUtilisee;//memorise quand une regle est utilise
	bool auMoinsUneInference=true;//vérifie si au moins une regle est utilise
	cout << endl;
	cout << "BASE DE FAIT ACTUELLE" << endl;
	for(Fait f:base_fait)
	{
		cout << f.toString()<<endl;
	}
	cout << endl;
	cout << "BASE DE REGLE ACTUELLE" << endl;				
	for(Regle reg:base_regle)
	{
		cout << reg.toString()<<endl;
	}
	cout << endl;
	cin.get();
			
	while(auMoinsUneInference)//tant qu'on applique au moins une regle
	{
		auMoinsUneInference=false;
		vector<Regle>::iterator it_regle=base_regle.begin();
		while(it_regle!=base_regle.end())
		{
			vector<Fait> antecedent=it_regle->getAntecedents();
			bool antecedentDansBaseFait=true;
			unsigned int j=0;
			while(antecedentDansBaseFait && j<antecedent.size())//on regarde dans tous les antecedents du fait
			{
				vector<Fait>::iterator it_fait=find(base_fait.begin(),base_fait.end(),antecedent[j]);
				bool estDansBaseFait=(it_fait!=base_fait.end());//regarde si l'antécédent est dans la base de fait'
				
				if(estDansBaseFait)//si un antécédent est dans la base de fait
				{
					
					cout << it_fait->toString()<< " | "<<antecedent[j].toString() << endl;
					if(it_fait->memeCategorie(antecedent[j]))//si l'antécédent est de même catégorie'
					{
						//antecedentDansBaseFait=true;// on continue
						cout << "J'ai trouvé un antécédent dans la base de fait"<<endl;
					}
					else//si l'antécédent n'est pas de même catégorie
					{
						antecedentDansBaseFait=false;//on s'arrête'
					}
				}
				else
				{
					antecedentDansBaseFait=false;//tous les antecedent ne sont pas dans la base de fait donc on s'arrête
				}
				j++;//on parcours tous les antécédent grâce à cet itérateur
			}
			if(antecedentDansBaseFait)//si tous les antecendent sont dans la base de fait
			{
				base_fait.push_back(it_regle->getConsequence());//on save le nouveau faitx	
				nbInference++;//une inférence en memoriserRegleUtilisee
				//plus.insert(pair(it_regle,nbInference));//on memorise la regle et le moment ou on l'a utilisée
				auMoinsUneInference=true;//il y a eu au moins une regle utilise
				base_regle.erase(it_regle);//supprime le ieme element du vector
				cout << "j'ai inséré un truc dans la base de fait " << endl;
				
			}
		
			it_regle++;
			if(it_regle==base_regle.end())
			{
				cout << "j'ai fait toute les règles'"<<endl;		
			}
			cout << "BASE DE FAIT ACTUELLE" << endl;
			for(Fait f:base_fait){
				cout << f.toString()<<endl;

			}
			cout << endl;
			cin.get();
		}
	}
}



