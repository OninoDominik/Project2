#include <SFML/Graphics.hpp>
#include <iostream>
#include "Database.h"
#include "./sqlite3.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "personnage.h"
#include "mur.h"

using namespace std;

int main()
{
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
	sf::Image icon;
	if (!icon.loadFromFile("orion.png"))
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
	/*const int level[] =
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,15,
		2, 3, 26, 0, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		4, 0, 0, 0, 0, 0, 24, 0, 3, 3, 3, 3, 3, 3, 3, 0,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 0,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 0,
	};


	// create the tilemap from the level definition
	TileMap map;
	if (!map.load("decor.jpg", sf::Vector2u(520, 600), level, 16, 8))
		return -1;*/

		//Création de la forme
		/*sf::RectangleShape rectangle(sf::Vector2f(32, 40));
		//Couleur de remplissage
		rectangle.setFillColor(sf::Color(50, 100, 250, 250));*/

	sf::Sprite spriteFond(fond);

	// set up the animations for all four directions (set spritesheet and push frames)
	/*Animation haut;
	haut.setSpriteSheet(texture);
	haut.addFrame(sf::IntRect(128, 96, 32, 32));
	haut.addFrame(sf::IntRect(160, 96, 32, 32));
	haut.addFrame(sf::IntRect(128, 96, 32, 32));
	haut.addFrame(sf::IntRect(96, 96, 32, 32));
	Animation bas;
	bas.setSpriteSheet(texture);
	bas.addFrame(sf::IntRect(128, 0, 32, 32));
	bas.addFrame(sf::IntRect(160, 0, 32, 32));
	bas.addFrame(sf::IntRect(128, 0, 32, 32));
	bas.addFrame(sf::IntRect(96, 0, 32, 32));
	Animation droite;
	droite.setSpriteSheet(texture);
	droite.addFrame(sf::IntRect(128, 64, 32, 32));
	droite.addFrame(sf::IntRect(160, 64, 32, 32));
	droite.addFrame(sf::IntRect(128, 64, 32, 32));
	droite.addFrame(sf::IntRect(96, 64, 32, 32));
	Animation gauche;
	gauche.setSpriteSheet(texture);
	gauche.addFrame(sf::IntRect(128, 32, 32, 32));
	gauche.addFrame(sf::IntRect(160, 32, 32, 32));
	gauche.addFrame(sf::IntRect(128, 32, 32, 32));
	gauche.addFrame(sf::IntRect(96, 32, 32, 32));

	Animation haut2;
	haut2.setSpriteSheet(texture2);
	haut2.addFrame(sf::IntRect(32, 96, 32, 32));
	haut2.addFrame(sf::IntRect(64, 96, 32, 32));
	haut2.addFrame(sf::IntRect(32, 96, 32, 32));
	haut2.addFrame(sf::IntRect(0, 96, 32, 32));
	Animation bas2;
	bas2.setSpriteSheet(texture2);
	bas2.addFrame(sf::IntRect(32, 0, 32, 32));
	bas2.addFrame(sf::IntRect(64, 0, 32, 32));
	bas2.addFrame(sf::IntRect(32, 0, 32, 32));
	bas2.addFrame(sf::IntRect(0, 0, 32, 32));
	Animation droite2;
	droite2.setSpriteSheet(texture2);
	droite2.addFrame(sf::IntRect(32, 64, 32, 32));
	droite2.addFrame(sf::IntRect(64, 64, 32, 32));
	droite2.addFrame(sf::IntRect(32, 64, 32, 32));
	droite2.addFrame(sf::IntRect(0, 64, 32, 32));
	Animation gauche2;
	gauche2.setSpriteSheet(texture2);
	gauche2.addFrame(sf::IntRect(32, 32, 32, 32));
	gauche2.addFrame(sf::IntRect(64, 32, 32, 32));
	gauche2.addFrame(sf::IntRect(32, 32, 32, 32));
	gauche2.addFrame(sf::IntRect(0, 32, 32, 32));

	Animation haut3;
	haut3.setSpriteSheet(texture3);
	haut3.addFrame(sf::IntRect(32, 96, 32, 32));
	haut3.addFrame(sf::IntRect(64, 96, 32, 32));
	haut3.addFrame(sf::IntRect(32, 96, 32, 32));
	haut3.addFrame(sf::IntRect(0, 96, 32, 32));
	Animation bas3;
	bas3.setSpriteSheet(texture3);
	bas3.addFrame(sf::IntRect(32, 0, 32, 32));
	bas3.addFrame(sf::IntRect(64, 0, 32, 32));
	bas3.addFrame(sf::IntRect(32, 0, 32, 32));
	bas3.addFrame(sf::IntRect(0, 0, 32, 32));
	Animation droite3;
	droite3.setSpriteSheet(texture3);
	droite3.addFrame(sf::IntRect(32, 64, 32, 32));
	droite3.addFrame(sf::IntRect(64, 64, 32, 32));
	droite3.addFrame(sf::IntRect(32, 64, 32, 32));
	droite3.addFrame(sf::IntRect(0, 64, 32, 32));
	Animation gauche3;
	gauche3.setSpriteSheet(texture3);
	gauche3.addFrame(sf::IntRect(32, 32, 32, 32));
	gauche3.addFrame(sf::IntRect(64, 32, 32, 32));
	gauche3.addFrame(sf::IntRect(32, 32, 32, 32));
	gauche3.addFrame(sf::IntRect(0, 32, 32, 32));

	Animation haut4;
	haut4.setSpriteSheet(texture4);
	haut4.addFrame(sf::IntRect(32, 96, 32, 32));
	haut4.addFrame(sf::IntRect(64, 96, 32, 32));
	haut4.addFrame(sf::IntRect(32, 96, 32, 32));
	haut4.addFrame(sf::IntRect(0, 96, 32, 32));
	Animation bas4;
	bas4.setSpriteSheet(texture4);
	bas4.addFrame(sf::IntRect(32, 0, 32, 32));
	bas4.addFrame(sf::IntRect(64, 0, 32, 32));
	bas4.addFrame(sf::IntRect(32, 0, 32, 32));
	bas4.addFrame(sf::IntRect(0, 0, 32, 32));
	Animation droite4;
	droite4.setSpriteSheet(texture4);
	droite4.addFrame(sf::IntRect(32, 64, 32, 32));
	droite4.addFrame(sf::IntRect(64, 64, 32, 32));
	droite4.addFrame(sf::IntRect(32, 64, 32, 32));
	droite4.addFrame(sf::IntRect(0, 64, 32, 32));
	Animation gauche4;
	gauche4.setSpriteSheet(texture4);
	gauche4.addFrame(sf::IntRect(32, 32, 32, 32));
	gauche4.addFrame(sf::IntRect(64, 32, 32, 32));
	gauche4.addFrame(sf::IntRect(32, 32, 32, 32));
	gauche4.addFrame(sf::IntRect(0, 32, 32, 32));

	Animation haut5;
	haut5.setSpriteSheet(texture5);
	haut5.addFrame(sf::IntRect(32, 96, 32, 32));
	haut5.addFrame(sf::IntRect(64, 96, 32, 32));
	haut5.addFrame(sf::IntRect(32, 96, 32, 32));
	haut5.addFrame(sf::IntRect(0, 96, 32, 32));
	Animation bas5;
	bas5.setSpriteSheet(texture5);
	bas5.addFrame(sf::IntRect(32, 0, 32, 32));
	bas5.addFrame(sf::IntRect(64, 0, 32, 32));
	bas5.addFrame(sf::IntRect(32, 0, 32, 32));
	bas5.addFrame(sf::IntRect(0, 0, 32, 32));
	Animation droite5;
	droite5.setSpriteSheet(texture5);
	droite5.addFrame(sf::IntRect(32, 64, 32, 32));
	droite5.addFrame(sf::IntRect(64, 64, 32, 32));
	droite5.addFrame(sf::IntRect(32, 64, 32, 32));
	droite5.addFrame(sf::IntRect(0, 64, 32, 32));
	Animation gauche5;
	gauche5.setSpriteSheet(texture5);
	gauche5.addFrame(sf::IntRect(32, 32, 32, 32));
	gauche5.addFrame(sf::IntRect(64, 32, 32, 32));
	gauche5.addFrame(sf::IntRect(32, 32, 32, 32));
	gauche5.addFrame(sf::IntRect(0, 32, 32, 32));

	Animation pnj;
	pnj.setSpriteSheet(texture5);
	pnj.addFrame(sf::IntRect(64, 64, 32, 32));


	Animation* monAnim = &bas;
	Animation* monAnim2 = &bas2;
	Animation* monAnim3 = &bas3;
	Animation* monAnim4 = &bas4;
	Animation* monAnim5 = &bas5;
	Animation* animePnj = &pnj;


	// set up AnimatedSprite
	spriteAnime monSprite(sf::seconds(0.2), true, false);
	monSprite.setPosition(sf::Vector2f(tailleEcran / 2));
	spriteAnime monSprite2(sf::seconds(0.2), true, false);
	monSprite2.setPosition(430, 330);
	spriteAnime monSprite3(sf::seconds(0.2), true, false);
	monSprite3.setPosition(400, 330);
	spriteAnime monSprite4(sf::seconds(0.2), true, false);
	monSprite4.setPosition(400, 270);
	spriteAnime monSprite5(sf::seconds(0.2), true, false);
	monSprite5.setPosition(430, 300);
	spriteAnime test(sf::seconds(0.2), true, false);
	test.setPosition(100,100);
	sf::Clock monTick;

	float vitesse = 80.f;*/
	bool aucunAppuyTouche = true;
	personnage Pj;
	Pj.sprite.setTexture(texture2);
	Pj.rect.setTextureRect(sf::IntRect(0, 0, 32, 32));
	vector<mur>::const_iterator iterateur;
	vector<mur> ligneMur;
	sf::Font font;
	if (!font.loadFromFile("pixel.ttf"))
	{
		std::cout << "pas de font pixel" << std::endl;
		return 1;
	}
	sf::Text text("Aidez moi ! ", font, 16);
	text.setPosition(370, 290);
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
	mur1.rect.setSize(sf::Vector2f(32, 32));
	ligneMur.push_back(mur1);
	i = 0;

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

		/*sf::Time leTempsduneFrame = monTick.restart();*/

		// if a key was pressed set the correct animation and move correctly
		sf::Vector2f movement(0.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			/*monAnim = &haut;
			monAnim2 = &haut2;
			monAnim3 = &haut3;
			monAnim4 = &haut4;
			monAnim5 = &haut5;
			movement.y -= vitesse;
			aucunAppuyTouche = false;*/
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			/*monAnim = &bas;
			monAnim2 = &bas2;
			monAnim3 = &bas3;
			monAnim4 = &bas4;
			monAnim5 = &bas5;
			movement.y += vitesse;
			aucunAppuyTouche = false;*/
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			/*monAnim = &gauche;
			monAnim2 = &gauche2;
			monAnim3 = &gauche3;
			monAnim4 = &gauche4;
			monAnim5 = &gauche5;
			movement.x -= vitesse;
			aucunAppuyTouche = false;*/
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			/*monAnim = &droite;
			monAnim2 = &droite2;
			monAnim3 = &droite3;
			monAnim4 = &droite4;
			monAnim5 = &droite5;
			movement.x += vitesse;
			aucunAppuyTouche = false;*/
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		{
			sf::RenderWindow menu(sf::VideoMode(tailleEcran.x, tailleEcran.y), "Option");
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
			}
		}
		int i = 0;
		for (iterateur = ligneMur.begin(); iterateur != ligneMur.end(); iterateur++)
		{
			if (Pj.rect.getGlobalBounds().intersects(ligneMur[i].rect.getGlobalBounds())) //touche un mur
			{

				if (Pj.direction == 1) // haut
				{
					Pj.monter = false;
					Pj.rect.move(0, Pj.vitesse);
				}
				else if (Pj.direction == 2) // bas
				{
					Pj.descendre = false;
					Pj.rect.move(0, -Pj.vitesse);
				}
				else if (Pj.direction == 3) // gauche
				{
					Pj.reculer = false;
					Pj.rect.move(Pj.vitesse, 0);
				}
				else if (Pj.direction == 4) // droite
				{
					Pj.avancer = false;
					Pj.rect.move(-Pj.vitesse, 0);
				}
				else
				{

				}
			}

			i++;
		}
		/*monSprite.play(*monAnim);
		monSprite.move(movement * leTempsduneFrame.asSeconds());
		monSprite2.play(*monAnim2);
		monSprite2.move(movement * leTempsduneFrame.asSeconds());
		monSprite3.play(*monAnim3);
		monSprite3.move(movement * leTempsduneFrame.asSeconds());
		monSprite4.play(*monAnim4);
		monSprite4.move(movement * leTempsduneFrame.asSeconds());
		monSprite5.play(*monAnim5);
		monSprite5.move(movement * leTempsduneFrame.asSeconds());
		test.play(*animePnj);*/


		// if no key was pressed stop the animation
		if (aucunAppuyTouche)
		{
			/*monSprite.stop();
			monSprite2.stop();
			monSprite3.stop();
			monSprite4.stop();
			monSprite5.stop();*/
		}
		aucunAppuyTouche = true;

		// update AnimatedSprite
		/*monSprite.update(leTempsduneFrame);
		monSprite2.update(leTempsduneFrame);
		monSprite3.update(leTempsduneFrame);
		monSprite4.update(leTempsduneFrame);
		monSprite5.update(leTempsduneFrame);*/

		// draw
		Pj.Positionnement();
		Pj.Mouvement();
		window.clear();
		for(i=0;i<ligneMur.size()-1;i++)
		{
			window.draw(ligneMur[i].rect);
		}
		window.draw(ligneMur[i].rect);
		window.draw(spriteFond);
		window.draw(spritePnjEmma);
		window.draw(Pj.sprite);
		window.draw(text);
		/*window.draw(monSprite);
		window.draw(monSprite2);
		window.draw(monSprite3);
		window.draw(monSprite4);
		window.draw(monSprite5);
		window.draw(test);*/
		window.display();
	}

	return 0;
}