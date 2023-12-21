#include <stdlib.h>
#include <stdio.h>

typedef struct {
	unsigned int pos_x;
	unsigned int pos_y;
	/*sens_x et sens_y sont dans {-1,0,1}. Ils permettent, selon la valeur, 
	d'indiquer les dÃ©placements interdits*/
	unsigned short int sens_x;
	unsigned short int sens_y;
} bloc;

int main(int argc, char **argv){
	/*variables*/
	int test = -1;
	bloc *pivots = (bloc *) calloc(5, sizeof(bloc));
	unsigned int ind;
	/*test pour tab vide*/
	for(ind=0; ind<5;ind++){
		printf("%u%u%hu%hu\n",(pivots+ind)->pos_x,(pivots+ind)->pos_y,(pivots+ind)->sens_x,(pivots+ind)->sens_y);
	}
	printf("\n");
	
	/*test pour remplissage*/
	for(ind=0; ind<5; ind++){
		(pivots+ind)->pos_x=ind;
		(pivots+ind)->pos_y=ind;
		(pivots+ind)->sens_x=ind;
		(pivots+ind)->sens_y=ind;
		printf("%u%u%hu%hu\n",(pivots+ind)->pos_x,(pivots+ind)->pos_y,(pivots+ind)->sens_x,(pivots+ind)->sens_y);
	}	
	printf("\n");
	
	/*test pour vidange*/
	for(ind=0; ind<5; ind++){
		(pivots+ind)->pos_x=0;
		(pivots+ind)->pos_y=0;
		(pivots+ind)->sens_x=0;
		(pivots+ind)->sens_y=0;
		printf("%u%u%hu%hu\n",(pivots+ind)->pos_x,(pivots+ind)->pos_y,(pivots+ind)->sens_x,(pivots+ind)->sens_y);
	}
	printf("\n");
	
	printf("%d\n", test);
	
	return EXIT_SUCCESS;
}