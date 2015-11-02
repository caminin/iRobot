#ifndef STRUCTCLASS
#define STRUCTCLASS

#include <string>

using namespace std;

//stocke tous les champions (personnage a jouer)
enum champion {GAREN,LULU,DARIUS,LEBLANC,MORGANA,AHRI,EZREAL,CAITLYN,VAYNE,NAMI,LEONA,NAUTILUS,LEE,SHACO,FIDDLE,CHAMPION_INCONNU};

//Les 5 postes disponibles
enum type_poste {TOP,MID,ADC,SUPPORT,JUNGLE};

enum situation {AVANTAGE,DESAVANTAGE,EGALITE};

//stockage du counter d'un personnage'
typedef struct s_counter {
	champion champion_a_counter;
	champion champion_qui_counter;
} counterType;

//stockage de nos données
typedef struct s_moi {
	type_poste poste_souhaite;
	type_poste poste_pris;
	champion* champion_souhaite[5];
	champion* champion_pris;
	situation ma_situation;
	
} moiType;

//stockage de l'adversaire'
typedef struct s_adversaireType {
	champion * son_champion;
	type_poste son_poste;
} adversaireType;


class Structure{
public: 
	champion * stockage_champion_pref;
	moiType moi;
	bool tab_allie[5];
	adversaireType adversaire;
	counterType* tab_counter;
	Structure();
};


#endif
