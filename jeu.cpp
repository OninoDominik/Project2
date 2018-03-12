#include "jeu.h"
#include <math.h>



jeu::jeu()
{
}


jeu::~jeu()
{
}
int jeu::NiveauUn()
{
	return 1;
}
void jeu::ChargerHpPjetbarre(personnage * ptrPj)
{
	scorePjHp->text.setString(to_string(*ptrPj->pvActuel) + " / " + to_string(*ptrPj->pvMax));
	scorePjHp->text.setFillColor(sf::Color::White);
	scorePjHp->text.setCharacterSize(16);
	scorePjHp->text.setPosition(5, 10);
	scorePjHp->rect.setPosition(0, 0);
	scorePjHp->rect.setSize((sf::Vector2f(90, 145)));
	scorePjHp->rect.setFillColor(sf::Color::Black);
}

void jeu::ChargerBoutonSoin()
{
	boutonSoin->text.setString("Se Soigner");
	boutonSoin->text.setFillColor(sf::Color::White);
	boutonSoin->text.setStyle(sf::Text::Bold);
	boutonSoin->text.setCharacterSize(16);
	boutonSoin->text.setPosition(0, 80);
	boutonSoin->rect.setPosition(0, 80);
	boutonSoin->rect.setSize((sf::Vector2f(100, 32)));
}

void jeu::ChargerBoutonAttaquer()
{

	boutonAttaquer->text.setString("Attaquer");
	boutonAttaquer->text.setFillColor(sf::Color::White);
	boutonAttaquer->text.setStyle(sf::Text::Bold);
	boutonAttaquer->text.setCharacterSize(16);
	boutonAttaquer->text.setPosition(0, 40);
	boutonAttaquer->rect.setPosition(0, 40);
	boutonAttaquer->rect.setSize((sf::Vector2f(100, 32)));
}
void jeu::ChargerHpPnj(personnage * ptrPNJ)
{
	scorePnjHP->text.setString(to_string(*ptrPNJ->pvActuel) + " / " + to_string(*ptrPNJ->pvMax));
	scorePnjHP->text.setFillColor(sf::Color::White);
	scorePnjHP->text.setCharacterSize(16);
	scorePnjHP->text.setPosition(360, 10);
	scorePnjHP->rect.setPosition(360, 10);
	scorePnjHP->rect.setSize((sf::Vector2f(400, 145)));
	scorePnjHP->rect.setFillColor(sf::Color::Black);
}


