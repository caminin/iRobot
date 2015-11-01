#include "../include/chaineAvant.hpp"

using namespace std;


void chaineAvant::runChaineAvant(){
	fileGeneration file;
	Structure struc_stockage_fait;

	vector<Regle> base_regle;
	file.getBaseRegle(base_regle);//contient la base des règles

	vector<Fait> base_fait;
	file.getBaseFait(base_fait,struc_stockage_fait);//contient la base des fait

	int nbInference=0;//nombre de fois qu'on applique une des regles
	map<int,string> memoriserRegleUtilisee;//memorise quand une regle est utilise
	bool auMoinsUneInference=true;//vérifie si au moins une regle est utilise
	cout << endl;
	cout << "BASE DE FAIT ACTUELLE" << endl;
	for(Fait f:base_fait)
	{
		cout << "| " << f.toString()<<endl;
	}
	cout << endl;
			
	while(auMoinsUneInference)//tant qu'on applique au moins une regle
	{
		auMoinsUneInference=false;
		vector<Regle>::iterator it_regle=base_regle.begin();
		while(it_regle!=base_regle.end())
		{
			//cout << "Je démarre la boucle" << endl;
			//cout << it_regle->toString() << endl;
			vector<Fait> antecedent=it_regle->getAntecedents();
			bool antecedentDansBaseFait=true;
			unsigned int j=0;
			while(antecedentDansBaseFait && j<antecedent.size())//on regarde dans tous les antecedents du fait
			{
				vector<Fait>::iterator it_fait=find(base_fait.begin(),base_fait.end(),antecedent[j]);
				bool estDansBaseFait=(it_fait!=base_fait.end());//regarde si l'antécédent est dans la base de fait'
				
				if(estDansBaseFait)//si un antécédent est dans la base de fait
				{
					
					//cout << it_fait->toString()<< " | "<<antecedent[j].toString() << endl;
					if(it_fait->memeValeur(antecedent[j],struc_stockage_fait))//si l'antécédent est de même catégorie'
					{
						//antecedentDansBaseFait=true;// on continue
						//cout << endl<<"> J'ai trouvé un antécédent dans la base de fait"<<endl;
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
				//cout << endl<<"Fait que j'insère : \n" << (it_regle->getConsequence()).getRegle()<< endl;
				Fait f((it_regle->getConsequence()).getRegle(),struc_stockage_fait);
				base_fait.push_back(f);//on save le nouveau fait
				//cout << "|" <<f.toString() << endl;
				nbInference++;//une inférence en memoriserRegleUtilisee
				memoriserRegleUtilisee.insert(pair<int,string>(nbInference,it_regle->toString()));//on memorise la regle et le moment ou on l'a utilisée
				auMoinsUneInference=true;//il y a eu au moins une regle utilise
				if((it_regle+1)==base_regle.end())// si on supprime le dernier élément, on met le vecteur sur l'avant-dernier car sinon on ne sait pas ou le vecteur est
				{
					base_regle.erase(it_regle);//supprime le ieme element du vector
					it_regle=base_regle.end();//remet sur le dernier élément		
				}
				else{
					base_regle.erase(it_regle);//supprime le ieme element du vector
					it_regle++;					
				}
				//cout << "j'ai inséré un truc dans la base de fait " << endl;
				
			}
			else
				it_regle++;
			//it_regle est vide au 5e, mais il continue
		}
	}
	
	for(unsigned int i=1;i<=memoriserRegleUtilisee.size();i++)
	{
		cout <<"La "<<i<<"ème règle utilisée est : "<<endl<<memoriserRegleUtilisee[i]<<endl<<endl;
	}
}




