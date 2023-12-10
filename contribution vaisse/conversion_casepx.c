#include <stdlib.h>
#include <stdio.h>

int CenterCase(unsigned short int cellule, char axe, int dimaxe){
	/*axe pour connaître la case ciblée, au lieu de la représenter par un couple de valeur*/
	unsigned short int px1case=10;
	if((axe!='x') && (axe!='y')){
		printf("DEVERROR: conversion_casepx: axe!=40 && axe!=60");
		return EXIT_FAILURE;
	}	
	if((cellule>=axe)||(cellule<0)){
		printf("DEVERROR: conversion_casepx: case>=axe or case<=0");
		return EXIT_FAILURE;
	}

	return ((int) cellule)*(px1case)+(px1case-dimaxe);
}

/*
tester
int main(void){
	unsigned short int test1=3, test2='y';
	printf("%d\n", CenterCase(test1,test2,7));
	return EXIT_SUCCESS; 
}*/