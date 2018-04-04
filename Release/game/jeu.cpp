#include "jeu.h"
#include <math.h>


jeu::jeu(int largeur, int hauteur, bool Affichagefps)
{
	AfficherFrameRate = Affichagefps;
	largeurEcranPrincipal = largeur;
	hauteurEcranPrincipal = hauteur;

}
jeu::jeu()
{

}


void jeu::Combat32(personnage * ptrPj, personnage * Pnj, sf::Texture texturePnj, int coordRepopX, int coordRepopY) // creer une fentre de combat 
{


	*ptrPj->fermeCombatWindow = false;
	//afficheText = true;
	int tailleblock = 32;

	sf::Time tempsAnime = sf::seconds(0.18);
	sf::Time Chronos;
	sf::Clock Chronometres;
	sf::RenderWindow combatWindow(sf::VideoMode(470, 145), "Combat", sf::Style::Titlebar );
	sf::Texture pv;
	sf::Texture pvRed;
	sf::Sprite viePj;
	sf::Sprite viePnj;
	float pourcentPnj = 0;
	float pourcentPj = 0;
	viePj.setTexture(pvRed);
	viePnj.setTexture(pvRed);
	viePj.setTextureRect(sf::IntRect(10, 10, 72, 8));
	viePnj.setTextureRect(sf::IntRect(10, 10, 72, 8));
	pv.loadFromFile("./assets/img/hpBar.png");
	pvRed.loadFromFile("./assets/img/red.png");



	sf::Thread thread(std::bind(&combat::startcombat, ptrPj, Pnj));

	thread.launch(); 
	ptrPj->rect.setPosition((100), (105));
	ptrPj->rect.setSize((sf::Vector2f(tailleblock, tailleblock)));
	ptrPj->sprite.setTexture(textureHero);
	Pnj->rect.setPosition((360), (105));
	Pnj->rect.setSize((sf::Vector2f(tailleblock, tailleblock)));
	Pnj->sprite.setTexture(texturePnj);
	ptrPj->sprite.setTextureRect(sf::IntRect(i * tailleblock, tailleblock * 2 + ptrPj->seretourner, tailleblock, tailleblock));
	Pnj->sprite.setTextureRect(sf::IntRect(i * tailleblock, tailleblock, tailleblock, tailleblock));

	int compteurPas = 0;
	sf::Sprite spriteAreneFront(areneFront);
	sf::Sprite spriteAreneBack(areneBack);
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

		combatWindow.setFramerateLimit(60);
		if (ptrPj->mouvementCombat)
		{
			ptrPj->sprite.setTextureRect(sf::IntRect(compteurPas * tailleblock, tailleblock * 2 + ptrPj->seretourner, tailleblock, tailleblock));
		}

		ptrPj->Positionnement();

		if (Pnj->mouvementCombat)
		{
			Pnj->sprite.setTextureRect(sf::IntRect(compteurPas * tailleblock, tailleblock, tailleblock, tailleblock));
		}
		Pnj->Positionnement();



		ChargerBoutonAttaquer();

		ChargerBoutonSoin();
		ChargerHpPjetbarre(ptrPj);
		ChargerHpPnj(Pnj);
		ChargerBoutonSpecial(ptrPj);

		ChargerBoutonAttaquer();
		boutonAttaquer->text.setFont(font);
		boutonSoin->text.setFont(font);
		scorePjHp->text.setFont(font);
		scorePjHp->sprite.setTextureRect(sf::IntRect(175, 275, 110, 20));
		scorePjHp->sprite.setPosition(90, 1);
		scorePjHp->sprite.setTexture(pv);
		viePj.setPosition(118, 6);
		viePnj.setPosition(318, 6);

		pourcentPj = ((float)(*ptrPj->pvActuel / ((float)*ptrPj->pvMax)));
		if (pourcentPj < 0)
		{
			pourcentPj = 0;
		}
		pourcentPnj = ((float)(*Pnj->pvActuel / ((float)*Pnj->pvMax)));
		if (pourcentPnj < 0)
		{
			pourcentPnj = 0;
		}


		viePj.setScale(pourcentPj, 1);
		viePnj.setScale(pourcentPnj, 1);
		scorePnjHP->text.setFont(font);
		scorePnjHP->sprite.setTextureRect(sf::IntRect(175, 275, 110, 20));
		scorePnjHP->sprite.setPosition(290, 1);
		scorePnjHP->sprite.setTexture(pv);
		boutonSpecial->text.setFont(font);




		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonAttaquer->rect.getGlobalBounds().intersects(spriteCurseurCombat.rect.getGlobalBounds()))
		{
			*ptrPj->choix = 1;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonSoin->rect.getGlobalBounds().intersects(spriteCurseurCombat.rect.getGlobalBounds()))
		{
			*ptrPj->choix = 2;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonSpecial->rect.getGlobalBounds().intersects(spriteCurseurCombat.rect.getGlobalBounds()))
		{
			*ptrPj->choix = 3;
		}


		Chronos += Chronometres.getElapsedTime();
		Chronometres.restart();
		if (Chronos >= tempsAnime)
		{
			Chronos -= tempsAnime;
			compteurPas++;
			compteurPas = (compteurPas) % 3;
		}
		

		spriteAreneFront.getPosition();
		combatWindow.clear();

		combatWindow.draw(spriteAreneFront);
		
		combatWindow.draw(ptrPj->sprite);
		combatWindow.draw(Pnj->sprite);
		combatWindow.draw(boutonAttaquer->text);
		combatWindow.draw(boutonSpecial->text);
		combatWindow.draw(boutonSoin->text);
		combatWindow.draw(ptrPj->text);
		combatWindow.draw(Pnj->text);
		combatWindow.draw(ptrPj->anim->animSprite);
		combatWindow.draw(Pnj->anim->animSprite);
		combatWindow.draw(scorePnjHP->sprite);
		combatWindow.draw(scorePjHp->sprite);
		combatWindow.draw(scorePjHp->rect);
		combatWindow.draw(boutonAttaquer->text);
		combatWindow.draw(boutonSpecial->text);
		combatWindow.draw(boutonSoin->text);
		combatWindow.draw(viePj);
		combatWindow.draw(viePnj);

		combatWindow.display();

		if (*ptrPj->fermeCombatWindow)
		{
			Pnj->rect.setSize(sf::Vector2f(0, 0));
			ptrPj->rect.setPosition(coordRepopX, coordRepopY);
			break;
		}
	}
}


