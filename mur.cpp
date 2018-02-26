#include "mur.h"
mur::mur()
{
	rect.setSize(sf::Vector2f(50, 50));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::White);
	//sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}
mur::mur(int x, int y, int largeur, int longueur)
{
	rect.setSize(sf::Vector2f(largeur, longueur));
	rect.setPosition(x, y);
	rect.setFillColor(sf::Color::White);
	//sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}
mur::~mur()
{
}
