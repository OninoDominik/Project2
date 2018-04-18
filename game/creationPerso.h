#pragma once
#include "../personnage/personnage.h"
#include <SFML/Graphics.hpp>
#include "jeu.h"
/**
* \file          creationPerso.h
* \author    Dominik Grobecker
* \version   1.0
* \date       04 april 2018
* \brief      permet au joueur de creer un personnage
*
* \details     permet au joueur de creer un personnage grace a un questionnaire
*
*/

/*! \class creationPerso
* \brief       permet au joueur de creer un personnage
*
* \details    permet au joueur de creer un personnage grace a un questionnaire
*
*/
class creationPerso
{
public:

	/**
	* \brief       constructeur
	*
	* Constructeur de la classe creationPerso
	*
	*/
	creationPerso();

	

	/**
	* \brief       constructeur
	*
	* Constructeur de la classe creationPerso surcharge
	*
	* \param largeurFenetreDeJeu : stocke la taille de la largeur de la fentere principale
	* \param hauteurFenetreDeJeu : stocke la taille de la hauteur de la fentere principale
	* \param Affichagefps : stocke l'information si l'utilisateur souhaite l'affichage des frames par seconde
	* \param volume : stocke le volume du jeu
	*/
	creationPerso(int largeurFenetreDeJeu, int hauteurFenetreDeJeu, bool Affichagefps, int volume);
	/**
	* \brief       destructeur
	*
	* Destructeur de la classe Database
	*
	*
	*/
	~creationPerso();

	chose * boutonGuerrier = new chose();   /*!< pointeur d'un objet chose boutonGuerrier*/
	chose * boutonPaladin = new chose();   /*!< pointeur d'un objet chose boutonPaladin*/
	chose * boutonVoleur = new chose();    /*!< pointeur d'un objet chose boutonVoleur*/
	chose * boutonAlchimiste = new chose();/*!< pointeur d'un objet chose boutonAlchimiste*/
	chose * boutonRanger = new chose();/*!< pointeur d'un objet chose boutonRanger*/
	chose * intro = new chose();/*!< pointeur d'un objet chose intro*/
	chose * boutonForce = new chose();/*!< pointeur d'un objet chose boutonForce*/
	chose * boutonDexterite = new chose();/*!< pointeur d'un objet chose boutonDexterite*/
	chose * boutonConstitution = new chose();/*!< pointeur d'un objet chose boutonConstitution*/
	chose * boutonCharisme = new chose();/*!< pointeur d'un objet chose boutonCharisme*/
	chose * boutonSagesse = new chose();/*!< pointeur d'un objet chose boutonSagesse*/
	chose * boutonIntelligence = new chose();/*!< pointeur d'un objet chose boutonIntelligence*/
	chose * choixCarac = new chose();/*!< pointeur d'un objet chose choixCarac*/
	chose * boutonSauvegarde1 = new chose();/*!< pointeur d'un objet chose boutonSauvegarde1*/
	chose * boutonSauvegarde2 = new chose();/*!< pointeur d'un objet chose boutonSauvegarde2*/
	chose * boutonSauvegarde3 = new chose();/*!< pointeur d'un objet chose boutonSauvegarde3*/
	chose spriteCurseurCrea; /*!< objet chose boutonGuerrier*/

	sf::Font font;    /*!< objet Font font*/
	int lFenetreDeJeu; /*!< stocke la taille de la largeur de la fentere principale */
	int hFenetreDeJeu; /*!< stocke la taille de la hauteur de la fentere principale */
	bool Affichfps;  /*!< affiche ou non les frames par seconde */
	int volumeSon; /*!< affiche ou non les frames par seconde */
	int classe;   /*!< code chiffre de la classe */
	int force = 10; /*!< force du personnage initialise a 10 */
	int constitution = 10;/*!< constitution du personnage initialisee a 10 */
	int dexterite = 10; /*!< dexterite du personnage initialisee a 10 */
	int sagesse = 10;  /*!< sagesse du personnage initialisee a 10 */
	int charisme = 10; /*!< charisme du personnage initialise a 10 */
	int intelligence = 10; /*!< intelligence du personnage initialisee a 10 */
	int slotSauvegarde = 1;  /*!< slot de sauvegarde de la partie*/

	bool apreschoix = false;  /*!<choix de classe effectue ou non*/
	bool avantChoix = true; /*!< choix de classe non effectue ou effectue*/
	bool choixForce = true; /*!< bouton force a ete clique */
	bool choixConstitution = true; /*!< bouton constitution a ete clique */
	bool choixDexterite = true;  /*!< bouton dexterite a ete clique */
	bool choixSagesse = true; /*!< bouton sagesse a ete clique */
	bool choixCharisme = true; /*!< bouton charisme a ete clique */
	bool choixIntelligence = true; /*!< bouton intelligence a ete clique */
	bool choixSauvegarde = false; /*!< choix du slot de la sauvegarde a ete fait */

