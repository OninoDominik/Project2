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
	*pvMax = 25+*constitution;
	 *pvActuel = *pvMax;
	*bonusInitiative = 0;
	*bonusAttaque = 4;
	*bonusBouclier = 1;
	*nbrAttaque = 2;
	*choix = 0;
	*niveau = 2;
	*classe = 1;
	estUnJoueur = true;
	*nomAttaqueSpecial = "Enchainement";
}


paladin::~paladin()
{
}
void paladin::AttaqueSpecial(personnage& ennemi)
{

	int x = this->rect.getPosition().x;
	int y = this->rect.getPosition().y;
	for (int i = 0; i < 2; i++)
	{
		int jetToucher = 0;
		jetToucher = ((rand() % 20) + 1) + *bonusAttaque + BonusStat(*nomBonusDegat);

		if (ennemi.CA()+2 <= jetToucher)
		{
			if (i == 0)
			{
				AvancerAttaque();
				this->text.setString("j'ai etourdit l'ennemi");
				ennemi.estEtourdit = true;
				this->text.setFillColor(sf::Color::Red);
				this->text.setCharacterSize(16);
				x = this->rect.getPosition().x;
				this->text.setPosition(x, y - 30);

				ReculerAttaque();
			}
			else
			{
				AvancerAttaque();
				this->InfligeDegat(ennemi);
				ReculerAttaque();
			}

		}
		else
		{
			if (i == 0)
			{
				AvancerAttaque();
				this->text.setString("j'ai rate l'etourdissement");
				
				this->text.setFillColor(sf::Color::White);
				this->text.setCharacterSize(16);
				x = this->rect.getPosition().x;
				this->text.setPosition(x, y - 30);
				sf::sleep(sf::milliseconds(750));
				ReculerAttaque();
			}
			else
			{
				AvancerAttaque();
				this->text.setString("rate");
				this->text.setFillColor(sf::Color::White);
				this->text.setCharacterSize(16);
				x = this->rect.getPosition().x;
				this->text.setPosition(x, y - 30);
				ReculerAttaque();
			}

		}
	}
	
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
	soin += BonusStat("charisme");
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