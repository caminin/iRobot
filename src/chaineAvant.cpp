#include "../include/chaineAvant.hpp"

using namespace std;


void chaineAvant::runChaineAvant(){
	fileGeneration file;
	vector<Regle> base_regle;
	file.getBaseRegle(base_regle);//contient la base des règles
	vector<Fait> base_fait;
	file.getBaseFait(base_fait);//contient la base des fait
	cout << base_regle[0].toString()<<endl;
	int nbInference=0;//nombre de fois qu'on applique une des regles
	map<Regle,int> memoriserRegleUtilisee;//memorise quand une regle est utilise
	bool resteAuMoinsUneRegle=true;//verifie s'il reste au moins une regle a utilise'
	bool auMoinsUneInference=true;//vérifie si au moins une regle est utilise
	while(auMoinsUneInference)//tant qu'on applique au moins une regle
	{
		auMoinsUneInference=false;
		cout << "onze" << endl;
		vector<Regle>::iterator it_regle=base_regle.begin();
		cout << "dix" << endl;
		while(resteAuMoinsUneRegle)
		{
			cout << "Premiere boucle" << endl;
			vector<Fait> antecedent=it_regle->getAntecedents();
			bool antecedentDansBaseFait=true;
			unsigned int j=0;
			while(antecedentDansBaseFait && j<antecedent.size())//on regarde dans tous les antecedents du fait
			{
				cout << "Deuxieme boucle" << endl;
				vector<Fait>::iterator it_fait=find(base_fait.begin(),base_fait.end(),antecedent[j]);
				bool estDansBaseFait=(it_fait!=base_fait.end());//regarde si l'antécédent est dans la base de fait'
				if(estDansBaseFait){//si un antécédent est dans la base de fait
					if(it_fait->memeCategorie(antecedent[j])){//si l'antécédent est de même catégorie'
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
			cout << "Trois" << endl;
			if(antecedentDansBaseFait)//si tous les antecendent sont dans la base de fait
			{
				cout << "sept "<<nbInference<< endl;
				cout << it_regle->getConsequence().toString();
				cout << "neuf"<<endl;
				base_fait.push_back(it_regle->getConsequence());//on save le nouveau faitx	
				cout << "huit" << endl;
				nbInference++;//une inférence en memoriserRegleUtilisee
				//plus.insert(pair(it_regle,nbInference));//on memorise la regle et le moment ou on l'a utilisée
				cout << "six" << endl;
				auMoinsUneInference=true;//il y a eu au moins une regle utilise
				cout << (*it_regle).getConsequence().toString();
				remove(base_regle.begin(),base_regle.end(),*it_regle);//supprime le ieme element du vector
			}
			cout << "cinq" << endl;
		
			if(base_regle.size()==0)//s'il ne reste pas de regle'
			{
				resteAuMoinsUneRegle=false;//on met fin a la boucle
			}
			it_regle++;
		}
	}
	cout << "je vais afficher la base de fait" << endl;
	for(vector<Fait>::iterator it=base_fait.begin();it!=base_fait.end();it++)
		cout << (*it).toString();
	cout <<endl <<"fin"<< endl;
}