	/**
	* \brief      lance le questionnaire
	*
	*  lance un questionnaire afin de stocker les valeurs choisies par le joueur
	*
	*/
	void start();
	/**
	* \brief      cree un bouton guerrier
	*
	*   transforme le pointeur d'objet chose boutonGuerrier en zone cliquable avec le texte "guerrier" affiche
	*
	*/
	void chargerBoutonGuerrier();

	/**
	* \brief     cree un bouton paladin
	*
	*    transforme le pointeur d'objet chose boutonPaladin en zone cliquable avec le texte "paladin" affiche
	*
	*/
	void chargerBoutonPaladin();

	/**
	* \brief      cree un bouton ranger
	*
	*    transforme le pointeur d'objet chose boutonRanger en zone cliquable avec le texte "ranger" affiche
	*
	*/
	void chargerBoutonRanger();

	/**
	* \brief      cree un bouton alchimiste

	*    transforme le pointeur d'objet chose boutonAlchimiste en zone cliquable avec le texte "alchimiste" affiche
	*
	*/
	void chargerBoutonAlchimiste();

	/**
	* \brief      creer un bouton voleur
	*
	*    transforme le pointeur d'objet chose boutonVoleur en zone cliquable avec le texte "voleur" affiche
	*
	*/
	void chargerBoutonVoleur();

	/**
	* \brief      genere tous les boutons de metier
	*
	*    genere tous les boutons  guerrier paladin voleur alchimiste voleur
	*
	*/
	void chargerBoutonclasses();

	/**
	* \brief      genere une zone de texte
	*
	*   genere une zone de texte  avec l'histoire du personnage
	*
	*/
	void chargerIntro();

	/**
	* \brief      cree un bouton force
	*
	*    transforme le pointeur d'objet chose boutonForce en zone cliquable avec le texte "force" affiche
	*
	*/
	void chargerBoutonForce();

	/**
	* \brief      cree un bouton Dexterite
	*    transforme le pointeur d'objet chose boutonDexterite en zone cliquable avec le texte "Dexterite" affiche
	*
	*/
	void chargerBoutonDexterite();

	/**
	* \brief      cree un bouton Constitution
	*    transforme le pointeur d'objet chose boutonConstitution en zone cliquable avec le texte "Constitution" affiche
	*
	*/
	void chargerBoutonConstitution();

	/**
	* \brief      cree un bouton Sagesse
	*    transforme le pointeur d'objet chose boutonSagesse en zone cliquable avec le texte "Sagesse" affiche
	*
	*/
	void chargerBoutonSagesse();

	/**
	* \brief      cree un bouton Charisme
	*    transforme le pointeur d'objet chose boutonCharisme en zone cliquable avec le texte "Charisme" affiche
	*
	*/
	void chargerBoutonCharisme();

	/**
	* \brief      cree un bouton Intelligence
	*    transforme le pointeur d'objet chose boutonIntelligence en zone cliquable avec le texte "Intelligence" affiche
	*
	*/
	void chargerBoutonIntelligence();

	/**
	* \brief      genere tous les boutons de metier
	*
	*    genere tous les boutons  force constitution dexterite charisme sagesse intelligence
	*
	*/
	void chargerBoutonCaracteristique();

	/**
	* \brief      genere une zone de texte
	*
	*   genere une zone de texte  qui demande le choix d'une caracteristique
	*
	*/
	void chargerChoixCarac();

	/**
	* \brief      creer un bouton Sauvegarde1
	*    transforme le pointeur d'objet chose boutonSauvegarde1 en zone cliquable avec le nom de la classe de la derniere sauvegarde sur le slot 1
	*
	*/
	void chargerBoutonSauvegarde1();

	/**
	* \brief      creer un bouton Sauvegarde2
	*    transforme le pointeur d'objet chose boutonSauvegarde1 en zone cliquable avec le nom de la classe de la derniere sauvegarde sur le slot 2
	*
	*/
	void chargerBoutonSauvegarde2();

	/**
	* \brief      creer un bouton Sauvegarde3
	*    transforme le pointeur d'objet chose boutonSauvegarde1 en zone cliquable avec le nom de la classe de la derniere sauvegarde sur le slot 3
	*
	*/
	void chargerBoutonSauvegarde3();

};

