#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 3
#define FIN_PARTIE 1

//==================================== Fonctions ====================================
void initialisation(char plateau[N][N]);
void placer_pion(char plateau[N][N], char signe, char* buffer);
char* demander_coordonnees(char plateau[N][N]);
void affichage(char plateau[N][N]);
int choisir_menu_12q(int* x);
void jouer(char plateau[N][N], int joueur, int nb_joueurs);
void jouer_ordinateur(char plateau[N][N]);
int partie_gagnee(char plateau[N][N]);
int evaluer(char plateau[N][N]);
void jouer_partie(char plateau[N][N], int nb_joueurs);
int joueur_suivant(int joueur);
int test_victoire_colonne(char plateau[N][N]);
int test_victoire_ligne(char plateau[N][N]);
int test_victoire_diagonales(char plateau[N][N]);


