#pragma once
#include "chose.h"
#include "string"
#include "../gestionCombat/animationCombat.h"
/**
* \file          personnage.h
* \author    Dominik Grobecker
* \version   1.0
* \date       04 april 2018
* \brief      creer et gerre les personnages joueurs et IA du jeu
*
* \details     creer et gerre les personnages joueurs et IA du jeu
*
*/

/*! \class personnage
* \brief       creer et gerre les personnages joueurs et IA du jeu
*
* \details     creer et gerre les personnages joueurs et IA du jeu
*
*/
class personnage : public chose
{
	
public:

	/**
	* \brief       constructeur
	*
	* Constructeur de la classe personnage
	*
	*/
	personnage();
	/**
	* \brief       constructeur
	*
	* Constructeur de la classe personnage surcharge afin de nomme un personnage
	*
	* \param nomDuPerso: nom du personnage
	*/
	personnage(string nomDuPerso);
	/**
	* \brief      destructeur
	*
	*Destructeur de la classe chose
	*
	*/
	~personnage();

	int vitesse = 2; /*!vitesse de deplacement du personage */
	int direction = 0;  /*!direction du regard du personnage */ // 1 - haut, 2 - bas, 3 - gauche, 4 - droite
	bool monter = true; /*!peut monter */
	bool descendre = true;/*!peut descendre */
	bool reculer = true;/*!peut aller a gauche */
	bool avancer = true; /*!peut aller a droite */
	int compteurPas = 0; /*!compteur pour l'animation de marche */

	/**
	* \brief      place le sprite sur le rectangle
	*
	*place le sprite sur le rectangle
	*
	*/
	void Positionnement();
	/**
	* \brief      permet de deplacer le personnage
	*
	* permet de deplacer le personnage et debloque la direction du mouvement d'un personnage si il s'eloigne d'un mur
	* lance l'animation de marche en fonction du temps et non du frame rate
	*/
	void Mouvement();

	int * force = new int(16);  /*!< pointeur d'un entier qui est la force du personnage */
	int * constitution = new int(12);/*!< pointeur d'un entier qui est la constitution du personnage */
	int * dexterite = new int(10);/*!< pointeur d'un entier qui est  la dexterite du personnage */
	int * sagesse = new int(12);/*!< pointeur d'un entier qui est la sagesse du personnage */
	int * charisme = new int(12);/*!< pointeur d'un entier qui est la charisme du personnage */
	int * intelligence = new int(12);/*!< pointeur d'un entier qui est l intelligence du personnage */
	int * nbrFaceDesDegat = new int(6); /*!< pointeur d'un entier qui est nombre de face des des(dices) de degats du personnage */
	int * nbrDesDegat = new int(3); /*!< pointeur d'un entier qui est le nombre de des (dice) lance pour calculer les degats*/
	int * bonusArmure = new int(5); /*!< pointeur d'un entier qui est le bonus d'armure pour etre plus dur a toucher */
	int * taille = new int(2); /*!< pointeur d'un entier qui est la taille (2 moyenne) */
	int * pvMax = new int(35+*constitution); /*!< pointeur d'un entier qui le nombre de point de vie maximum */
	int * pvActuel= new int(*pvMax); /*!< pointeur d'un entier qui le nombre de point de vie actuel */
	int * bonusInitiative = new int(0); /*!< pointeur d'un entier qui est le bonus d'initiative */
	int * bonusAttaque = new int(4); /*!< pointeur d'un entier qui est un bonus pour toucher l'adversaire  */
	int * bonusBouclier = new int(0); /*!< pointeur d'un entier qui est le bonus si le metier porte un bouclier pour etre plus dur a toucher */
	int * nbrAttaque = new int(1); /*!< pointeur d'un entier qui est le nombre de fois qu'un ennemi attaque dans le même tour */
	int * choix = new int(0); /*!< pointeur d'un entier qui le choix du joueur qui est definir par quel bouton il a cliquer en combat*/
	int * nbrDesSoin = new int(0); /*!< pointeur d'un entierqui est le nombre de des (dice) lance pour calculer les soins */
	int * nbrFaceDesSoin = new int(0); /*!< pointeur d'un entier qui est nombre de face des des(dices) de soins  */
	int * niveau = new int(2); /*!< pointeur d'un entier qui est le niveau actuel du personnage */
	int * tempsDot = new int(0); /*!<pointeur qui indique le nombre de tour restant d'un affaiblissement (tels que saignement) */
	int * valeurDot = new int(0); /*!<pointeur qui indique le nombre de degats par tour d'un affaiblissement (tels que saignement) */
	int * classe = new int(0); /*!< pointeur d'un entier qui indique le la classe par un code chiffré  */
	bool * fermeCombatWindow = new bool(false); /*!< pointeur pour ferme la fenetre de combat si un adversaire meurt dans dans un combat ou si l'avatar du joueur meurt */
	bool * envie = new bool(true); /*!< pointeur qui indique si un personnage est mort ou non */
	bool  estUnJoueur = false; /*!< pointeur qui indique si le personnage est un ennemi ou le joueur */
	bool  estEtourdit = false; /*!< pointeur qui indique si l'ennemie est etourdit et qu'il passe son prochain tour */ 
	bool mouvementCombat = false; /*!< pointeur qui empeche de bouger quand ce n'est aps son tour en combat */
	bool enCombat = false; /*!< pointeur qui indique si le personnage combat */
	int seretourner = 0; /*!< pointeur qui permet de faire regarder  dans la direction voulue*/
	bool feinte = false; /*!< pointeur qui indique si le joueur a effectuer une feinte */
	sf::Time difference;  /*!< temps qui permet de calculler la difference de temps entre chaque frame */
	sf::Time Chrono; /*!< temps quichronometre */
	sf::Sound sound;  /*!< temps quichronometre */
	sf::SoundBuffer buffer; /*!< buffer pour le sound afin d'envoyer tout le sound d'un coup */
	sf::Clock Chronometre; /*!< clock quichronometre */
	sf::Time tempsAnime = sf::seconds(0.20); /*!< temps minimum entre 2 animation de mouvement*/

