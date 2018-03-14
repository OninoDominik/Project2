#include "guerrier.h"



guerrier::guerrier()
{
	*nbrDesSoin = 1;
	*nbrFaceDesSoin = 6;
	*force = 18;
	*constitution = 16;
	*dexterite = 14;
	*sagesse = 8;
	*charisme = 6;
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
	 *dot = 3;
	estUnJoueur = true;
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
	soin += BonusStat("charisme");

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
	this->text.setFillColor(sf::Color::Green);
	this->text.setCharacterSize(16);
	this->text.setPosition(x, y - 30);
}

