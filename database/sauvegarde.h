#pragma once
#include <string>
#include "../personnage/personnage.h"
/**
* \file          sauvegarde.h
* \author    Dominik Grobecker
* \version   1.0
* \date       04 april 2018
* \brief       classe qui reprend toutes les informations necessaire afin de les stocked en abse de donnee
*                 
* \details    cette classe tampon qui permet de prendre directement les informations du jeu afin qu'elles soient utilisees par la classe DataBase
*                  
*/

/*! \class sauvegarde
* \brief       Cette classe tampon qui permet de prendre directement les informations du jeu afin qu'elles soient utilisees par la classe DataBase   
*                 
*/
class sauvegarde
{
public:
	/**
	* \brief       constructeur
	*
	* Constructeur de la classe sauvegarde surcharge
	* \param nomdelaClasse : nom du metier choisi par le joueur
	* \param ptrPj : pointeur sur un objet personnage (le personnage principal du Personnage Joueur)
	* \param mob1 : indicateur si le monstre 1 est en vie
	* \param mob2 : indicateur si le monstre 2 est en vie
	* \param mob3 : indicateur si le monstre 3 est en vie
	* \param mob4 : indicateur si le monstre 4 est en vie
	* \param rowid : numero du slot de sauvegarde
	* \return true si la requete a ete execute
	*/
	sauvegarde(string nomdelaClasse, personnage * ptrPj, bool viemob1, bool viemob2, bool viemob3, bool viemob4, int rowid);

	/**
	* \brief       constructeur
	*
	* Constructeur de la classe sauvegarde
	*
	*/
	sauvegarde();

	/**
	* \brief       Destructeur
	*
	*  Destructeur de la classe sauvegarde
	*
	*/
	~sauvegarde();

	int classe;  /*!< code chiffre de la classe */
	std::string nomClasse;   /*!<nom de la classe */
	int force = 10;  /*!< force du personnage initialise a 10 */
	int constitution = 10;  /*!< constitution du personnage initialise a 10 */
	int dexterite = 10; /*!< dexterite du personnage initialise a 10 */
	int sagesse = 10; /*!< sagesse du personnage initialise a 10 */
	int charisme = 10;  /*!< charisme du personnage initialise a 10 */
	int intelligence = 10; /*!< intelligence du personnage initialise a 10 */
	int coordx = 8 * 32; /*!< absysse du personnage initialise a  256*/
	int coordy = 45 * 32; /*!< ordonnee du personnage initialise a  1440*/
	int rowID=0; /*!< slot de sauvegarde de la partie*/
	int currentHp=99; /*!< vie actuelle du personnage initialiser a 99 */
	bool mob1 = true; /*!< mort ou vie du monstre mob1  */
	bool mob2 = true; /*!< mort ou vie du monstre mob2 */
	bool mob3 = true; /*!< mort ou vie du monstre mob3  */
	bool mob4 = true; /*!< mort ou vie du monstre mob4  */
	/*
	bool mob5 = true;
	bool mob6 = true;
	bool mob7 = true;
	bool mob8 = true;
	bool mob9 = true;
	bool mob10 = true 
	*/;
};

