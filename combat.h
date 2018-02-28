#pragma once
#include "personnage.h"
class combat
{
public:
	combat();
	~combat();

	void Choixjoueur(personnage * joueur);

	void startcombat(personnage * ami, personnage * ennemi);


};

