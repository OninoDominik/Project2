#pragma once
#include "../personnage.h"
/**
* \file          voleur.h
* \author    Dominik Grobecker
* \version   1.0
* \date       04 april 2018
* \brief      attaque et calcul de soin du metier voleur
*
* \details     attaque et calcul de soin du metier voleur
*
*/

/*! \class voleur
* \brief       attaque et calcul de soin du metier voleur
*
* \details     attaque et calcul de soin du metier voleur
*
*/
class voleur : public personnage
{
public:
	/**
	* \brief       constructeur
	*
	* Constructeur de la classe voleur
	*
	*/
	voleur();
	/**
	* \brief      destructeur
	*
	*Destructeur de la classe voleur
	*
	*/
	~voleur();

	/**
	* \brief      lance l'attaque feinte-backstab
	*
	* si la feinte est vrai lance l'attaque backstab et calcul ces degats
	* sinon la met sur vrai
	* lance les animations et les sounds
	*
	* \param ennemi: adresse d'un objet personnage  (un ennemie)
	*/
	void AttaqueSpecial(personnage & ennemi);
	/**
	* \brief     calcul les soins du voleur
	*
	* calcul les soins et lance les animations et les sounds
	*
	*/
	void sesoigne();
};

