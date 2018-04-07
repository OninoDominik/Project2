#pragma once
#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <deque>
#include <list>
/**
* \file          chose.h
* \author    Dominik Grobecker
* \version   1.0
* \date       04 april 2018
* \brief      creer les entites basique du jeu
*
* \details     creer les entites basique du jeu
*
*/



/*! \namespace std
*
* espace de nommage regroupant les outils composant de la librairie standard
*/
using namespace std;

/*! \class chose
* \brief       creer les entites basique du jeu
*
* \details     creer les entites basique du jeu
*
*/

class chose
{

public:
	/**
	* \brief       constructeur
	*
	* Constructeur de la classe chose
	*
	*/
	chose();
	/**
	* \brief      destructeur
	*
	*Destructeur de la classe chose
	*
	*/
	~chose();
	sf::RectangleShape rect;  /*!<objet de la classe rectangleShape c'est une forme rectangulaire */
	sf::Sprite sprite; /*!<objet de la classe sprite c'est une forme avec une texture appliquer dessus */
	sf::Text text;/*!<objet de la classe text  */

private:
protected:
};
