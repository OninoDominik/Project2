#pragma once

#include "./sqlite3.h"
#include <string>
#include <vector>
#include "produit.h"

class database
{
public:
	database();
	virtual ~database();

	void openDatabase();
	void closeDatabase();
	bool executeQuery(std::string query);

	bool insertProduit(std::string nom, float prix, int qtevendue);
	std::vector<Produit*>* getAllProduits();
	bool updateProduit(Produit* produit);
	bool deleteProduit(int id);
protected:

private:
	sqlite3 * db;
	std::string dbfile;
};

