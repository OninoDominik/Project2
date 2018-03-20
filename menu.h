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
	int largeurFenetreDeJeu=800 ;
	int hauteurFenetreDeJeu = 800;
	int choixTailleEcran = 0;
	int numeroSauvegarde = 0;
	chose spriteCurseurCombat;
	void menuStart();
	void chargerBoutonNouvellePartie();
	void chargerBoutonChargerPartie();
	void chargerBoutonOption();

	void chargerBoutonsmenu();

	void ChargerBoutonTailleEcran();
	void ChargerBoutonFrameRate();

	chose *boutonTailleEcran = new chose();
	chose *boutonFrameRate = new chose();







};

