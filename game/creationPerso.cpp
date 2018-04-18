#include "creationPerso.h"



creationPerso::creationPerso()
{
}

creationPerso::creationPerso(int largeurFenetreDeJeu, int hauteurFenetreDeJeu, bool Affichagefps,int volume)
{
	lFenetreDeJeu = largeurFenetreDeJeu;
	hFenetreDeJeu = hauteurFenetreDeJeu;
	Affichfps = Affichagefps;
	volumeSon = volume;
}


creationPerso::~creationPerso()
{
	delete boutonGuerrier;
	delete boutonPaladin;
	delete boutonVoleur;
	delete boutonAlchimiste;
	delete boutonRanger;
	delete intro;
	delete boutonForce;
	delete boutonDexterite;
	delete boutonConstitution;
	delete boutonCharisme;
	delete boutonSagesse;
	delete boutonIntelligence;
	delete choixCarac;
	delete boutonSauvegarde1;
	delete boutonSauvegarde2;
	delete boutonSauvegarde3;
}

void creationPerso::start()
{
	database bdd;
	bdd.openDatabase();
	std::vector<sauvegarde*>* touteSauvegarde;
	touteSauvegarde = bdd.getAllSauvegarde();
	sf::Image icon;
	sf::RenderWindow creaWindow(sf::VideoMode(1000, 510), "Creation de personnage");
	if (!icon.loadFromFile("./assets/img/iconPath.jpeg"))
	{
		std::cout << "pas de d'icone ./assets/img/iconPath.jpeg" << std::endl;
	}
	creaWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	chargerBoutonclasses();
	chargerIntro();



	font.loadFromFile("./assets/font/Champ.ttf");

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
			intro->text.setString("Rezza te demanda de le suivre et, d'un claquement de doigts, vous avez disparu dans les ombres.\nLorsque la lumière revint, tu te retrouvas, seul, devant une femme rousse en armure lourde, secondée par un imposant Tiefling.\nCe dernier se présente :\nje suis William prêtre de Gorum, dieux de la guerre et voici ma soeur Emma, seigneur du duché du nord du Mendev.\nCette dernière prit la parole : Alors petit, comme ça on veut devenir un guerrier ? Moi aussi à ton âge j'avais ce rêve - là,\net me voilà à diriger des armées et former de jeunots comme toi ! Tu verras, ce n'est pas une vie facile,\ntu feras couler le sang et perdra beaucoup du tien lors des batailles. En somme il faut que ta force soit sans\négale pour pourfendre tes ennemis et que tu aies la constitution d'un ours des montagnes.\net c'est ainsi que tu t'entrainas pendant les huit années suivantes.");
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
			intro->text.setString("Rezza te demanda de le suivre et d'un claquement de doigts vous avez disparu dans les ombres\n Lorsque la lumière revint, tu te retrouvas, seul, devant un Gnome dont les cheveux étincelaient\nd'un orange pareil à celui d'un crépuscule d'été. D'une voix forte mais amicale, il se présenta :\nJe suis Abroshtor, paladin de Sarenrae, Fleur de l'Aube. J'ai besoin d'un nouvel écuyer, \nsuis-moi, tu vas avoir beaucoup à apprendre.\nLes huit années qui suivirent furent consacrées à ton apprentissage de la magie du soin et du combat au sein de l'Ordre de la Luciole.\nChaque jour tu bombardais Abroshtor de questions auxquelles il ne répondait jamais. \nC'est qu'il était sourd, mais ça, tu l'ignorais encore à cette époque.\nLe jour de ton adoubement, c'est Abroshtor qui présida la cérémonie :\nTe voilà qui deviens Paladin, au service du Bien et de la Lumière\nEn ce monde envahi par des créatures de l'ombre.\nTon rôle sera de mener les Hommes vers le droit chemin et d'éliminer ceux qui les en empêchent.\nTu as été choisi pour ton charisme qui guidera et soignera tes compagnons sur le champ de bataille \net pour ta force qui fera tomber tes ennemis.");
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
			intro->text.setString("Rezza te demanda de le suivre et d'un claquement de doigts vous avez disparu dans les ombres\nLorsque la lumière revint, tu te retrouvas, seul, devant une Demi-Elfe qui apprenait des tours à un jeune ours.\nAh ! Te voilà ! Je m'appelle Eline et je suis druide. Lui, c'est Misha. \nL'ours te lança un regard suspicieux, comme pour te prévenir de ne pas faire de mal à sa maîtresse. \nRezza m'a demandé de te former, continua-t-elle, il nous faut un nouveau ranger pour pister ces monstres qui rodent en nos terres.\nOn oublie souvent à quel point il est essentiel de connaître un territoire avant de vouloir y partir en guerre.\nA l'image de ces braves et rutilants Paladin tu guides les armées vers la victoire.\nMais c'est grâce à ta sagesse et à ta dextérité qui te font toujours trouver les meilleurs chemins. \nEt c'est ainsi que débutèrent tes huit ans d'apprentissage");
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
			intro->text.setString("Rezza te demanda de le suivre et d'un claquement de doigts vous avez disparu dans les ombres\nLorsque la lumière revint, tu te retrouvas, seul, dans une tour nimbée d'ombre. \nLes murs étaient recouverts d'étagères remplies d'imposants grimoires. Rezza te dit: \nil m'a fallu toute une vie pour rassembler ces ouvrages. Tu resteras ici avec moi jusqu'à ce que tu connaisses la plupart de ces écrits. \nC'est très bien de vouloir s'essayer aux sciences et devenir alchimiste mais il te faudra beaucoup étudier avant d'arriver à tes fins !\nJ'espère aussi que tu es bien conscient que ton métier servira plus à créer des armes toujours plus puissantes qu'à trouver \nje ne sais quel remède... Tu verras, ça reste un métier passionnant où l'intelligence est la clé de la réussite!\nIl t'a fallu huit ans d'études avant que Rezza te juge digne de sortir de la tour en tant que son apprenti.");
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
			intro->text.setString("Rezza te demanda de le suivre et d'un claquement de doigts vous avez disparu dans les ombres\n Lorsque la lumière revint, tu te retrouvas, seul, devant un Goblin qui t'accueillit en sautillant.\nJe suis Isotope le Régicide ! Grâce à Isotope, la qualité de vos régicides est au top !!\nTu veux devenir un lame de l'ombre pour éliminer les ennemis de ta cause ?\nNoble intention mais pour y parvenir tu vas devoir te défaire de toute compassion et de ton honneur sinon tu n'y arriveras jamais.\nBien, bien bien, dit-il avant d'imiter un geste d’adoubement avec sa dague. Je te déclare novice de la lame d'ombre !\nIl te faudra une grande dextérité, tu sais, les poches sont de mieux en mieux cousues de nos jours.\nNe néglige cependant pas ta constitution : elle sera ton salut si jamais tu venais à devoir encaisser quelques réprimandes.\nAprès huit ans d'apprentissage, tu pus te complaire enfin dans les basses oeuvres dont tu avais tant rêvé, \nmême si tu n'étais pas aussi au top qu'Isotope.");
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
			choixSauvegarde = true;
			apreschoix = false;
			choixCarac->text.setString("A quel endroit se ferons tes futurs sauvegardes?");
			chargerBoutonSauvegarde2();
			chargerBoutonSauvegarde3();
			chargerBoutonSauvegarde1();
			boutonSauvegarde1->text.setString("1 " + ((*touteSauvegarde)[0]->nomClasse));
			boutonSauvegarde1->text.setFont(font);
			boutonSauvegarde2->text.setString("2 " + ((*touteSauvegarde)[1]->nomClasse));
			boutonSauvegarde2->text.setFont(font);
			boutonSauvegarde3->text.setString("3 " + ((*touteSauvegarde)[2]->nomClasse));
			boutonSauvegarde3->text.setFont(font);
			boutonSauvegarde3->rect.setSize((sf::Vector2f(200, 50)));
			boutonSauvegarde2->rect.setSize((sf::Vector2f(200, 50)));
			boutonSauvegarde1->rect.setSize((sf::Vector2f(200, 50)));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonSauvegarde1->rect.getGlobalBounds().intersects(spriteCurseurCrea.rect.getGlobalBounds()))
			{
				slotSauvegarde = 1;
				i++;

			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonSauvegarde2->rect.getGlobalBounds().intersects(spriteCurseurCrea.rect.getGlobalBounds()))
			{
				slotSauvegarde = 2;
				i++;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && boutonSauvegarde3->rect.getGlobalBounds().intersects(spriteCurseurCrea.rect.getGlobalBounds()))
			{
				slotSauvegarde = 3;
				i++;
			}
		}
		if (i == 4)
		{
			creaWindow.close();
			jeu * partie = new jeu(lFenetreDeJeu, hFenetreDeJeu, Affichfps,volumeSon);
			partie->Startjeu(classe, 99, force, dexterite, constitution, charisme, sagesse, intelligence, 256, 1440, 1, 1, 1, 1, slotSauvegarde);
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
		if (choixSauvegarde)
		{
			creaWindow.draw(boutonSauvegarde1->text);
			creaWindow.draw(boutonSauvegarde2->text);
			creaWindow.draw(boutonSauvegarde3->text);
			creaWindow.draw(choixCarac->text);
		}
		if (!choixSauvegarde)
		{
			creaWindow.draw(intro->text);
		}
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
	boutonAlchimiste->text.setPosition(400, 200);
	boutonAlchimiste->rect.setPosition(400, 200);
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
	intro->text.setString("Galdwell est un jeune garçon de quatorze ans qui a eu l'orphelinat pour unique foyer. Ce Galdwell, c'est toi.\nUn soir, la gardienne de l'orphelinat réveilla tous les enfants et les fit attendre dans un couloir, \nA tour de rôle tu vis tes camarades entrer dans le bureau du directeur\npour en ressortir un court instant plus tard, sans rien dire. Ton tour arriva bien vite.\nFace à toi, tu vis non pas le directeur mais un homme à la peau grise et au cheveux noir ébène. \nIl te lança un regard sévère et te dit :\nJe suis Rezza, Heros de Kenabres, Libérateur de Drezen. Un éclat d'une pierre de garde s'est logé dans ton âme\nIl te donnera accès à une grandeur que nul autre ne pourra jamais atteindre.\nTu es promis à un avenir fabuleux, à toi de choisir la voie pour y parvenir: que souhaites-tu devenir ?");
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

}
void creationPerso::chargerBoutonCaracteristique()
{
	chargerBoutonForce();
	chargerBoutonDexterite();
	chargerBoutonConstitution();
	chargerBoutonSagesse();
	chargerBoutonCharisme();
	chargerBoutonIntelligence();
	chargerChoixCarac();
}
void creationPerso::chargerChoixCarac()
{
	choixCarac->text.setString("Choisis ta meuilleur caracteristique !");
	choixCarac->text.setFillColor(sf::Color::Magenta);
	choixCarac->text.setCharacterSize(20);
	choixCarac->text.setPosition(50, 350);
	choixCarac->rect.setPosition(50, 350);
	choixCarac->rect.setSize((sf::Vector2f(100, 40)));
}
void creationPerso::chargerBoutonSauvegarde1()
{
	boutonSauvegarde1->text.setString("1 ");
	boutonSauvegarde1->text.setFillColor(sf::Color::Red);
	boutonSauvegarde1->text.setCharacterSize(20);
	boutonSauvegarde1->text.setPosition(0, 50);
	boutonSauvegarde1->rect.setPosition(0, 50);
	boutonSauvegarde1->rect.setSize((sf::Vector2f(200, 50)));;
}

void creationPerso::chargerBoutonSauvegarde2()
{
	boutonSauvegarde2->text.setString("2 ");
	boutonSauvegarde2->text.setFillColor(sf::Color::Magenta);
	boutonSauvegarde2->text.setCharacterSize(20);
	boutonSauvegarde2->text.setPosition(0, 110);
	boutonSauvegarde2->rect.setPosition(0, 110);
	boutonSauvegarde2->rect.setSize((sf::Vector2f(200, 50)));;
}

void creationPerso::chargerBoutonSauvegarde3()
{
	boutonSauvegarde3->text.setString("3 ");
	boutonSauvegarde3->text.setFillColor(sf::Color::Cyan);
	boutonSauvegarde3->text.setCharacterSize(20);
	boutonSauvegarde3->text.setPosition(0, 170);
	boutonSauvegarde3->rect.setPosition(0, 170);
	boutonSauvegarde3->rect.setSize((sf::Vector2f(200, 50)));;
}









