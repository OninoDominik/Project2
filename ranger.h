#pragma once
#include "personnage.h"

class ranger : public personnage
{
public:
	ranger();
	void AttaqueSpecial(personnage & ennemi);
	void sesoigne();
	~ranger();
};

