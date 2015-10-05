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
			      	baseFait<<ligne<<"\n";
            		
            	}
            }																						

        }
    }
    baseFait.close();
    return 0;
}
