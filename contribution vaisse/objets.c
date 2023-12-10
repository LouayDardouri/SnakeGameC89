#include <stdlib.h>
#include <stdio.h>

/*toolbox
{}


*/

void SerpentInit(void){
	struct tete_s{
		int posx;
		int poxy;
		/*sens_x et sens_y sont dans {-1,0,1}. Ils permettent, selon la valeur, 
		d'indiquer les déplacements interdits*/
		int sens_x;
		int sens_y;
	}
	struct queue_s{
		int suiveur;
		struct queue* successeur; 
	}
	typedef struct tete_s tete;
	typedef struct queue_s queue;
}

void SerpentUpdate(tete argtete, queue argqueue,int increment){
	argtete = 
}