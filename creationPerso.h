#pragma once
#include "personnage.h"
#include <SFML/Graphics.hpp>
#include "jeu.h"
class creationPerso
{
public:
	creationPerso();
	creationPerso(int largeurFenetreDeJeu, int hauteurFenetreDeJeu, bool Affichagefps);
	~creationPerso();

	chose * boutonGuerrier = new chose();
	chose * boutonPaladin = new chose();
	chose * boutonVoleur = new chose();
	chose * boutonAlchimiste = new chose();
	chose * boutonRanger = new chose();
	chose * intro = new chose();
	chose * boutonForce = new chose();
	chose * boutonDexterite = new chose();
	chose * boutonConstitution = new chose();
	chose * boutonCharisme = new chose();
	chose * boutonSagesse = new chose();
	chose * boutonIntelligence = new chose();
	chose * choixCarac = new chose();
	chose spriteCurseurCrea;

	sf::Font font;
	int lFenetreDeJeu;
	int hFenetreDeJeu;
	bool Affichfps;
	int classe;
	int force = 10;
	int constitution = 10;
	int dexterite = 10;
	int sagesse = 10;
	int charisme = 10;
	int intelligence = 10;

	bool apreschoix = false;
	bool avantChoix = true;
	bool choixForce = true;
	bool choixConstitution = true;
	bool choixDexterite = true;
	bool choixSagesse = true;
	bool choixCharisme = true;
	bool choixIntelligence = true;

	void start();
	void chargerBoutonGuerrier();
	void chargerBoutonPaladin();
	void chargerBoutonRanger();
	void chargerBoutonAlchimiste();
	void chargerBoutonVoleur();
	void chargerBoutonclasses();

	

	void chargerIntro();

	void chargerBoutonForce();
	void chargerBoutonDexterite();
	void chargerBoutonConstitution();
	void chargerBoutonSagesse();
	void chargerBoutonCharisme();
	void chargerBoutonIntelligence();
	void chargerBoutonCaracteristique();
	void chargerChoixCarac();


};

