#pragma once
#include <string>
#include "personnage.h"

class sauvegarde
{
public:
	sauvegarde();
	sauvegarde(string nomdelaClasse, personnage * ptrPj, bool viemob1, bool viemob2, bool viemob3, int rowid);
	~sauvegarde();

	int classe;
	std::string nomClasse;
	int force = 10;
	int constitution = 10;
	int dexterite = 10;
	int sagesse = 10;
	int charisme = 10;
	int intelligence = 10;
	int coordx = 8 * 32;
	int coordy = 45 * 32;
	int rowID=0;
	int currentHp=99;
	bool mob1 = true;
	bool mob2 = true;
	bool mob3 = true;
	/*bool mob4 = true;
	bool mob5 = true;
	bool mob6 = true;
	bool mob7 = true;
	bool mob8 = true;
	bool mob9 = true;
	bool mob10 = true*/;
};

