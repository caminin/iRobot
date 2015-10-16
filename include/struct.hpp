/*enum sort_invoc {FLASH,SMITE,IGNITE,HEAL,EXHAUST,SHIELD,TELEPORT,CLARITY};*/

enum champion {GAREN,LULU,DARIUS,LEBLANC,MORGANA,AHRI,EZREAL,CAITLYN,VAYNE,NAMI,LEONA,NAUTILUS,LEE,SHACO,FIDDLE};
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

enum type_poste {TOP,MID,ADC,SUPPORT,JUNGLE};
 
enum statut {LIBRE,PRIS};


typedef struct s_poste {
	type_poste nom_poste;
	statut mon_statut;
} poste;

// champion *TabAdversaire[5];
// bool TabAllies[5];

typedef struct s_counter {
	champion champion_a_counter;
	champion champion_qui_counter;
} counter;

typedef struct s_moi {
	bool a_fait_un_choix;
	type_poste poste_souhaite;
	champion champion_souhaite;
	champion champion_pris;
	//sort_invoc mes_sorts[2];
} moi;

typedef struct s_preference
{
	string poste[5];
	string champion[5];
} preference;
