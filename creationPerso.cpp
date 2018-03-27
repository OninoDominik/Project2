#include "creationPerso.h"



creationPerso::creationPerso(int largeurFenetreDeJeu, int hauteurFenetreDeJeu, bool Affichagefps)
{
	lFenetreDeJeu = largeurFenetreDeJeu;
	hFenetreDeJeu = hauteurFenetreDeJeu;
	Affichfps = Affichagefps;
}


creationPerso::~creationPerso()
{
}

void creationPerso::start()
{
	sf::RenderWindow creaWindow(sf::VideoMode(1000, 510), "Creation de personnage");
	chargerBoutonclasses();
	chargerIntro();



	font.loadFromFile("Champ.ttf");

	chargerBoutonForce();
	chargerBoutonDexterite();
	chargerBoutonConstitution();
	chargerBoutonIntelligence();
	chargerBoutonCharisme();
	chargerBoutonSagesse();
	chargerChoixCarac();

	boutonVoleur->text.setFont(font);
	boutonGuerrier->text.setFont(font);
	boutonPaladin->text.setFont(font);
	boutonRanger->text.setFont(font);
	boutonAlchimiste->text.setFont(font);
	intro->text.setFont(font);
	boutonForce->text.setFont(font);
	boutonDexterite->text.setFont(font);
	boutonCharisme->text.setFont(font);
	boutonConstitution->text.setFont(font);
	boutonIntelligence->text.setFont(font);
	boutonSagesse->text.setFont(font);

	choixCarac->text.setFont(font);
	int i = 0;

	while (creaWindow.isOpen())
	{
		sf::Event CreaEvent;
		while (creaWindow.pollEvent(CreaEvent))
		{
			if (CreaEvent.type == sf::Event::Closed)
				creaWindow.close();
			if (CreaEvent.type == sf::Event::KeyPressed && CreaEvent.key.code == sf::Keyboard::Escape)
				creaWindow.close();
		}

		spriteCurseurCrea.rect.setPosition((sf::Vector2f)sf::Mouse::getPosition(creaWindow));
		spriteCurseurCrea.rect.setSize(sf::Vector2f(4, 4));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonGuerrier->rect.getGlobalBounds().intersects(spriteCurseurCrea.rect.getGlobalBounds()))
		{
			classe = 1;
			avantChoix = false;
			intro->text.setString("Rezza te demanda de le suivre et d'un claquement de doigts vous avez disparu dans les ombres\nTu reapparu seul devant une femme rousse seconder par un tiefling de 2 metres de haut et celui-ci dit:\n je suis William prêtre du dieux de la guerre gorum Et voici ma soeur Emma seigneur du duché nord du mendev.\n  Alors petit, comme ça on veut devenir un guerrier  ? Moi aussi à ton âge j’avais ce rêve - là, et me voilà\nà diriger des armées et former des jeunots comme toi !Tu verras, ce n’est pas une vie facile, tu feras\ncouler le sang et perdra beaucoup du tien lors des batailles.En somme il faut que ta force soit sans\négale pour pourfendre tes ennemis et que tu aies la constitution d’un ours des montagnes.\n et c'est ainsi que tu t'entraina pendant les 8 prochaines années.");
			apreschoix = true;
			boutonVoleur->rect.setSize((sf::Vector2f(0, 0)));
			boutonGuerrier->rect.setSize((sf::Vector2f(0, 0)));
			boutonPaladin->rect.setSize((sf::Vector2f(0, 0)));
			boutonRanger->rect.setSize((sf::Vector2f(0, 0)));
			boutonAlchimiste->rect.setSize((sf::Vector2f(0, 0)));

		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonPaladin->rect.getGlobalBounds().intersects(spriteCurseurCrea.rect.getGlobalBounds()))
		{
			classe = 2;
			avantChoix = false;
			intro->text.setString("Rezza te demanda de le suivre et d'un claquement de doigts vous avez disparu dans les ombres\nTu reapparu seul devant un Gnome dont les cheveux brillait d'un orange que tu avais déjà vu lors de certain crepuscule d'été et celui-ci dit:\n Je suis Abroshtor paladin de Sarenrae. J'ai besoin d'un nouvel ecuyer, suis-moi, tu vas avoir beaucoup a apprendre.\nTu passa 8 ans a apprendre la magie du soins et le combat dans l'ordre de la luciole.\nLe jour de ton adoubement c'est Abroshtor qui preside la céremonie: Te voilà qui devient Paladin, au service du Bien et de la Lumière\nEn ce monde envahi par des créatures de l’ombre.\nTon rôle sera de mener les Hommes vers le droit chemin et d’éliminer ceux qui les en empêchent.\nTu as été choisi pour ton charisme qui guidera et soignera tes compagnons sur le champ de bataille \net pour ta force qui fera tomber tes ennemis.");
			apreschoix = true;
			boutonVoleur->rect.setSize((sf::Vector2f(0, 0)));
			boutonGuerrier->rect.setSize((sf::Vector2f(0, 0)));
			boutonPaladin->rect.setSize((sf::Vector2f(0, 0)));
			boutonRanger->rect.setSize((sf::Vector2f(0, 0)));
			boutonAlchimiste->rect.setSize((sf::Vector2f(0, 0)));
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonRanger->rect.getGlobalBounds().intersects(spriteCurseurCrea.rect.getGlobalBounds()))
		{
			classe = 3;
			avantChoix = false;
			intro->text.setString("Rezza te demanda de le suivre et d'un claquement de doigts vous avez disparu dans les ombres\nTu reapparu seul devant une demi elfe blonde et son ours de compagnie\nAh !Te voilà ! je suis Eline ,druide, Rezza m'a demandé de te former.\n Il nous fallait un nouveau ranger pour pister ces monstres qui rodent en nos terres.\nL’on oublie souvent à quel point il est essentiel de connaître un territoire avant de vouloir y partir en guerre.\nA l’image de ces braves et rutilants Paladin tu guides les armées vers la victoire.\n Mais c'est grâce à ta sagesse et ta dextérité qui te font toujours trouver les meilleurs chemins. Tu appris avec elle pendant huits années");
			apreschoix = true;
			boutonVoleur->rect.setSize((sf::Vector2f(0, 0)));
			boutonGuerrier->rect.setSize((sf::Vector2f(0, 0)));
			boutonPaladin->rect.setSize((sf::Vector2f(0, 0)));
			boutonRanger->rect.setSize((sf::Vector2f(0, 0)));
			boutonAlchimiste->rect.setSize((sf::Vector2f(0, 0)));
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonAlchimiste->rect.getGlobalBounds().intersects(spriteCurseurCrea.rect.getGlobalBounds()))
		{
			classe = 4;
			avantChoix = false;
			intro->text.setString("Rezza te demanda de le suivre et d'un claquement de doigts vous avez disparu dans les ombres\nTu reapparu avec rezza un dans une tour faites d'ombres rempli de livre. Rezza dit: il m'a fallu une vie pour collectionner tout ceci\n tu restera ici avec moi jusqu'a connaite la plupart de ces écrits.\nTu veux t'essayer aux sciences et devenir alchimiste, très bien !\nJ’espère que tu es bien conscient que ton métier servira plus à créer des armes toujours plus puissantes qu’à trouver je ne sais quel remède…\nOn ne sait jamais les miracles arrive vite.\n Tu verras, ça reste un métier passionnant où l’intelligence est la clé de la réussite!\nIl ta fallu 8 ans d'etudes avant que rezza te juge digne de sortir de la tour en tant que son apprenti.");
			apreschoix = true;
			boutonVoleur->rect.setSize((sf::Vector2f(0, 0)));
			boutonGuerrier->rect.setSize((sf::Vector2f(0, 0)));
			boutonPaladin->rect.setSize((sf::Vector2f(0, 0)));
			boutonRanger->rect.setSize((sf::Vector2f(0, 0)));
			boutonAlchimiste->rect.setSize((sf::Vector2f(0, 0)));
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonVoleur->rect.getGlobalBounds().intersects(spriteCurseurCrea.rect.getGlobalBounds()))
		{
			classe = 5;
			avantChoix = false;
			intro->text.setString("Rezza te demanda de le suivre et d'un claquement de doigts vous avez disparu dans les ombres\nTu reapparu devant un Goblin, Je suis Isotope le regicide, grace a Isotop, la qualité de vos regicides sont au top !!\nTu veux devenir un lame de l'ombre pour eliminer les ennemis de ta cause \nNoble intention mais pour y parvenir tu avs devoir anneantir tout once de compassion ou de noblesse sinon tu n'y arrivera jamais.\nJe te declare novice Voleur de la lame d'ombre\nIl te faudra une grande dextérité, les poches sont de mieux en mieux cousues de nos jours.\nNe néglige pas ta forme physique cependant ta constitution sera ton salut si jamais tu venais à devoir encaisser quelques réprimandes.\nIl ta fallu 8 ans pour apprendre quelques techniques interdites.");
			apreschoix = true;
			boutonVoleur->rect.setSize((sf::Vector2f(0, 0)));
			boutonGuerrier->rect.setSize((sf::Vector2f(0, 0)));
			boutonPaladin->rect.setSize((sf::Vector2f(0, 0)));
			boutonRanger->rect.setSize((sf::Vector2f(0, 0)));
			boutonAlchimiste->rect.setSize((sf::Vector2f(0, 0)));
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonForce->rect.getGlobalBounds().intersects(spriteCurseurCrea.rect.getGlobalBounds()))
		{

			switch (i)
			{
			case 0:
				sf::sleep(sf::milliseconds(100));
				force = 18;
				cout << "force" << force;
				i++;
				boutonForce->rect.setSize((sf::Vector2f(0, 0)));
				boutonForce->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			case 1:
				sf::sleep(sf::milliseconds(100));
				force = 16;
				i++;
				boutonForce->rect.setSize((sf::Vector2f(0, 0)));
				boutonForce->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			case 2:
				sf::sleep(sf::milliseconds(100));
				force = 6;
				i++;
				boutonForce->rect.setSize((sf::Vector2f(0, 0)));
				boutonForce->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			default:
				break;
			}

		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonDexterite->rect.getGlobalBounds().intersects(spriteCurseurCrea.rect.getGlobalBounds()))
		{

			switch (i)
			{
			case 0:
				sf::sleep(sf::milliseconds(100));
				dexterite = 18;
				i++;
				boutonDexterite->rect.setSize((sf::Vector2f(0, 0)));
				boutonDexterite->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			case 1:
				sf::sleep(sf::milliseconds(100));
				dexterite = 16;
				i++;
				boutonDexterite->rect.setSize((sf::Vector2f(0, 0)));
				boutonDexterite->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			case 2:
				sf::sleep(sf::milliseconds(100));
				dexterite = 6;
				i++;
				boutonDexterite->rect.setSize((sf::Vector2f(0, 0)));
				boutonDexterite->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			default:
				break;
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonConstitution->rect.getGlobalBounds().intersects(spriteCurseurCrea.rect.getGlobalBounds()))
		{

			switch (i)
			{
			case 0:
				sf::sleep(sf::milliseconds(100));
				constitution = 18;
				i++;
				boutonConstitution->rect.setSize((sf::Vector2f(0, 0)));
				boutonConstitution->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			case 1:
				sf::sleep(sf::milliseconds(100));
				constitution = 16;
				i++;
				boutonConstitution->rect.setSize((sf::Vector2f(0, 0)));
				boutonConstitution->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			case 2:
				sf::sleep(sf::milliseconds(100));
				constitution = 6;
				i++;
				boutonConstitution->rect.setSize((sf::Vector2f(0, 0)));
				boutonConstitution->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			default:
				break;
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonSagesse->rect.getGlobalBounds().intersects(spriteCurseurCrea.rect.getGlobalBounds()))
		{

			switch (i)
			{
			case 0:
				sf::sleep(sf::milliseconds(100));
				sagesse = 18;
				i++;
				boutonSagesse->rect.setSize((sf::Vector2f(0, 0)));
				boutonSagesse->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			case 1:
				sf::sleep(sf::milliseconds(100));
				sagesse = 16;
				i++;
				boutonSagesse->rect.setSize((sf::Vector2f(0, 0)));
				boutonSagesse->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			case 2:
				sf::sleep(sf::milliseconds(100));
				sagesse = 6;
				i++;
				boutonSagesse->rect.setSize((sf::Vector2f(0, 0)));
				boutonSagesse->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			default:
				break;
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonSagesse->rect.getGlobalBounds().intersects(spriteCurseurCrea.rect.getGlobalBounds()))
		{

			switch (i)
			{
			case 0:
				sf::sleep(sf::milliseconds(100));
				sagesse = 18;
				i++;
				boutonSagesse->rect.setSize((sf::Vector2f(0, 0)));
				boutonSagesse->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			case 1:
				sf::sleep(sf::milliseconds(100));
				sagesse = 16;
				i++;
				boutonSagesse->rect.setSize((sf::Vector2f(0, 0)));
				boutonSagesse->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			case 2:
				sf::sleep(sf::milliseconds(100));
				sagesse = 6;
				i++;
				boutonSagesse->rect.setSize((sf::Vector2f(0, 0)));
				boutonSagesse->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			default:
				break;
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonCharisme->rect.getGlobalBounds().intersects(spriteCurseurCrea.rect.getGlobalBounds()))
		{

			switch (i)
			{
			case 0:
				sf::sleep(sf::milliseconds(100));
				charisme = 18;
				i++;
				boutonCharisme->rect.setSize((sf::Vector2f(0, 0)));
				boutonCharisme->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			case 1:
				sf::sleep(sf::milliseconds(100));
				charisme = 16;
				i++;
				boutonCharisme->rect.setSize((sf::Vector2f(0, 0)));
				boutonCharisme->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			case 2:
				sf::sleep(sf::milliseconds(100));
				charisme = 6;
				i++;
				boutonCharisme->rect.setSize((sf::Vector2f(0, 0)));
				boutonCharisme->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			default:
				break;
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonIntelligence->rect.getGlobalBounds().intersects(spriteCurseurCrea.rect.getGlobalBounds()))
		{

			switch (i)
			{
			case 0:
				sf::sleep(sf::milliseconds(100));
				intelligence = 18;
				i++;
				boutonIntelligence->rect.setSize((sf::Vector2f(0, 0)));
				boutonIntelligence->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			case 1:
				sf::sleep(sf::milliseconds(100));
				intelligence = 16;
				i++;
				boutonIntelligence->rect.setSize((sf::Vector2f(0, 0)));
				boutonIntelligence->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			case 2:
				sf::sleep(sf::milliseconds(100));
				intelligence = 6;
				i++;
				boutonIntelligence->rect.setSize((sf::Vector2f(0, 0)));
				boutonIntelligence->text.setString("");
				sf::sleep(sf::milliseconds(100));
				break;
			default:
				break;
			}
		}


		if (i == 1)
		{
			choixCarac->text.setString("Choisis ta 2eme meuilleur caracteristique !");

		}
		if (i == 2)
		{
			choixCarac->text.setString("Choisis ta plus mauvaise caracteristique !");
		}
		if (i == 3)
		{
			creaWindow.close();
			jeu * partie = new jeu(lFenetreDeJeu, hFenetreDeJeu, Affichfps);
			partie->Startjeu(classe,99 ,force, dexterite, constitution, charisme, sagesse, intelligence, 256,1440 ,1,1,1,1);
			delete partie;
		}

		creaWindow.clear();
		if (avantChoix)
		{
			creaWindow.draw(boutonGuerrier->text);
			creaWindow.draw(boutonPaladin->text);
			creaWindow.draw(boutonRanger->text);
			creaWindow.draw(boutonAlchimiste->text);
			creaWindow.draw(boutonVoleur->text);
		}
		if (apreschoix)
		{
			if (choixForce)
			{
				creaWindow.draw(boutonForce->text);
			}
			if (choixConstitution)
			{
				creaWindow.draw(boutonConstitution->text);
			}
			if (choixDexterite)
			{
				creaWindow.draw(boutonDexterite->text);
			}
			if (choixSagesse)
			{
				creaWindow.draw(boutonSagesse->text);
			}
			if (choixCharisme)
			{
				creaWindow.draw(boutonCharisme->text);
			}
			if (choixIntelligence)
			{
				creaWindow.draw(boutonIntelligence->text);
			}

			creaWindow.draw(choixCarac->text);
		}


		creaWindow.draw(intro->text);
		creaWindow.display();
	}
}


void creationPerso::chargerBoutonGuerrier()
{
	boutonGuerrier->text.setString("Guerrier");
	boutonGuerrier->text.setFillColor(sf::Color::Red);
	boutonGuerrier->text.setCharacterSize(20);
	boutonGuerrier->text.setPosition(110, 200);
	boutonGuerrier->rect.setPosition(110, 200);
	boutonGuerrier->rect.setSize((sf::Vector2f(100, 40)));
}
void creationPerso::chargerBoutonPaladin()
{
	boutonPaladin->text.setString("Paladin");
	boutonPaladin->text.setFillColor(sf::Color::Yellow);
	boutonPaladin->text.setCharacterSize(20);
	boutonPaladin->text.setPosition(210, 200);
	boutonPaladin->rect.setPosition(210, 200);
	boutonPaladin->rect.setSize((sf::Vector2f(100, 40)));

}

void creationPerso::chargerBoutonRanger()
{
	boutonRanger->text.setString("Ranger");
	boutonRanger->text.setFillColor(sf::Color::Green);
	boutonRanger->text.setCharacterSize(20);
	boutonRanger->text.setPosition(310, 200);
	boutonRanger->rect.setPosition(310, 200);
	boutonRanger->rect.setSize((sf::Vector2f(100, 40)));
}
void creationPerso::chargerBoutonAlchimiste()
{
	boutonAlchimiste->text.setString("Alchimiste");
	boutonAlchimiste->text.setFillColor(sf::Color::Magenta);
	boutonAlchimiste->text.setCharacterSize(20);
	boutonAlchimiste->text.setPosition(410, 200);
	boutonAlchimiste->rect.setPosition(410, 200);
	boutonAlchimiste->rect.setSize((sf::Vector2f(100, 40)));
}
void creationPerso::chargerBoutonVoleur()
{
	boutonVoleur->text.setString("Assassin");
	boutonVoleur->text.setFillColor(sf::Color::Cyan);
	boutonVoleur->text.setCharacterSize(20);
	boutonVoleur->text.setPosition(510, 200);
	boutonVoleur->rect.setPosition(510, 200);
	boutonVoleur->rect.setSize((sf::Vector2f(100, 40)));
}
void creationPerso::chargerBoutonclasses()
{
	chargerBoutonAlchimiste();
	chargerBoutonVoleur();
	chargerBoutonRanger();
	chargerBoutonPaladin();
	chargerBoutonGuerrier();
}
void creationPerso::chargerIntro()
{
	intro->text.setString("Tu as 15 ans, ton nom est Gallwell.\nTu n'as connus que ton orphelinat comme foyer.\nUn soir, la gardienne de l'orphelinat reveille tout les enfants et les fait attendre dans un couloir,\nA tour de rôle vous rentrer un par un dans le bureau du directeur.\nles enfants ne restent que quelque secondes dans le bureau pour ressortir sans rien dire, ton tour arrive tu entre\nTu vois un homme à la peaux grise et au cheveux noirs ebene, il te regarde de ces yeux severes.\nIl dit :Je suis Rezza, Heros de Kenabres, Liberateur de Drezen; Un eclat d'une pierre de garde s'est loger dans ton âme\nCelle ci te donnera acces a une grandeur que les autres ne peuvent entrevoir.\nJe suis ici pour te donner un choix,que souhaite tu devenir ?");
	intro->text.setFillColor(sf::Color::White);
	intro->text.setCharacterSize(16);
	intro->text.setPosition(50, 10);
	intro->rect.setPosition(50, 10);
	intro->rect.setSize((sf::Vector2f(0, 0)));
}
void creationPerso::chargerBoutonForce()
{
	boutonForce->text.setString("Force");
	boutonForce->text.setFillColor(sf::Color::White);
	boutonForce->text.setCharacterSize(20);
	boutonForce->text.setPosition(10, 400);
	boutonForce->rect.setPosition(10, 400);
	boutonForce->rect.setSize((sf::Vector2f(100, 40)));
}
void creationPerso::chargerBoutonDexterite()
{
	boutonDexterite->text.setString("Dexterite");
	boutonDexterite->text.setFillColor(sf::Color::White);
	boutonDexterite->text.setCharacterSize(20);
	boutonDexterite->text.setPosition(110, 400);
	boutonDexterite->rect.setPosition(110, 400);
	boutonDexterite->rect.setSize((sf::Vector2f(100, 40)));
}
void creationPerso::chargerBoutonConstitution()
{
	boutonConstitution->text.setString("Constitution");
	boutonConstitution->text.setFillColor(sf::Color::White);
	boutonConstitution->text.setCharacterSize(20);
	boutonConstitution->text.setPosition(210, 400);
	boutonConstitution->rect.setPosition(210, 400);
	boutonConstitution->rect.setSize((sf::Vector2f(100, 40)));
}
void creationPerso::chargerBoutonSagesse()
{
	boutonSagesse->text.setString("Sagesse");
	boutonSagesse->text.setFillColor(sf::Color::White);
	boutonSagesse->text.setCharacterSize(20);
	boutonSagesse->text.setPosition(350, 400);
	boutonSagesse->rect.setPosition(350, 400);
	boutonSagesse->rect.setSize((sf::Vector2f(100, 40)));
}
void creationPerso::chargerBoutonCharisme()
{
	boutonCharisme->text.setString("Charisme");
	boutonCharisme->text.setFillColor(sf::Color::White);
	boutonCharisme->text.setCharacterSize(20);
	boutonCharisme->text.setPosition(450, 400);
	boutonCharisme->rect.setPosition(450, 400);
	boutonCharisme->rect.setSize((sf::Vector2f(100, 40)));
}
void creationPerso::chargerBoutonIntelligence()
{
	boutonIntelligence->text.setString("Intelligence");
	boutonIntelligence->text.setFillColor(sf::Color::White);
	boutonIntelligence->text.setCharacterSize(20);
	boutonIntelligence->text.setPosition(550, 400);
	boutonIntelligence->rect.setPosition(550, 400);
	boutonIntelligence->rect.setSize((sf::Vector2f(100, 40)));

}void creationPerso::chargerBoutonCaracteristique()
{
	chargerBoutonForce();
	chargerBoutonDexterite();
	chargerBoutonConstitution();
	chargerBoutonSagesse();
	chargerBoutonCharisme();
	chargerBoutonIntelligence();
	chargerBoutonCaracteristique();
	chargerChoixCarac();
}
void creationPerso::chargerChoixCarac()
{
	choixCarac->text.setString("Choisis ta meuilleur caracteristique !");
	choixCarac->text.setFillColor(sf::Color::Magenta);
	choixCarac->text.setCharacterSize(20);
	choixCarac->text.setPosition(50, 250);
	choixCarac->rect.setPosition(50, 250);
	choixCarac->rect.setSize((sf::Vector2f(100, 40)));
}









