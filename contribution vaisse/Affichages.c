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

unsigned short int InitMur(bloc *mur){
	unsigned short int ind;
	if(mur==NULL){
		return 0;
	}
	/*remplissage bordures verticales*/
	for(ind=0;ind<=20;ind++){
		AfficherSprite(mur->sprite, 0, 20*ind);
		AfficherSprite(mur->sprite, L_ECRAN-20, 20*ind);
	}
	/*afficher bordures horizontales*/
	for(ind=0; ind<=30; ind++){
		AfficherSprite(mur->sprite,ind*20,0);
		AfficherSprite(mur->sprite,ind*20,H_ECRAN-20);
		AfficherSprite(mur->sprite,ind*20,H_ECRAN-40);
	}
	return 1;
}

unsigned short int DeplacerSerpent(bloc *tete, bloc *queue, bloc * pivots, unsigned short int increment, short int nb_pivots){
	tete->pos_x+=increment*(tete->sens_x);
	tete->pos_y+=increment*(tete->sens_y);
	AfficherSprite(tete->sprite, tete->pos_x, tete->pos_y);
	/*
	printf("%u %u %d %d \n\n", pivots->pos_x, pivots->pos_y, pivots->sens_x, pivots->sens_y);*/
	if((queue->pos_x==pivots->pos_x)&&(queue->pos_y==pivots->pos_y)){
		queue->sens_x=pivots->sens_x;
		queue->sens_y=pivots->sens_y;
		DelPivot(pivots, nb_pivots);
	}
	queue->pos_x+=increment*queue->sens_x;
	queue->pos_y+=increment*queue->sens_y;
	AfficherSprite(queue->sprite, queue->pos_x, queue->pos_y);
	
	return 1;
}

