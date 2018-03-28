#pragma once
#include "../personnage/personnage.h"
#include <time.h>
class combat
{
public:
	combat();
	~combat();
	int tailleblock = 32;

	

	static void Choixjoueur(personnage * joueur);

	static void startcombat(personnage * ami, personnage * ennemi);
	
	
};

