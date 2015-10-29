#include "../include/fileGeneration.hpp"

using namespace std;

extern string pathBaseFait;
extern string pathBaseConnaissance;


bool fileGeneration::myfind(vector<string> *myvector,string &ligne)
{
	for(vector<string>::iterator i=myvector->begin();i!=myvector->end();i++)
   {
		if(strcmp(ligne.c_str(),(*i).c_str())==0)
		{
			return true;
		}
	}
	return false;
}

void fileGeneration::afficheBaseFait()
{
	ifstream fichier(pathBaseFait);
        if(!fichier) 
        {
            cerr << "Le fichier baseFait.txt n'existe pas" << endl;
        }
        else
        {
            string line;
            while(getline(fichier,line))
            {
                cout << line << endl;
            }
        }
}

void fileGeneration::generationBaseFait()
{
    fstream fichier(pathBaseConnaissance);
    ofstream baseFait;
    baseFait.open(pathBaseFait);
    string ligne;
    vector<string> lignes;
    

    if ( !fichier )
    {
        cout << "fichier inexistant";
    }
    else if(baseFait.bad())
    {
    	cout << "Erreur fichier de connaissance";
    }
    else
    {
        while( !fichier.eof() )
        {
            getline(fichier, ligne);
            if(ligne!= "")
            {
            	size_t pos=ligne.find_first_of(" ");
            	if(pos!=string::npos)
            	{
            		ligne=ligne.substr(pos+1);
						bool existe = false;
                  unsigned int i = 0;
                  while ((existe == false) & (i < lignes.size()))
            		{
							if (lignes[i]==ligne)
								 existe = true;
							i++;
						}
						if (existe == false)
							lignes.push_back(ligne);
            	}
            }
        }
        for (vector<string>::iterator i = lignes.begin(); i != lignes.end(); ++i)
        {
            baseFait << *i << endl;
        }
    }
    baseFait.close();
}

void fileGeneration::generationSortsFile()
{
	sortsType list_sorts[5];

	//=====================TOP=====================
	list_sorts[0].sort1 = TELEPORT;
	list_sorts[0].sort2 = FLASH;
	
	//====================MID=======================
	list_sorts[1].sort1 = IGNITE;
	list_sorts[1].sort2 = FLASH;

	//====================ADC=======================
	list_sorts[2].sort1 = HEAL;
	list_sorts[2].sort2 = FLASH;
	
	//==================SUPPORT====================
	list_sorts[3].sort1 = EXHAUST;
	list_sorts[3].sort2 = FLASH;
	
	//===================JUNGLE======================
	list_sorts[4].sort1 = SMITE;
	list_sorts[4].sort2 = FLASH;

	ofstream strucFile("./base/list_sorts.bin",ios::out |ios::binary);
	for(int i=0;i<5;i++)
	{
		strucFile.write((char *)&(list_sorts[i]),sizeof(sortsType));
	}
	strucFile.close();
}

void fileGeneration::generationStructFile(){
	counterType list_counter[15];
	
	//=====================TOP=====================
	list_counter[0].champion_a_counter=GAREN;
	list_counter[0].champion_qui_counter=DARIUS;
	
	list_counter[1].champion_a_counter=DARIUS;
	list_counter[1].champion_qui_counter=LULU;
	
	list_counter[2].champion_a_counter=LULU;
	list_counter[2].champion_qui_counter=GAREN;
	
	//====================MID=======================
	list_counter[3].champion_a_counter=MORGANA;
	list_counter[3].champion_qui_counter=LEBLANC;
	
	list_counter[4].champion_a_counter=LEBLANC;
	list_counter[4].champion_qui_counter=AHRI;
	
	list_counter[5].champion_a_counter=AHRI;
	list_counter[5].champion_qui_counter=MORGANA;
	
	//====================ADC=======================
	list_counter[6].champion_a_counter=CAITLYN;
	list_counter[6].champion_qui_counter=EZREAL;
	
	list_counter[7].champion_a_counter=EZREAL;
	list_counter[7].champion_qui_counter=VAYNE;
	
	list_counter[8].champion_a_counter=VAYNE;
	list_counter[8].champion_qui_counter=CAITLYN;
	
	//==================SUPPORT====================
	list_counter[9].champion_a_counter=LEONA;
	list_counter[9].champion_qui_counter=NAUTILUS;
	
	list_counter[10].champion_a_counter=NAUTILUS;
	list_counter[10].champion_qui_counter=NAMI;
	
	list_counter[11].champion_a_counter=NAMI;
	list_counter[11].champion_qui_counter=LEONA;
	
	//===================JUNGLE======================
	list_counter[12].champion_a_counter=SHACO;
	list_counter[12].champion_qui_counter=LEE;
	
	list_counter[13].champion_a_counter=LEE;
	list_counter[13].champion_qui_counter=FIDDLE;
	
	list_counter[14].champion_a_counter=FIDDLE;
	list_counter[14].champion_qui_counter=SHACO;
	
	ofstream strucFile("./base/list_counter.bin",ios::out |ios::binary);
	for(int i=0;i<15;i++)
	{
		strucFile.write((char *)&(list_counter[i]),sizeof(counterType));
	}
	strucFile.close();
	//counter* tab_counter=nullptr;
	//getStructFile(tab_counter);
}


void fileGeneration::getStructFile(counterType* tab_counter){
	if(tab_counter==nullptr)
	{
		cerr << "tab_counter non intialisé dans getStructFile" << endl;		
	}
	else
	{
		ifstream strucFile("./base/list_counter.bin",ios::out |ios::binary);
		strucFile.read((char*)tab_counter,15*sizeof(counterType));
		strucFile.close();
	}
	
}

void fileGeneration::getBaseRegle(vector<Regle> &base_regle)
{
	Structure struc_qui_sert_pas;
	ifstream fichier("./base/baseDeRegle.txt");
	if(!fichier) 
	{
		cerr << "Le fichier base n'existe pas" << endl;
	}
	else
	{
		string ligne,debut;
		vector<string> lignes;
		
		Regle new_regle;
		while(getline(fichier,ligne))
		{
			//Fait new_fait(ligne,struc_qui_sert_pas);
		    if(ligne.size()>0)
		    {
			   	size_t pos=ligne.find_first_of(" ");
			   	if(pos!=string::npos)
			   	{
			        debut=ligne.substr(0,pos);
			   		ligne=ligne.substr(pos+1);
			        Fait new_fait(ligne,struc_qui_sert_pas);
			        if(!debut.find("THEN"))
			        {
			            new_regle.addCons(new_fait);
			            base_regle.push_back(new_regle);
			            new_regle=Regle();
			            cout << endl;
			        }
			        else
			        {
			        	new_regle.addAnt(new_fait);
			        }     
			   	}
		    }   
		}
	}
	cout << "==> Il y a "<< base_regle.size() << " Règles"<<endl;
	fichier.close();
}

void fileGeneration::getBaseFait(vector<Fait> &base_fait,Structure &struc_stockage_fait)
{
	ifstream fichier2("./base/baseFaitInital.txt");
	if(!fichier2) 
	{
		cerr << "Le fichier help n'existe pas" << endl;
	}
	else
	{
		string line;
		while(getline(fichier2,line))
		{
			Fait new_fait(line,struc_stockage_fait);
			base_fait.push_back(new_fait);
		}
	}
}



