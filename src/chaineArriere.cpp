#include "../include/chaineArriere.hpp"

using namespace std;


void chaineArriere::runChaineArriere(Fait but, vector<Fait> base_fait){
	vector<Fait> base_regle;
	bool dem=false;
	if(find(base_fait.begin(),base_fait.end(),but)!=base_fait.end()){
		dem=true;
	}
	vector<Fait>::iterator it=base_regle.begin();
	while(dem==false && it!=base_regle.end()){
		dem=verif(but.antecedent(),base_fait);
		it++;	
	}
	if(dem==false && but.demandable()){
		bool reponse;
		string reponse_but_demandable;
		cout << "Le fait : "<< but <<" est-il demandable ? (y/N)" endl;
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
}

bool chaineArriere::verif(vector<Fait> but, vector<Fait> base_fait){
	bool estVerifie=true;
	for(vector<Fait>::iterator i=but.begin();i<but.end()&&estVerifie==true;i++ ){
		estVerifie=runChaineArriere(but,base_fait);
	}
	
	return estVerifie;
}
