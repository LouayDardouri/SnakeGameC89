#include <stdlib.h>
#include <stdio.h>

/*FONCTIONS CALCULS ET ADRESSAGES*/
unsigned short int isBlocVide(bloc arg){
	/*
	printf("%u %u %d %d \n\n", arg.pos_x, arg.pos_y, arg.sens_x, arg.sens_y);*/
	/*nécessité de cette fonction pour palier à l'erreur du invalid operands to binary*/
	if((arg.sprite==0)&&(arg.pos_x==0)&&(arg.pos_y==0)&&(arg.sens_x==0)&&(arg.sens_y==0)){
		return 1;
	}
	return 0;
}

short int AddPivot(bloc * pivots, short int nb_pivots, bloc add){
	unsigned short int cellule=0;
	printf("flag\n");
	while((isBlocVide(*(pivots+cellule))!=1)&&(cellule<=PIVOTLIM)){
		/*printf("%hu\n", isBlocVide(*(pivots+cellule)));
		printf("%hu\n",cellule);*/
		cellule++;
	}
	if(cellule>PIVOTLIM){
		printf("DEVERROR: AddPivot: nb_pivots>PIVOTLIM\n");
		return -1;
	}
	
	(pivots+cellule)->pos_x=add.pos_x;
	(pivots+cellule)->pos_y=add.pos_y;
	(pivots+cellule)->sens_x=add.sens_x;
	(pivots+cellule)->sens_y=add.sens_y;
	(pivots+cellule)->sprite=-1;
	
	nb_pivots++;
	return nb_pivots;
}