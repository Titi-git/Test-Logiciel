#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "morpion_funcs.h"

#define N 3

//==================================== Main ====================================

int main(){
	srand(time(NULL));
	char plateau[N][N];
	initialisation(plateau);
	int x;
	int p=choisir_menu_12q(&x);
	if(p==1 || p==2){
		jouer_partie(plateau,p);
	}
	else{
		printf("\n Merci d'avoir participé \n");
	}
	
	return 0;
}


