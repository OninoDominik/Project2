#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../database/Database.h"
#include "../sqlite3.h"
#include <iostream>
#include <string>
#include <time.h>
#include "../personnage/chose.h"
#include "../game/jeu.h"
#include <stdio.h>
#include "charger.h"

class menu
{
public:
	menu();
	~menu();

	sf::RenderWindow menuWindow;
	sf::RenderWindow chargerdeWindow;
	chose * boutonChargerPartie = new chose();
	chose * boutonNouvellePartie = new chose();
	chose * boutonOption = new chose();
	chose * boutonSauvegarde1 = new chose();
	chose * boutonSauvegarde2 = new chose();
	chose * boutonSauvegarde3 = new chose();
	
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

	void chargerBoutonSauvegarde();

	void chargerBoutonSauvegarde1();
	void chargerBoutonSauvegarde2();
	void chargerBoutonSauvegarde3();
	void ChargerBoutonTailleEcran();
	void ChargerBoutonFrameRate();

	chose *boutonTailleEcran = new chose();
	chose *boutonFrameRate = new chose();
	chose *boutonSauvegarde = new chose();







};

