#pragma once
#include "../personnage/chose.h"

class mur : public chose
{
	
	public:
		mur();
		mur(int x, int y, int largeur, int longueur);
		~mur();
		vector<mur> ligneMur;
		
};


