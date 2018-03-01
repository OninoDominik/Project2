#pragma once
#include "personnage.h"
class combat
{
public:
	combat();
	~combat();

	static void Choixjoueur(personnage * joueur);

	static void startcombat(personnage * ami, personnage * ennemi);
	


};

