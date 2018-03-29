#include "charger.h"



charger::charger(int largeurFenetreDeJeu, int hauteurFenetreDeJeu, int Affichagefps)
{
	this->largeurFenetreDeJeu = largeurFenetreDeJeu;
	this->hauteurFenetreDeJeu = hauteurFenetreDeJeu;
	this->Affichagefps = Affichagefps;
}

charger::charger()
{

}

void charger::chargerBoutonSauvegarde1()
{
	boutonSauvegarde1->text.setString("1 ");
	boutonSauvegarde1->text.setFillColor(sf::Color::Red);
	boutonSauvegarde1->text.setCharacterSize(20);
	boutonSauvegarde1->text.setPosition(0, 50);
	boutonSauvegarde1->rect.setPosition(0, 50);
	boutonSauvegarde1->rect.setSize((sf::Vector2f(200, 50)));
}

void charger::chargerBoutonSauvegarde2()
{
	boutonSauvegarde2->text.setString("2 ");
	boutonSauvegarde2->text.setFillColor(sf::Color::Magenta);
	boutonSauvegarde2->text.setCharacterSize(20);
	boutonSauvegarde2->text.setPosition(0, 110);
	boutonSauvegarde2->rect.setPosition(0, 110);
	boutonSauvegarde2->rect.setSize((sf::Vector2f(200, 50)));
}

void charger::chargerBoutonSauvegarde3()
{
	boutonSauvegarde3->text.setString("3 ");
	boutonSauvegarde3->text.setFillColor(sf::Color::Cyan);
	boutonSauvegarde3->text.setCharacterSize(20);
	boutonSauvegarde3->text.setPosition(0, 170);
	boutonSauvegarde3->rect.setPosition(0, 170);
	boutonSauvegarde3->rect.setSize((sf::Vector2f(200, 50)));
}

charger::~charger()
{
}

void charger::start()
{
	sf::RenderWindow chargerWindow(sf::VideoMode(600, 600), "Chargement", sf::Style::Titlebar | sf::Style::Close);

	chose spriteCurseurCharger;
	

	database bdd;
	bdd.openDatabase();
	std::vector<sauvegarde*>* touteSauvegarde;
	touteSauvegarde = bdd.getAllSauvegarde();
	font.loadFromFile("./assets/font/Champ.ttf");

	while (chargerWindow.isOpen())
	{
		spriteCurseurCharger.rect.setPosition((sf::Vector2f)sf::Mouse::getPosition(chargerWindow));
		spriteCurseurCharger.rect.setSize(sf::Vector2f(3, 3));

		sf::Event chargerEvent;
		while (chargerWindow.pollEvent(chargerEvent))
		{
			if (chargerEvent.type == sf::Event::Closed)
				chargerWindow.close();
			if (chargerEvent.type == sf::Event::KeyPressed && chargerEvent.key.code == sf::Keyboard::Escape)
				chargerWindow.close();
		}
		chargerBoutonSauvegarde3();
		chargerBoutonSauvegarde2();
		chargerBoutonSauvegarde1();
		boutonSauvegarde1->rect.setSize((sf::Vector2f(200, 50)));



		boutonSauvegarde1->text.setString("1 " + ((*touteSauvegarde)[0]->nomClasse));//+" "+ std::to_string((*touteSauvegarde)[0]->coordx)+" "+ std::to_string((*touteSauvegarde)[0]->coordy));
		boutonSauvegarde1->text.setFont(font);
		boutonSauvegarde2->text.setString("2 " + ((*touteSauvegarde)[1]->nomClasse));// + " " + std::to_string((*touteSauvegarde)[1]->coordx) + " " + std::to_string((*touteSauvegarde)[1]->coordy));
		boutonSauvegarde2->text.setFont(font);
		boutonSauvegarde3->text.setString("3 " + ((*touteSauvegarde)[2]->nomClasse));// + " " + std::to_string((*touteSauvegarde)[2]->coordx) + " " + std::to_string((*touteSauvegarde)[2]->coordy));
		boutonSauvegarde3->text.setFont(font);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonSauvegarde1->rect.getGlobalBounds().intersects(spriteCurseurCharger.rect.getGlobalBounds()))
		{
			
			chargerWindow.close();
			jeu * partie = new jeu(largeurFenetreDeJeu, hauteurFenetreDeJeu, Affichagefps);
			partie->Startjeu((*touteSauvegarde)[0]->classe, (*touteSauvegarde)[0]->currentHp, (*touteSauvegarde)[0]->force, (*touteSauvegarde)[0]->dexterite, (*touteSauvegarde)[0]->constitution, (*touteSauvegarde)[0]->charisme, (*touteSauvegarde)[0]->sagesse, (*touteSauvegarde)[0]->intelligence, (*touteSauvegarde)[0]->coordx, (*touteSauvegarde)[0]->coordy, (*touteSauvegarde)[0]->mob1, (*touteSauvegarde)[0]->mob2, (*touteSauvegarde)[0]->mob3, 1);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonSauvegarde2->rect.getGlobalBounds().intersects(spriteCurseurCharger.rect.getGlobalBounds()))
		{
			chargerWindow.close();
			jeu * partie = new jeu(largeurFenetreDeJeu, hauteurFenetreDeJeu, Affichagefps);
			partie->Startjeu((*touteSauvegarde)[1]->classe, (*touteSauvegarde)[1]->currentHp, (*touteSauvegarde)[1]->force, (*touteSauvegarde)[1]->dexterite, (*touteSauvegarde)[1]->constitution, (*touteSauvegarde)[1]->charisme, (*touteSauvegarde)[1]->sagesse, (*touteSauvegarde)[1]->intelligence, (*touteSauvegarde)[1]->coordx, (*touteSauvegarde)[1]->coordy, (*touteSauvegarde)[1]->mob1, (*touteSauvegarde)[1]->mob2, (*touteSauvegarde)[1]->mob3, 2);
			
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonSauvegarde3->rect.getGlobalBounds().intersects(spriteCurseurCharger.rect.getGlobalBounds()))
		{
			chargerWindow.close();
			jeu * partie = new jeu(largeurFenetreDeJeu, hauteurFenetreDeJeu, Affichagefps);
			partie->Startjeu((*touteSauvegarde)[2]->classe, (*touteSauvegarde)[2]->currentHp, (*touteSauvegarde)[2]->force, (*touteSauvegarde)[2]->dexterite, (*touteSauvegarde)[2]->constitution, (*touteSauvegarde)[2]->charisme, (*touteSauvegarde)[2]->sagesse, (*touteSauvegarde)[2]->intelligence, (*touteSauvegarde)[2]->coordx, (*touteSauvegarde)[2]->coordy, (*touteSauvegarde)[2]->mob1, (*touteSauvegarde)[2]->mob2, (*touteSauvegarde)[2]->mob3, 3);
		}

		chargerWindow.clear();
		chargerWindow.draw(boutonSauvegarde1->text);
		chargerWindow.draw(boutonSauvegarde2->text);
		chargerWindow.draw(boutonSauvegarde3->text);
		chargerWindow.display();
	}

}

