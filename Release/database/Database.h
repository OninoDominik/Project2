#pragma once

#include "../sqlite3.h"
#include <vector>
#include "sauvegarde.h"
#include <iostream>
#include <string>

class database
{
public:
	database();
	virtual ~database();

	void openDatabase();
	void closeDatabase();
	bool executeQuery(std::string query);

	bool insertSauvegardeSansDoublon(std::string nomClasse, int classe, int currentHp, int force, int constitution, int dexterite, int sagesse, int charisme, int intelligence, int coordx, int coordy, int mob1, int mob2, int mob3, int id);


	bool insertProduit(std::string nom, float prix, int qtevendue);
	std::vector<sauvegarde*>* getAllSauvegarde();
	bool updateSauvegarde(sauvegarde* save);
	bool deleteProduit(int id);

protected:

private:
	sqlite3 * db;
	std::string dbfile;
};

