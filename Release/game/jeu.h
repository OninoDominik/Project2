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
/**
* \file          jeu.h
* \author    Dominik Grobecker
* \version   1.0
* \date       04 april 2018
* \brief      permet de jouer apres la creation de personnage
*
* \details    permete de creer une fenetre , de bouger un sprite sur une map de lancer des combat et de generer une fenetre de combat
*
*/

/*! \class jeu
* \brief      permet de jouer apres la creation de personnage
*
* \details    permet de creer une fenetre , de bouger un sprite sur une map de lancer des combat et de generer une fenetre de combat
*
*/
class jeu
{
public:
	
	/**
	* \brief       constructeur
	*
	* Constructeur de la classe jeu
	*
	*/
	jeu();

	/**
	* \brief       constructeur
	*
	* Constructeur de la classe jeu surcharge
	*
	* \param largeur : stocke la taille de la largeur de la fentere principal
	* \param hauteur : stocke la taille de la hauteur de la fentere principal
	* \param framerate : stocke l'information si l'utilisateur souhaite l'affichage des frames par seconde
	* \param volumeSon : stocke le niveau de volume
	*/
	jeu(int largeur, int hauteur, bool Affichagefps, int volumeSon);

	/**
	* \brief       lance une fenetre de combat et un thread d'un objet combat
	*
	* lance une fenetre de combat et un thread d'un objet combat afin de pouvoir cliquer sur les choix de combat et d'afficher les actions qui en resulte
	*
	* \param ptrPj : pointeur sur un objet personnage( le personnage principal du Personnage Joueur)
	* \param Pnj : pointeur sur un objet personnage ( un ennemie)
	* \param texturePnj : stocke la texture pour els animation de l ennemie
	* \param x: abscisse de la position du joueur
	* \param y: ordonne de la position du joueur
	*/
	void Combat32(personnage * ptrPj, personnage * Pnj, sf::Texture texturePnj, int x, int y);
	/**
	* \brief       met a jour la vue 
	*
	* met a jour la vue 
	*
	* \param sf::View vuePj : vue centré actuelle
	* \return sf::View vuePj mise a jour dans le cas des coins
	*/
	sf::View majVue(sf::View vuePj);

	/**
	* \brief       destructeur
	*
	* destructeur de la classe jeu
	*
	*/
	~jeu();

	sf::Texture texture;  /*!< une texture de monstre*/
	sf::Texture texture3;  /*!< une texture de monstre*/
	sf::Texture texture4;  /*!< une texture de monstre*/
	// sf::Texture pala; /*!< une texture */
	sf::Texture textureHero; /*!< une texture qui stocke le skin du perso enf ocntion du metier choisis*/
	sf::Texture grave; /*!< une texture pour indiquer la mort d'un ennemi */
	sf::Texture fond; /*!< une texture qui generera la carte*/
	sf::Texture areneBack; /*!< une texture pour l'arene*/
	sf::Texture areneFront; /*!< une texture pour l'arene*/
	sf::Texture cactus;/*!< une texture pour les cactus*/
	sf::Texture textureOrc; /*!< une texture de monstre*/
	sf::Texture texturegobMage; /*!< une texture de monstre*/
	sf::RenderWindow combatWindow2; /*!< fenetre de combat pour ennemi dont le sprite ne fait pas une taille de 32*32pixels**/
	chose spriteCurseurCombat; /*!<objet chose qui permetetra de traquer la position de la sourie*/
	sf::RenderWindow combatWindow; /*!< fenetre de combat pour ennemi dont le sprite fait une taille de 32*32pixels*/
	sf::Image icon; /*!< image qui est en icone dans le coin superieur gauche de la fenetre */
	sf::Sprite spriteFond; /*!< un prite qui generera la carte*/
	sf::Sprite spriteAreneFront;  /*!< un sprite qui generera la carte arende combat*/
	sf::Sprite spriteAreneBack; /*!< un sprite qui generera la carte arende combat*/
	sf::Font font; /*!<Font qui definit la police d'ecriture */
	int largeurEcranPrincipal = 800;  /*!<largeur de la fentere principal*/
	int hauteurEcranPrincipal = 600; /*!<hauteur de la fentere principal*/
	int volume = 50; /*!<niveau du son de la musique */
	chose * boutonAttaquer = new chose();  /*!< pointeur d'un objet chose bouton attaquer*/
	chose * boutonSoin = new chose();  /*!< pointeur d'un objet chose bouton Soin*/
	chose * scorePjHp = new chose();  /*!< pointeur d'un objet chose pour afficher la barre de vie du joueur*/
	chose * scorePnjHP = new chose(); /*!< pointeur d'un objet chose pour afficher la barre de vie de l'ennemi*/
	chose * boutonSpecial = new chose(); /*!< pointeur d'un objet chose  bouton special (bouton qui change de nom en fonction du metier choisi par le joueur*/
	chose * texteGameOver = new chose(); /*!< pointeur d'un objet chose pour afficher le texte de Game Over*/
	chose * texteRemerciement = new chose(); /*!< pointeur d'un objet chose pour afficher le texte des credits*/
	sf::Event combatEvent; /*!< evenement de la fenetre de combat*/
	sf::View vuePj; /*!< vue pour la camera */
	personnage * ptrPj;  /*!< pointeur du Personnage du joueur */
	int i = 0; /*!<compteur */
	int j = 0; /*!<compteur */

