#include <SFML/Graphics.hpp>
#include <iostream>
#include "Database.h"
#include "./sqlite3.h"
#include <iostream>
#include <string>
#include "personnage.h"
#include "mur.h"
#include "combat.h"
#include "paladin.h"

 
using namespace std;

int main()
{
	srand(time(NULL));
	database bdd;
	bdd.openDatabase();
	string nomDuSprite = "eline.png";


	/*bdd.executeQuery("CREATE TABLE IF NOT EXISTS produits (nom TEXT, prix FLOAT, qtevendue INT)");
	/*bdd.insertProduit("Banane", 1.3, 10);
	bdd.insertProduit("Avocat", 2.5, 1);
	bdd.insertProduit("Tomate", 1., 666);

	std::vector<Produit*>* produits = bdd.getAllProduits();
	for (int i = 0; i<produits->size(); i++)
	{
		std::cout << (*produits)[i]->nom << " " << (*produits)[i]->prix << std::endl;
	}


	bdd.closeDatabase();*/

	// setup window
	sf::Vector2i tailleEcran(800, 600);
	sf::RenderWindow window(sf::VideoMode(tailleEcran.x, tailleEcran.y), "Pathfinder");
	window.setFramerateLimit(60);//Limitation du framerate

	// load texture (spritesheet)
	sf::Texture texture;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;
	sf::Texture texture5;
	sf::Texture fond;
	sf::Texture areneBack;

	sf::Texture areneFront;
	
	sf::Image icon;
	if (!icon.loadFromFile("iconPath.jpeg"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	if (!fond.loadFromFile("decor.jpg"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}
	if (!areneBack.loadFromFile("arenaFront.png"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}
	if (!areneFront.loadFromFile("arenaFront.png"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}
	if (!texture.loadFromFile(nomDuSprite))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}
	if (!texture2.loadFromFile("knight.png"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}
	if (!texture3.loadFromFile("emma.png"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}
	if (!texture4.loadFromFile("rezza.png"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}
	if (!texture5.loadFromFile("misha.png"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}
	sf::Sprite spritePnjEmma(texture3);
	spritePnjEmma.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	spritePnjEmma.setTextureRect(sf::IntRect(0, 0, 32, 32));
	

	sf::Sprite spriteFond(fond);
	sf::Sprite spriteAreneFront(areneFront);
	sf::Sprite spriteAreneBack(areneBack);

	
	bool aucunAppuyTouche = true;
	personnage* ptrPj = nullptr;
	paladin *ptrPal = new paladin();
	if (true)
	{
		ptrPj = ptrPal;
	}
	ptrPj->setNom("Dom");

	
	ptrPj->sprite.setTexture(texture2);
	ptrPj->rect.setTextureRect(sf::IntRect(0, 0, 32, 32));
	vector<mur>::const_iterator iterateur;
	vector<mur>::const_iterator iterateur2;
	vector<mur> ligneMur;
	vector<mur> ligneMur2;
	sf::Font font;
	if (!font.loadFromFile("pixel.ttf"))
	{
		std::cout << "pas de font pixel" << std::endl;
		return 1;
	}
	sf::Text text("Ecartez vous !! Manant !!", font, 16);
	text.setPosition(370, 290);
	bool afficheText = false;
	int i = 0;
	class mur mur1;
	mur1.rect.setPosition(0, 0);
	ligneMur.push_back(mur1);
	while (i < 14)
	{
		mur1.rect.setPosition(50 * i, 420);
		ligneMur.push_back(mur1);
		mur1.rect.setPosition(50 * i, 0);
		ligneMur.push_back(mur1);
		mur1.rect.setPosition(0, 50 * i);
		ligneMur.push_back(mur1);
		mur1.rect.setPosition(490, 50 * i);
		ligneMur.push_back(mur1);

		i++;
	}
	mur1.rect.setPosition((400), (300));
	mur1.rect.setSize(sf::Vector2f(30, 30));
	ligneMur.push_back(mur1);
	mur1.rect.setPosition((320), (170));
	mur1.rect.setSize(sf::Vector2f(50, 50));
	ligneMur.push_back(mur1);
	mur1.rect.setPosition((250), (235));
	mur1.rect.setSize(sf::Vector2f(2, 2));
	ligneMur.push_back(mur1);
	i = 0;
	mur mur2;
	mur2.rect.setPosition((399), (299));
	mur2.rect.setSize(sf::Vector2f(40, 40));
	ligneMur2.push_back(mur2);
	personnage emma("Emma");
	personnage* ptrEmma = &emma;
	combat* fight1 = new combat();


	
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
		}

		chose spriteCursor;
		spriteCursor.rect.setPosition((sf::Vector2f)sf::Mouse::getPosition(window));
		spriteCursor.rect.setSize(sf::Vector2f(4, 4));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && ptrPj->rect.getGlobalBounds().intersects(spriteCursor.rect.getGlobalBounds()))
		{
			window.close();
		}
		else
		{
			
		}

		sf::Vector2f movement(0.f, 0.f);

		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		{
			sf::RenderWindow menu(sf::VideoMode(180, 300), "Option");
			menu.setFramerateLimit(60);

			while (menu.isOpen())
			{
				while (menu.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						menu.close();
					if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
						menu.close();
					
				}
				menu.clear(sf::Color::Yellow);
				menu.draw(ptrPj->sprite);
				menu.display();
			}
		}
		int i = 0;
		for (iterateur = ligneMur.begin(); iterateur != ligneMur.end(); iterateur++)
		{
			if (ptrPj->rect.getGlobalBounds().intersects(ligneMur[i].rect.getGlobalBounds())) //touche un mur
			{
			
				if (ptrPj->direction == 1) // haut
				{
					ptrPj->monter = false;
					ptrPj->rect.move(0, ptrPj->vitesse);
				}
				else if (ptrPj->direction == 2) // bas
				{
					ptrPj->descendre = false;
					ptrPj->rect.move(0, -ptrPj->vitesse);
					
				}
				else if (ptrPj->direction == 3) // gauche
				{
					ptrPj->reculer = false;
					ptrPj->rect.move(ptrPj->vitesse, 0);
				}
				else if (ptrPj->direction == 4) // droite
				{
					ptrPj->avancer = false;
					ptrPj->rect.move(-ptrPj->vitesse, 0);
				}
				else
				{

				}
			}

			i++;
		}
		for (int i =0;i<ligneMur2.size();i++)
		{
			if (ptrPj->rect.getGlobalBounds().intersects(ligneMur2[i].rect.getGlobalBounds())) //touche un mur
			{
				afficheText = true;
				sf::RenderWindow combat(sf::VideoMode(300, 300), "Fight");
				combat.setFramerateLimit(60);
				ptrPj->rect.setPosition((20), (70));
				ptrPj->rect.setSize((sf::Vector2f(32, 32)));
				ptrPj->sprite.setTexture(texture2);
				ptrPj->rect.setTextureRect(sf::IntRect(0, 0, 32, 32));
				ptrPj->Positionnement();
				
				ptrEmma->rect.setPosition((70), (20));
				ptrEmma->rect.setSize((sf::Vector2f(32, 32)));
				ptrEmma->sprite.setTexture(texture3);
				ptrEmma->rect.setTextureRect(sf::IntRect(0, 0, 32, 32));
				ptrEmma->Positionnement();

				spriteAreneBack.getPosition();
				combat.clear();
				combat.draw(spriteAreneBack);
				combat.draw(spriteAreneFront);
				combat.draw(ptrPj->sprite);
				combat.draw(ptrEmma->sprite);
				combat.display();

				fight1->startcombat(ptrPj, ptrEmma);

			}
			else
			{
				afficheText = false;
			}
		}
		
		
		
		ptrPj->Positionnement();
		ptrPj->Mouvement();
		window.clear();
		for(i=0;i<ligneMur.size()-1;i++)
		{
			window.draw(ligneMur[i].rect);
		}
		

		window.draw(spriteFond);
		window.draw(spritePnjEmma);
		window.draw(ptrPj->sprite);
		if (afficheText)
		{
			window.draw(text);
		}
		
		window.display();
		//cout << (int)sf::Mouse::getPosition(window).x <<"    " <<(int)sf::Mouse::getPosition(window).y << endl;
	}

	return 0;
}