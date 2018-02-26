#include "personnage.h"
#include <SFML/Graphics.hpp>




personnage::personnage()
{
	rect.setSize(sf::Vector2f(32, 32));
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Blue);
	sprite.setTextureRect(sf::IntRect( 32, 0, 32, 32));
}
void personnage::Positionnement()
{
	sprite.setPosition(rect.getPosition());
}

void personnage::Mouvement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (monter == true)
		{
			rect.move(0, -vitesse);
			sprite.setTextureRect(sf::IntRect(compteurPas * 32, 32 * 3, 32, 32));
			direction = 1;
			monter = true;
			descendre = true;
			reculer = true;
			avancer = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (descendre == true)
		{
			rect.move(0, vitesse);
			sprite.setTextureRect(sf::IntRect(compteurPas * 32, 0, 32, 32));
			direction = 2;
			monter = true;
			descendre = true;
			reculer = true;
			avancer = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (reculer == true)
		{
			rect.move(-vitesse, 0);
			sprite.setTextureRect(sf::IntRect(compteurPas * 32, 32 * 1, 32, 32));
			direction = 3;
			monter = true;
			descendre = true;
			reculer = true;
			avancer = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (avancer == true)
		{
			rect.move(vitesse, 0);
			sprite.setTextureRect(sf::IntRect(compteurPas * 32, 32 * 2, 32, 32));
			direction = 4;
			monter = true;
			descendre = true;
			reculer = true;
			avancer = true;
		}
	}
	compteurPas= (compteurPas+1)%3;

	
}


personnage::~personnage()
{
}
