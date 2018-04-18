#include "menu.h"



menu::menu()
{
}


menu::~menu()
{
	delete boutonTailleEcran;
	delete boutonFrameRate;
	delete boutonSauvegarde;
	delete boutonChargerPartie;
	delete boutonNouvellePartie;
	delete boutonOption;
	delete boutonSauvegarde1;
	delete boutonSauvegarde2;
	delete boutonSauvegarde3;
	delete logo;
}

void menu::chargerBoutonNouvellePartie()
{
	boutonNouvellePartie->text.setString("	Nouvelle partie");
	boutonNouvellePartie->text.setFillColor(sf::Color::White);
	boutonNouvellePartie->text.setCharacterSize(20);
	boutonNouvellePartie->text.setPosition(0, 20 + 220);
	boutonNouvellePartie->rect.setPosition(0, 20 + 220);
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
	chargerBoutonAdmin();
}
void menu::chargerBoutonAdmin()
{
	boutonAdmin->text.setString("Relancer le jeu \n(projet2.exe) \nen Tant qu'\nADMINISTRATEUR");
	boutonAdmin->text.setFillColor(sf::Color::Red);
	boutonAdmin->text.setCharacterSize(20);
	boutonAdmin->text.setPosition(0, 240);
	boutonAdmin->rect.setPosition(0,240);
	boutonAdmin->rect.setSize((sf::Vector2f(220, 220)));

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
	boutonTailleEcran->text.setPosition(0, 20);
	boutonTailleEcran->rect.setPosition(0, 20);
	boutonTailleEcran->rect.setSize((sf::Vector2f(325, 50)));

}
void menu::chargerBoutonSon(int sound)
{
	boutonSon->text.setString("Volume : " + to_string(sound));
	boutonSon->text.setFillColor(sf::Color::White);
	boutonSon->text.setCharacterSize(20);
	boutonSon->text.setPosition(0, 120);
	boutonSon->rect.setPosition(0, 120);
	boutonSon->rect.setSize((sf::Vector2f(120, 50)));

}
void menu::chargerBoutonPlus()
{
	boutonPlus->text.setString(" + ");
	boutonPlus->text.setFillColor(sf::Color::Green);
	boutonPlus->text.setCharacterSize(20);
	boutonPlus->text.setPosition(120, 120);
	boutonPlus->rect.setPosition(120, 120);
	boutonPlus->rect.setSize((sf::Vector2f(50, 50)));
}
void menu::chargerBoutonMoins()
{
	boutonMoins->text.setString(" - ");
	boutonMoins->text.setFillColor(sf::Color::Green);
	boutonMoins->text.setCharacterSize(20);
	boutonMoins->text.setPosition(170, 120);
	boutonMoins->rect.setPosition(170, 120);
	boutonMoins->rect.setSize((sf::Vector2f(50, 50)));
}
void menu::chargerBoutonValider()
{
	boutonValider->text.setString(" Retour au menu");
	boutonValider->text.setFillColor(sf::Color::Blue);
	boutonValider->text.setCharacterSize(20);
	boutonValider->text.setPosition(170, 170);
	boutonValider->rect.setPosition(170, 170);
	boutonValider->rect.setSize((sf::Vector2f(150, 50)));
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
		cout << "erreur bouton frame rate" << endl;
		break;
	}
	boutonFrameRate->text.setCharacterSize(16);
	boutonFrameRate->text.setPosition(0, 70);
	boutonFrameRate->rect.setPosition(0, 70);
	boutonFrameRate->rect.setSize((sf::Vector2f(325, 50)));
}


