#pragma once
#include "menu.h"
/**
* \file          charger.h
* \author    Dominik Grobecker
* \version   1.0
* \date       04 april 2018
* \brief      permet d'afficher les sauvegardes et cliquer sur une
*
* \details    permet d'afficher les sauvegardes et cliquer sur une afin de lancer une instance de jeu avec les info de la sauvegarde
*
*/

/*! \class charger
* \brief      permet d'afficher les sauvegardes et cliquer sur une
*
* \details    permet d'afficher les sauvegardes et cliquer sur une afin de lancer une instance de jeu avec les info de la sauvegarde
*
*/
class charger
{
public:
	/**
	* \brief       constructeur
	*
	* Constructeur de la classe charger
	*
	*/
	charger();
	/**
	* \brief       constructeur
	*
	* Constructeur de la classe charger surcharge
	*
	* \param largeurFenetreDeJeu : stocke la taille de la largeur de la fentere principal
	* \param hauteurFenetreDeJeu : stocke la taille de la hauteur de la fentere principal
	* \param Affichagefps : stocke l'information si l'utilisateur souhaite l'affichage des frames par seconde
	*/
	charger(int largeurFenetreDeJeu, int hauteurFenetreDeJeu, int Affichagefps);
	/**
	* \brief       destructeur
	*
	* destructeur de la classe jeu
	*
	*/
	~charger();

	/**
	* \brief       creer une fenetre et affiche les 3 sauvegardes
	*
	* creer une fenetre et affiche les 3 sauvegardes , creer bes boutons pour chacunes des sauvegarder et permet de cliquer sur une affin de lancer une instance de la classe jeu avec les infos de la sauvegardes
	*
	*/
	void start();

	chose * boutonSauvegarde1 = new chose(); /*!< pointeur d'un objet chose boutonSauvegarde1*/
	chose * boutonSauvegarde2 = new chose(); /*!< pointeur d'un objet chose boutonSauvegarde2*/
	chose * boutonSauvegarde3 = new chose(); /*!< pointeur d'un objet chose boutonSauvegarde3*/

	/**
	* \brief      creer un bouton Sauvegarde1
	*    transforme le pointeur d'objet chose boutonSauvegarde1 en zone cliquable avec le nom de la classe de la derniere sauvegarde sur le slot 1
	*
	*/
	void chargerBoutonSauvegarde1();

	sf::Font font; /*!< pointeur d'un objet chose boutonSauvegarde1*/
	int largeurFenetreDeJeu;/*!< stocke la taille de la largeur de la fentere principal */
	int hauteurFenetreDeJeu; /*!< stocke la taille de la hauteur de la fentere principal */
	int Affichagefps;  /*!< affiche ou non les frames par seconde */

	/**
	* \brief      creer un bouton Sauvegarde1
	*    transforme le pointeur d'objet chose boutonSauvegarde2 en zone cliquable avec le nom de la classe de la derniere sauvegarde sur le slot 2
	*
	*/
	void chargerBoutonSauvegarde2();

	/**
	* \brief      creer un bouton Sauvegarde1
	*    transforme le pointeur d'objet chose boutonSauvegarde3 en zone cliquable avec le nom de la classe de la derniere sauvegarde sur le slot 3
	*
	*/
	void chargerBoutonSauvegarde3();
};

