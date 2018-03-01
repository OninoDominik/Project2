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
	do
	{

	} while (*joueur->choix==0);
}
void combat::startcombat(personnage* ami, personnage* ennemi)
{
	while ((*ami->envie ) && (*ennemi->envie ))
	{
		int initiativeAmi = ami->Initiative();
		cout << ami->nom << " a une initiative de  " << initiativeAmi <<"  "  <<" pour le tour "<< endl;

		int initiativeEnnemi = ennemi->Initiative();
		cout << ennemi->nom << " a une initiative de  " << initiativeEnnemi<< "  " <<" pour le tour "<< endl;
		for (int i = 50; i > 0; i--)
		{
			if (initiativeAmi == i)
			{
				Choixjoueur(ami);
				cout << "Vos Pvs sont de " << *ami->pvActuel << endl;
				switch (*ami->choix)
				{
				case 1:
					ami->Attaque(*ennemi);
					*ami->choix = 0;
					break;
				case 2:
					ami->sesoigne();
					*ami->choix = 0;
					cout << "Apres les soins vos Pvs sont de " << *ami->pvActuel<< endl;
					break;
				default:
					*ami->choix = 0;
					break;
				}
			}
			if (initiativeEnnemi == i)
			{
				ennemi->Attaque(*ami);
			}
			
			if (*ennemi->pvActuel <= 0 )
			{
				*ennemi->envie = false;
				cout << *ennemi->envie << endl;
				break;
			}
			if (*ami->pvActuel <= 0)
			{
				*ami->envie = false;
				cout << *ami->envie << endl;
				break;
			}
		}
		
		
		

	}
}