void menu::menuStart()
{
	sf::Image icon;
	sf::Music music;
	music.openFromFile("./assets/sound/Dreamseer.ogg");
	music.play();
	music.setLoop(true);
	sf::Font font;
	music.setVolume(volume);
	font.loadFromFile("./assets/font/Champ.ttf");

	textureLogo.loadFromFile("./assets/img/iconPath.jpeg");

	logo->rect.setPosition(0, 0);
	logo->sprite.setTextureRect(sf::IntRect(0, 0, 220, 220));
	logo->sprite.setTexture(textureLogo);
	logo->rect.setSize(sf::Vector2f(110, 64));
	logo->sprite.setPosition(logo->rect.getPosition());
	chargerBoutonsmenu();
	
	sf::Vector2i tailleEcran(220, 420);
	sf::RenderWindow menuWindow(sf::VideoMode(tailleEcran.x, tailleEcran.y), "Pathfinder", sf::Style::Titlebar | sf::Style::Close);
	sf::Color orange(255, 150, 0);
	if (!icon.loadFromFile("./assets/img/iconPath.jpeg"))
	{
		std::cout << "pas de d'icone ./assets/img/iconPath.jpeg" << std::endl;

	}
	menuWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	database bdd;
	bdd.openDatabase();
	bool fermer = false;
	bdd.executeQuery("CREATE TABLE IF NOT EXISTS sauvegarde (nomClasse TEXT,classe INT,currentHp Int,force INT, constitution INT, dexterite INT, sagesse INT, charisme INT, intelligence INT, coordx INT, coordY INT,mob1 INT, mob2 INT, mob3 INT, mob4 INT, id INT)");
	if (bdd.insertSauvegardeSansDoublon("Alchimiste", 4, 99, 10, 16, 10, 10, 6, 18, 256, 1440, 1, 1, 1, 1, 1)) // prix FLOAT, qtevendue INT, nom TEXT)
	{
		std::cout << "tu es bien en admin" << endl ;
	}
	else
	{
		fermer = true;
	}
	bdd.insertSauvegardeSansDoublon("Paladin", 2, 99, 16, 10, 10, 6, 18, 10, 256, 1440, 1, 1, 1, 1, 2);
	bdd.insertSauvegardeSansDoublon("Ranger", 3, 99, 10, 10, 18, 16, 6, 10, 256, 1440, 1, 1, 1, 1, 3);

	std::vector<sauvegarde*>* produits = bdd.getAllSauvegarde();
	for (int i = 0; i < produits->size(); i++)
	{
		std::cout << (*produits)[i]->nomClasse << " + " << (*produits)[i]->classe << std::endl;
	}

	bdd.closeDatabase();
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



		music.setVolume(volume);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonNouvellePartie->rect.getGlobalBounds().intersects(spriteCurseur.rect.getGlobalBounds()))
		{
			music.stop();
			menuWindow.close();

			creationPerso * crea = new creationPerso(largeurFenetreDeJeu, hauteurFenetreDeJeu, Affichagefps,volume);
			crea->start();
			menuWindow.create(sf::VideoMode(tailleEcran.x, tailleEcran.y), "Pathfinder", sf::Style::Titlebar | sf::Style::Close);
			menuWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
			music.play();
			delete crea;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonChargerPartie->rect.getGlobalBounds().intersects(spriteCurseur.rect.getGlobalBounds()))
		{
			music.stop();
			menuWindow.close();
			charger * chargeSauvegarde = new charger(largeurFenetreDeJeu, hauteurFenetreDeJeu, Affichagefps,volume);
			chargeSauvegarde->start();
			menuWindow.create(sf::VideoMode(tailleEcran.x, tailleEcran.y), "Pathfinder", sf::Style::Titlebar | sf::Style::Close);
			menuWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
			music.play();
			delete chargeSauvegarde;

		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonOption->rect.getGlobalBounds().intersects(spriteCurseur.rect.getGlobalBounds()))
		{
			menuWindow.setVisible(false);
			sf::RenderWindow optionWindow(sf::VideoMode((325), 225), "Pathfinder Option", sf::Style::Titlebar | sf::Style::Close);
			optionWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
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
				chargerBoutonSon(volume);
				chargerBoutonPlus();
				chargerBoutonMoins();
				chargerBoutonValider();

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

					Affichagefps = !Affichagefps;
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
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonPlus->rect.getGlobalBounds().intersects(spriteCurseur2.rect.getGlobalBounds()))
				{
					if (volume < 100)
					{
						volume += 5;
						sf::sleep(sf::milliseconds(80));
					}
					

				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonMoins->rect.getGlobalBounds().intersects(spriteCurseur2.rect.getGlobalBounds()))
				{
					if (volume > 0)
					{
						volume -= 5;
						sf::sleep(sf::milliseconds(80));
					}

				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonValider->rect.getGlobalBounds().intersects(spriteCurseur2.rect.getGlobalBounds()))
				{
					menuWindow.setVisible(true);
					sf::sleep(sf::milliseconds(80));
					optionWindow.close();
				}
				

				boutonTailleEcran->text.setFont(font);
				boutonFrameRate->text.setFont(font);
				boutonSon->text.setFont(font);
				boutonPlus->text.setFont(font);
				boutonMoins->text.setFont(font);
				boutonValider->text.setFont(font);


				optionWindow.clear();
				optionWindow.draw(boutonTailleEcran->text);
				optionWindow.draw(boutonFrameRate->text);
				optionWindow.draw(boutonSon->text);
				optionWindow.draw(boutonPlus->text);
				optionWindow.draw(boutonMoins->text);
				optionWindow.draw(boutonValider->text);
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
		if (!(boutonNouvellePartie->rect.getGlobalBounds().intersects(spriteCurseur.rect.getGlobalBounds())))
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
		boutonAdmin->text.setFont(font);
		menuWindow.clear();
		
		if (fermer == false)
		{
			menuWindow.draw(boutonChargerPartie->text);
			menuWindow.draw(boutonNouvellePartie->text);
			menuWindow.draw(boutonOption->text);
		}
		else
		{
			menuWindow.draw(boutonAdmin->text);
		}
		menuWindow.draw(logo->sprite);
		
		menuWindow.display();
		if (fermer == true)
		{
			sf::sleep(sf::milliseconds(10000));
			menuWindow.close();

		}
		
		
	}
	

}

