#include "voleur.h"



voleur::voleur()
{
	*force = 8;
	*constitution = 16;
	*dexterite = 18;
	*sagesse = 14;
	*charisme = 10;
	*intelligence = 12;
	*nbrFaceDesDegat = 6;
	*nbrDesDegat = 3;
	*bonusArmure = 3;
	*taille = 2;
	*pvMax = 25 + *constitution;
	*pvActuel = *pvMax;
	*bonusInitiative = 8;
	*bonusAttaque = 2;
	*bonusBouclier = 0;
	*nbrAttaque = 2;
	*choix = 0;
	*niveau = 2;
	*tempsDot = 0;
	*valeurDot = 0;
	estUnJoueur = true;
	*classe = 2;
	*nbrDesSoin = 3;
	*nbrFaceDesSoin = 5;
	*nomAttaqueSpecial = "Backstab";
	*nomBonusDegat = "dexterite";
	seretourner = 0;
}

voleur::~voleur()
{
}
void voleur::AttaqueSpecial(personnage& ennemi)
{
	int x = this->rect.getPosition().x;
	int y = this->rect.getPosition().y;

	if ((this->feinte))
	{
		int jetToucher = 0;
		int rando = ((rand() % 20) + 1);
		jetToucher = rando + *bonusAttaque + BonusStat(*nomBonusDegat) ;

		if (ennemi.CA()+2 >= jetToucher)
		{
			AvancerAttaque();
			this->text.setString("j'ai raté");
			this->text.setFillColor(sf::Color::Red);
			this->text.setCharacterSize(16);
			x = this->rect.getPosition().x;
			this->text.setPosition(x, y - 30);
			ReculerAttaque();
			this->text.setString("Ma feinte est perdu");
			(this->feinte) = false;
		}
		else
		{	
			this->rect.setPosition((392), (105));
			*nbrDesDegat +=2 ;
			x = this->rect.getPosition().x;
			this->text.setPosition(x-30, y - 60);
			this->seretourner = -32;
			this->text.setString("Backstab !!");
			sf::sleep(sf::milliseconds(750));
			for (int i = 0; i < 2; i++)
			{
				this->InfligeDegat(ennemi);
				sf::sleep(sf::milliseconds(550));
			}
			*nbrDesDegat -= 2;
			this->rect.setPosition((100), (105));
			this->seretourner = 0;
			this->text.setString("Ma feinte est perdu");
			(this->feinte) = false;
		}


	}
	else
	{
		this->text.setString("feinte reussi");
		this->text.setFillColor(sf::Color::Red);
		this->text.setCharacterSize(16);
		x = this->rect.getPosition().x;
		this->text.setPosition(x, y - 30);
		(this->feinte) = true;
	}
}
void voleur::sesoigne()
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
	this->anim->heal();
	this->text.setFillColor(sf::Color::Green);
	this->text.setCharacterSize(16);
	this->text.setPosition(x, y - 30);
}
