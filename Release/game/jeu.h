#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../database/Database.h"
#include "../sqlite3.h"
#include <iostream>
#include <string>
#include "../personnage/personnage.h"
#include "mur.h"
#include "../gestionCombat/combat.h"
#include "../personnage/paladin/paladin.h"
#include <time.h>
#include "../personnage/guerrier/guerrier.h"
#include "../personnage/alchimiste/alchimiste.h"
#include "../personnage/ranger/ranger.h"
#include "../personnage/voleur/voleur.h"
#include "creationPerso.h"

class jeu
{
public:
	jeu();
	jeu(int largeur, int hauteur, bool framerate);
	void Combat32(personnage * ptrPj, personnage * Pnj, sf::Texture texturePnj, int x, int y);
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
	sf::Texture textureOrc;
	sf::RenderWindow combatWindow2;
	chose spriteCurseurCombat;
	sf::RenderWindow combatWindow;
	sf::Image icon;
	sf::Sprite spriteFond;
	sf::Sprite spriteAreneFront;
	sf::Sprite spriteAreneBack;
	sf::Font font;
	int largeurEcranPrincipal = 800;
	int hauteurEcranPrincipal = 600;
	chose * boutonAttaquer = new chose();
	chose * boutonSoin = new chose();
	chose * scorePjHp = new chose();
	chose * scorePnjHP = new chose();
	chose * boutonSpecial = new chose();
	chose * texteGameOver = new chose();
	chose * texteRemerciement = new chose();
	sf::Event combatEvent;
	int NiveauUn();
	int i = 0;
	int j = 0;
	int Startjeu(int classe, int force, int dexterite, int constitution, int charisme, int sagesse, int intelligence);
	int Startjeu(int classe, int currenthp, int force, int dexterite, int constitution, int charisme, int sagesse, int intelligence, int coordx, int coordy, int mob1, int mob2, int mob3, int numeroSauvegarde);
	vector<mur> murmap1();
	mur mur1;
	void ChargerHpPjetbarre(personnage * ptrPj);
	void ChargerBoutonSoin();
	void ChargerTexteGameover();
	void ChargerTexteRemerciement();
	void ChargerBoutonAttaquer();
	void ChargerHpPnj(personnage * ptrPNJ);
	void ChargerBoutonSpecial(personnage * ptrPj);
	int Startjeu();
	float framerate = 0;
	bool AfficherFrameRate = true;
	

};


