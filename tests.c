#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

int main(void){
	/*variables locales main*/
	int run=1;
	long int clock=0;

	InitialiserGraphique();
	CreerFenetre(500,500,700,500);
	head = ChargerSprite(“sprites/head.png”);
	AfficherSprite(head,100,100);
	while(run==1){
		clock=clock+1;	
	};
	FermerGraphique();

	return 0;
}
