#pragma once
#include "../personnage.h"
/**
* \file          guerrier.h
* \author    Dominik Grobecker
* \version   1.0
* \date       04 april 2018
* \brief      attaque et calcul de soin du metier guerrier
*
* \details     attaque et calcul de soin du metier guerrier
*
*/

/*! \class guerrier
* \brief       attaque et calcul de soin du metier guerrier
*
* \details     attaque et calcul de soin du metier guerrier
*
*/
class guerrier : public personnage
{
public:
	/**
	* \brief       constructeur
	*
	* Constructeur de la classe guerrier
	*
	*/
	guerrier();

	/**
	* \brief      destructeur
	*
	*Destructeur de la classe guerrier
	*
	*/
	~guerrier();

	/**
	* \brief      lance l'attaque saignement 
	*
	* calcul les effets de saignement pour 3 tours et lance les sounds 
	* lance les animations et lance les sounds
	* 
	* \param ennemi :pointeur d'un objet personnage (un ennemie)
	*/
	void AttaqueSpecial(personnage & ennemi);

	/**
	* \brief     calcul les soins du guerrier
	*
	* calcul les soins et lance les animations et lance les sounds
	*
	*/
	void sesoigne();

};

