#include "paladin.h"


paladin::paladin() 
{
	*nbrDesSoin = 2;
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
	*nbrAttaque = 2;

}


paladin::~paladin()
{
}
void paladin::sesoigne()
{
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
}