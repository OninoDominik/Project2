#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>



class animationCombat
{
public:
	animationCombat();
	~animationCombat();
	void burn();
	void heal();
	void badaBoom();
	sf::Texture explosion;
	sf::Texture soin;
	sf::Texture textureBurn;
	//void Boom(personnage & victime);

	//void Boom(personnage & victime);
	
	sf::Clock chronoAnim;
	int compteurPas=0;
	int compteurLigne = 0;
	sf::Sprite animSprite;
};

