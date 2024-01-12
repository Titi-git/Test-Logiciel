#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <string.h>

#define N 3
//==================================== Tests Definitions ====================================
void test_initialisation();
void test_placer_pion();
void test_partie_gagnee();

//==================================== Fonctions ====================================
void initialisation(char plateau[N][N]){
	for (int a=0;a<N; a++){
		for (int b=0; b<N; b++){
				plateau[a][b]='_';
			}
		}
	}

//Fonction qui place un pion sur le plateau en fonction d'un signe et d'un buffer de coordonnées
void placer_pion(char plateau[N][N], char signe, char* buffer){
	plateau[buffer[0]-'0'-1][buffer[1]-'0'-1]=signe;
}
//Fonction qui demande au joueur les coordonnées
char* demander_coordonnees(char plateau[N][N]){
	char* buffer = malloc(2*sizeof(char));
	printf("Entrez les coordonnées de votre pion sous la forme \"xy\" : ");
	scanf("%s", buffer);
	if(strlen(buffer)!=2 || (buffer[0]!='1' && buffer[0]!='2' && buffer[0]!='3') || (buffer[1]!='1' && buffer[1]!='2' && buffer[1]!='3') ){
		printf("Erreur de saisie, veuillez recommencer\n");
		demander_coordonnees(plateau);
	}
	else if(plateau[buffer[0]-'0'-1][buffer[1]-'0'-1]!='_'){
		printf("Case déjà prise, veuillez recommencer\n");
		demander_coordonnees(plateau);
	}
	else{
		return buffer;
	}
}

//Fonction qui affiche le plateau
void affichage(char plateau[N][N]){
	printf("\n  ");
	for (int i=0;i<N;i++)printf("%d ",i+1);
	printf("\n");
	for (int i=0;i<N; i++){
		printf("%d ",i+1);
		for (int j=0; j<N; j++)printf("%c ",plateau[i][j]);
		printf("\n");
		}
	printf("\n");
}

int choisir_menu_12q(int* x){
	printf("\n-------Choisissez votre mode de jeu------- \n 1 Partie à deux joueurs \n 2 Partie contre l'ordinateur \n 3 Quitter \n \n Entrez le chiffre souaithé pour continuer \n'");
	scanf("%d",x); 
	if (*x!=1 && *x !=2 && *x != 3){
		printf("\n Erreur de saisie, veuillez recommencer \n");
		choisir_menu_12q(x);
	}
	else{return *x;}
}

void jouer(char plateau[N][N], int joueur,int* c1, int* c2){
	char signe;
	if (joueur==0){signe='X';}
	else{signe='O';}
	placer_pion(plateau,signe,demander_coordonnees(plateau));
	affichage(plateau);
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
//evalue si il existe une occurence de 3 signes identiques en ligne, en colomne ou en diagonal
	//test ligne
	int flag=0;
	for (int i=0;i<N;i++){
		for(int j=0;j<N-1;j++){
			if(plateau[i][j]==plateau[i][j+1] && plateau[i][j]!='_'){
				flag=1;
			}
			else{
				flag=0;
				break;
			}
		}
		if(flag==1){
			if(plateau[i][0]=='X'){printf("\n Le joueur 1 a gagné \n");}
			else{printf("\n Le joueur 2 a gagné \n");}
			return 1;
		}
	}
	//test colonne
	for (int i=0;i<N;i++){
		for(int j=0;j<N-1;j++){
			if(plateau[j][i]==plateau[j+1][i] && plateau[j][i]!='_'){
				flag=1;
			}
			else{
				flag=0;
				break;
			}
		}
		if(flag==1){
			if(plateau[0][i]=='X'){printf("\n Le joueur 1 a gagné \n");}
			else{printf("\n Le joueur 2 a gagné \n");}
			return 1;
		}
	}
	//test diagonale 1
	for (int i=0;i<N-1;i++){
		if(plateau[i][i]==plateau[i+1][i+1] && plateau[i][i]!='_'){
			flag=1;
		}
		else{
			flag=0;
			break;
		}
	}
	if(flag==1){
		if(plateau[0][0]=='X'){printf("\n Le joueur 1 a gagné \n");}
		else{printf("\n Le joueur 2 a gagné \n");}
		return 1;
	}
	//test diagonale 2
	for (int i=0;i<N-1;i++){
		if(plateau[i][N-1-i]==plateau[i+1][N-1-i-1] && plateau[i][N-1-i]!='_'){
			flag=1;
		}
		else{
			flag=0;
			break;
		}
	}
	if(flag==1){
		if(plateau[0][N-1]=='X'){printf("\n Le joueur 1 a gagné \n");}
		else{printf("\n Le joueur 2 a gagné \n");}
		return 1;
	}
	return -1;
}

