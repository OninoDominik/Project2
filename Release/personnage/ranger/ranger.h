#pragma once
#include "../personnage.h"
/**
* \file          ranger.h
* \author    Dominik Grobecker
* \version   1.0
* \date       04 april 2018
* \brief      attaque et calcul de soin du metier ranger
*
* \details     attaque et calcul de soin du metier ranger
*
*/

/*! \class ranger
* \brief       attaque et calcul de soin du metier ranger
*
* \details     attaque et calcul de soin du metier ranger
*
*/
class ranger : public personnage
{
public:
	/**
	* \brief       constructeur
	*
	* Constructeur de la classe ranger
	*
	*/
	ranger();

	/**
	* \brief      destructeur
	*
	*Destructeur de la classe ranger
	*
	*/
	~ranger();
	/**
	* \brief      lance l'attaque headshot
	*
	* calcul les effets des degats si l'attaque touche, et lance les animations et lance les sounds
	*
	* \param ennemi :adresse d'un objet personnage (un ennemie)
	*/
	void AttaqueSpecial(personnage & ennemi);
	/**
	* \brief     calcul les soins du ranger
	*
	* calcul les soins et lance les animations et les sounds
	*
	*/
	void sesoigne();

};

