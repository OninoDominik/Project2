#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Database.h"
#include "./sqlite3.h"
#include <iostream>
#include <string>
#include "personnage.h"
#include "mur.h"
#include "combat.h"
#include "paladin.h"
#include <time.h>
#include "guerrier.h"
class jeu
{
public:
	jeu();
	~jeu();

	sf::Texture texture;
	sf::Texture texture3;
	sf::Texture texture4;
	sf::Texture pala;
	sf::Texture textureHero;
	sf::Texture grave;
	sf::Texture fond;
	sf::Texture areneBack;
	sf::Texture areneFront;
	sf::RenderWindow combatWindow2;
	chose spriteCurseurCombat;
	sf::RenderWindow combatWindow;
	sf::Image icon;
	chose * boutonAttaquer = new chose();
	chose * boutonSoin = new chose();
	chose * scorePjHp = new chose();
	chose * scorePnjHP = new chose();
	chose * boutonSpecial = new chose();
	sf::Event combatEvent;
	int NiveauUn();
	vector<mur> murmap1();
	mur mur1;
	void ChargerHpPjetbarre(personnage * ptrPj);
	void ChargerBoutonSoin();
	void ChargerBoutonAttaquer();
	void ChargerHpPnj(personnage * ptrPNJ);
	void ChargerBoutonSpecial(personnage * ptrPj);
	int Startjeu();
	float framerate = 0;
	bool AfficherFrameRate = true;
	

};


