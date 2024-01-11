#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <string.h>

#define N 3
//==================================== Tests Definitions ====================================
void test_initialisation();

//==================================== Fonctions ====================================
void initialisation(char plateau[N][N]){
	int a;
	int b;
	for (a=0;a<N; a++){
		for (b=0; b<N; b++){
				plateau[a][b]='_';
			}
		}
	}

void affichage(char plateau[N][N]){
	int i;
	int j;
	printf("\n");
	printf("  ");
	for (i=0;i<N;i++){
	printf("%d ",i+1);
	}
	printf("\n");
	for (i=0;i<N; i++){
		printf("%d ",i+1);
		for (j=0; j<N; j++){
				printf("%c ",plateau[i][j]);
			}
		printf("\n");
		}
	printf("\n");
}

int choisir_menu_12q(int* x){
	printf("\n-------Choisissez votre mode de jeu------- \n 1 Partie à deux joueurs \n 2 Partie contre l'ordinateur \n 3 Quitter \n \n Entrez le chiffre souaithé pour continuer \n'");
	scanf("%d",x); 
	if (*x==1){
	return 1;
	}
	if (*x==2){
	return 2;
	}
	else{
	return 0;
	}
}

void jouer(char plateau[N][N], int joueur,int* c1, int* c2){
	printf("\n Saissisez la coordonnée ligne\n");
	scanf("%d",c1);
	printf("\n Saissisez la coordonnée colonne\n");
	scanf("%d",c2);
	if (plateau[*c1-1][*c2-1]!='_'){
	printf("\nCase déjà prise, choissisez en une autre \n");
	jouer(plateau,joueur,c1,c2);
	}
	else{
		if (joueur ==1){plateau[*c1-1][*c2-1]='O';}
		else{plateau[*c1-1][*c2-1]='X';}	
		affichage(plateau);
	}
}


void jouer_ordinateur(char plateau[N][N], int* c1, int* c2){
	int a=rand()%(N);
	int b=rand()%(N);
	if (plateau[a][b]!='_'){
	jouer_ordinateur(plateau,c1,c2);
	}
	else{
		plateau[a][b]='O';	
	}
}

int partie_gagnee(char plateau[N][N]){
	int i;
	int j;
	int g=0;
	for(i=0;i<N;i++){
		if(plateau[i][i]=='X'){
			g=1;
		}
		else{g=0;
			i=N;}
	}
	if(g==1){printf("\nJoueur 1 a gagné\n");return g;}
	for(i=0;i<N;i++){
		if(plateau[i][i]=='O'){
			g=1;
		}
		else{g=0;
			i=N;}
	}
	if(g==1){printf("\nJoueur 2 a gagné\n");return g;}
	for(i=0;i<N;i++){
		if(plateau[(N-1)-i][i]=='X'){
			g=1;
		}
		else{g=0;
			i=N;}
	}
	if(g==1){printf("\nJoueur 1 a gagné\n");return g;}
	for(i=0;i<N;i++){
		if(plateau[N-1-i][i]=='O'){
			g=1;
		}
		else{g=0;
			i=N;}
	}
	if(g==1){printf("\nJoueur 2 a gagné\n");return g;}

	for (i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(plateau[i][j]=='O'){g=1;}
			else{g=0;
				j=N;}
		}
		if(g==1){printf("\nJoueur 2 a gagné\n");return g;}
	}

	for (i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(plateau[i][j]=='X'){g=1;}
			else{g=0;
				j=N;}
		}
		if(g==1){printf("\nJoueur 1 a gagné\n");return g;}
	}

	for (j=0; j<N; j++){
		for(i=0; i<N; i++){
			if(plateau[i][j]=='X'){g=1;}
			else{g=0;
				i=N;}
		}
		if(g==1){return g;}
		else{g=0;}
	}
	for (j=0; j<N; j++){
		for(i=0; i<N; i++){
			if(plateau[i][j]=='O'){g=1;}
			else{g=0;
				i=N;}
		}
		if(g==1){return g;}
		else{g=0;}
	}
	return g;
}

void joueur_a(char plateau[N][N], int nb_joueurs, int*c1, int*c2){
		int i=0;
		int Njoueur=0;
		int fgh=partie_gagnee(plateau);
		while(fgh!=1){
		if (nb_joueurs==1){
			jouer(plateau,0,c1,c2);
			
			if (partie_gagnee(plateau)!=1){jouer_ordinateur(plateau,c1,c2);
			printf("\nl'ordinateur a joué: \n'");
			affichage(plateau);}
			}
		else{
			fgh=partie_gagnee(plateau);
			jouer(plateau,Njoueur,c1,c2);
			}
			if(Njoueur==0){Njoueur=1;}
			else{Njoueur=0;}
			fgh=partie_gagnee(plateau);
			int a;
			int b;
			int kgb=0;
			int fin=0;
			while(kgb!=1){
				if(fin==1){kgb=1; fgh=1;}
				for (a=0;a<N; a++){
					for (b=0; b<N; b++){
							if(plateau[a][b]=='_'){kgb=1;}
							else{fin=1;
							}
						}
					}
				}
			}
		
		printf("\n La partie est terminé \n");
}

int main(){
	srand(time(NULL));
	char plateau[N][N];
	initialisation(plateau);

	CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("maxi_test", 0, 0);

    CU_add_test(suite, "maxi_fun", test_initialisation);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

	int x;
	int c1;
	int c2;
	int p=choisir_menu_12q(&x);
	if(p==1){
			joueur_a(plateau,2,&c1,&c2);
	}
	else{
		if(p==2){
				joueur_a(plateau,1,&c1,&c2);
		}
		else{printf("\n Merci d'avoir participé \n");}
		printf("\n");
	}
	
	return 0;
}

//==================================== Tests ====================================

void test_initialisation(){
	char plateau[N][N];
	initialisation(plateau);
    int i;
    int j;
    for (i=0;i<N;i++){
        for (j=0; j<N; j++){
            CU_ASSERT(plateau[i][j]=='_');
        }
    }
}
