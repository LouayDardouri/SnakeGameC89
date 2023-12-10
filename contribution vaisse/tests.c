#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

int main(void){
	/*variables locales main*/
	int run=1, tete, regle, increment=100;
	long int horloge=0;

	InitialiserGraphique();
	CreerFenetre(500,500,700,500);
	tete = ChargerSprite("sprites/head.png");
	/*regle = ChargerSprite("sprites/head.png");
	printf("%d %d\n", tete, regle);*/
	
	/*ECRAN 2 VIDE SUPER IMPORTANT*/
	ChoisirEcran(0);

	while(run==1){
		if((horloge%1000000)==0){
			increment++;
			EffacerEcran(CouleurParNom("white")); /*vider écran 0*/
			AfficherSprite(tete, 100, increment);
		}
		horloge+=1;
	};
	FermerGraphique();

	return EXIT_SUCCESS;
}
