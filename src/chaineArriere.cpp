#include "../include/chaineArriere.hpp"

using namespace std;
int i=0;

chaineArriere::chaineArriere()
{
	fileGeneration gen;
	gen.getBaseFait(base_fait,s);
	gen.getBut(but);
	
	
}
void chaineArriere::runChaineArriere()
{
	vector<Regle> base_regle;
	gen.getBaseRegle(base_regle);
	
	verif(base_fait,but,base_regle);
	
	cout << "Résultat" << endl;
	for(Fait f:but)
	{
		cout << f.toString()<<endl;
	}
	cout << "FIN" << endl;
}

bool chaineArriere::Demo(Fait& but, vector<Fait> &base_fait,vector<Regle> &base_regle)
{
	/**/
	bool dem=false;
	vector<Fait>::iterator it_fait=find(base_fait.begin(),base_fait.end(),but);
	
	bool estDansBaseFait=(it_fait!=base_fait.end());
	if(estDansBaseFait)
	{
		//cout <<"Premier fait : "<< but.toString() << " | "<< it_fait->toString() << endl;
		dem=true;
	}
	vector<Regle>::iterator it_regle=base_regle.begin();
	vector<Regle> save_regle_applicable;
	while(dem==false && it_regle!=base_regle.end())
	{
		if(it_regle->getConsequence()==but)
		{
			save_regle_applicable.push_back(*it_regle);
			
		}
		it_regle++;	
	}
	if(!save_regle_applicable.empty())
	{
		vector<Fait> f;
		Regle regle_a_appliquer=getBestRegle(save_regle_applicable);
		f=regle_a_appliquer.getAntecedents();
		dem=verif(f,base_fait,base_regle);
	}
	
	if(dem==false)
	{
		bool reponse;
		string reponse_but_demandable;
		cout << "Le fait : "<< but.toString();
		cout <<" est-il connu ? (y/N)"<<endl;
		cin >> reponse_but_demandable;
		if(strcmp(reponse_but_demandable.c_str(),"y")==0)
			reponse =true;
		else{
			reponse=false;
		}
		dem=reponse;
	}
	if(dem==true)
	{
		base_fait.push_back(but);
	}
	
	return dem;
}

bool chaineArriere::verif(vector<Fait> &ensemble_but, vector<Fait> &base_fait,vector<Regle> &base_regle){
	bool estVerifie=true;
	for(vector<Fait>::iterator i=ensemble_but.begin();i!=ensemble_but.end()&&estVerifie==true;i++ ){
		estVerifie=Demo(*i,base_fait,base_regle);
	}
	
	return estVerifie;
}

Regle chaineArriere::getBestRegle(vector<Regle> base_regle)
{
	Regle res;
	unsigned int size=0;
	for(Regle regle:base_regle)
	{
		vector <Fait> f=regle.getAntecedents();
		if(size<f.size())
		{
			res=regle;
		}
		else
			cout << "la règle était plus grnade" << endl;
	}
	
	return res;
}
