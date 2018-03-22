#include "guerrier.h"



guerrier::guerrier()
{
	*nbrDesSoin = 2;
	*nbrFaceDesSoin = 4;
	*force = 18;
	*constitution = 16;
	*dexterite = 14;
	*sagesse = 12;
	*charisme = 10;
	*intelligence = 8;
	*nbrFaceDesDegat = 8;
	*nbrDesDegat = 2;
	*bonusArmure = 6;
	*taille = 2;
	*pvMax = 30+*constitution;
	*pvActuel = *pvMax;
	*bonusInitiative = 2;
	*bonusAttaque = 4;
	*bonusBouclier = 0;
	*nbrAttaque = 2;
	*choix = 0;
	*niveau = 2;
	*tempsDot = 0;
	*valeurDot = 0;
	estUnJoueur = true;
	*classe = 2;
	*nomAttaqueSpecial = "Saignement";
}
void guerrier::AttaqueSpecial(personnage& ennemi)
{
	int x = this->rect.getPosition().x;
	int y = this->rect.getPosition().y;

	AvancerAttaque();
	cout << nom << "Saignement";
	this->text.setString("Saignement : "+ to_string(((int)(1.5 * BonusStat("force"))))+ "pour 3 tours");
	this->text.setFillColor(sf::Color::Red);
	this->text.setCharacterSize(16);

	x = this->rect.getPosition().x;
	this->text.setPosition(x, y - 30);

	*ennemi.tempsDot += 3;
	*ennemi.valeurDot = 2*BonusStat("force");
	ReculerAttaque();
}

guerrier::~guerrier()
{
}
void guerrier::sesoigne()
{

	int x = this->rect.getPosition().x;
	int y = this->rect.getPosition().y;

	int soin = 0;

	for (int i = 0; i < *nbrDesSoin; i++)
	{
		soin += (rand() % *nbrFaceDesSoin + 1);
	}
	soin += BonusStat("sagesse");

	if (soin <= 0)
	{
		soin = 1;
	}
	*pvActuel += soin;

	if (*pvActuel > *pvMax)
	{
		*pvActuel = *pvMax;
	}
	this->text.setString(" Soin : " + to_string(soin));
	this->anim->heal();
	this->text.setFillColor(sf::Color::Green);
	this->text.setCharacterSize(16);
	this->text.setPosition(x, y - 30);
}

