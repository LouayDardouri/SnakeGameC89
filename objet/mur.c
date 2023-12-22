#include <stdlib.h>
#include <stdio.h>

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