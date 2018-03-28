#pragma once
#include "../personnage.h"

class alchimiste : public personnage
{
public:
	alchimiste();
	void AttaqueSpecial(personnage & ennemi);
	~alchimiste();
	void sesoigne();
};

