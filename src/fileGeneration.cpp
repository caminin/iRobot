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
            cerr << "Le fichier help n'existe pas" << endl;
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

void fileGeneration::structGeneration(){
	counter list_counter[15];
	
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
	
	ofstream strucFile("../base/list_counter",ios_base::binary); 
	
	for(int i=0;i<15;i++)
	{
		strucFile.write((char *)&(list_counter[i]),sizeof(counter));
	}
	strucFile.close();
}




