#include <stdlib.h>
#include <stdio.h>
#include <graph.h>


short int DansSerpent(bloc * tete, bloc * queue, bloc_static * pomme){
	unsigned short int cellule=0;
	if((tete==NULL)||(queue==NULL)||(pomme==NULL)){
		printf("DEVERROR: DansSerpent: tete or queue or pomme NULL");
		return -1;
	}
	if((tete->pos_x==pomme->pos_x)&&(tete->pos_y==pomme->pos_y)){
		return 1;
	}
	while(!isBlocVide(*(queue+cellule))){
		if(((queue+cellule)->pos_x==pomme->pos_x)&&((queue+cellule)->pos_y==pomme->pos_y)){
			return 1;
		}
		cellule++;
	}
	return 0;
}

unsigned short int CorrectionsPomme(bloc_static * pomme){
	if(pomme==NULL){
		printf("DEVERROR: CorrectionsPomme: pomme NULL");
		return 0;
	}		
	if((pomme->pos_x>=(L_ECRAN-20))){
		pomme->pos_x -= 100;
	}
	if(pomme->pos_y>=(H_ECRAN-40)){
		pomme->pos_y -=100;
	}
	if(pomme->pos_x<20){
		pomme->pos_x += 100;
	}
	if(pomme->pos_y<20){
		pomme->pos_y += 100;
	}
	if((pomme->pos_x%10)!=0){
		pomme->pos_x+=10-((pomme->pos_x)%10);
	}
	if((pomme->pos_y%10)!=0){
		pomme->pos_y+=10-((pomme->pos_y)%10);
	}
	return 1;
}

/*fonction dans laquelle le bug a lieu, lorsqu'elle est appelé depuis la fonction miamMiam.*/
unsigned short int SetPomme(bloc_static * pomme, bloc * tete, bloc * queue, char * frame){
	if((pomme==NULL)||(tete==NULL)||(queue==NULL)){
		printf("DEVERROR: InitPommes: pomme or pommes NULL");
		return 0;
	}
	
	pomme->sprite = ChargerSprite(frame);
	pomme->pos_x = (unsigned int)(rand() % L_ECRAN);
	pomme->pos_y = (unsigned int)(rand() % H_ECRAN);
	printf("pomme : %p %p - \n%u %u --\n", &(pomme->pos_x), &(pomme->pos_y), (pomme->pos_x), (pomme->pos_y));
	
	CorrectionsPomme(pomme);
	while(DansSerpent(tete, queue, pomme)){
		pomme->pos_x = (unsigned int)(rand() % L_ECRAN);
		pomme->pos_y = (unsigned int)(rand() % H_ECRAN);
		CorrectionsPomme(pomme);
	}	
	return 1;
}	

unsigned short int AnimationPommes(bloc_static * pommes, char * frame){
	unsigned short int ind;
	for(ind=0; ind<NB_POMMES; ind++){
		LibererSprite((pommes+ind)->sprite);
		(pommes+ind)->sprite=ChargerSprite(frame);
		AfficherSprite((pommes+ind)->sprite, (pommes+ind)->pos_x, (pommes+ind)->pos_y);
	}
	return 1;
}	