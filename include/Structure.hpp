#ifndef STRUCTCLASS
#define STRUCTCLASS

#include <string>

using namespace std;

enum sort_invoc {FLASH,SMITE,IGNITE,HEAL,EXHAUST,SHIELD,TELEPORT,CLARITY};

enum champion {GAREN,LULU,DARIUS,LEBLANC,MORGANA,AHRI,EZREAL,CAITLYN,VAYNE,NAMI,LEONA,NAUTILUS,LEE,SHACO,FIDDLE,CHAMPION_INCONNU};

enum type_poste {TOP,MID,ADC,SUPPORT,JUNGLE};

enum statut {LIBRE,PRIS};

enum situation {AVANTAGE,DESAVANTAGE,EGALITE};

/*
typedef struct s_poste {
	type_poste nom_poste;
	statut mon_statut;
} posteType;*/

typedef struct s_counter {
	champion champion_a_counter;
	champion champion_qui_counter;
} counterType;

typedef struct s_sort
{
	sort_invoc sort1;
	sort_invoc sort2;
} sortsType;

typedef struct s_moi {
	type_poste poste_souhaite;
	type_poste poste_pris;
	champion* champion_souhaite;
	champion* champion_pris;
	sortsType mes_sorts;
	situation ma_situation;
	
} moiType;

typedef struct s_adversaireType {
	champion * son_champion;
	type_poste son_poste;
} adversaireType;

/*
TOP:
	Garen
	Lulu
	Darius
MID:
	Leblanc
	Morgana
	Ahri
ADC:
	Ezreal
	Caitlyn
	Vayne
SUPPORT:
	Nami
	Leona
	Nautilus
JUNGLE:
	Lee
	Shaco
	Fiddle
*/

class Structure{
public: 
	moiType moi;
	bool tab_allie[5];
	adversaireType adversaire;
	counterType* tab_counter;
	Structure();

	champion getCounter(champion* aCounter);
	
};


#endif
