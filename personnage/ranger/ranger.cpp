#include "ranger.h"



ranger::ranger()
{

	*force = 8;
	*constitution = 16;
	*dexterite = 18;
	*sagesse = 14;
	*charisme = 10;
	*intelligence = 12;
	*nbrFaceDesDegat = 8;
	*nbrDesDegat = 2;
	*bonusArmure = 3;
	*taille = 2;
	*pvMax = 25 + *constitution;
	*pvActuel = *pvMax;
	*bonusInitiative = 4;
	*bonusAttaque = 3;
	*bonusBouclier = 0;
	*nbrAttaque = 2;
	*choix = 0;
	*niveau = 2;
	*tempsDot = 0;
	*valeurDot = 0;
	estUnJoueur = true;
	*classe = 3;
	*nbrDesSoin = 4;
	*nbrFaceDesSoin = 4;
	*nomAttaqueSpecial = "Headshot";
	*nomBonusDegat = "dexterite";
}

void ranger::AttaqueSpecial(personnage& ennemi)
{
	int x = this->rect.getPosition().x;
	int y = this->rect.getPosition().y;

	cout << nom << "headshot";
	int jetToucher = 0;
	int rando = (( rand() % 20) + 1);
	jetToucher =  rando + *bonusAttaque + BonusStat(*nomBonusDegat) + BonusStat("sagesse");
	cout << "headshot" << "rando = " << rando <<endl << "bonusAttaque ="  << *bonusAttaque << endl <<"BonusStat(nomBonusDegat)" << BonusStat(*nomBonusDegat)<< endl << *nomBonusDegat << endl <<"sagese" <<BonusStat("sagesse") << endl;;

	if (ennemi.CA() + 5 >= jetToucher)
	{

		AvancerAttaque();
		this->buffer.loadFromFile("./assets/sound/rate.ogg");
		this->sound.setBuffer(this->buffer);
		this->sound.setVolume(50);
		this->sound.play();
		this->text.setString("j'ai raté");
		this->text.setFillColor(sf::Color::White);
		this->text.setCharacterSize(16);
		x = this->rect.getPosition().x;
		this->text.setPosition(x, y - 30);
		ReculerAttaque();
	}
	else
	{
		
		*nbrDesDegat +=4 ;
		AvancerAttaque();
		this->buffer.loadFromFile("./assets/sound/ranger/arrow.ogg");
		this->sound.setBuffer(this->buffer);
		this->sound.setVolume(50);
		this->sound.play();
		this->anim->arrow();
		this->InfligeDegat(ennemi);
		this->text.setString("Headshot !");
		this->text.setFillColor(sf::Color::Red);
		this->text.setCharacterSize(16);
		*nbrDesDegat -= 4;
		ReculerAttaque();
	}

}
void ranger::sesoigne()
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
	soin += BonusStat("sagesse");
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

ranger::~ranger()
{
}
