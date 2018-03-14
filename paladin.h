#pragma once
#include "personnage.h"

class paladin : public personnage
{
	
public:
	paladin();
	~paladin();
	
	//int * nbrDesSoin = new int(2);
	//int * nbrFaceDesSoin = new int(6);

	

	void sesoigne();
	void AttaqueSpecial(personnage & ennemi);
};

