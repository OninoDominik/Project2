#include "combat.h"
#include "personnage.h"
#include "paladin.h"

combat::combat()
{

}

combat::~combat()
{
}
void combat::Choixjoueur(personnage* joueur)
{
	cout << *joueur->choix << endl;
	*joueur->choix = 0;
	do
	{
		cout << *joueur->choix << endl;
		
	} while (*joueur->choix == 0);

}

void combat::startcombat(personnage* ami, personnage* ennemi)
{
	srand((unsigned)time(0));

	while ((*ami->envie) && (*ennemi->envie))
	{
		*ami->choix = 0;
		ami->text.setString(" ");
		ennemi->text.setString(" ");

		int initiativeAmi = ami->Initiative();
		cout << ami->nom << " a une initiative de  " << initiativeAmi << "  " << " pour le tour " << endl;
		int initiativeEnnemi = ennemi->Initiative();
		cout << ennemi->nom << " a une initiative de  " << initiativeEnnemi << "  " << " pour le tour " << endl;
		for (int i = 50; i > 0; i--)
		{
			if (initiativeAmi == i)
			{
				ami->text.setString(" ");
				ennemi->text.setString(" ");

				ami->mouvementCombat = true;
				Choixjoueur(ami);
				cout << "Vos Pvs sont de " << *ami->pvActuel << endl;
				switch (*ami->choix)
				{
				case 1:
					ami->Attaque(*ennemi);
					*ami->choix = 0;
					sf::sleep(sf::seconds(0.75));
					ami->mouvementCombat = false;
					break;
				case 2:
					ami->sesoigne();
					*ami->choix = 0;
					sf::sleep(sf::seconds(0.75));
					cout << "heal:  " << *ami->pvActuel << endl;
					ami->mouvementCombat = false;
					break;
				case 3:
					ami->AttaqueSpecial(*ennemi);
					ami->mouvementCombat = false;
					break;
				default:
					*ami->choix = 0;
					ami->mouvementCombat = false;
					break;
				}
			}
			ami->text.setString(" ");
			ennemi->text.setString(" ");
			if (*ennemi->pvActuel <= 0)
			{
				ami->buffer.loadFromFile("mort.ogg");
				ami->sound.setBuffer(ami->buffer);
				ami->sound.setVolume(50);
				ami->sound.play();

				*ennemi->envie = false;
				cout << *ennemi->envie << endl;
				sf::sleep(sf::seconds(0.75));

				
				*ami->fermeCombatWindow = true;
				break;
			}
			if (*ami->pvActuel <= 0)
			{
				*ami->envie = false;
				cout << *ami->envie << endl;

				*ami->fermeCombatWindow = true;
				break;
			}
			if (initiativeEnnemi == i)
			{
				ennemi->mouvementCombat = true;
				if (!(ennemi->estEtourdit))
				{
					sf::sleep(sf::seconds(0.05));
					if (*ennemi->tempsDot > 0)
					{
						ami->buffer.loadFromFile("saignement.ogg");
						ami->sound.setBuffer(ami->buffer);
						ami->sound.setVolume(50);
						ami->sound.setPlayingOffset(sf::seconds(3));
						ami->sound.play(); 
						sf::sleep(sf::seconds(0.55));
						*ennemi->tempsDot -= 1;
						*ennemi->pvActuel -= *ennemi->valeurDot;
						ami->anim->sang();
						cout << "dot" << *ennemi->valeurDot << "        " << *ennemi->tempsDot << endl;
					}
					ennemi->Attaque(*ami);
				}
				else
				{
					ennemi->estEtourdit = false;
				}
				ennemi->mouvementCombat = false;
			}


		}
	}

}

