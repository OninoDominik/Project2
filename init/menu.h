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
/**
* \file          menu.h
* \author    Dominik Grobecker
* \version   1.0
* \date       04 april 2018
* \brief      creer une fenetre permettant d'afficher les boutons du menu
*
* \details     creer une fenetre permettant d'afficher les boutons du menu et le logo, creer aussi un effet de hoover sur les choix
*
*/

/*! \class menu
* \brief       creer une fenetre permettant d'afficher les boutons du menu
*
* \details     creer une fenetre permettant d'afficher les boutons du menu et le logo, creer aussi un effet de hoover sur les choix
*
*/
class menu
{
public:
	/**
	* \brief       constructeur
	*
	* Constructeur de la classe menu
	*
	*/
	menu();

	/**
	* \brief      destructeur
	*
	*Destructeur de la classe menu
	*
	*/
	~menu();

	sf::RenderWindow menuWindow; /*!< fentere du menu*/
	chose * boutonChargerPartie = new chose(); /*!< pointeur d'un objet chose du menu:  boutonChargerPartie*/
	chose * boutonNouvellePartie = new chose(); /*!< pointeur d'un objet chose du menu:  boutonNouvellePartie*/
	chose * boutonOption = new chose(); /*!< pointeur d'un objet chose du menu:  boutonOption*/
	chose * boutonSauvegarde1 = new chose(); /*!< pointeur d'un objet chose boutonSauvegarde1*/
	chose * boutonSauvegarde2 = new chose(); /*!< pointeur d'un objet chose boutonSauvegarde2*/
	chose * boutonSauvegarde3 = new chose(); /*!< pointeur d'un objet chose boutonSauvegarde3*/
	
	chose * logo = new chose();   /*!< pointeur d'un objet chose du menu:  logo*/
	sf::Texture textureLogo; /*!< texture du logo */

	bool Affichagefps = false; /*!< affiche ou non les frames par seconde */
	int largeurFenetreDeJeu=800 ; /*!< stocke la taille de la largeur de la fentere principal */
	int hauteurFenetreDeJeu = 800; /*!< stocke la taille de la hauteur de la fentere principal */
	int choixTailleEcran = 0; /*!< comteur des choix */
	int numeroSauvegarde = 0; /*!< numero du slot de sauvegarde */
	chose spriteCurseurCombat;   /*!< objet chose afin de suivre la sourie */

	/**
	* \brief      lance le menu
	*
	*creer une fenetre permettant d'afficher les boutons du menu et le logo, creer aussi un effet de hoover sur les choix
	*
	*/
	void menuStart();
	/**
	* \brief      creer un bouton BoutonNouvellePartie

	*    transforme le pointeur d'objet chose BoutonNouvellePartie en zone cliquable avec le texte "Nouvelle Partie" affiche
	*
	*/
	void chargerBoutonNouvellePartie();
	/**
	* \brief      creer un bouton BoutonChargerPartie

	*    transforme le pointeur d'objet chose BoutonChargerPartie en zone cliquable avec le texte "Charger Partie" affiche
	*
	*/
	void chargerBoutonChargerPartie();
	/**
	* \brief      creer un bouton BoutonOption

	*    transforme le pointeur d'objet chose BoutonOption en zone cliquable avec le texte "Option" affiche
	*
	*/
	void chargerBoutonOption();
	/**
	* \brief      genere tout les boutons des menu
	*
	*    genere tout les boutons  BoutonOption BoutonChargerPartie BoutonNouvellePartie
	*
	*/
	void chargerBoutonsmenu();
	/**
	* \brief      creer un bouton BoutonTailleEcran

	*    transforme le pointeur d'objet chose BoutonTailleEcran en zone cliquable avec un texte qui  cycle par nombre de clique sur le bouton
	*
	*/
	void ChargerBoutonTailleEcran();

	/**
	* \brief      creer un bouton FrameRate

	*    transforme le pointeur d'objet chose BoutonTailleEcran en zone cliquable avec un texte et la couleur qui change en fonction de son etat
	*
	*/
	void ChargerBoutonFrameRate();

	chose *boutonTailleEcran = new chose(); /*!< pointeur d'un objet chose du menu:  boutonTailleEcran*/
	chose *boutonFrameRate = new chose(); /*!< pointeur d'un objet chose du menu:  boutonFrameRate*/
	chose *boutonSauvegarde = new chose(); /*!< pointeur d'un objet chose du menu:  boutonSauvegarde*/







};

