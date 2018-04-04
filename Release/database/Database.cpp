#include "database.h"
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string>

database::database()
{
	//ctor
	dbfile = "./database.db";
}

database::~database()
{
	//dtor
}

void database::openDatabase()
{
	sqlite3_initialize();
	sqlite3_open(dbfile.c_str(), &db);
}

void database::closeDatabase()
{
	sqlite3_close_v2(db);
	sqlite3_shutdown();
}

bool database::executeQuery(std::string query)
{
	char * errmsg = 0;
	if (sqlite3_exec(db, query.c_str(), NULL, 0, &errmsg) != SQLITE_OK)
	{
		std::cout << errmsg << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}

bool database::insertSauvegardeSansDoublon(std::string nomClasse, int classe,int currentHp, int force, int constitution,int dexterite, int sagesse, int charisme, int intelligence, int coordx, int coordy , int mob1, int mob2, int mob3, int mob4, int id)
{
	

	std::string query = "INSERT INTO sauvegarde(nomClasse,classe,currentHp,force,constitution,dexterite,sagesse,charisme,intelligence,coordx,coordy,mob1,mob2,mob3,mob4, id) select'" + nomClasse + "'," + std::to_string(classe) + "," + std::to_string(currentHp) + "," + std::to_string(force) + "," + std::to_string(constitution) + "," + std::to_string(dexterite) + "," + std::to_string(sagesse) + "," + std::to_string(charisme) + "," + std::to_string(intelligence) + "," + std::to_string(coordx) + "," + std::to_string(coordy) + "," + std::to_string(mob1) + "," + std::to_string(mob2) + "," + std::to_string(mob3) +"," + std::to_string(mob4) + "," + std::to_string(id)+" WHERE NOT EXISTS (SELECT 1 FROM sauvegarde WHERE id="+ std::to_string(id)+" )";

	std::cout << query << std::endl;

	return executeQuery(query);
}

std::vector<sauvegarde*>* database::getAllSauvegarde()
{
	std::string query = "SELECT rowid, * FROM sauvegarde LIMIT 3";
	std::vector<sauvegarde*>* listeSave = new std::vector<sauvegarde*>;
	int i;

	sqlite3_stmt * stmt;
	sqlite3_prepare_v2(db, query.c_str(), strlen(query.c_str()) + 1, &stmt, NULL);

	do {
		i = sqlite3_step(stmt);
		if (i == SQLITE_ROW)
		{
			sauvegarde * save = new sauvegarde();
			listeSave->push_back(save);

			save->nomClasse = (char*)sqlite3_column_text(stmt, 1);
			save->classe = sqlite3_column_int(stmt, 2);
			save->currentHp = sqlite3_column_int(stmt, 3);
			save->force = sqlite3_column_int(stmt, 4);
			save->constitution = sqlite3_column_int(stmt, 5);
			save->dexterite = sqlite3_column_int(stmt, 6);
			save->sagesse = sqlite3_column_int(stmt, 7);
			save->charisme = sqlite3_column_int(stmt, 8);
			save->intelligence = sqlite3_column_int(stmt, 9);
			save->coordx = sqlite3_column_int(stmt, 10);
			save->coordy = sqlite3_column_int(stmt, 11);
			save->mob1 = sqlite3_column_int(stmt, 12);
			save->mob2 = sqlite3_column_int(stmt, 13);
			save->mob3 = sqlite3_column_int(stmt, 14);
			save->mob4 = sqlite3_column_int(stmt, 15);
			save->rowID = sqlite3_column_int(stmt, 16);

		}
	} while (i == SQLITE_ROW);

	return listeSave;
}

bool database::updateSauvegarde(sauvegarde* save)
{
	std::string query = "UPDATE sauvegarde set nomClasse=?, classe=?,currentHp=?, force=?, constitution=?, dexterite=?,sagesse=?, charisme=?, intelligence=?, coordx=?, coordy=?, mob1=?, mob2 =?, mob3=?, mob4=? WHERE id=?"; //where rowid=?";//"UPDATE produits SET nom=?, prix=?, qtevendue=? WHERE rowid=?";
	sqlite3_stmt * stmt;
	sqlite3_prepare_v2(db, query.c_str(), strlen(query.c_str()) + 1, &stmt, NULL);

	//Binds
	sqlite3_bind_text(stmt, 1, save->nomClasse.c_str(), strlen(save->nomClasse.c_str()), 0);
	sqlite3_bind_double(stmt, 2, save->classe);
	sqlite3_bind_int(stmt, 3, save->currentHp);
	sqlite3_bind_int(stmt, 4, save->force);
	sqlite3_bind_int(stmt, 5, save->constitution);
	sqlite3_bind_int(stmt, 6, save->dexterite);
	sqlite3_bind_int(stmt, 7, save->sagesse);
	sqlite3_bind_int(stmt, 8, save->charisme);
	sqlite3_bind_int(stmt, 9, save->intelligence);
	sqlite3_bind_int(stmt, 10, save->coordx);
	sqlite3_bind_int(stmt, 11, save->coordy);
	sqlite3_bind_int(stmt, 12, save->mob1);
	sqlite3_bind_int(stmt, 13, save->mob2);
	sqlite3_bind_int(stmt, 14, save->mob3);
	sqlite3_bind_int(stmt, 15, save->mob4);
	sqlite3_bind_int(stmt, 16, save->rowID);


	//Execute
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);

	return true;
}


