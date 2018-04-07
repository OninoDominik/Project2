#pragma once

#include "../sqlite3.h"
#include <vector>
#include "sauvegarde.h"
#include <iostream>
#include <string>

/**
* \file          Database.h
* \author    Dominik Grobecker
* \version   1.0
* \date       04 april 2018
* \brief       creation ecriture modification d'une base de donnees fichier database.db
*                  qui permet la sauvegarde d'une partie
* \details    cette classe permet la gestion de la basse de donnees database.db afin d'avoir trois sauvegardes a la maniere des vieux rpg
*                  et pour sauvegarder une partie en cours et la charger ulterieurement
*/

/*! \class database
* \brief       creation ecriture modification d'une base de donnees fichier database.db
*                  qui permet la sauvegarde d'une partie
* \details    Cette classe surcharge les accesseurs standards du module_voiture pour
*                  convenir aux specificites des differents modeles possibles.
*/
class database
{
public:
	/**
	* \brief       constructeur
	*
	* Constructeur de la classe Database
	*
	*/
	database();

	/**
	* \brief       destructeur
	*
	* Destructeur de la classe Database
	*
	*
	*/
	virtual ~database();

	/**
	* \brief       connection de la base de donnees
	*
	* permet la connection a la base de donnees database.bd
	*
	*/
	void openDatabase();

	/**
	* \brief       fermeture de la connection a la base de donnees
	*
	* permet la deconnection a la base de donnees database.bd
	*
	*/
	void closeDatabase();

	/**
	* \brief      permet l'execution de requete SQL
	*
	*  execute la requete sql dans database.bd
	* \param query : requete sql
	* \return true si la requete a ete executee
	*/
	bool executeQuery(std::string query);

	/**
	* \brief      permet l'insertion sans doublon
	*
	*  execute une requete sql afin de sauvegarder une partie
	* \param nomClasse : nom du metier de l'avatard du joueur
	* \param classe : code du metier
	* \param currenthp: points de vie actuels
	* \param force: score de force
	* \param constitution : score de constitution
	* \param dexterite : score de dexterite
	* \param sagesse : score de sagesse
	* \param charisme : score de charisme
	* \param intelligence : score d'intelligence
	* \param coordx : abscisse de la position du joueur
	* \param coordy : ordonnee de la position du joueur
	* \param mob1 : indicateur si le monstre 1 est en vie
	* \param mob2 : indicateur si le monstre 2 est en vie
	* \param mob3 : indicateur si le monstre 3 est en vie
	* \param mob4 : indicateur si le monstre 4 est en vie
	* \param id : numero du slot de sauvegarde
	* \return true si la requete a ete execute
	*/
	bool insertSauvegardeSansDoublon(std::string nomClasse, int classe, int currentHp, int force, int constitution, int dexterite, int sagesse, int charisme, int intelligence, int coordx, int coordy, int mob1, int mob2, int mob3, int mob4, int id);

	/**
	* \brief retourne la liste de sauvegarde
	*
	*  execute la requete sql dans database.bd afin
	*
	* \return un pointeur de vecteur de pointeur de la classe sauvegarde
	*/
	std::vector<sauvegarde*>* getAllSauvegarde();

	/**
	* \brief modifie une sauvegarde
	*
	*  execute la requete sql dans database.bd afin de modifier une sauvegarde
	*
	* \return vrai si la requete est executee
	*/
	bool updateSauvegarde(sauvegarde* save);
protected:

private:
	sqlite3 * db; /*!< pointeur sqlite3*/
	std::string dbfile; /*!< chemin et nom de la bdd */
};

