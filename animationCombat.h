#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>



class animationCombat
{
public:
	animationCombat();
	~animationCombat();
	void coup(int i);
	void sang();
	void palastun();
	void burn(int i);
	void heal();
	void badaBoom();
	sf::Texture explosion;
	sf::Texture soin;
	sf::Texture textureBurn;
	sf::Texture stun;
	sf::Texture saignement;
	sf::Texture slash;
	sf::Texture slash2;
	//void Boom(personnage & victime);

	//void Boom(personnage & victime);
	
	sf::Clock chronoAnim;
	int compteurPas=0;
	int compteurLigne = 0;
	sf::Sprite animSprite;
};

