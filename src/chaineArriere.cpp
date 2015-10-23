#include "../include/chaineArriere.hpp"

using namespace std;


bool chaineArriere::runChaineArriere(Fait& but, vector<Fait> &base_fait){
	vector<Regle> base_regle;
	bool dem=false;
	if(find(base_fait.begin(),base_fait.end(),but)!=base_fait.end()){
		dem=true;
	}
	vector<Regle>::iterator it=base_regle.begin();
	while(dem==false && it!=base_regle.end()){
		dem=verif((*it).getAntecedents(),base_fait);
		it++;	
	}
	if(dem==false){
		bool reponse;
		string reponse_but_demandable;
		cout << "Le fait : "<< but.toString();
		cout <<" est-il demandable ? (y/N)"<<endl;
		cin >> reponse_but_demandable;
		if(strcmp(reponse_but_demandable,"y")==0)
			reponse =true;
		else{
			reponse=false;
		}
		dem=reponse;
	}
	if(dem==true){
		base_fait.push_back(but);
	}
	return dem;
}

bool chaineArriere::verif(vector<Fait> &ensemble_but, vector<Fait> &base_fait){
	bool estVerifie=true;
	for(vector<Fait>::iterator i=ensemble_but.begin();i<ensemble_but.end()&&estVerifie==true;i++ ){
		estVerifie=runChaineArriere(*i,base_fait);
	}
	
	return estVerifie;
}
