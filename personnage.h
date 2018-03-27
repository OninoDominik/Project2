#pragma once
#include "chose.h"
#include "string"
#include "animationCombat.h"

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

	int * force = new int(14);
	int * constitution = new int(10);
	int * dexterite = new int(12);
	int * sagesse = new int(12);
	int * charisme = new int(12);
	int * intelligence = new int(12);
	int * nbrFaceDesDegat = new int(8);
	int * nbrDesDegat = new int(2);
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
	int * classe = new int(0);
	bool * fermeCombatWindow = new bool(false);
	bool * envie = new bool(true);
	bool  estUnJoueur = false;
	bool  estEtourdit = false;
	bool mouvementCombat = false;
	int seretourner = 0;
	bool feinte = false;
	sf::Time difference;
	sf::Time Chrono;
	sf::Clock Chronometre;
	sf::Time tempsAnime = sf::seconds(0.20);

	string * nomAttaqueSpecial = new string("aa");
	string * nomBonusDegat = new string("force");
	string nom;
	animationCombat * anim = new animationCombat;

	virtual void sesoigne();
	

	int Initiative();
	void afficheStat();
	void AvancerAttaque();
	void ReculerAttaque();
	int CA();
	void InfligeDegat(personnage& ennemi);
	void Attaque(personnage & ennemi);
	virtual void AttaqueSpecial(personnage & ennemi);
	

	

	int BonusStat(string stat);
	void setNom(string choixNom);

};


