#include "animationCombat.h"



animationCombat::animationCombat()
{
}


animationCombat::~animationCombat()
{
}
void animationCombat::arrow()
{
	compteurLigne = 96;
	compteurPas = 0;
	fleche.loadFromFile("./assets/img/ranger/arrow.png");
	animSprite.setTexture(fleche);
	animSprite.setPosition(232, 90);
	int longueur = 0;
	while (longueur < 125)
	{

		if (chronoAnim.getElapsedTime().asMilliseconds() > 45)
		{
			compteurPas += 32;
			animSprite.move(5, 0);
			longueur += 5;
			if (compteurPas >= 96)
			{
				compteurPas = 0;
				chronoAnim.restart();
			}

			animSprite.setTextureRect(sf::IntRect(compteurPas, compteurLigne, 32, 48));
			sf::sleep(sf::milliseconds(35));
		}
	}
}


void animationCombat::coup(int i)
{
	compteurPas = 150;
	slash.loadFromFile("./assets/img/sword.png");
	animSprite.setTexture(slash);
	chronoAnim.restart();

	while (compteurPas < 300)
	{
		if (i == 0)
		{
			animSprite.rotate(180);
			animSprite.setPosition(100 + 40, 105 + 60);
			animSprite.rotate(180);
		}
		if (i == 1)
		{
			animSprite.setPosition(360 - 10, 105 - 25);
		}
		animSprite.setTextureRect(sf::IntRect(compteurPas, 0, 40, 80));

		if (chronoAnim.getElapsedTime().asMilliseconds() > 125)
		{
			compteurPas += 40;

			if (compteurPas >= 270)
			{
				chronoAnim.restart();
			}



			sf::sleep(sf::milliseconds(25));
		}
	}
}
void animationCombat::sang()
{
	compteurLigne = 0;
	compteurPas = 0;
	saignement.loadFromFile("./assets/img/guerrier/bloody2.png");
	animSprite.setTexture(saignement);
	while (compteurPas < 12 * 49)
	{

		if (chronoAnim.getElapsedTime().asMilliseconds() > 55)
		{
			compteurPas += 50;

			if (compteurPas > 12 * 49)
			{
				chronoAnim.restart();
			}

			animSprite.setTextureRect(sf::IntRect(compteurPas, 0, 50, 50));
			animSprite.setPosition(360 - 10, 105 - 10);
			sf::sleep(sf::milliseconds(25));
		}
	}
}

void animationCombat::palastun()
{
	compteurLigne = 0;
	compteurPas = 0;
	stun.loadFromFile("./assets/img/fx.png");
	animSprite.setTexture(stun);
	while (compteurPas < 200)
	{

		if (chronoAnim.getElapsedTime().asMilliseconds() > 25)
		{
			compteurPas += 50;

			if (compteurPas > 200)
			{
				chronoAnim.restart();
			}

			animSprite.setTextureRect(sf::IntRect(compteurPas, compteurLigne, 50, 50));
			animSprite.setPosition(360 - 10, 105 - 10);
			sf::sleep(sf::milliseconds(55));
		}
	}
}
void animationCombat::burn(int i)
{
	compteurPas = 0;
	textureBurn.loadFromFile("./assets/img/fx.png");
	animSprite.setTexture(textureBurn);
	while (compteurPas != -1)
	{

		if (chronoAnim.getElapsedTime().asMilliseconds() > 35)
		{
			compteurPas += 80;
			animSprite.setTextureRect(sf::IntRect(compteurPas, 17 * 32 + 10, 64, 4 * 31));
			if (i == 1)
			{
				animSprite.setPosition(360 - 25, 105 - 25);
			}
			if (i == 0)
			{
				animSprite.setPosition(225 - 25, 105 - 25);
			}
			sf::sleep(sf::milliseconds(45));
			if (compteurPas >= 450)
			{
				compteurPas = -1;

				chronoAnim.restart();
			}

		}
	}
}

void animationCombat::heal()
{
	compteurPas = 0;
	soin.loadFromFile("./assets/img/fx.png");
	animSprite.setTexture(soin);
	while (compteurPas != -1)
	{

		if (chronoAnim.getElapsedTime().asMilliseconds() > 25)
		{
			compteurPas += 75;
			animSprite.setTextureRect(sf::IntRect(compteurPas, 30 * 32 + 10, 64, 4 * 31));
			animSprite.setPosition(100 - 25 / 2, 105 - 128 / 2);
			sf::sleep(sf::milliseconds(45));
			if (compteurPas >= 450)
			{
				compteurPas = -1;

				chronoAnim.restart();
			}

		}
	}
}

void animationCombat::badaBoom()
{
	compteurLigne = 0;
	compteurPas = 0;
	explosion.loadFromFile("./assets/img/alchimiste/boom.png");
	animSprite.setTexture(explosion);
	while (compteurLigne < 400)
	{

		if (chronoAnim.getElapsedTime().asMilliseconds() > 25)
		{
			compteurPas += 79;

			if (compteurPas > 630)
			{
				compteurLigne += 79;
				compteurPas = 0;
				chronoAnim.restart();
			}

			animSprite.setTextureRect(sf::IntRect(compteurPas, compteurLigne, 79, 79));
			animSprite.setPosition(360 - 25, 105 - 25);
			sf::sleep(sf::milliseconds(25));
		}
	}
}

