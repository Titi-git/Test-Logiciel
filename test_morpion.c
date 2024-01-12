#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "morpion_funcs.h"

#define N 3
#define FIN_PARTIE 1

//==================================== Tests Definitions ====================================
void test_initialisation();
void test_placer_pion();
void test_partie_gagnee();
void test_joueur_suivant();

//==================================== Main ====================================

int main(){
	srand(time(NULL));

	CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Morpion Test", 0, 0);

    CU_add_test(suite, "test_initialisation", test_initialisation);
	CU_add_test(suite, "test_placer_pion", test_placer_pion);
	CU_add_test(suite, "test_partie_gagnee", test_partie_gagnee);
	CU_add_test(suite, "test_joueur_suivant", test_joueur_suivant);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
	
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

void test_joueur_suivant(){
	int joueur=1;
	CU_ASSERT(joueur_suivant(joueur)==0);
	joueur=0;
	CU_ASSERT(joueur_suivant(joueur)==1);
}
