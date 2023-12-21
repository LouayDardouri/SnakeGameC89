#include <stdlib.h>
#include <stdio.h>

/*-----initialisation des objets------*/
typedef struct {
	int sprite;
	unsigned int pos_x;
	unsigned int pos_y;
	/*sens_x et sens_y sont dans {-1,0,1}. Ils permettent, selon la valeur, 
	d'indiquer les dÃ©placements interdits*/
	int sens_x;
	int sens_y;
} bloc;