	/**
	* \brief       lance la fentre principal de jeu
	*
	* permet de creer une fenetre, de bouger un sprite sur une map
	*
	* \param classe : code de la classe afin de charger le bon sprite en focntion du choix lors de la creationd e personnage ( le personnage principal du Personnage Joueur)
	* \param currenthp  : point vie du personnage au debut du jeu ou lors du chargement de la sauvegarde
	* \param force: score de force
	* \param constitution : score de constitution
	* \param dexterite : score de dexterite
	* \param sagesse : score de sagesse
	* \param charisme : score de charisme
	* \param intelligence : score de intelligence
	* \param coordx : absysse de la position du joueur
	* \param coordy : ordonne de la position du joueur
	* \param mob1 : indicateur si le monstre 1 est en vie
	* \param mob2 : indicateur si le monstre 2 est en vie
	* \param mob3 : indicateur si le monstre 3 est en vie
	* \param mob4 : indicateur si le monstre 4 est en vie
	* \param numeroSauvegarde : numero du slot de sauvegarde
	*/
	int Startjeu(int classe, int currenthp, int force, int dexterite, int constitution, int charisme, int sagesse, int intelligence, int coordx, int coordy, int mob1, int mob2, int mob3, int mob4, int numeroSauvegarde);

	vector<mur> murmap1(); /*!< listes contenant tout les objet murs de la carte*/
	mur mur1;/*!<objet mur */

	/**
	* \brief       charge le sprite qui entoure la barre de vie et gerre la redimension de la barre de vie
	*
	* charge le sprite qui entoure la barre de vie et gerre la redimension de la barre de vie du joueur
	*
	* \param classe :pointeur d'un objet personnage ( le personnage principal du Personnage Joueur)
	*/
	void ChargerHpPjetbarre(personnage * ptrPj);

	/**
	* \brief      creer un boutonSoin
	*
	*    transforme le pointeur d'objet chose boutonSoin en zone cliquable n zone cliquable avec le texte "soin" affiche
	*
	*/
	void ChargerBoutonSoin();

	/**
	* \brief      genere une zone de texte
	*
	*   genere une zone de texte  Game Over
	*/
	void ChargerTexteGameover();

	/**
	* \brief      genere une zone de texte
	*
	*   genere une zone de texte Credits
	*/
	void ChargerTexteRemerciement();

	/**
	* \brief      creer un boutonAttaquer
	*
	*    transforme le pointeur d'objet chose boutonAttaquer en zone cliquable n zone cliquable avec le texte "Attaquer" affiche
	*
	*/
	void ChargerBoutonAttaquer();

	/**
	* \brief       charge le sprite qui entoure la barre de vie et gerre la redimension de la barre de vie
	*
	* charge le sprite qui entoure la barre de vie et gerre la redimension de la barre de vie de l'ennemi
	*
	* \param classe :pointeur d'un objet personnage ( ennemie)
	*/
	void ChargerHpPnj(personnage * ptrPNJ);

	/**
	* \brief      creer un boutonSpecial
	*
	*    transforme le pointeur d'objet chose boutonSoin en zone cliquable n zone cliquable avec le texte qui contient le nom de l'attaque special du metier choisi affiche
	*
	*/
	void ChargerBoutonSpecial(personnage * ptrPj);

	
	float framerate = 60;/*!<framerate de base a 60 */
	bool AfficherFrameRate = true; /*!<afficher framerate */


};


