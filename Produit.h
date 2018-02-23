#pragma once


#include <string>

class Produit
{
public:
	Produit();
	virtual ~Produit();

	std::string nom;
	float prix;
	int qtevendue;
	int id;

protected:

private:
};
