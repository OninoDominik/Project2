#include "menu.h"



menu::menu()
{
}


menu::~menu()
{
}

void menu::chargerBoutonNouvellePartie()
{
	boutonNouvellePartie->text.setString("	Nouvelle partie");
	boutonNouvellePartie->text.setFillColor(sf::Color::White);
	boutonNouvellePartie->text.setCharacterSize(20);
	boutonNouvellePartie->text.setPosition(0, 20+ 220);
	boutonNouvellePartie->rect.setPosition(0, 20+ 220);
	boutonNouvellePartie->rect.setSize((sf::Vector2f(200, 50)));
	
}

void menu::chargerBoutonChargerPartie()
{
	boutonChargerPartie->text.setString("	Charger partie");
	boutonChargerPartie->text.setFillColor(sf::Color::White);
	boutonChargerPartie->text.setCharacterSize(20);
	boutonChargerPartie->text.setPosition(0, 80 + 220);
	boutonChargerPartie->rect.setPosition(0, 80 + 220);
	boutonChargerPartie->rect.setSize((sf::Vector2f(200, 50)));
	
}

void menu::chargerBoutonOption()
{
	boutonOption->text.setString("	Option");
	boutonOption->text.setFillColor(sf::Color::Red);
	boutonOption->text.setCharacterSize(20);
	boutonOption->text.setPosition(0, 140 + 220);
	boutonOption->rect.setPosition(0, 140 + 220);
	boutonOption->rect.setSize((sf::Vector2f(200, 50)));
	
}
void menu::chargerBoutons()
{
	chargerBoutonOption();
	chargerBoutonChargerPartie();
	chargerBoutonNouvellePartie();
	
}








void menu::menuStart()
{
	sf::Music music;
	music.openFromFile("Necromancy.ogg");
	music.play();
	sf::Font font;
	font.loadFromFile("CloisterBlack.ttf");

	textureLogo.loadFromFile("iconPath.jpeg");

	logo->rect.setPosition(0, 0);
	logo->sprite.setTextureRect(sf::IntRect(0, 0, 220,220));
	logo->sprite.setTexture(textureLogo);
	logo->rect.setSize(sf::Vector2f(110, 64));
	logo->sprite.setPosition(logo->rect.getPosition());

	sf::Vector2i tailleEcran(220, 420);
	sf::RenderWindow menuWindow(sf::VideoMode(tailleEcran.x, tailleEcran.y), "Pathfinder", sf::Style::Titlebar | sf::Style::Close);

	while (menuWindow.isOpen())
	{
		sf::Event menuEvent;
		while (menuWindow.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::Closed)
				menuWindow.close();
			if (menuEvent.type == sf::Event::KeyPressed && menuEvent.key.code == sf::Keyboard::Escape)
				menuWindow.close();
		}

		chose spriteCurseur;
		spriteCurseur.rect.setPosition((sf::Vector2f)sf::Mouse::getPosition(menuWindow));
		spriteCurseur.rect.setSize(sf::Vector2f(4, 4));



		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonNouvellePartie->rect.getGlobalBounds().intersects(spriteCurseur.rect.getGlobalBounds()))
		{
			music.stop();
			menuWindow.close();
			jeu * partie = new jeu();
			partie->Startjeu();
			delete partie;
			menuWindow.create(sf::VideoMode(tailleEcran.x, tailleEcran.y), "Pathfinder", sf::Style::Titlebar | sf::Style::Close);
			music.play();
		}
		chargerBoutons();

		/*chargerBoutonOption();
		chargerBoutonChargerPartie();
		chargerBoutonNouvellePartie();*/

		boutonOption->text.setFont(font);
		boutonNouvellePartie->text.setFont(font);
		boutonChargerPartie->text.setFont(font);
		
		menuWindow.draw(boutonChargerPartie->text);
		menuWindow.draw(boutonNouvellePartie->text);
		menuWindow.draw(boutonOption->text);
		menuWindow.draw(logo->sprite);
		menuWindow.display();

	}



}

