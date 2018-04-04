#pragma once
#include "../personnage.h"
/**
* \file          paladin.h
* \author    Dominik Grobecker
* \version   1.0
* \date       04 april 2018
* \brief      attaque et calcul de soin du metier paladin
*
* \details     attaque et calcul de soin du metier paladin
*
*/

/*! \class paladin
* \brief       attaque et calcul de soin du metier paladin
*
* \details     attaque et calcul de soin du metier paladin
*
*/
class paladin : public personnage
{
	
public:
	/**
	* \brief       constructeur
	*
	* Constructeur de la classe paladin
	*
	*/
	paladin();

	/**
	* \brief      destructeur
	*
	*Destructeur de la classe paladin
	*
	*/
	~paladin();
	
	/**
	* \brief      lance l'attaque Justice 
	*
	* calcul les effets du stun et lance une attaque apres  et lance les sounds 
	* lance les animations et lance les sounds
	*
	* \param ennemi :pointeur d'un objet personnage (un ennemie)
	*/
	void AttaqueSpecial(personnage & ennemi);

	/**
	* \brief     calcul les soins du paladin
	*
	* calcul les soins et lance les animations et lance les sounds
	*
	*/
	void sesoigne();
	
};

