#include <stdio.h>
#include<stdlib.h>
#include<graph.h>
int main(void){
  /*unsigned short int run=1;*/
	InitialiserGraphique();
      
	CreerFenetre(500,500,700,500);
	ChargerImageFond("imageg.png");
	/*	DessinerPixel(4000,6000);
	for (int i =0; i<=500; i+=10){
		DessinerSegment(0,i,700,i);
		DessinerSegment(i,0,i,500);
		}

	CouleurParNom("red");
	while(run==1){
		
		run=1;
		}*/
	getchar();
	FermerGraphique();

	return EXIT_SUCCESS;
}

