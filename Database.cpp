#include "database.h"
#include <cstring>
#include <iostream>
#include <stdio.h>

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

bool database::insertProduit(std::string nom, float prix, int qtevendue)
{
	char bprix[10];
	char bqtevendue[10];
	sprintf_s(bprix, "%f", prix);
	sprintf_s(bqtevendue, "%d", qtevendue);

	std::string query = "INSERT INTO produits VALUES('";
	query += nom;
	query += "',";
	query += bprix;
	query += ",";
	query += bqtevendue;
	query += ")";

	std::cout << query << std::endl;

	return executeQuery(query);
}

std::vector<Produit*>* database::getAllProduits()
{
	std::string query = "SELECT rowid, * FROM produits";
	std::vector<Produit*>* produits = new std::vector<Produit*>;
	int i;

	sqlite3_stmt * stmt;
	sqlite3_prepare_v2(db, query.c_str(), strlen(query.c_str()) + 1, &stmt, NULL);

	do {
		i = sqlite3_step(stmt);
		if (i == SQLITE_ROW)
		{
			Produit * produit = new Produit();
			produits->push_back(produit);

			produit->id = sqlite3_column_int(stmt, 0);
			produit->nom = (char*)sqlite3_column_text(stmt, 1);
			produit->prix = sqlite3_column_double(stmt, 2);
			produit->qtevendue = sqlite3_column_int(stmt, 3);
		}
	} while (i == SQLITE_ROW);

	return produits;
}

bool database::updateProduit(Produit* produit)
{
	std::string query = "UPDATE produits SET nom=?, prix=?, qtevendue=? WHERE rowid=?";
	sqlite3_stmt * stmt;
	sqlite3_prepare_v2(db, query.c_str(), strlen(query.c_str()) + 1, &stmt, NULL);

	//Binds
	sqlite3_bind_text(stmt, 1, produit->nom.c_str(), strlen(produit->nom.c_str()), 0);
	sqlite3_bind_double(stmt, 2, produit->prix);
	sqlite3_bind_int(stmt, 3, produit->qtevendue);
	sqlite3_bind_int(stmt, 4, produit->id);

	//Execute
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);

	return true;
}

bool database::deleteProduit(int id)
{
	std::string query = "DELETE FROM produits WHERE rowid=?";
	sqlite3_stmt * stmt;
	sqlite3_prepare_v2(db, query.c_str(), strlen(query.c_str()) + 1, &stmt, NULL);

	//Bind
	sqlite3_bind_int(stmt, 1, id);

	//Execute
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);

	return true;
}

