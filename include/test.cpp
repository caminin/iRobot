#include <fstream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {

    fstream fichier("baseDeConnaissance.txt");
    ofstream baseFait;
    baseFait.open("baseFait.txt");
    string ligne;
    std::vector<string> lignes;
    

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
                    int i = 0;

                    while (existe == false && i < lignes.size())
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
    return 0;
}
