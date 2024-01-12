#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "morpion_funcs.h"

#define N 3
#define FIN_PARTIE 1
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
begin:
	printf("Entrez les coordonnées de votre pion sous la forme \"xy\" : ");
	scanf("%s", buffer);
	if(strlen(buffer)!=2 || (buffer[0]!='1' && buffer[0]!='2' && buffer[0]!='3') || (buffer[1]!='1' && buffer[1]!='2' && buffer[1]!='3') ){
		printf("Erreur de saisie, veuillez recommencer\n");
		goto begin;
	}
	else if(plateau[buffer[0]-'0'-1][buffer[1]-'0'-1]!='_'){
		printf("Case déjà prise, veuillez recommencer\n");
		goto begin;
	}
	return buffer;
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

//Fonction qui affiche le menu et renvoie le choix du joueur
int choisir_menu_12q(int* x){
	printf("\n-------Choisissez votre mode de jeu------- \n 1 Partie contre l'ordinateur \n 2 Partie à deux joueurs \n 3 Quitter \n \n Entrez le chiffre souaithé pour continuer \n'");
	scanf("%d",x); 
	if (*x!=1 && *x !=2 && *x != 3){
		printf("\n Erreur de saisie, veuillez recommencer \n");
		choisir_menu_12q(x);
	}
	return *x;
}

//Fonction qui permet de jouer un tour
void jouer(char plateau[N][N], int joueur, int nb_joueurs){
	char signe;
	if(nb_joueurs==1 && joueur==1){
		jouer_ordinateur(plateau);
		printf("\nl'ordinateur a joué: \n'");
		affichage(plateau);
		return;
	}
	if (joueur==0){signe='X';}
	else{signe='O';}
	printf("\n Au tour du joueur %d \n",joueur+1);
	placer_pion(plateau,signe,demander_coordonnees(plateau));
	affichage(plateau);
}

//Fonction qui permet à l'ordinateur de jouer un tour
void jouer_ordinateur(char plateau[N][N]){
	int a=rand()%(N);
	int b=rand()%(N);
	if (plateau[a][b]!='_'){
	jouer_ordinateur(plateau);
	}
	else{
		plateau[a][b]='O';	
	}
}

int test_victoire_ligne(char plateau[N][N]){
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
	return 0;
}

int test_victoire_colonne(char plateau[N][N]){
	int flag=0;
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
	return 0;
}

int test_victoire_diagonales(char plateau[N][N]){
	int flag = 0;
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
	return 0;
}

int partie_gagnee(char plateau[N][N]){
//evalue si il existe une occurence de 3 signes identiques en ligne, en colomne ou en diagonal
	if(test_victoire_ligne(plateau)){return 1;}
	//test colonne
	if(test_victoire_colonne(plateau)){return 1;}
	//test diagonales
	if(test_victoire_diagonales(plateau)){return 1;}
	return -1;
}

//fonction qui permet d'evaluer si il reste de la place sur le plateau
int evaluer(char plateau[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(plateau[i][j]=='_'){
				return -1;
			}
		}
	}
	return 1;
}


int joueur_suivant(int joueur){
	joueur++;
	if(joueur==2){joueur=0;}
	return joueur;
}

void jouer_partie(char plateau[N][N], int nb_joueurs){
	int joueur=0;
	int flagfin=partie_gagnee(plateau);
	while(flagfin!=FIN_PARTIE){
		jouer(plateau,joueur, nb_joueurs);
		flagfin=partie_gagnee(plateau);

		if(flagfin==-1)flagfin=evaluer(plateau);
		
		joueur = joueur_suivant(joueur);
	}
	printf("\n La partie est terminé \n");
}

