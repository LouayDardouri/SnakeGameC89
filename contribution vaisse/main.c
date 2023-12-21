#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

int main(void){
	
	/*VARIABLES*/
	unsigned short int out, run=1, verif_pivot=0;
	unsigned int serpent_length = LENGTH_INIT;
	bloc tete = {-1, 300, 200, 1, 0};
	bloc queue = {-1, 300, 200, 1, 0};
	bloc *pivots = (bloc *) calloc(PIVOTLIM, sizeof(bloc)); /*ça m'emmerde de faire ça*/
	short int nb_pivots=0;
	int affichage_cycle;
	
	/*printf("%lu\n",sizeof(bloc));*/
	
	/*PROG*/
	InitialiserGraphique();
	CreerFenetre(400,300,L_ECRAN,H_ECRAN);
	
	tete.sprite = ChargerSprite("sprites/head.png"); 
	queue.sprite = ChargerSprite("sprites/follower.png");
	ChargerImageFond("sprites/follower.png");
	
	out = InitSerpent(&tete, &queue, serpent_length);
	if (out==0){
		printf("CRITICALERROR: echec à l'initialisation. abort.\n");
		return EXIT_FAILURE;
	} 
	
	while(run==1){
		if((affichage_cycle%70000)==0){
			/*ajoute un pivot dans le tableaux des pivots*/
			if(verif_pivot==1){
				AddPivot(pivots, nb_pivots, tete);
				verif_pivot=0;
			}
			/*déplace le serpent d'une case*/
			out = DeplacerSerpent(&tete, &queue, pivots, 10, nb_pivots);
			if(out==0){
				printf("CRITICALERROR: deplacement echue. abort\n");
				return EXIT_FAILURE;
			}
		}
		
		
		/*GESTIONNAIRE DE TOUCHES*/
		/*un syst?me pour substituer tous les if si possible*/
		if(ToucheEnAttente()){
			int touche=Touche();
			if(touche==XK_Escape){
				run=0;
			}
			/*la variable verif_pivot permet de ne pas surcharger la liste des pivots*/
			if(verif_pivot==0){
				if((touche==XK_Right)&&(tete.sens_x==0)){
					tete.sens_x=1;
					tete.sens_y=0;
					verif_pivot=1;
				}
				if((touche==XK_Left)&&(tete.sens_x==0)){
					tete.sens_x=-1;
					tete.sens_y=0;
					verif_pivot=1;
				}
				if((touche==XK_Up)&&(tete.sens_y==0)){
					tete.sens_x=0;
					tete.sens_y=-1;
					verif_pivot=1;
				}
				if((touche==XK_Down)&&(tete.sens_y==0)){
					tete.sens_x=0;
					tete.sens_y=1;
					verif_pivot=1;
				}
			}
		}
		
		
	affichage_cycle++;
	}
	FermerGraphique();
	
	return EXIT_SUCCESS;
}