#include "../include/chaineArriere.hpp"

using namespace std;

chaineArriere::chaineArriere(string regle)
{
	fait = new Fait(regle,s);
	cout << "le but est :" << fait->toString() << " fait avec la regle : " << regle << endl;
}
void chaineArriere::runChaineArriere()
{
	Demo(*fait,base_fait);
}

bool chaineArriere::Demo(Fait& but, vector<Fait> &base_fait)
{
	cout << "debut" << endl;
	vector<Regle> base_regle;
	gen.getBaseRegle(base_regle);
	
	cout << "BASE DE FAIT ACTUELLE" << endl;
	for(Fait f:base_fait)
	{
		cout << f.toString()<<endl;
	}
	cout << "FIN BASE FAIT" << endl;
	
	bool dem=false;
	vector<Fait>::iterator it_fait=find(base_fait.begin(),base_fait.end(),but);
	
	bool estDansBaseFait=(it_fait!=base_fait.end());
	if(estDansBaseFait)
	{
		cout <<"Premier fait : "<< but.toString() << " | "<< it_fait->toString() << endl;
		dem=true;
	}
	vector<Regle>::iterator it_regle=base_regle.begin();
	while(dem==false && it_regle!=base_regle.end())
	{
		vector<Fait> f;
		if(it_regle==base_regle.end())
			cout << "plop"<< endl;
		if(it_regle->getConsequence()==but)
		{
			f=it_regle->getAntecedents();
			dem=verif(f,base_fait);
		}
		it_regle++;	
	}
	if(dem==false)
	{
		bool reponse;
		string reponse_but_demandable;
		cout << "Le fait : "<< but.toString();
		cout <<" est-il demandable ? (y/N)"<<endl;
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
	
	cout << "BASE DE FAIT ACTUELLE" << endl;
	for(Fait f:base_fait)
	{
		cout << f.toString()<<endl;
	}
	cout << "FIN BASE FAIT" << endl;
	cout << "boucle 5" << endl;
	return dem;
}

bool chaineArriere::verif(vector<Fait> &ensemble_but, vector<Fait> &base_fait){
	bool estVerifie=true;
	for(vector<Fait>::iterator i=ensemble_but.begin();i!=ensemble_but.end()&&estVerifie==true;i++ ){
		estVerifie=Demo(*i,base_fait);
	}
	
	return estVerifie;
}
