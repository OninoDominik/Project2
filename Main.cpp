#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include <iostream>
#include "Database.h"
#include "./sqlite3.h"

using namespace std;
int main()
{
	database bdd;
	bdd.openDatabase();

	bdd.executeQuery("CREATE TABLE IF NOT EXISTS produits (nom TEXT, prix FLOAT, qtevendue INT)");
	/*bdd.insertProduit("Banane", 1.3, 10);
	bdd.insertProduit("Avocat", 2.5, 1);
	bdd.insertProduit("Tomate", 1., 666);*/

	std::vector<Produit*>* produits = bdd.getAllProduits();
	for (int i = 0; i<produits->size(); i++)
	{
		std::cout << (*produits)[i]->nom << " " << (*produits)[i]->prix << std::endl;
	}


	bdd.closeDatabase();

	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Tilemap");

	// define the level with an array of tile indices
	const int level[] =
	{
		0, 1, 2, 0, 24, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0,0,
		48, 49, 26, 0, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 24, 0, 3, 3, 3, 3, 3, 3, 3, 0,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 0,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 0,
	};

	// create the tilemap from the level definition
	TileMap map;
	if (!map.load("tileset.png", sf::Vector2u(32, 40), level, 16, 8))
		return -1;
	//Limitation du framerate
	window.setFramerateLimit(60);
	//Création de la forme
	sf::RectangleShape rectangle(sf::Vector2f(32, 40));
	//Couleur de remplissage
	rectangle.setFillColor(sf::Color(50, 100, 250, 250));


	// run the main loop
	while (window.isOpen())
	{
		window.clear();

		//Touches de déplacement (à faire en switch-case)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			rectangle.move(0, -5);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			rectangle.move(0, 5);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			rectangle.move(5, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			rectangle.move(-5, 0);
		}
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// draw the map
		window.clear();
		window.draw(map);
		window.draw(rectangle);
		window.display();
	}

	return 0;
}