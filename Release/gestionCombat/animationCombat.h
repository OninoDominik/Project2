#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
/**
* \file          animationCombat.h
* \author    Dominik Grobecker
* \version   1.0
* \date       04 april 2018
* \brief      permet de creer des animations
*
* \details    permet de creer des animations on fonctions des choix effectuer lors d'un combat
*
*/

/*! \class animationCombat
*
* \brief      permet de creer des animations
*
* \details    permet de creer des animations on fonctions des choix effectuer lors d'un combat
*
*/


class animationCombat
{
public:
	/**
	* \brief       constructeur
	*
	* Constructeur de la classe animationCombat
	*
	*/
	animationCombat();

	/**
	* \brief       destructeur
	*
	* destructeur de la classe animationCombat
	*
	*/
	~animationCombat();
	/**
	* \brief      affiche une animation d'une fleche qui vole
	*
	*   affiche une fleche qui vole jusqu'au coordonnes de l'ennemi et joue des sounds
	*
	*/
	void arrow();
	/**
	* \brief      affiche une animation d'un coup d'epee 
	*
	*   affiche un coup d'epee du joueur ver l'ennemi ou inversement et joue des sounds
	*
	* \param i : entier qui indique qsi le joueur frappe sur l ennmi ou inversement afin de bien placé l'animation
	*/
	void coup(int i);

	/**
	* \brief      affiche une animation de saignement
	*
	*   affiche saignement et joue des sounds
	*
	*/
	void sang();
	/**
	* \brief      affiche une animation d'eclat de lumiere
	*
	*   affiche eclat de lumiere et joue des sounds
	*
	*/
	void palastun();
	/**
	* \brief      affiche  une animation d'une brulure
	*
	*   affiche brulureet joue des sounds
	*
	* \param i : entier qui indique si le joueur ou lennemi brule
	*/
	void burn(int i);
	/**
	* \brief      affiche une animation d'un halo de soin
	*
	*   affiche un halo de soin et joue des sounds
	*
	*/
	void heal();

	/**
	* \brief      affiche une animation d'explosion
	*
	*   affiche une explosion et joue des sounds
	*
	*/
	void badaBoom();
	sf::Texture explosion;  /*!< une texture d explosion*/
	sf::Texture soin; /*!< une texture de soin*/
	sf::Texture textureBurn; /*!< une texture de brulure*/
	sf::Texture stun;/*!< une texture de halo de lumiere*/
	sf::Texture saignement;  /*!< une texture desaignement*/
	sf::Texture slash; /*!< une texture de coup d'epee*/
	sf::Texture slash2;  /*!< une texture de coup d'epee dans l'autre sens*/
	sf::Texture fleche; /*!< une texture de fleche*/	
	sf::Clock chronoAnim; /*!< temp pour les animation*/
	int compteurPas=0; /*!< compteur d'animation en absisse*/
	int compteurLigne = 0; /*!< compteur d'animation en ordonnee*/
	sf::Sprite animSprite; /*!< sprite pour coller les texture*/
};

