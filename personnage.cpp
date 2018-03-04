#include "personnage.h"
#include <SFML/Graphics.hpp>
#include <time.h>

personnage::personnage()
{
	rect.setSize(sf::Vector2f(32, 32));
	sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));

}
personnage::personnage(string nomDuPerso)
{
	rect.setSize(sf::Vector2f(32, 32));
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
			sprite.setTextureRect(sf::IntRect(compteurPas * 32, 32, 32, 32));
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
	compteurPas = (compteurPas + 1) % 3;


}




personnage::~personnage()
{
}
int personnage::CA()
{

	int ca = BonusStat("dexterite") + 10 + 1 + *bonusBouclier + *bonusArmure;
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
void personnage::sesoigne()
{

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
		cout << "pv actuel de : " << ennemi.nom << "  " << *ennemi.pvActuel << endl;
		cout << "des de degats : " << degtempo << endl;

	}
	this->text.setString("j'ai inflige " + to_string(deg) + " degats");

	sf::sleep(sf::microseconds(650));
	*ennemi.pvActuel -= deg;

	cout << nom << " frappe  " << ennemi.nom << "  et inflige   " << deg << " Degats " << endl << "il lui reste " << *ennemi.pvActuel << " PV" << endl;
}
void personnage::Attaque(personnage& ennemi)
{
	int x = this->rect.getPosition().x;
	int y = this->rect.getPosition().y;
	cout.clear();
	for (int i = 0; i < *this->nbrAttaque; i++)
	{
		if (*ennemi.pvActuel <= 0)
		{
			*ennemi.envie = false;
			break;
		}
		int jetToucher = 0;
		jetToucher = ((rand() % 20) + 1) + *bonusAttaque;
		if (ennemi.CA() <= jetToucher)
		{
			AvancerAttaque();
			cout << nom << "avance";
			this->text.setString("Toucher");
			this->text.setFillColor(sf::Color::White);
			this->text.setCharacterSize(16);

			x = this->rect.getPosition().x;
			this->text.setPosition(x, y - 30);


			cout << nom << " touche  " << ennemi.nom << " avec un  " << jetToucher << endl << " la ca de  " << ennemi.nom << " etait de " << ennemi.CA() << endl;

			InfligeDegat(ennemi);
			ReculerAttaque();

			
		}
		else
		{
			AvancerAttaque();
			cout << nom << "avance";
			this->text.setString("Rater");
			this->text.setFillColor(sf::Color::White);
			this->text.setCharacterSize(16);
			x = this->rect.getPosition().x;
			this->text.setPosition(x, y - 30);
			sf::sleep(sf::milliseconds(750));
			ReculerAttaque();
			cout << nom << " rate  " << ennemi.nom << " avec un  " << jetToucher << endl << " la ca de  " << ennemi.nom << " etait de " << ennemi.CA() << endl;
		}

	}


}
int personnage::Initiative()
{

	int initiative = (BonusStat("dexterite") + *bonusInitiative + (rand() % 20 + 1));
	cout << "init" << initiative << endl;
	return initiative;
}
void personnage::afficheStat()
{
	cout << "nom nom nom nom " << this->nom << endl;
	/*cout << "force = 10; " << *this->force << endl;
	cout << "constitution = 10; " << *this->constitution << endl;
	cout << "dexterite = 10; " << *this->dexterite << endl;
	cout << "sagesse = 10; " << *this->sagesse << endl;
	cout << "charisme = 10; " << *this->charisme << endl;
	cout << "intelligence = 10; " << *this->intelligence << endl;
	cout << "nbrFaceDesDegat = 6; " << *this->nbrFaceDesDegat << endl;
	cout << "nbrDesDegat = 2; " << *this->nbrDesDegat << endl;
	cout << "bonusArmure = 5; " << *this->bonusArmure << endl;
	cout << " taille = 2; " << *this->taille << endl;
	cout << "pvMax = 40; " << *this->pvMax << endl;

	cout << "pvActuel = pvMax; " << *this->pvActuel << endl;

	cout << "bonusInitiative = 2; " << *this->bonusInitiative << endl;
	cout << "bonusAttaque = 5; " << *this->bonusAttaque << endl;
	cout << "bonusBouclier = 0; " << *this->bonusBouclier << endl;
	cout << "nbrAttaque = 2; " << *this->nbrAttaque << endl;
	cout << "choix = 0; " << *this->choix << endl;*/

	cout << "nbrDesSoin = 0; " << *this->nbrDesSoin << endl;
	cout << " nbrFaceDesSoin = 0; " << *this->nbrFaceDesSoin << endl;
	cout << " niveau = 2; " << *this->niveau << endl;
}
void personnage::AvancerAttaque()
{

	for (int i = 1; i <= 25; i++)
	{
		if (this->estUnJoueur)
		{
			if (i <= 25)
			{
				this->rect.move(5, 0);
				this->text.move(5, 0);

			}
		}
		else
		{
			this->rect.move(-5, 0);
			this->text.move(-5, 0);

		}
		sf::sleep(sf::milliseconds(30));
	}
}
void personnage::ReculerAttaque()
{
	sf::sleep(sf::milliseconds(750));
	for (int i = 1; i <= 25; i++)
	{
		if (this->estUnJoueur)
		{
			if (i <= 25)
			{
				this->rect.move(-5, 0);
				this->text.move(-5, 0);

			}

		}
		else
		{
			this->rect.move(5, 0);
			this->text.move(5, 0);
		}
	}
}
