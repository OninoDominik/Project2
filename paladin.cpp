#include "paladin.h"



paladin::paladin()
{
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