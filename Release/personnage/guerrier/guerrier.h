#pragma once
#include "../personnage.h"

class guerrier : public personnage
{
public:
	guerrier();
	void AttaqueSpecial(personnage & ennemi);
	~guerrier();

	
	void sesoigne();

};

