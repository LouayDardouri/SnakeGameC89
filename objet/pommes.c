#include <stdlib.h>
#include <stdio.h>
#include <graph.h>


unsigned short int DansSerpent(bloc * tete, bloc * queue, bloc * pommes){
	unsigned short int ind;
	if((tete==NULL)||(queue==NULL)||(pommes==NULL)){
		printf("DEVERROR: DansSerpent: tete or queue or pommes NULL");
		return -1;
	}
}

unsigned short int InitPommes(bloc * pommes, bloc * tete, bloc * queue){
	unsigned short int ind;
	if((pommes==NULL)||(tete==NULL)||(queue==NULL)){
		printf("DEVERROR: InitPommes: pomme or pommes NULL");
		return 0;
	}
	for(ind=0; ind<NB_POMMES; ind++){	
		(pommes+ind)->pos_x = (unsigned int)(rand() % L_ECRAN );
		(pommes+ind)->pos_y = (unsigned int)(rand()% H_ECRAN);
		
		/*corrections*/
		if(((pommes+ind)->pos_x%10)!=0){
			(pommes+ind)->pos_x+=10-(pommes+ind)->pos_x;
		}
		if(((pommes+ind)->pos_y%10)!=0){
			(pommes+ind)->pos_y+=10-(pommes+ind)->pos_y;
		}
			
   	}
	return 1;
}	

unsigned short int AfficherPommes(bloc * pommes, char * frame){
	unsigned short int ind;
	if((pommes==NULL)||(frame==NULL)){
		printf("DEVERROR : AfficherPommes: pommes or frame NULL");
		return 0;
	}
	printf("flag\n");
	for(ind=0; ind<NB_POMMES; ind++){
		(pommes+ind)->sprite=ChargerSprite(frame);
		printf("%d %s\n", (pommes+ind)->sprite, frame);
		AfficherSprite((pommes+ind)->sprite, (pommes+ind)->pos_x, (pommes+ind)->pos_y);
	}
	return 1;
}