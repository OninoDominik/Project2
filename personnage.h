#pragma once
#include "chose.h"
#include "string"
#include "personnage.h"

class personnage : public chose
{
	
public:
	personnage();
	personnage(string nomDuPerso);
	~personnage();

	int vitesse = 2;
	int direction = 0; // 1 - haut, 2 - bas, 3 - gauche, 4 - droite
	bool monter = true;
	bool descendre = true;
	bool reculer = true;
	bool avancer = true;
	int compteurPas = 0;
	void Positionnement();
	void Mouvement();

	int * force = new int(10);
	int * constitution = new int(10);
	int * dexterite = new int(10);
	int * sagesse = new int(10);
	int * charisme = new int(10);
	int * intelligence = new int(10);
	int * nbrFaceDesDegat = new int(6);
	int * nbrDesDegat = new int(3);
	int * bonusArmure = new int(5);
	int * taille = new int(2);
	int * pvMax = new int(25+*constitution);
	int * pvActuel= new int(*pvMax);
	int * bonusInitiative = new int(0);
	int * bonusAttaque = new int(4);
	int * bonusBouclier = new int(0);
	int * nbrAttaque = new int(1);
	int * choix = new int(0);
	int * nbrDesSoin = new int(0);
	int * nbrFaceDesSoin = new int(0);
	int * niveau = new int(2);
	int * tempsDot = new int(0);
	int * valeurDot = new int(0);
	bool * fermeCombatWindow = new bool(false);
	bool  estUnJoueur = false;
	bool  estEtourdit = false;
	int * classe = new int(0);

	string * nomAttaqueSpecial = new string("aa");

	string nomBonusDegat = "force";
	string nom;
	virtual void sesoigne();
	bool * envie = new bool(true);

	int Initiative();
	void afficheStat();
	void AvancerAttaque();
	void ReculerAttaque();
	int CA();
	void InfligeDegat(personnage& ennemi);

	void Attaque(personnage & ennemi);

	virtual void AttaqueSpecial(personnage & ennemi);
	sf::Time difference;
	sf::Time Chrono;
	sf::Clock Chronometre;
	sf::Time tempsAnime = sf::seconds(0.25);

	

	int BonusStat(string stat);
	void setNom(string choixNom);

};


