#include <stdio.h>
#include<stdlib.h>
#include<graph.h>
int main(){
	unsigned short int run=1;
	InitialiserGraphique();
	CreerFenetre(500,500,700,500);
	DessinerPixel(4000,6000);
	for (int i =0; i<=500; i+=10){
		DessinerSegment(0,i,700,i);
		DessinerSegment(i,0,i,500);
	}
	DessinerSegment(0,10,700,10);
	DessinerSegment(0,20,700,20);
	DessinerSegment(0,30,700,30);
	DessinerSegment(0,40,700,40);
	DessinerSegment(0,50,700,50);
	DessinerSegment(0,60,700,60);
	DessinerSegment(0,70,700,70);
	DessinerSegment(0,80,700,80);
	DessinerSegment(0,90,700,90);

	CouleurParNom("red"); /*pas à préciser le type pour l'appel d'une fonction*/
	while(run==1){
		
		run=1;
	}
	FermerGraphique();
}
