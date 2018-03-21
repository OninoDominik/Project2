#include "animationCombat.h"



animationCombat::animationCombat()
{
}


animationCombat::~animationCombat()
{
}
void animationCombat::burn()
{
	compteurPas = 0;
	textureBurn.loadFromFile("fx.png");
	animSprite.setTexture(textureBurn);
	while (compteurPas != -1)
	{

		if (chronoAnim.getElapsedTime().asMilliseconds() > 25)
		{
			compteurPas += 75;
			animSprite.setTextureRect(sf::IntRect(compteurPas, 17 * 32 + 10, 64, 4 * 31));
			animSprite.setPosition(360 - 80 / 2, 105 - 80 / 2);
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
	soin.loadFromFile("fx.png");
	animSprite.setTexture(soin);
	while (compteurPas != -1)
	{

		if (chronoAnim.getElapsedTime().asMilliseconds() > 25)
		{
			compteurPas += 75;
			animSprite.setTextureRect(sf::IntRect(compteurPas, 30 * 32 +10, 64, 4 * 31));
			animSprite.setPosition(100 -25  / 2, 105 - 128 / 2);
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
	explosion.loadFromFile("boom.png");
	animSprite.setTexture(explosion);
	while (compteurLigne<400)
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
			animSprite.setPosition(360-80/2, 105-80/2);
			sf::sleep(sf::milliseconds(25));
		}
	}
}

