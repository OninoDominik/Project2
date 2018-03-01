#pragma once
#include "personnage.h"
#include <time.h>
class combat
{
public:
	combat();
	~combat();

	static void Choixjoueur(personnage * joueur);

	static void startcombat(personnage * ami, personnage * ennemi);
	
	
};

