#include "../include/baseGeneration.hpp"


using namespace std;


bool baseGeneration::myfind(vector<string> *myvector,string &ligne)
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
void baseGeneration::afficheBaseFait()
{
	ifstream fichier("./base/baseFait.txt");
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

void baseGeneration::creerBaseFaitUnique()
{
   fstream fichier("./base/baseDeConnaissance.txt");
    ofstream baseFait;
    baseFait.open("./base/baseFait.txt");
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



