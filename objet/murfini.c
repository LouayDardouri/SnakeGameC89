#include <stdlib.h>
#include <stdio.h>

unsigned short int InitMur(int mur){
	unsigned short int ind;
	if(mur==-1){
		return 0;
	}
	/*remplissage bordures verticales*/
	for(ind=0;ind<=20;ind++){
		AfficherSprite(mur, 0, 20*ind);
		AfficherSprite(mur, L_ECRAN-20, 20*ind);
	}
	/*afficher bordures horizontales*/
	for(ind=0; ind<=30; ind++){
		AfficherSprite(mur,ind*20,0);
		AfficherSprite(mur,ind*20,H_ECRAN-20);
		AfficherSprite(mur,ind*20,H_ECRAN-40);
	}
	return 1;
}