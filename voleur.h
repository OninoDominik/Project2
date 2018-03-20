#pragma once
#include "personnage.h"

class voleur : public personnage
{
public:
	voleur();
	~voleur();
	void AttaqueSpecial(personnage & ennemi);
	void sesoigne();
	bool feinte = false;
};

