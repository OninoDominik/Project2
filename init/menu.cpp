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
	boutonOption->text.setString("	Options");
	boutonOption->text.setFillColor(sf::Color::Red);
	boutonOption->text.setCharacterSize(20);
	boutonOption->text.setPosition(0, 140 + 220);
	boutonOption->rect.setPosition(0, 140 + 220);
	boutonOption->rect.setSize((sf::Vector2f(200, 50)));
	
}
void menu::chargerBoutonsmenu()
{
	chargerBoutonOption();
	chargerBoutonChargerPartie();
	chargerBoutonNouvellePartie();
	
}


void menu::ChargerBoutonTailleEcran()
{
	switch (choixTailleEcran)
	{
	case 0:
		boutonTailleEcran->text.setString("Taille de l'ecran de jeu :800*600");
		largeurFenetreDeJeu = 800;
		hauteurFenetreDeJeu = 600;
		break;
	case 1:
		boutonTailleEcran->text.setString("Taille de l'ecran de jeu :1200*900");
		largeurFenetreDeJeu = 1200;
		hauteurFenetreDeJeu = 900;
		break;
	case 2:
		boutonTailleEcran->text.setString("Taille de l'ecran de jeu :400*300");
		largeurFenetreDeJeu = 600;
		hauteurFenetreDeJeu = 300;
		break;
	default:
		break;
	}
	boutonTailleEcran->text.setFillColor(sf::Color::White);
	boutonTailleEcran->text.setCharacterSize(20);
	boutonTailleEcran->text.setPosition(0, 20 );
	boutonTailleEcran->rect.setPosition(0, 20 );
	boutonTailleEcran->rect.setSize((sf::Vector2f(325, 50)));

}
void menu::ChargerBoutonFrameRate()
{
	switch (Affichagefps)
	{
	case 0:
		boutonFrameRate->text.setString("Affichage actuel du framerate : non");
		boutonFrameRate->text.setFillColor(sf::Color::Red);
		break;
	case 1:
		boutonFrameRate->text.setString("Affichage actuel du framerate : oui");
		boutonFrameRate->text.setFillColor(sf::Color::Green);
		break;
	default:
		break;
	}
	boutonFrameRate->text.setCharacterSize(16);
	boutonFrameRate->text.setPosition(0, 70);
	boutonFrameRate->rect.setPosition(0, 70);
	boutonFrameRate->rect.setSize((sf::Vector2f(325, 50)));
}









