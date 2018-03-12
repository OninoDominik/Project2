#include "paladin.h"
#include <time.h>


paladin::paladin() 
{
	*nbrDesSoin = 4;
	*nbrFaceDesSoin = 6;
	*force = 14;
	*constitution = 12;
	*dexterite = 10;
	*sagesse = 8;
	*charisme = 12;
	*intelligence = 8;
	*nbrFaceDesDegat = 6;
	*nbrDesDegat = 2;
	*bonusArmure = 7;
	*taille = 2;
	*pvMax = 34;
	 *pvActuel = *pvMax;
	*bonusInitiative = 0;
	*bonusAttaque = 4;
	*bonusBouclier = 1;
	*nbrAttaque = 2;
	*choix = 0;
	*niveau = 2;
	*nbrAttaque = 6;
	estUnJoueur = true;
}


paladin::~paladin()
{
}
void paladin::sesoigne()
{
	
	int x = this->rect.getPosition().x;
	int y = this->rect.getPosition().y;

	int soin=0;

	for (int i = 0; i < *nbrDesSoin; i++)
	{
		soin += (rand() % *nbrFaceDesSoin + 1);
	}

	*pvActuel += soin;

	if (*pvActuel > *pvMax)
	{
		*pvActuel = *pvMax;
	}
	this->text.setString(" Soin : "+ to_string(soin));
	this->text.setFillColor(sf::Color::Green);
	this->text.setCharacterSize(16);
	this->text.setPosition(x, y - 30);
}