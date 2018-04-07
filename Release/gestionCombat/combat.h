#pragma once
#include "../personnage/personnage.h"
#include <time.h>
/**
* \file          combat.h
* \author    Dominik Grobecker
* \version   1.0
* \date       04 april 2018
* \brief      permet de gerrer le combat
*
* \details    permet de gerrer le combat , les tours d'initiatives, et de faire patienter le logiciel  le temps que le joueur fasse un choix
*
*/

/*! \class combat
*
* \brief      permet de gerrer le combat
*
* \details    permet de gerrer le combat , les tours d'initiatives, et de faire patienter le logiciel  le temps que le joueur fasse un choix
*
*/
class combat
{
public:

	/**
	* \brief       constructeur
	*
	* Constructeur de la classe combat
	*
	*/
	combat();

	/**
	* \brief       destructeur
	*
	* destructeur de la classe combat
	*
	*/
	~combat();
	int tailleblock = 32; /*!< taille en pixel d'un block de la taille d'un personnage*/


	/**
	* \brief       boucle infini tant que le joueur ne clique aps sur un choix
	*
	* reinitialise le choix a 0 et attend une modification pour sortir de la boucle infini
	*
	* \param joueur :pointeur d'un objet personnage ( le personnage principal du Personnage Joueur)
	*
	*/
	static void Choixjoueur(personnage * joueur);

	/**
	* \brief       enchaine les tours de combat jusqu'a la mort d'un des participant
	*
	* calcul qui agis en premier, gerre les ennemis si il sont stun ou si ils on un dot.
	* lance aussi les methodes en fonction des choix du joueur
	* reinitialise aussi les texte du combat entre chaque action
	*
	* \param ami :pointeur d'un objet personnage ( le personnage principal du Personnage Joueur)
	* \param ennemi :pointeur d'un objet personnage ( l'ennemi)
	*
	*/
	static void startcombat(personnage * ami, personnage * ennemi);


};