void menu::menuStart()
{

	database bdd;
	bdd.openDatabase();
	bdd.executeQuery("CREATE TABLE IF NOT EXISTS sauvegarde (nomClasse TEXT,classe INT,currentHp Int,force INT, constitution INT, dexterite INT, sagesse INT, charisme INT, intelligence INT, coordx INT, coordY INT,mob1 INT, mob2 INT, mob3 INT, mob4 INT, id INT)"); // prix FLOAT, qtevendue INT, nom TEXT
	bdd.insertSauvegardeSansDoublon("Alchimiste", 4,99, 10, 16, 10, 10, 6, 18, 256, 1440, 1, 1, 1, 1,1);
	bdd.insertSauvegardeSansDoublon("Paladin", 2,99, 16, 10, 10, 6, 18, 10, 256, 1440, 1, 1, 1, 1,2);
	bdd.insertSauvegardeSansDoublon("Ranger", 3,99, 10, 10, 18, 16, 6, 10,256, 1440, 1, 1, 1, 1,3);

	std::vector<sauvegarde*>* produits = bdd.getAllSauvegarde();
	for (int i = 0; i<produits->size(); i++)
	{
	std::cout << (*produits)[i]->nomClasse<< " + " << (*produits)[i]->classe << std::endl;
	}

	bdd.closeDatabase();
	sf::Music music;
	music.openFromFile("./assets/sound/Dreamseer.ogg");
	music.play();
	music.setLoop(true);
	sf::Font font;
	font.loadFromFile("./assets/font/Champ.ttf");

	textureLogo.loadFromFile("./assets/img/iconPath.jpeg");

	logo->rect.setPosition(0, 0);
	logo->sprite.setTextureRect(sf::IntRect(0, 0, 220,220));
	logo->sprite.setTexture(textureLogo);
	logo->rect.setSize(sf::Vector2f(110, 64));
	logo->sprite.setPosition(logo->rect.getPosition());
	chargerBoutonsmenu();
	sf::Vector2i tailleEcran(220, 420);
	sf::RenderWindow menuWindow(sf::VideoMode(tailleEcran.x, tailleEcran.y), "Pathfinder", sf::Style::Titlebar | sf::Style::Close);
	sf::Color orange(255, 150, 0);
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
			
			creationPerso * crea = new creationPerso(largeurFenetreDeJeu, hauteurFenetreDeJeu, Affichagefps);
			crea->start();
			delete crea;
			menuWindow.create(sf::VideoMode(tailleEcran.x, tailleEcran.y), "Pathfinder", sf::Style::Titlebar | sf::Style::Close);
			music.play();
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonChargerPartie->rect.getGlobalBounds().intersects(spriteCurseur.rect.getGlobalBounds()))
		{
			music.stop();
			menuWindow.close();
			charger * chargeSauvegarde = new charger(largeurFenetreDeJeu, hauteurFenetreDeJeu, Affichagefps);
			chargeSauvegarde->start();
			
		}
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonOption->rect.getGlobalBounds().intersects(spriteCurseur.rect.getGlobalBounds()))
		{
			menuWindow.setVisible(false);
			sf::RenderWindow optionWindow(sf::VideoMode((325), 125), "Pathfinder", sf::Style::Titlebar | sf::Style::Close);
			while (optionWindow.isOpen())
			{
				sf::Event optionEvent;
				while (optionWindow.pollEvent(optionEvent))
				{
					if (optionEvent.type == sf::Event::Closed)
						optionWindow.close();
					if (optionEvent.type == sf::Event::KeyPressed && optionEvent.key.code == sf::Keyboard::Escape)
						optionWindow.close();
				}
				ChargerBoutonTailleEcran();
				ChargerBoutonFrameRate();
				chose spriteCurseur2;
				spriteCurseur2.rect.setPosition((sf::Vector2f)sf::Mouse::getPosition(optionWindow));
				spriteCurseur2.rect.setSize(sf::Vector2f(4, 4));
				
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonTailleEcran->rect.getGlobalBounds().intersects(spriteCurseur2.rect.getGlobalBounds()))
				{

						choixTailleEcran++;
						sf::sleep(sf::milliseconds(100));
						choixTailleEcran = (choixTailleEcran) % 3;

				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonFrameRate->rect.getGlobalBounds().intersects(spriteCurseur2.rect.getGlobalBounds()))
				{

					Affichagefps= !Affichagefps;
					sf::sleep(sf::milliseconds(100));

				}
				if (boutonFrameRate->rect.getGlobalBounds().intersects(spriteCurseur.rect.getGlobalBounds()))
				{
					boutonFrameRate->text.setFillColor(orange);
				}
				if (boutonTailleEcran->rect.getGlobalBounds().intersects(spriteCurseur.rect.getGlobalBounds()))
				{
					boutonTailleEcran->text.setFillColor(orange);
				}

				

				boutonTailleEcran->text.setFont(font);
				boutonFrameRate->text.setFont(font);

				optionWindow.clear();
				optionWindow.draw(boutonTailleEcran->text);
				optionWindow.draw(boutonFrameRate->text);
				optionWindow.display();


			}
			menuWindow.setVisible(true);
		}

		if (boutonNouvellePartie->rect.getGlobalBounds().intersects(spriteCurseur.rect.getGlobalBounds()))
		{
			boutonNouvellePartie->text.setFillColor(orange);
		}
		if (boutonChargerPartie->rect.getGlobalBounds().intersects(spriteCurseur.rect.getGlobalBounds()))
		{
			boutonChargerPartie->text.setFillColor(orange);
		}
		if (boutonOption->rect.getGlobalBounds().intersects(spriteCurseur.rect.getGlobalBounds()))
		{
			boutonOption->text.setFillColor(orange);
		}
		if  (!(boutonNouvellePartie->rect.getGlobalBounds().intersects(spriteCurseur.rect.getGlobalBounds())))
		{
			boutonNouvellePartie->text.setFillColor(sf::Color::White);
		}
		if (!(boutonChargerPartie->rect.getGlobalBounds().intersects(spriteCurseur.rect.getGlobalBounds())))
		{
			boutonChargerPartie->text.setFillColor(sf::Color::White);
		}
		if (!(boutonOption->rect.getGlobalBounds().intersects(spriteCurseur.rect.getGlobalBounds())))
		{
			boutonOption->text.setFillColor(sf::Color::Red);
		}
		boutonOption->text.setFont(font);
		boutonNouvellePartie->text.setFont(font);
		boutonChargerPartie->text.setFont(font);
		menuWindow.clear();
		menuWindow.draw(boutonChargerPartie->text);
		menuWindow.draw(boutonNouvellePartie->text);
		menuWindow.draw(boutonOption->text);
		menuWindow.draw(logo->sprite);
		menuWindow.display();

	}



}