void joueur_a(char plateau[N][N], int nb_joueurs, int*c1, int*c2){
		int i=0;
		int Njoueur=0;
		int fgh=partie_gagnee(plateau);
		while(fgh!=1){
		if (nb_joueurs==1){
			jouer(plateau,0,c1,c2);
			
			fgh=partie_gagnee(plateau);
			if (fgh!=1){jouer_ordinateur(plateau,c1,c2);
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
    CU_pSuite suite = CU_add_suite("Morpion Test", 0, 0);

    CU_add_test(suite, "test_initialisation", test_initialisation);
	CU_add_test(suite, "test_placer_pion", test_placer_pion);
	CU_add_test(suite, "test_partie_gagnee", test_partie_gagnee);

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
void test_placer_pion(){
	char plateau[N][N];
	initialisation(plateau);
	char signe='X';
	char buffer[2];
	buffer[0]='1';
	buffer[1]='1';
	placer_pion(plateau,signe,buffer);
	CU_ASSERT(plateau[0][0]=='X');
	buffer[0]='2';
	buffer[1]='1';
	placer_pion(plateau,signe,buffer);
	CU_ASSERT(plateau[1][0]=='X');
	buffer[0]='3';
	buffer[1]='2';
	placer_pion(plateau,signe,buffer);
	CU_ASSERT(plateau[2][1]=='X');
	signe='O';
	buffer[1]='3';
	placer_pion(plateau,signe,buffer);
	CU_ASSERT(plateau[2][2]=='O');
}

void test_partie_gagnee(){
	char plateau[N][N];
	initialisation(plateau);
	char signe='X';
	char buffer[2];
	buffer[0]='1';
	buffer[1]='1';
	placer_pion(plateau,signe,buffer);
	buffer[0]='2';
	buffer[1]='1';
	placer_pion(plateau,signe,buffer);
	buffer[0]='3';
	buffer[1]='1';
	placer_pion(plateau,signe,buffer);
	printf("ASSERT 1\n");
	CU_ASSERT(partie_gagnee(plateau)==1);
	printf("FIN ASSERT 1\n");
	initialisation(plateau);
	buffer[0]='1';
	buffer[1]='1';
	placer_pion(plateau,signe,buffer);
	buffer[0]='1';
	buffer[1]='2';
	placer_pion(plateau,signe,buffer);
	buffer[0]='1';
	buffer[1]='3';
	placer_pion(plateau,signe,buffer);
	CU_ASSERT(partie_gagnee(plateau)==1);
	initialisation(plateau);
	buffer[0]='1';
	buffer[1]='1';
	placer_pion(plateau,signe,buffer);
	buffer[0]='2';
	buffer[1]='2';
	placer_pion(plateau,signe,buffer);
	buffer[0]='3';
	buffer[1]='3';
	placer_pion(plateau,signe,buffer);
	CU_ASSERT(partie_gagnee(plateau)==1);
	initialisation(plateau);
	buffer[0]='1';
	buffer[1]='3';
	placer_pion(plateau,signe,buffer);
	buffer[0]='2';
	buffer[1]='2';
	placer_pion(plateau,signe,buffer);
	buffer[0]='3';
	buffer[1]='1';
	placer_pion(plateau,signe,buffer);
	CU_ASSERT(partie_gagnee(plateau)==1);
	initialisation(plateau);
	buffer[0]='1';
	buffer[1]='1';
	placer_pion(plateau,signe,buffer);
	buffer[0]='2';
	buffer[1]='1';
	placer_pion(plateau,signe,buffer);
	buffer[0]='3';
	buffer[1]='2';
	placer_pion(plateau,signe,buffer);
	CU_ASSERT(partie_gagnee(plateau)==-1);
}

