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
#include <time.h>

 
using namespace std;

int main()
{
	srand((unsigned) time(0));

	database bdd;
	bdd.openDatabase();
	string nomDuSprite = "eline.png";
	bool * fermeCombatWindow = new bool(false);

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
	sf::Vector2i tailleEcran(530, 420);
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
	if (!font.loadFromFile("CloisterBlack.ttf"))
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
	spritePnjEmma.setPosition(399, 299);
	ligneMur2.push_back(mur2);

	personnage emma("Emma");
	personnage* ptrEmma = &emma;
	ptrEmma->text.setString(" ");
	ptrEmma->text.setFont(font);
	ptrEmma->text.setFillColor(sf::Color::White);
	ptrEmma->text.setCharacterSize(16);
	ptrEmma->text.setPosition(ptrEmma->rect.getPosition());

	ptrPj->text.setString(" ");
	ptrPj->text.setFont(font);
	ptrPj->text.setFillColor(sf::Color::White);
	ptrPj->text.setCharacterSize(16);
	ptrPj->text.setPosition(ptrPj->rect.getPosition());

	combat fight1;
	
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

		chose spriteCurseur;
		spriteCurseur.rect.setPosition((sf::Vector2f)sf::Mouse::getPosition(window));
		spriteCurseur.rect.setSize(sf::Vector2f(4, 4));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && ptrPj->rect.getGlobalBounds().intersects(spriteCurseur.rect.getGlobalBounds()))
		{
			window.close();
		}
		else
		{
			
		}

		sf::Vector2f movement(0.f, 0.f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		{
			sf::RenderWindow menu(sf::VideoMode(100, 800), "Option");
			menu.setFramerateLimit(60);
			sf::Event menuEvent;
			while (menu.isOpen())
			{
				while (menu.pollEvent(menuEvent))
				{
					if (menuEvent.type == sf::Event::Closed)
						menu.close();
					if (menuEvent.type == sf::Event::KeyPressed && menuEvent.key.code == sf::Keyboard::Escape)
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
		*fermeCombatWindow = false;
		for (int i =0;i<ligneMur2.size();i++)
		{
			if (ptrPj->rect.getGlobalBounds().intersects(ligneMur2[i].rect.getGlobalBounds())) //touche un mur
			{
				sf::Event combatEvent;
				afficheText = true;
				sf::RenderWindow combatWindow(sf::VideoMode(470, 145), "Combat"); //470.145

				chose spriteCurseurCombat;
				sf::Thread thread(std::bind(&combat::startcombat, ptrPj, ptrEmma));

				thread.launch(); // start the thread (internally calls task.run())
				ptrPj->rect.setPosition((100), (105));
				ptrPj->rect.setSize((sf::Vector2f(32, 32)));
				ptrPj->sprite.setTexture(texture2);
				ptrEmma->rect.setPosition((360), (105));
				ptrEmma->rect.setSize((sf::Vector2f(32, 32)));
				ptrEmma->sprite.setTexture(texture3);

				int i = 0;
				while (combatWindow.isOpen())
				{
					

					spriteCurseurCombat.rect.setPosition((sf::Vector2f)sf::Mouse::getPosition(combatWindow));
					spriteCurseurCombat.rect.setSize(sf::Vector2f(4, 4));

					while (combatWindow.pollEvent(combatEvent))
					{
						if (combatEvent.type == sf::Event::Closed)
							combatWindow.close();

						if (combatEvent.type == sf::Event::KeyPressed && combatEvent.key.code == sf::Keyboard::Escape)
							combatWindow.close();

					}
					
					combatWindow.setFramerateLimit(20);

					ptrPj->sprite.setTextureRect(sf::IntRect(i * 32, 64, 32, 32));
					ptrPj->Positionnement();

					ptrEmma->sprite.setTextureRect(sf::IntRect(i * 32, 32, 32, 32));
					ptrEmma->Positionnement();

					chose * boutonAttaquer = new chose();
					boutonAttaquer->text.setString("Attaquer");
					boutonAttaquer->text.setFont(font);
					boutonAttaquer->text.setFillColor(sf::Color::White);
					boutonAttaquer->text.setStyle(sf::Text::Bold);
					boutonAttaquer->text.setCharacterSize(16);
					boutonAttaquer->text.setPosition(0, 40);
					boutonAttaquer->rect.setPosition(0, 40);
					boutonAttaquer->rect.setSize((sf::Vector2f(100, 32)));

					chose * scorePjHp = new chose();
					scorePjHp->text.setString(to_string(*ptrPj->pvActuel)+" / "+ to_string(*ptrPj->pvMax));
					scorePjHp->text.setFont(font);
					scorePjHp->text.setFillColor(sf::Color::White);
					scorePjHp->text.setCharacterSize(16);
					scorePjHp->text.setPosition(5, 10);
					scorePjHp->rect.setPosition(0, 0);
					scorePjHp->rect.setSize((sf::Vector2f(70, 145)));
					scorePjHp->rect.setFillColor(sf::Color::Black);

					chose*  scorePnjHP = new chose();
					scorePnjHP->text.setString(to_string(*ptrEmma->pvActuel) + " / " + to_string(*ptrEmma->pvMax));
					scorePnjHP->text.setFont(font);
					scorePnjHP->text.setFillColor(sf::Color::White);
					scorePnjHP->text.setCharacterSize(16);
					scorePnjHP->text.setPosition(360, 10);
					scorePnjHP->rect.setPosition(360, 10);
					scorePnjHP->rect.setSize((sf::Vector2f(70, 145)));
					scorePnjHP->rect.setFillColor(sf::Color::Black);

					if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonAttaquer->rect.getGlobalBounds().intersects(spriteCurseurCombat.rect.getGlobalBounds()))
					{
						*ptrPj->choix = 1;
					}
	
					i = (i + 1) % 3;

					spriteAreneBack.getPosition();
					combatWindow.clear();
					combatWindow.draw(spriteAreneBack);
					combatWindow.draw(spriteAreneFront);
					combatWindow.draw(scorePjHp->rect);
					combatWindow.draw(ptrPj->sprite);
					combatWindow.draw(ptrEmma->sprite);
					combatWindow.draw(boutonAttaquer->text);
					combatWindow.draw(scorePjHp->text);
					combatWindow.draw(scorePnjHP->text);
					combatWindow.draw(ptrPj->text);
					combatWindow.draw(ptrEmma->text);
					
					combatWindow.display();

					if (*ptrPj->fermeCombatWindow)
					{
						emma.rect.setSize(sf::Vector2f(0, 0));
						for (int i = 0; i < ligneMur2.size(); i++)
						{
							ligneMur2[i].rect.setSize(sf::Vector2f(0, 0));
						}
						

						cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
						break;
					}
				}
				
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

		if (!*ptrEmma->envie)
		{
			
			if (!texture3.loadFromFile("grave.png"))
			{
				std::cout << "pas de sprite" << std::endl;
				spritePnjEmma.setTexture(texture3);
			}

		}
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