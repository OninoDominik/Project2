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
	chose *boutonTailleEcran = new chose(); /*!< pointeur d'un objet chose du menu:  boutonTailleEcran*/
	chose *boutonFrameRate = new chose(); /*!< pointeur d'un objet chose du menu:  boutonFrameRate*/
	chose *boutonSauvegarde = new chose(); /*!< pointeur d'un objet chose du menu:  boutonSauvegarde*/
	chose * boutonChargerPartie = new chose(); /*!< pointeur d'un objet chose du menu:  boutonChargerPartie*/
	chose * boutonNouvellePartie = new chose(); /*!< pointeur d'un objet chose du menu:  boutonNouvellePartie*/
	chose * boutonOption = new chose(); /*!< pointeur d'un objet chose du menu:  boutonOption*/
	chose * boutonSauvegarde1 = new chose(); /*!< pointeur d'un objet chose boutonSauvegarde1*/
	chose * boutonSauvegarde2 = new chose(); /*!< pointeur d'un objet chose boutonSauvegarde2*/
	chose * boutonSauvegarde3 = new chose(); /*!< pointeur d'un objet chose boutonSauvegarde3*/
	chose * boutonAdmin = new chose();/*!< pointeur d'un objet chose boutonAdmin*/
	chose * boutonSon = new chose(); /*!< pointeur d'un objet chose boutonSon*/
	chose * boutonPlus = new chose(); /*!< pointeur d'un objet chose boutonPlus*/
	chose * boutonMoins = new chose(); /*!< pointeur d'un objet chose boutonMoins*/
	chose * boutonValider =new chose(); /*!< pointeur d'un objet chose boutonValider*/
	chose * logo = new chose();   /*!< pointeur d'un objet chose du menu:  logo*/

	sf::Texture textureLogo; /*!< texture du logo */

	bool Affichagefps = false; /*!< affiche ou non les frames par seconde de la fentere principal generer  par jeu.cpp nome :window*/
	int largeurFenetreDeJeu = 800; /*!< stocke la taille de la largeur de la fentere principal generer par jeu.cpp nome :window*/
	int hauteurFenetreDeJeu = 800; /*!< stocke la taille de la hauteur de la fentere principal generer par jeu.cpp nome :window*/
	int volume = 50;   /*!< stocke le volume de la fenetre principal generer par jeu.cpp nome :window */
	int choixTailleEcran = 0; /*!< compteur des choix */
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

	*    transforme le pointeur d'objet chose BoutonTailleEcran en zone cliquable avec un texte qui indique que le logiciel n'a pas les droits de modifier la base de donnees
	*
	*/
	void chargerBoutonAdmin();
	/**
	* \brief      creer un bouton BoutonTailleEcran

	*    transforme le pointeur d'objet chose BoutonTailleEcran en zone cliquable avec un texte qui  cycle par nombre de clique sur le bouton
	*
	*/
	void ChargerBoutonTailleEcran();
	/**
	* \brief      creer un bouton son non clickable

	*    transforme le pointeur d'objet chose boutonSon pour lui ajouter un texte
	*
	*/
	void chargerBoutonSon(int sound);
	/**
	* \brief      creer un bouton plus

	*    transforme le pointeur d'objet chose boutonPlus en zone cliquable avec un texte afin de modifier le volume son
	*
	* \param int: attribut volume de la classe menu 
	*/
	void chargerBoutonPlus();
	/**
	* \brief      creer un bouton Moins

	*    transforme le pointeur d'objet chose boutonPlus en zone cliquable avec un texte afin de modifier le volume son
	*
	*/
	void chargerBoutonMoins();
	/**
	* \brief      creer un bouton FrameRate

	*    transforme le pointeur d'objet chose BoutonTailleEcran en zone cliquable avec un texte  
	*    ce bouron servira a fermer la fenete option
	*
	*/
	void chargerBoutonValider();

	/**
	* \brief      creer un bouton FrameRate

	*    transforme le pointeur d'objet chose BoutonTailleEcran en zone cliquable avec un texte et la couleur qui change en fonction de son etat
	*
	*/
	void ChargerBoutonFrameRate();

};

