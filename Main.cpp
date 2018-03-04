#include <SFML/Graphics.hpp>
#include <iostream>
#include "Database.h"
#include "./sqlite3.h"
#include <iostream>
#include <string>
#include "personnage.h"
#include "mur.h"
#include "combat.h"
#include "paladin.h"
#include <time.h>
#include"jeu.h"

 
using namespace std;

int main()
{
	jeu * partie = new jeu();
	partie->Startjeu();
	delete partie;
	return 0;
}