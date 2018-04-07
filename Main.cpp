#include <SFML/Graphics.hpp>
#include <iostream>
#include "./database/Database.h"
#include "./sqlite3.h"
#include <iostream>
#include <string>
#include "./personnage/personnage.h"
#include "./game/mur.h"
#include "./gestionCombat/combat.h"
#include <time.h>
#include"./game/jeu.h"
#include "./init/menu.h"

 
using namespace std;

int main()
{
	menu * menuPartie = new menu();
	menuPartie->menuStart();
	delete menuPartie;
	return 0;
}