	string * nomAttaqueSpecial = new string("AS");  /*!< nom provisoire de l'attaque special*/
	string * nomBonusDegat = new string("force"); /*!< nom de la statistique a utiliser en combat en fonction du metier*/
	string nom; /*!< nom du personnage*/
	animationCombat * anim = new animationCombat;   /*!< pointeur d'un objet animation de combat */
	/**
	* \brief     methode virtuel de soin qui sera develloper par chaque metier differement
	*
	*  methode virtuel de soin qui sera develloper par chaque metier differement
	* 
	*/
	virtual void sesoigne();
	/**
	* \brief   calcul l'initiative du personnage
	*
	* calcul l'initiative du personnage c'est a dire quand le personnage pourra agir
	* le personnage qui a la plus haute initiative agira avant l'autre personnage
	* en cas d'egalite le joueur est prioritaire 
	*
	*/
	int Initiative();
	//void afficheStat();
	/**
	* \brief  fait avancer le personnage vers son adversaire en combat
	*
	* fait avancer le personnage vers son adversaire en combat
	*
	*/
	void AvancerAttaque();
	/**
	* \brief  fait avancer le personnage vers son adversaire en combat
	*
	* fait reculer le personnage vers sa position initiale en combat
	*
	*/
	void ReculerAttaque();
	/**
	* \brief  calcul la difficulté de toucher le personnage
	*
	* calcul la difficulté de toucher le personnage, plus le chiffre est elleve moins l'adversaire aura des chance de le toucher
	*
	*/
	int CA();

	/**
	* \brief  calcul le nombre de point de vie que l'adversaire perd
	*
	* calcul le nombre de point de vie que l'adversaire perd
	*
	* \param ennemi:adresse d'un objet personnage
	*/
	void InfligeDegat(personnage& ennemi);

	/**
	* \brief  calcul si le personnage arrive a toucher ou non son adversaire
	*
	* calcul si le personnage arrive a toucher ou non son adversaire et lance inflige degats le cas echeant
	*
	* \param ennemi: adresse d'un objet personnage
	*/
	void Attaque(personnage & ennemi);

	/**
	* \brief     methode virtuel de l'attaque special de chaque metier qui sera develloper dans la classe de chaque metier differement
	*
	* methode virtuel de l'attaque special de chaque metier qui sera develloper dans la classe de chaque metier differement
	*
	* \param ennemi: adresse d'un objet personnage 
	*
	*/
	virtual void AttaqueSpecial(personnage & ennemi);

	/**
	* \brief     calcul un bonus en fonction de la caractristique du personnage 
	*
	* calcul un bonus en fonction de la caractristique du personnage 
	*
	* \param stat: nom de la caracteristique qui donne un bonus lors des combat
	* \return un entier plus il est haut plus la caracteristique tester etait forte
	*/
	int BonusStat(string stat);

	/**
	* \brief     change le nom du personnage
	*
	* calcul un bonus en fonction de la caractristique du personnage
	*
	* \param choixNom: nouveau nom du personnage
	* 
	*/
	void setNom(string choixNom);

};


