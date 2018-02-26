#pragma once
#include "chose.h"

class personnage : public chose
{
public:
	personnage();
	~personnage();

	int vitesse = 1;
	int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
	bool monter = true;
	bool descendre = true;
	bool reculer = true;
	bool avancer = true;
	int compteurPas = 0;
	void Positionnement();
	void Mouvement();
};


