#ifndef STRUCT
#define STRUCT

#include <string>

using namespace std;

enum sort_invoc {FLASH,SMITE,IGNITE,HEAL,EXHAUST,SHIELD,TELEPORT,CLARITY};

enum champion {GAREN,LULU,DARIUS,LEBLANC,MORGANA,AHRI,EZREAL,CAITLYN,VAYNE,NAMI,LEONA,NAUTILUS,LEE,SHACO,FIDDLE};

enum type_poste {TOP,MID,ADC,SUPPORT,JUNGLE};

enum statut {LIBRE,PRIS};

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
	bool a_fait_un_choix;
	type_poste poste_souhaite;
	champion champion_souhaite;
	champion champion_pris;
	sortsType mes_sorts;
} moiType;

typedef struct s_preference
{
	string poste[5];
	string champion[5];
} preferenceType;


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

class Structure {
	preferenceType preference;
	moiType moi;
	bool tab_allie[5];
	champion* tab_adversaire[5];
	counterType* tab_counter;
	Structure();
	
};


#endif