jeu::~jeu()
{
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
	boutonSoin->text.setPosition(0, 60);
	boutonSoin->rect.setPosition(0, 60);
	boutonSoin->rect.setSize((sf::Vector2f(100, 32)));
}

void jeu::ChargerTexteGameover()
{
	texteGameOver->text.setString(" Game Over");
	texteGameOver->text.setFillColor(sf::Color::Red);
	texteGameOver->text.setStyle(sf::Text::Bold);
	texteGameOver->text.setCharacterSize(55);
	texteGameOver->text.setPosition(0, 20);
	texteGameOver->rect.setPosition(0, 20);
	texteGameOver->rect.setSize((sf::Vector2f(100, 32)));
}
void jeu::ChargerTexteRemerciement()
{
	texteRemerciement->text.setString("Merci pour :  \nla musique à \nAdrien von Ziegler\nles sprites sheet à\n87uhgb\nla map à\nRaZziraZzi,RTPCelianna\nLunarea; Pandamaru\nPathfinder à Paizo");
	texteRemerciement->text.setFillColor(sf::Color::Cyan);
	texteRemerciement->text.setCharacterSize(20);
	texteRemerciement->text.setPosition(0, 120);
	texteRemerciement->rect.setPosition(0, 120);
	texteRemerciement->rect.setSize((sf::Vector2f(100, 32)));
}

