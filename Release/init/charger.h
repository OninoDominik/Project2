#pragma once
#include "menu.h"

class charger
{
public:
	charger(int largeurFenetreDeJeu, int hauteurFenetreDeJeu, int Affichagefps);
	charger();
	~charger();
	void start();
	chose * boutonSauvegarde1 = new chose();
	chose * boutonSauvegarde2 = new chose();
	chose * boutonSauvegarde3 = new chose();
	void chargerBoutonSauvegarde1();
	sf::Font font;
	int largeurFenetreDeJeu;
	int hauteurFenetreDeJeu; 
	int Affichagefps;
	void chargerBoutonSauvegarde2();
	void chargerBoutonSauvegarde3();
};

