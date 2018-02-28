#include "personnage.h"
#include <SFML/Graphics.hpp>


personnage::personnage()
{
	rect.setSize(sf::Vector2f(32, 32));
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Blue);
	sprite.setTextureRect(sf::IntRect( 32, 0, 32, 32));

}
personnage::personnage(string nomDuPerso)
{
	rect.setSize(sf::Vector2f(32, 32));
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Blue);
	sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
	this->nom = nomDuPerso;
	cout << "nom = " << this->nom << endl;
}
void personnage::setNom(string choixNom)
{
	this->nom = choixNom;
}
void personnage::Positionnement()
{
	sprite.setPosition(rect.getPosition());
}

void personnage::Mouvement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (monter == true)
		{
			rect.move(0, -vitesse);
			sprite.setTextureRect(sf::IntRect(compteurPas * 32, 32 * 3, 32, 32));
			direction = 1;
			monter = true;
			descendre = true;
			reculer = true;
			avancer = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (descendre == true)
		{
			rect.move(0, vitesse);
			sprite.setTextureRect(sf::IntRect(compteurPas * 32, 0, 32, 32));
			direction = 2;
			monter = true;
			descendre = true;
			reculer = true;
			avancer = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (reculer == true)
		{
			rect.move(-vitesse, 0);
			sprite.setTextureRect(sf::IntRect(compteurPas * 32, 32 , 32, 32));
			direction = 3;
			monter = true;
			descendre = true;
			reculer = true;
			avancer = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (avancer == true)
		{
			rect.move(vitesse, 0);
			sprite.setTextureRect(sf::IntRect(compteurPas * 32, 32 * 2, 32, 32));
			direction = 4;
			monter = true;
			descendre = true;
			reculer = true;
			avancer = true;
		}
	}
	compteurPas= (compteurPas+1)%3;

	
}


personnage::~personnage()
{
}
int personnage::CA()
{
 
	int ca = BonusStat("dexterite") + 10 + 1 +*bonusBouclier +*bonusArmure;
			if (*taille == 1)
			{
				ca++;
			}
			return ca;

}
int personnage::BonusStat(string stat)
{
	if (stat == "force")
	{
		return (*force - 10) / 2;
	}
	if (stat == "constitution")
	{
		return (*constitution - 10) / 2;
	}
	if (stat == "dexterite")
	{
		return (*dexterite - 10) / 2;
	}
	if (stat == "sagesse")
	{
		return (*sagesse - 10) / 2;
	}
	if (stat == "charisme")
	{
		return (*charisme - 10) / 2;
	}
	if (stat == "intelligence")
	{
		return (*intelligence - 10) / 2;
	}
}
void personnage::InfligeDegat(personnage& ennemi)
{
	int deg = 0;
	int degtempo;
	for (int i = 0; i < *nbrDesDegat; i++)
	{
		degtempo = 0;
		degtempo = ((rand() % (*nbrFaceDesDegat)) + 1 + BonusStat(nomBonusDegat));
		deg += degtempo;
		cout << "pv actuel : " << *ennemi.pvActuel;
		cout << "des de degats : " << degtempo << endl;
		
	}
	*ennemi.pvActuel -= deg ;
	cout << nom << " frappe  " << ennemi.nom << "  et inflige   " << deg << " Degats " << endl << "il lui reste " << *ennemi.pvActuel << " PV" << endl;
}
void personnage::Attaque(personnage& ennemi)
{
	int jetToucher = 0;
	jetToucher = (rand() % 20 + 1) + *bonusAttaque;
	if (ennemi.CA() <= jetToucher)
	{
		cout << nom << " touche  " << ennemi.nom << " avec un  " << jetToucher << endl << " la ca de  " << ennemi.nom << " etait de " << ennemi.CA() << endl;
		InfligeDegat(ennemi);
	}
	else
	{
		cout << nom << " rate  " << ennemi.nom << " avec un  " << jetToucher << endl <<" la ca de  " << ennemi.nom << " etait de " << ennemi.CA() << endl;
	}
	
}
int personnage::Initiative()
{

		int initiative = (BonusStat("dexterite") + *bonusInitiative + (rand()%20+1));
		cout << "init" << initiative << endl;
		return initiative;
}

