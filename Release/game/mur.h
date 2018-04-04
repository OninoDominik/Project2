#pragma once
#include "../personnage/chose.h"
/**
* \file          mur.h
* \author    Dominik Grobecker
* \version   1.0
* \date       04 april 2018
* \brief      permet de creer des blocks
*
* \details    permet de creer des blocks invisibles 
*
*/

/*! \class mur
* \brief      permet de creer des block
*
* \details    permet de creer des blocks invisibles
*
*/
class mur : public chose
{
	
	public:

		/**
		* \brief       constructeur
		*
		* Constructeur de la classe mur
		*
		*/
		mur();

		/**
		* \brief       constructeur
		*
		* Constructeur de la classe mur surcharge
		*
		* \param x : abscisse du coin superieur gauche
		* \param y : ordonne du coin superieur gauche
		* \param largeur :largeur du block
		* \param longueur :longueur du block
		*/
		mur(int x, int y, int largeur, int longueur);

		/**
		* \brief       destructeur
		*
		* destructeur de la classe mur
		*
		*/
		~mur();
		
};


