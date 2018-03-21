#include "alchimiste.h"



alchimiste::alchimiste()
{

	*force = 8;
	*constitution = 16;
	*dexterite = 14;
	*sagesse = 10;
	*charisme = 6;
	*intelligence = 18;
	*nbrFaceDesDegat = 6;
	*nbrDesDegat = 2;
	*bonusArmure = 3;
	*taille = 2;
	*pvMax = 25 + *constitution;
	*pvActuel = *pvMax;
	*bonusInitiative = 4;
	*bonusAttaque = 2;
	*bonusBouclier = 0;
	*nbrAttaque = 2;
	*choix = 0;
	*niveau = 2;
	*tempsDot = 0;
	*valeurDot = 0;
	estUnJoueur = true;
	*classe = 2;
	*nbrDesSoin = 2;
	*nbrFaceDesSoin = 8;
	*nomAttaqueSpecial = "Bombe";
	*nomBonusDegat = "intelligence";
}
void alchimiste::AttaqueSpecial(personnage& ennemi)
{
	int x = this->rect.getPosition().x;
	int y = this->rect.getPosition().y;

	AvancerAttaque();
	cout << nom << "Bombe";
	this->text.setString("Bombe : " + to_string(3 * BonusStat("intelligence")) );
	this->text.setFillColor(sf::Color::Red);
	this->text.setCharacterSize(16);
	this->anim->badaBoom();
	*ennemi.pvActuel -= 3 * BonusStat("intelligence");
	if (rand() % 2 == 1)
	{
		sf::sleep(sf::seconds(0.75));
		this->text.setString("degats bonus : " + to_string(2 * BonusStat("intelligence")));
		*ennemi.pvActuel -= 2 * BonusStat("intelligence");
		this->anim->burn();
		sf::sleep(sf::seconds(0.75));
	}
	if (rand() % 2 == 1)
	{
		sf::sleep(sf::seconds(0.75));
		this->text.setString("je brule : " + to_string(2 * BonusStat("intelligence")));
		*this->pvActuel -= 2 * BonusStat("intelligence");
		sf::sleep(sf::seconds(0.75));
		
	}

	x = this->rect.getPosition().x;
	this->text.setPosition(x, y - 30);
	ReculerAttaque();
}

alchimiste::~alchimiste()
{
}
void alchimiste::sesoigne()
{

	int x = this->rect.getPosition().x;
	int y = this->rect.getPosition().y;

	int soin = 0;

	for (int i = 0; i < *nbrDesSoin; i++)
	{
		soin += (rand() % *nbrFaceDesSoin + 1);
	}

	soin += BonusStat("intelligence");
	*pvActuel += soin;

	if (*pvActuel > *pvMax)
	{
		*pvActuel = *pvMax;
	}
	this->anim->heal();
	this->text.setString(" Soin : " + to_string(soin));
	this->text.setFillColor(sf::Color::Green);
	this->text.setCharacterSize(16);
	this->text.setPosition(x, y - 30);
}