int jeu::Startjeu()
{
	sf::Clock chronometre;
	sf::Music music;
	if (!music.openFromFile("Necromancy.ogg"))
		return -1; // erreur
	music.play();
	database bdd;
	bdd.openDatabase();





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

	bool * fermeCombatWindow = new bool(false);


	// setup window
	sf::Vector2i tailleEcran(800, 600);
	sf::RenderWindow window(sf::VideoMode(tailleEcran.x, tailleEcran.y), "Pathfinder");

	sf::View vuePj(sf::FloatRect(200, 200, 300, 200));
	vuePj.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	vuePj.setCenter(sf::Vector2f(vuePj.getSize().x / 2, vuePj.getSize().y / 2));
	window.setView(vuePj);

	window.setFramerateLimit(60);//Limitation du framerate


								 // load texture (spritesheet)


	if (!icon.loadFromFile("iconPath.jpeg"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	if (!fond.loadFromFile("steampunkMap.png"))
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
	if (!texture4.loadFromFile("darkBoss.png"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}
	if (!grave.loadFromFile("grave.png"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}


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

	personnage * ptrDB = new personnage();

	ptrDB->nom = "Demon";
	ptrDB->rect.setPosition(27 * 32, 34 * 32);
	ptrDB->sprite.setTextureRect(sf::IntRect(0, 0, 110, 64));
	ptrDB->sprite.setTexture(texture4);
	ptrDB->rect.setSize(sf::Vector2f(110, 64));
	ptrDB->sprite.setPosition(ptrDB->rect.getPosition());
	ptrDB->text.setString(" ");
	ptrDB->text.setFont(font);
	ptrDB->text.setFillColor(sf::Color::White);
	ptrDB->text.setCharacterSize(16);

	sf::Sprite spritePnjEmma(texture3);


	spritePnjEmma.setTextureRect(sf::IntRect(0, 0, 64, 32));

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

	ptrPj->rect.setPosition(8 * 32, 45 * 32);
	ptrPj->sprite.setTexture(texture2);
	ptrPj->rect.setTextureRect(sf::IntRect(0, 0, 32, 32));
	ptrPj->Positionnement();
	vector<mur>::const_iterator iterateur;
	vector<mur>::const_iterator iterateur2;
	vector<mur> ligneMur;
	vector<mur> ligneMur2;


	class mur mur1;
	mur1.rect.setPosition(0, 0);
	ligneMur.push_back(mur1);
	/*while (i < 14)
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
	i = 0;*/

	mur mur2;
	mur2.rect.setPosition((27 * 32), (10 * 32));
	mur2.rect.setSize(sf::Vector2f(40, 40));
	ligneMur2.push_back(mur2);

	personnage emma("Emma");
	personnage* ptrEmma = &emma;
	ptrEmma->text.setString(" ");
	ptrEmma->text.setFont(font);
	ptrEmma->text.setFillColor(sf::Color::White);
	ptrEmma->text.setCharacterSize(16);
	ptrEmma->rect.setPosition(27 * 32, 10 * 32);
	ptrEmma->sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	ptrEmma->sprite.setTexture(texture3);
	ptrEmma->rect.setSize(sf::Vector2f(32, 32));
	ptrEmma->sprite.setPosition(ptrEmma->rect.getPosition());

	ptrPj->text.setString(" ");
	ptrPj->text.setFont(font);
	ptrPj->text.setFillColor(sf::Color::White);
	ptrPj->text.setCharacterSize(16);
	ptrPj->text.setPosition(ptrPj->rect.getPosition());


	chose * fps = new chose();

	fps->rect.setSize(sf::Vector2f(110, 64));
	fps->sprite.setPosition(100, 100);
	fps->text.setString(" ");
	fps->text.setFont(font);
	fps->text.setFillColor(sf::Color::White);
	fps->text.setCharacterSize(16);
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
			sf::RenderWindow menu(sf::VideoMode(200, 400), "Option");
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
		if (ptrPj->rect.getGlobalBounds().intersects(ptrDB->rect.getGlobalBounds()))
		{
			*ptrPj->fermeCombatWindow = false;
			sf::Event combatEvent;
			afficheText = true;
			sf::RenderWindow combatWindow2(sf::VideoMode(470, 145), "Combat", sf::Style::Titlebar | sf::Style::Close); //470.145

			chose spriteCurseurCombat;
			sf::Thread thread(std::bind(&combat::startcombat, ptrPj, ptrDB));

			thread.launch(); // start the thread (internally calls task.run())
			ptrPj->rect.setPosition((100), (105));
			ptrPj->rect.setSize((sf::Vector2f(32, 32)));
			ptrPj->sprite.setTexture(texture2);
			ptrDB->rect.setPosition((360), (77));
			ptrDB->rect.setSize((sf::Vector2f(110, 64)));
			ptrDB->sprite.setTexture(texture4);

			int i = 0;
			int j = 0;
			while (combatWindow2.isOpen())
			{


				spriteCurseurCombat.rect.setPosition((sf::Vector2f)sf::Mouse::getPosition(combatWindow2));
				spriteCurseurCombat.rect.setSize(sf::Vector2f(4, 4));

				while (combatWindow2.pollEvent(combatEvent))
				{
					if (combatEvent.type == sf::Event::Closed)
						combatWindow2.close();

					if (combatEvent.type == sf::Event::KeyPressed && combatEvent.key.code == sf::Keyboard::Escape)
						combatWindow2.close();

				}

				combatWindow2.setFramerateLimit(20);

				ptrPj->sprite.setTextureRect(sf::IntRect(i * 32, 64, 32, 32));
				ptrPj->Positionnement();

				ptrDB->sprite.setTextureRect(sf::IntRect(j * 110, 64, 110, 64));
				ptrDB->Positionnement();


				ChargerBoutonAttaquer();
				boutonAttaquer->text.setFont(font);
				ChargerBoutonSoin();
				boutonSoin->text.setFont(font);
				ChargerHpPjetbarre(ptrPj);
				scorePjHp->text.setFont(font);
				ChargerHpPnj(ptrDB);
				scorePnjHP->text.setFont(font);

				

				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonAttaquer->rect.getGlobalBounds().intersects(spriteCurseurCombat.rect.getGlobalBounds()))
				{
					*ptrPj->choix = 1;
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonSoin->rect.getGlobalBounds().intersects(spriteCurseurCombat.rect.getGlobalBounds()))
				{
					*ptrPj->choix = 2;
				}

				i = (i + 1) % 3;
				j = (j + 1) % 4;

				spriteAreneBack.getPosition();

				combatWindow2.clear();
				combatWindow2.draw(spriteAreneBack);
				combatWindow2.draw(spriteAreneFront);
				combatWindow2.draw(scorePjHp->rect);
				combatWindow2.draw(ptrPj->sprite);
				combatWindow2.draw(ptrDB->sprite);
				combatWindow2.draw(boutonAttaquer->text);
				combatWindow2.draw(boutonSoin->text);
				combatWindow2.draw(scorePjHp->text);
				combatWindow2.draw(scorePnjHP->text);
				combatWindow2.draw(ptrPj->text);
				combatWindow2.draw(ptrDB->text);

				combatWindow2.display();

				if (*ptrPj->fermeCombatWindow)
				{
					ptrDB->rect.setSize(sf::Vector2f(0, 0));
					ptrDB->rect.setPosition(27 * 32, 34 * 32);
					ptrPj->rect.setPosition(28 * 32, 35 * 32);
					break;
				}
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


		if (ptrPj->rect.getGlobalBounds().intersects(ptrEmma->rect.getGlobalBounds())) //touche un mur
		{
			*ptrPj->fermeCombatWindow = false;

			afficheText = true;
			sf::RenderWindow combatWindow(sf::VideoMode(470, 145), "Combat"); //470.145


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


				ChargerBoutonAttaquer();
				boutonAttaquer->text.setFont(font);
				ChargerBoutonSoin();
				boutonSoin->text.setFont(font);
				ChargerHpPjetbarre(ptrPj);
				scorePjHp->text.setFont(font);
				ChargerHpPnj(ptrEmma);
				scorePnjHP->text.setFont(font);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonAttaquer->rect.getGlobalBounds().intersects(spriteCurseurCombat.rect.getGlobalBounds()))
				{
					*ptrPj->choix = 1;
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonSoin->rect.getGlobalBounds().intersects(spriteCurseurCombat.rect.getGlobalBounds()))
				{
					*ptrPj->choix = 2;
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
				combatWindow.draw(boutonSoin->text);
				combatWindow.draw(scorePjHp->text);
				combatWindow.draw(scorePnjHP->text);
				combatWindow.draw(ptrPj->text);
				combatWindow.draw(ptrEmma->text);

				combatWindow.display();

				if (*ptrPj->fermeCombatWindow)
				{
					emma.rect.setSize(sf::Vector2f(0, 0));
					ptrPj->rect.setPosition(27 * 32, 10 * 32);
					cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
					break;
				}
			}

		}
		else
		{
			afficheText = false;
		}



		ptrPj->Positionnement();
		ptrPj->Mouvement();

		window.setView(vuePj);
		vuePj.setCenter(ptrPj->rect.getPosition());
		window.clear();
		for (i = 0; i < ligneMur.size() - 1; i++)
		{
			window.draw(ligneMur[i].rect);

		}

		window.draw(spriteFond);

		if (!(*ptrEmma->envie))
		{

			ptrEmma->rect.setSize(sf::Vector2f(0, 0));
			ptrEmma->sprite.setTexture(grave);
			ptrEmma->sprite.setPosition(27 * 32, 10 * 32);
			ptrEmma->sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

		}
		if (!*ptrDB->envie)
		{
			ptrDB->rect.setSize(sf::Vector2f(0, 0));
			ptrDB->sprite.setTexture(grave);
			ptrDB->sprite.setPosition(27 * 32, 34 * 32);
			ptrDB->sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
		}


		window.draw(ptrDB->sprite);
		window.draw(ptrEmma->sprite);
		window.draw(ptrPj->sprite);

		if (AfficherFrameRate)
		{

		}

		sf::Time tempsUneFrame = chronometre.getElapsedTime();
		fps->text.setString("Framerate: " + to_string(1.00f /tempsUneFrame.asSeconds()) + "Fps");
		fps->text.setPosition(ptrPj->rect.getPosition().x - tailleEcran.x / 2, ptrPj->rect.getPosition().y - tailleEcran.y / 2);
		chronometre.restart().asSeconds();
		window.draw(fps->text);
		window.display();
		//cout << (int)sf::Mouse::getPosition(window).x <<"    " <<(int)sf::Mouse::getPosition(window).y << endl;
		if ((!(*ptrEmma->envie)) && (!*ptrDB->envie))
		{
			return 1;
		}
	}

	return 0;
}

