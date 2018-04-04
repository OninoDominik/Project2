#include "sauvegarde.h"



sauvegarde::sauvegarde(string nomdelaClasse, personnage * ptrPj, bool viemob1, bool viemob2, bool viemob3,bool viemob4, int rowid)
{
	nomClasse = nomdelaClasse;
	force = *ptrPj->force;
	constitution = *ptrPj->constitution;
	dexterite = *ptrPj->dexterite;
	sagesse = *ptrPj->sagesse;
	charisme = *ptrPj->charisme;
	intelligence = *ptrPj->intelligence;
	coordx = ptrPj->rect.getPosition().x;
	coordy = ptrPj->rect.getPosition().y;
	classe = *ptrPj->classe;
	mob1 = viemob1;
	mob2 = viemob2;
	mob3 = viemob3;
	mob4 = viemob4;
	rowID = rowid;
	currentHp = *ptrPj->pvActuel;
}
sauvegarde::sauvegarde()
{

}

sauvegarde::~sauvegarde()
{
}