void jeu::ChargerBoutonAttaquer()
{

	boutonAttaquer->text.setString("Attaquer");
	boutonAttaquer->text.setFillColor(sf::Color::White);
	boutonAttaquer->text.setStyle(sf::Text::Bold);
	boutonAttaquer->text.setCharacterSize(16);
	boutonAttaquer->text.setPosition(0, 30);
	boutonAttaquer->rect.setPosition(0, 30);
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
void jeu::ChargerBoutonSpecial(personnage * ptrPj)
{
	string nomattaque = "Backstab";
	if (*ptrPj->classe == 5)
	{
		if (ptrPj->feinte)
		{
			nomattaque = (*ptrPj->nomAttaqueSpecial);
		}
		else
		{
			nomattaque = "Feinte";
		}

	}
	else
	{
		nomattaque = (*ptrPj->nomAttaqueSpecial);
	}
	boutonSpecial->text.setString(nomattaque);
	boutonSpecial->text.setFillColor(sf::Color::White);
	boutonSpecial->text.setStyle(sf::Text::Bold);
	boutonSpecial->text.setCharacterSize(16);
	boutonSpecial->text.setPosition(0, 90);
	boutonSpecial->rect.setPosition(0, 90);
	boutonSpecial->rect.setSize((sf::Vector2f(100, 32)));
}
///////
//////
/////
int jeu::Startjeu(int classe,int currenthp, int force, int dexterite,int constitution,int charisme,int sagesse, int intelligence, int coordx, int coordy, int mob1, int mob2, int mob3 ,int mob4, int numeroSauvegarde)
{
	sf::Clock chronometre;
	sf::Music music;
	if (!music.openFromFile("./assets/sound/Gleipnir.ogg"))
		return -1; // erreur
	music.play();
	music.setVolume(5);
	music.setLoop(true);

	bool * fermeCombatWindow = new bool(false);


	// setup window
	sf::Vector2i tailleEcranPrincipal(largeurEcranPrincipal, hauteurEcranPrincipal);
	sf::RenderWindow window(sf::VideoMode(tailleEcranPrincipal.x, tailleEcranPrincipal.y), "Pathfinder");

	sf::View vuePj(sf::FloatRect(200, 200, 300, 200));
	vuePj.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	vuePj.setCenter(sf::Vector2f(vuePj.getSize().x / 2, vuePj.getSize().y / 2));
	window.setView(vuePj);

	window.setFramerateLimit(60);//Limitation du framerate


								 // load texture (spritesheet)


	if (!icon.loadFromFile("./assets/img/iconPath.jpeg"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	if (!fond.loadFromFile("./assets/img/map/steampunkMap.png"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}
	if (!cactus.loadFromFile("./assets/img/map/cactus2.png"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}

	if (!areneBack.loadFromFile("./assets/img/arenaFront.png"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}
	if (!areneFront.loadFromFile("./assets/img/arenaFront.png"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}
	if (!texturegobMage.loadFromFile("./assets/img/gobMage.png"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}

	if (!texture3.loadFromFile("./assets/img/gobGuerrier.png"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}
	if (!texture4.loadFromFile("./assets/img/darkBoss.png"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}
	if (!grave.loadFromFile("./assets/img/grave.png"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}
	/*if (!pala.loadFromFile("./assets/img/grave.png"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}*/
	if (!textureOrc.loadFromFile("./assets/img/gobarmure.png"))
	{
		std::cout << "pas de sprite" << std::endl;
		return 1;
	}

	int tailleblock = 32;
	//sf::Font font;
	if (!font.loadFromFile("./assets/font/Champ.ttf"))
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
	ptrDB->rect.setPosition(21 * tailleblock, 8 * tailleblock);
	ptrDB->sprite.setTextureRect(sf::IntRect(0, 0, 110, 64));
	ptrDB->sprite.setTexture(texture4);
	ptrDB->rect.setSize(sf::Vector2f(110, 64));
	ptrDB->sprite.setPosition(ptrDB->rect.getPosition());
	ptrDB->text.setString(" ");
	ptrDB->text.setFont(font);
	ptrDB->text.setFillColor(sf::Color::White);
	ptrDB->text.setCharacterSize(16);
	*ptrDB->nbrAttaque = 2;
	*ptrDB->envie = mob2;

	sf::Sprite spritePnjEmma(texture3);
	sf::Sprite spriteCactus(cactus);

	spritePnjEmma.setTextureRect(sf::IntRect(0, 0, 64, 32));

	sf::Sprite spriteFond(fond);
	sf::Sprite spriteAreneFront(areneFront);
	sf::Sprite spriteAreneBack(areneBack);
	
	bool aucunAppuyTouche = true;
	personnage* ptrPj = nullptr;
	paladin *ptrPal = new paladin();
	guerrier * ptrGue = new guerrier();
	alchimiste * ptrAlc = new alchimiste();
	ranger * ptrRan = new ranger();
	voleur * ptrVol = new voleur();

	if (classe == 2)
	{
		if (!textureHero.loadFromFile("./assets/img/paladin/paladin.png"))
		{
			std::cout << "pas de sprite" << std::endl;
			return 1;
		}
		ptrPj = ptrPal;
		ptrPj->sprite.setTexture(textureHero);
		ptrPj->rect.setTextureRect(sf::IntRect(0, 0, tailleblock, tailleblock));
	}
	if (classe == 1)
	{
		if (!textureHero.loadFromFile("./assets/img/guerrier/guerrier.png"))
		{
			std::cout << "pas de sprite" << std::endl;
			return 1;
		}
		ptrPj = ptrGue;
		ptrPj->sprite.setTexture(textureHero);
		ptrPj->rect.setTextureRect(sf::IntRect(0, 0, tailleblock, tailleblock));
	}
	if (classe == 4)
	{
		if (!textureHero.loadFromFile("./assets/img/alchimiste/alchimiste.png"))
		{
			std::cout << "pas de sprite" << std::endl;
			return 1;
		}
		ptrPj = ptrAlc;
		ptrPj->sprite.setTexture(textureHero);
		ptrPj->rect.setTextureRect(sf::IntRect(0, 0, tailleblock, tailleblock));
	}
	if (classe == 3)
	{
		if (!textureHero.loadFromFile("./assets/img/ranger/ranger.png"))
		{
			std::cout << "pas de sprite" << std::endl;
			return 1;
		}
		ptrPj = ptrRan;
		ptrPj->sprite.setTexture(textureHero);
		ptrPj->rect.setTextureRect(sf::IntRect(0, 0, tailleblock, tailleblock));
	}
	if (classe == 5)
	{
		if (!textureHero.loadFromFile("./assets/img/voleur/voleur.png"))
		{
			std::cout << "pas de sprite" << std::endl;
			return 1;
		}
		ptrPj = ptrVol;
		ptrPj->sprite.setTexture(textureHero);
		ptrPj->rect.setTextureRect(sf::IntRect(0, 0, tailleblock, tailleblock));
	}



	ptrPj->setNom("Dom");

	*ptrPj->force = force;
	*ptrPj->constitution = constitution;
	*ptrPj->dexterite = dexterite;
	*ptrPj->charisme = charisme;
	*ptrPj->intelligence = intelligence;
	*ptrPj->sagesse = sagesse;
	ptrPj->rect.setPosition(coordx, coordy);
	*ptrPj->pvActuel = currenthp;
	if ((*ptrPj->pvActuel) > (*ptrPj->pvMax))
	{
		*ptrPj->pvActuel = *ptrPj->pvMax;
	}

	ptrPj->Positionnement();
	vector<mur>::const_iterator iterateur;
	vector<mur> ligneMur;
	
	ligneMur = murmap1();

	personnage emma("Emma");
	personnage* ptrEmma = &emma;
	ptrEmma->text.setString(" ");
	ptrEmma->text.setFont(font);
	ptrEmma->text.setFillColor(sf::Color::White);
	ptrEmma->text.setCharacterSize(16);
	ptrEmma->rect.setPosition(25.5 * tailleblock, 13 * tailleblock);
	ptrEmma->sprite.setTextureRect(sf::IntRect(0, 0, tailleblock, tailleblock));
	ptrEmma->sprite.setTexture(texture3);
	ptrEmma->rect.setSize(sf::Vector2f(tailleblock, tailleblock));
	ptrEmma->sprite.setPosition(ptrEmma->rect.getPosition());
	*ptrEmma->envie = mob3;
	*ptrEmma->bonusAttaque = 7;

	sf::Sprite spritePnjOrc(textureOrc);
	spritePnjOrc.setTextureRect(sf::IntRect(0, 0, 64, 32));
	personnage Orc("Orc");
	personnage* ptrOrc = &Orc;
	ptrOrc->text.setString(" ");
	ptrOrc->text.setFont(font);
	ptrOrc->text.setFillColor(sf::Color::White);
	ptrOrc->text.setCharacterSize(16);
	ptrOrc->rect.setPosition(25.5 * tailleblock, 14 * tailleblock);
	ptrOrc->sprite.setTextureRect(sf::IntRect(0, 0, tailleblock, tailleblock));
	ptrOrc->sprite.setTexture(textureOrc);
	ptrOrc->rect.setSize(sf::Vector2f(tailleblock, tailleblock));
	ptrOrc->sprite.setPosition(ptrOrc->rect.getPosition());
	*ptrOrc->envie = mob1;
	*ptrOrc->bonusBouclier = 1;
	*ptrOrc->nbrDesDegat = 4;

	sf::Sprite spritePnjgobMage(texturegobMage);
	spritePnjgobMage.setTextureRect(sf::IntRect(0, 0, 64, 32));
	personnage gobMage("gobMage");
	personnage* ptrGobMage = &gobMage;
	ptrGobMage->text.setString(" ");
	ptrGobMage->text.setFont(font);
	ptrGobMage->text.setFillColor(sf::Color::White);
	ptrGobMage->text.setCharacterSize(16);
	ptrGobMage->rect.setPosition(25.5 * tailleblock, 16 * tailleblock);
	ptrGobMage->sprite.setTextureRect(sf::IntRect(0, 0, tailleblock, tailleblock));
	ptrGobMage->sprite.setTexture(texturegobMage);
	ptrGobMage->rect.setSize(sf::Vector2f(tailleblock, tailleblock));
	ptrGobMage->sprite.setPosition(ptrGobMage->rect.getPosition());
	*ptrGobMage->envie = mob4;
	*ptrGobMage->nbrFaceDesDegat = 8;

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
		if (!(*ptrEmma->envie))
		{

			ptrEmma->rect.setSize(sf::Vector2f(0, 0));
			ptrEmma->sprite.setTexture(grave);
			ptrEmma->sprite.setPosition(25.5 * tailleblock, 13 * tailleblock);
			ptrEmma->sprite.setTextureRect(sf::IntRect(0, 0, tailleblock, tailleblock));

		}
		if (!*ptrDB->envie)
		{
			ptrDB->rect.setSize(sf::Vector2f(0, 0));
			ptrDB->sprite.setTexture(grave);
			ptrDB->sprite.setPosition(25.5 * tailleblock, 13 * tailleblock);
			ptrDB->sprite.setTextureRect(sf::IntRect(0, 0, tailleblock, tailleblock));
		}
		if (!*ptrOrc->envie)
		{
			ptrOrc->rect.setSize(sf::Vector2f(0, 0));
			ptrOrc->sprite.setTexture(grave);
			ptrOrc->sprite.setPosition(25.5 * tailleblock, 14 * tailleblock);
			ptrOrc->sprite.setTextureRect(sf::IntRect(0, 0, tailleblock, tailleblock));
		}
		if (!*ptrGobMage->envie)
		{
			ptrGobMage->rect.setSize(sf::Vector2f(0, 0));
			ptrGobMage->sprite.setTexture(grave);
			ptrGobMage->sprite.setPosition(25.5 * tailleblock, 16 * tailleblock);
			ptrGobMage->sprite.setTextureRect(sf::IntRect(0, 0, tailleblock, tailleblock));
		}


		sf::Vector2f movement(0.f, 0.f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			sf::sleep(sf::milliseconds(200));
			string classeSave;
			sf::RenderWindow sauvegarderWindow(sf::VideoMode(190, 50), "Sauvegarde");
			sauvegarderWindow.setFramerateLimit(60);
			sf::Text texteSauvegarde;
			texteSauvegarde.setFont(font);
			texteSauvegarde.setString("Partie sauvegardée");
			texteSauvegarde.setFillColor(sf::Color::Yellow);
			texteSauvegarde.setCharacterSize(22);
			sf::Event sauvegarderEvent;
			while (sauvegarderWindow.isOpen())
			{
				while (sauvegarderWindow.pollEvent(sauvegarderEvent))
				{
					if (sauvegarderEvent.type == sf::Event::Closed)
						sauvegarderWindow.close();
					if (sauvegarderEvent.type == sf::Event::KeyPressed && sauvegarderEvent.key.code == sf::Keyboard::Escape)
						sauvegarderWindow.close();

				}
				sauvegarderWindow.clear(sf::Color::Black);
				switch (*ptrPj->classe)
				{
				case 1:
					classeSave = "Guerrier";
					break;
				case 2:
					classeSave = "Paladin";
					break;
				case 3:
					classeSave = "Ranger";
					break;
				case 4:
					classeSave = "Alchimiste";
					break;
				default:
					classeSave = "Assassin";
					break;
				}
				sauvegarde * encours = new sauvegarde(classeSave, ptrPj, *ptrOrc->envie, *ptrDB->envie, *ptrEmma->envie,*ptrGobMage->envie, numeroSauvegarde);
				database bdd;
				bdd.openDatabase();
				bdd.updateSauvegarde(encours);
				sauvegarderWindow.draw(texteSauvegarde);
				sauvegarderWindow.display();
				sf::sleep(sf::milliseconds(400));
				sauvegarderWindow.close();
			}
			
		}
		if (ptrPj->rect.getGlobalBounds().intersects(ptrDB->rect.getGlobalBounds()))
		{
			*ptrPj->fermeCombatWindow = false;
			sf::Time tempsAnime = sf::seconds(0.18);
			sf::Time Chronos;
			sf::Clock Chronometres;
			sf::Event combatEvent;
			afficheText = true;
			sf::Texture pv;
			sf::Texture pvRed;
			sf::Sprite viePj;
			sf::Sprite viePnj;
			int compteurPas = 0;
			int compteurPasPNJ = 0;
			float pourcentPnj = 0;
			float pourcentPj = 0;
			viePj.setTexture(pvRed);
			viePnj.setTexture(pvRed);
			viePj.setTextureRect(sf::IntRect(10, 10, 72, 8));
			viePnj.setTextureRect(sf::IntRect(10, 10, 72, 8));
			pv.loadFromFile("./assets/img/hpBar.png");
			pvRed.loadFromFile("./assets/img/red.png");
			sf::RenderWindow combatWindow2(sf::VideoMode(470, 145), "Combat", sf::Style::Titlebar); //470.145

			sf::Thread thread(std::bind(&combat::startcombat, ptrPj, ptrDB));

			thread.launch();
			ptrPj->rect.setPosition((100), (105));
			ptrPj->rect.setSize((sf::Vector2f(tailleblock, tailleblock)));
			ptrPj->sprite.setTexture(textureHero);
			ptrPj->sprite.setTextureRect(sf::IntRect(i * tailleblock, tailleblock * 2 + ptrPj->seretourner, tailleblock, tailleblock));
			ptrDB->rect.setPosition((300), (77));
			ptrDB->rect.setSize((sf::Vector2f(110, tailleblock * 2)));
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
				ChargerHpPjetbarre(ptrPj);
				ChargerHpPnj(ptrDB);
				ChargerBoutonSpecial(ptrPj);

				combatWindow2.setFramerateLimit(60);
				if (ptrPj->mouvementCombat)
				{
					ptrPj->sprite.setTextureRect(sf::IntRect(compteurPas * tailleblock, tailleblock * 2 + ptrPj->seretourner, tailleblock, tailleblock));
				}

				ptrPj->Positionnement();

				if (ptrDB->mouvementCombat)
				{
					ptrDB->sprite.setTextureRect(sf::IntRect(compteurPasPNJ * 110, tailleblock * 2, 110, tailleblock * 2));
				}
				ptrDB->Positionnement();


				ChargerBoutonAttaquer();
				boutonAttaquer->text.setFont(font);
				ChargerBoutonSoin();
				boutonSoin->text.setFont(font);
				ChargerHpPjetbarre(ptrPj);
				scorePjHp->text.setFont(font);
				ChargerHpPnj(ptrDB);
				scorePnjHP->text.setFont(font);
				ChargerBoutonSpecial(ptrPj);
				boutonSpecial->text.setFont(font);
				scorePjHp->text.setFont(font);
				scorePjHp->sprite.setTextureRect(sf::IntRect(175, 275, 110, 20));
				scorePjHp->sprite.setPosition(90, 1);
				scorePjHp->sprite.setTexture(pv);
				viePj.setPosition(118, 6);
				viePnj.setPosition(318, 6);
				viePj.setScale(pourcentPj, 1);
				viePnj.setScale(pourcentPnj, 1);
				scorePnjHP->text.setFont(font);
				scorePnjHP->sprite.setTextureRect(sf::IntRect(175, 275, 110, 20));
				scorePnjHP->sprite.setPosition(290, 1);
				scorePnjHP->sprite.setTexture(pv);
				boutonSpecial->text.setFont(font);


				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonAttaquer->rect.getGlobalBounds().intersects(spriteCurseurCombat.rect.getGlobalBounds()))
				{
					*ptrPj->choix = 1;
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonSoin->rect.getGlobalBounds().intersects(spriteCurseurCombat.rect.getGlobalBounds()))
				{
					*ptrPj->choix = 2;
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonSpecial->rect.getGlobalBounds().intersects(spriteCurseurCombat.rect.getGlobalBounds()))
				{
					*ptrPj->choix = 3;
				}


				
				
				Chronos += Chronometres.getElapsedTime();
				Chronometres.restart();
				if (Chronos >= tempsAnime)
				{
					Chronos -= tempsAnime;
					compteurPas++;
					compteurPas = (compteurPas) % 3;
					compteurPasPNJ++;
					compteurPasPNJ = (compteurPasPNJ) % 4;
				}

				spriteAreneBack.getPosition();
				pourcentPj = ((float)(*ptrPj->pvActuel / ((float)*ptrPj->pvMax)));
				if (pourcentPj < 0)
				{
					pourcentPj = 0;
				}
				pourcentPnj = ((float)(*ptrDB->pvActuel / ((float)*ptrDB->pvMax)));
				if (pourcentPnj < 0)
				{
					pourcentPnj = 0;
				}


				viePj.setScale(pourcentPj, 1);
				viePnj.setScale(pourcentPnj, 1);
				scorePnjHP->text.setFont(font);
				scorePnjHP->sprite.setTextureRect(sf::IntRect(175, 275, 110, 20));
				scorePnjHP->sprite.setPosition(290, 1);
				scorePnjHP->sprite.setTexture(pv);

				/*combatWindow2.clear();
				combatWindow2.draw(spriteAreneBack);
				combatWindow2.draw(spriteAreneFront);
				combatWindow2.draw(scorePjHp->rect);
				combatWindow2.draw(ptrPj->sprite);
				combatWindow2.draw(ptrDB->sprite);
				combatWindow2.draw(boutonAttaquer->text);
				combatWindow2.draw(boutonSpecial->text);
				combatWindow2.draw(boutonSoin->text);
				combatWindow2.draw(scorePjHp->text);
				combatWindow2.draw(scorePnjHP->text);
				combatWindow2.draw(ptrPj->text);
				combatWindow2.draw(ptrDB->text);
				combatWindow2.draw(ptrPj->anim->animSprite);
				combatWindow2.draw(scorePnjHP->sprite);
				combatWindow2.draw(scorePjHp->sprite);
				combatWindow2.draw(scorePjHp->rect);
				combatWindow2.draw(viePj);
				combatWindow2.draw(viePnj);*/

				combatWindow2.clear();
				combatWindow2.draw(spriteAreneFront);
				combatWindow2.draw(ptrPj->sprite);
				combatWindow2.draw(ptrDB->sprite);
				combatWindow2.draw(ptrPj->text);
				combatWindow2.draw(ptrDB->text);
				combatWindow2.draw(ptrPj->anim->animSprite);
				combatWindow2.draw(ptrDB->anim->animSprite);
				
				combatWindow2.draw(scorePnjHP->sprite);
				combatWindow2.draw(scorePjHp->sprite);
				combatWindow2.draw(scorePjHp->rect);
				combatWindow2.draw(boutonAttaquer->text);
				combatWindow2.draw(boutonSpecial->text);
				combatWindow2.draw(boutonSoin->text);
				combatWindow2.draw(viePj);
				combatWindow2.draw(viePnj);

				combatWindow2.display();

				if (*ptrPj->fermeCombatWindow)
				{
					ptrDB->rect.setSize(sf::Vector2f(0, 0));
					ptrDB->rect.setPosition(27 * tailleblock, 34 * tailleblock);
					ptrPj->rect.setPosition(28 * tailleblock, 35 * tailleblock);
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

			}
			i++;
		}


		if (ptrPj->rect.getGlobalBounds().intersects(ptrEmma->rect.getGlobalBounds()))
		{
			afficheText = true;
			int coordRepopX = ptrPj->rect.getPosition().x;
			int coordRepopY = ptrPj->rect.getPosition().y;
			Combat32(ptrPj, ptrEmma, texture3, coordRepopX, coordRepopY);
			afficheText = false;
			chronometre.restart();
		}
		if (ptrPj->rect.getGlobalBounds().intersects(ptrOrc->rect.getGlobalBounds()))
		{
			
			afficheText = true;
			int coordRepopX = ptrPj->rect.getPosition().x;
			int coordRepopY = ptrPj->rect.getPosition().y;
			Combat32(ptrPj, ptrOrc, textureOrc, coordRepopX, coordRepopY);
			afficheText = false;
		}
		if (ptrPj->rect.getGlobalBounds().intersects(ptrGobMage->rect.getGlobalBounds()))
		{
			
			afficheText = true;
			int coordRepopX = ptrPj->rect.getPosition().x;
			int coordRepopY = ptrPj->rect.getPosition().y;
			Combat32(ptrPj, ptrGobMage, texturegobMage, coordRepopX, coordRepopY);
			afficheText = false;
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

		window.draw(spriteFond);

		
		if (!*ptrPj->envie)
		{
			music.stop();
			window.close();
			ptrPj->buffer.loadFromFile("./assets/sound/gameOver.ogg");
			ptrPj->sound.setBuffer(ptrPj->buffer);
			ptrPj->sound.setPlayingOffset(sf::seconds(1));
			ptrPj->sound.play();
			ptrPj->sound.setVolume(60);
			sf::Event  gameOverEvent;
			sf::RenderWindow gameOverWindow(sf::VideoMode(320, 335), "Game Over");
			
			while (gameOverWindow.isOpen())
			{


				while (gameOverWindow.pollEvent(gameOverEvent))
				{
					if (gameOverEvent.type == sf::Event::Closed)
						gameOverWindow.close();

					if (gameOverEvent.type == sf::Event::KeyPressed && gameOverEvent.key.code == sf::Keyboard::Escape)
						gameOverWindow.close();

				}
				ChargerTexteGameover();
				ChargerTexteRemerciement();
				texteRemerciement->text.setFont(font);
				texteGameOver->text.setFont(font);

				gameOverWindow.clear();
				gameOverWindow.draw(texteGameOver->text);
				gameOverWindow.draw(texteRemerciement->text);
				gameOverWindow.display();
			}


		}

		window.draw(ptrPj->sprite);
		window.draw(ptrDB->sprite);
		window.draw(ptrEmma->sprite);
		window.draw(ptrOrc->sprite);
		window.draw(ptrGobMage->sprite);
		window.draw(ptrPj->sprite);
		window.draw(spriteCactus);


		if (AfficherFrameRate)
		{
			sf::Time tempsUneFrame = chronometre.getElapsedTime();
			fps->text.setString("Framerate: " + to_string(1.00f / tempsUneFrame.asSeconds()) + "Fps");
			fps->text.setPosition(ptrPj->rect.getPosition().x - tailleEcranPrincipal.x / 2, ptrPj->rect.getPosition().y - tailleEcranPrincipal.y / 2);
			chronometre.restart().asSeconds();
		}

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

vector<mur> jeu::murmap1()
{
	vector<mur> ligneMur;
	int tailleblock = 32;
	mur1.rect.setPosition(0, 0);
	mur1.rect.setSize(sf::Vector2f(tailleblock, tailleblock));
	ligneMur.push_back(mur1);

	for (int i = 0; i < 50; i++)
	{
		mur1.rect.setPosition(-1, i*tailleblock);
		mur1.rect.setSize(sf::Vector2f(1, tailleblock));
		ligneMur.push_back(mur1);
		mur1.rect.setSize(sf::Vector2f(tailleblock, tailleblock));
		mur1.rect.setPosition(i*tailleblock, 50 * tailleblock);
		ligneMur.push_back(mur1);
		mur1.rect.setPosition(50 * tailleblock, i*tailleblock);
		ligneMur.push_back(mur1);
	}
	mur1.rect.setPosition(25 * tailleblock, 1 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(4 * tailleblock, 41 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(30 * tailleblock, 32 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(34 * tailleblock, 21 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(34 * tailleblock, 22 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(32 * tailleblock, 15 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(17 * tailleblock, 12 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(29 * tailleblock, 9 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(7 * tailleblock, 46 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(18 * tailleblock, 42 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(26 * tailleblock, 43 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(36 * tailleblock, 48 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(37 * tailleblock, 40 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(43 * tailleblock, 44 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(47 * tailleblock, 42 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(49 * tailleblock, 38 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(14 * tailleblock, 49 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(14 * tailleblock, 49 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(2 * tailleblock, 2 * tailleblock));
	mur1.rect.setPosition(39 * tailleblock, 30 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(23 * tailleblock, 15 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(27 * tailleblock, 15 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(tailleblock, tailleblock));
	mur1.rect.setPosition(8 * tailleblock, 20 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(10 * tailleblock, 17 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(9 * tailleblock, 16 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(10 * tailleblock, 15 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(11 * tailleblock, 16 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(10 * tailleblock, 13 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(15 * tailleblock, 12 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(19 * tailleblock, 12 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(20 * tailleblock, 13 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(19 * tailleblock, 14 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(39 * tailleblock, 14 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(5 * tailleblock, 3 * tailleblock));
	mur1.rect.setPosition(22 * tailleblock, 32 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(7 * tailleblock, 3 * tailleblock));
	mur1.rect.setPosition(15 * tailleblock, 34 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(7 * tailleblock, 1 * tailleblock));
	mur1.rect.setPosition(7 * tailleblock, 38 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(5 * tailleblock, 2 * tailleblock));
	mur1.rect.setPosition(30 * tailleblock, 33 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(33 * tailleblock, 34 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(37 * tailleblock, 35 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(7 * tailleblock, 9 * tailleblock));
	mur1.rect.setPosition(16 * tailleblock, 15 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(4 * tailleblock, 9 * tailleblock));
	mur1.rect.setPosition(28 * tailleblock, 15 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(12 * tailleblock, 5 * tailleblock));
	mur1.rect.setPosition(32 * tailleblock, 16 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(5 * tailleblock, 10 * tailleblock));
	mur1.rect.setPosition(8 * tailleblock, 23 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(9 * tailleblock, 7 * tailleblock));
	mur1.rect.setPosition(42 * tailleblock, 26 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(12 * tailleblock, 1 * tailleblock));
	mur1.rect.setPosition(4 * tailleblock, 22 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(8 * tailleblock, 9 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(3 * tailleblock, 3 * tailleblock));
	mur1.rect.setPosition(19 * tailleblock, 16 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(25 * tailleblock, 6 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(27 * tailleblock, 5 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(30 * tailleblock, 6 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(33 * tailleblock, 5 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(34 * tailleblock, 7 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(36 * tailleblock, 9 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(39 * tailleblock, 11 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(24 * tailleblock, 0 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(21 * tailleblock, 5 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(5 * tailleblock, 1 * tailleblock));
	mur1.rect.setPosition(25 * tailleblock, 4 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(4 * tailleblock, 31 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(1 * tailleblock, 5 * tailleblock));
	mur1.rect.setPosition(20 * tailleblock, 0 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(30 * tailleblock, 0 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(9 * tailleblock, 10 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(4 * tailleblock, 31 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(15 * tailleblock, 16 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(5 * tailleblock, 17 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(6 * tailleblock, 14 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(11 * tailleblock, 1 * tailleblock));
	mur1.rect.setPosition(20 * tailleblock, 0 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(2 * tailleblock, 1 * tailleblock));
	mur1.rect.setPosition(12 * tailleblock, 12 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(11 * tailleblock, 14 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(8 * tailleblock, 18 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(9 * tailleblock, 19 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(23 * tailleblock, 14 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(27 * tailleblock, 14 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(37 * tailleblock, 15 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(39 * tailleblock, 15 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(13 * tailleblock, 38 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(41 * tailleblock, 37 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(43 * tailleblock, 37 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(40 * tailleblock, 37 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(44 * tailleblock, 37 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(44 * tailleblock, 36 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(46 * tailleblock, 35 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(36 * tailleblock, 22 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(47 * tailleblock, 34 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(37 * tailleblock, 23 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(38 * tailleblock, 24 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(39 * tailleblock, 25 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(40 * tailleblock, 26 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(41 * tailleblock, 27 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(36 * tailleblock, 21 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(13 * tailleblock, 37 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(9 * tailleblock, 39 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(11 * tailleblock, 39 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(0 * tailleblock, 36 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(2 * tailleblock, 36 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(3 * tailleblock, 35 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(5 * tailleblock, 35 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(1 * tailleblock, 3 * tailleblock));
	mur1.rect.setPosition(6 * tailleblock, 36 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(41 * tailleblock, 32 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(13 * tailleblock, 19 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(14 * tailleblock, 19 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(7 * tailleblock, 14 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(8 * tailleblock, 13 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setSize(sf::Vector2f(3 * tailleblock, 1 * tailleblock));
	mur1.rect.setPosition(9 * tailleblock, 21 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(31 * tailleblock, 9 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(31 * tailleblock, 10 * tailleblock);
	ligneMur.push_back(mur1);
	mur1.rect.setPosition(26 * tailleblock, 9 * tailleblock);
	ligneMur.push_back(mur1);
	return ligneMur;
}

