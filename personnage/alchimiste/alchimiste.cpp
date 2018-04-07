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
	*classe = 4;
	*nbrDesSoin = 5;
	*nbrFaceDesSoin = 4;
	*nomAttaqueSpecial = "Bombe";
	*nomBonusDegat = "intelligence";
}
void alchimiste::AttaqueSpecial(personnage& ennemi)
{
	int x = this->rect.getPosition().x;
	int y = this->rect.getPosition().y;

	AvancerAttaque();
	this->buffer.loadFromFile("./assets/sound/alchimiste/boom.ogg");
	this->sound.setBuffer(this->buffer);
	this->sound.setVolume(50);
	this->sound.play();
	cout << nom << "Bombe";
	this->text.setString("la Bombe a infligée " + to_string(4 + 2 * BonusStat("intelligence")) + "dégats");
	this->text.setFillColor(sf::Color::Red);
	this->text.setCharacterSize(16);
	this->anim->badaBoom();
	*ennemi.pvActuel -= 6 + 2 * BonusStat("intelligence");
	if (rand() % 2 == 1)
	{

		sf::sleep(sf::seconds(0.25));
		this->buffer.loadFromFile("./assets/sound/alchimiste/brulure.ogg");
		this->sound.setBuffer(this->buffer);
		this->sound.setVolume(50);
		this->sound.play();
		this->text.setString("degats bonus : " + to_string(4 + BonusStat("intelligence")));
		*ennemi.pvActuel -= 6 + BonusStat("intelligence");
		this->anim->burn(1);
		sf::sleep(sf::seconds(0.75));

	}
	if (rand() % 2 == 1)
	{

		sf::sleep(sf::seconds(0.25));
		this->buffer.loadFromFile("./assets/sound/alchimiste/brulure.ogg");
		this->sound.setBuffer(this->buffer);
		this->sound.setVolume(50);
		this->sound.play();
		this->text.setString("Je brule : " + to_string(4 + BonusStat("intelligence")));
		*this->pvActuel -= 6 + BonusStat("intelligence");
		this->anim->burn(0);
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
	this->buffer.loadFromFile("./assets/sound/heal.ogg");
	this->sound.setBuffer(this->buffer);
	this->sound.play();
	this->sound.setVolume(20);

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
	this->text.setString(" Soin : " + to_string(soin));
	this->anim->heal();
	this->text.setFillColor(sf::Color::Green);
	this->text.setCharacterSize(16);
	this->text.setPosition(x, y - 30);
}
