#pragma once
#include "../personnage.h"
/**
* \file          alchimiste.h
* \author    Dominik Grobecker
* \version   1.0
* \date       04 april 2018
* \brief      attaque et calcul de soin du metier Alchimiste
*
* \details     attaque et calcul de soin du metier Alchimiste
*
*/

/*! \class alchimiste
* \brief       attaque et calcul de soin du metier Alchimiste
*
* \details     attaque et calcul de soin du metier Alchimistex
*
*/
class alchimiste : public personnage
{
public:
	/**
	* \brief       constructeur
	*
	* Constructeur de la classe alchimiste
	*
	*/
	alchimiste();

	/**
	* \brief      destructeur
	*
	*Destructeur de la classe alchimiste
	*
	*/
	~alchimiste();
	/**
	* \brief      lance l'attaque Bombe avec les brulure possible
	*
	* calcul les effets de l'attaque bombe et lance les animations et les sounds 
	* calcul les degats et regarde si l'ennemi ou les joueurs subissent des degats supplementaire   
	*
	* \param ennemi : adresse d'un objet personnage  (un ennemie)
	*/
	void AttaqueSpecial(personnage & ennemi);
	/**
	* \brief     calcul les soins de l'alchimiste
	*
	* calcul les soins et lance les animations et les sounds
	* 
	*/
	void sesoigne();
};

