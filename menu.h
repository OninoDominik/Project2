#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Database.h"
#include "./sqlite3.h"
#include <iostream>
#include <string>
#include <time.h>
#include "chose.h"
#include "jeu.h"

class menu
{
public:
	menu();
	~menu();

	sf::RenderWindow menuWindow;
	
	chose * boutonChargerPartie = new chose();
	chose * boutonNouvellePartie = new chose();
	chose * boutonOption = new chose();
	chose * logo = new chose();
	sf::Texture textureLogo;

	bool Affichagefps = false;

	int tailleFenetreDeJeu = 1;
	int numeroSauvegarde = 0;
	chose spriteCurseurCombat;
	void menuStart();
	void chargerBoutonNouvellePartie();
	void chargerBoutonChargerPartie();
	void chargerBoutonOption();

	void chargerBoutons();




};

