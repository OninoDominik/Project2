#include "combat.h"
#include "personnage.h"
combat::combat() 
{

}

combat::~combat()
{
}

void combat::startcombat(personnage* ami, personnage* ennemi)
{
	while ((*ami->envie ) && (*ennemi->envie ))
	{
		int initiativeAmi = ami->Initiative();
		cout << ami->nom << " a une initiative de  " << initiativeAmi <<"  "  <<" pour le tour "<< endl;

		

		int initiativeEnnemi = ennemi->Initiative();
		cout << ennemi->nom << " a une initiative de  " << initiativeEnnemi<< "  " <<" pour le tour "<< endl;
		system("Pause");
		for (int i = 0; i < 50; i++)
		{
			if (initiativeAmi == i)
			{
				ami->Attaque(*ennemi);
				cout << "aaaaaaaaaaaaaaaaaaaa" << endl;
			}
			if (initiativeEnnemi == i)
			{
				ennemi->Attaque(*ami);
				cout << "oooooooooooooooo" << endl;
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