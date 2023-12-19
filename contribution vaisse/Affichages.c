#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

/*FONCTIONS AFFICHAGES*/
unsigned short int InitSerpent(bloc *tete, bloc *queue, unsigned int init_length){
	unsigned short int ind;
	if((tete==NULL)||(queue==NULL)){
		printf("DEVERROR: serpent vide\n");
		return 0;
	}
	for(ind=0; ind<init_length; ind++){
		AfficherSprite(tete->sprite, tete->pos_x, tete->pos_y);
		tete->pos_x+=10;
	}
	AfficherSprite(queue->sprite, queue->pos_x-10, queue->pos_y-10);
	return 1;
}