/**
 * @file linkedList_main.c
 * @brief Programme pour les tests de fonctions de gestion de liste chainee
 * ATTENTION : Il faut creer autant de tests que les cas d'execution pour chaque fonction a tester
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "teZZt.h"

BEGIN_TEST_GROUP(linkedList)

/*
TEST(monom_degree_cmp) {
	monom_t v1 = {5.11, 7};
	monom_t v2 = {3., 5};
	monom_t v3 = {5.25, 7};

	printf("\nComparaison des monomes : \n");
	CHECK( monom_degree_cmp(&v1, &v2) > 0 );
	CHECK( monom_degree_cmp(&v2, &v1) < 0 );
	CHECK( monom_degree_cmp(&v1, &v3) == 0 );
}
*/

/*
TEST(monom_save2file) {
	monom_t v = {5., 7};

	// creation du flux de texte => buffer
	char buffer[1024];
	FILE * file = fmemopen(buffer, 1024, "w");
	REQUIRE ( NULL != file);

	monom_save2file(file, &v);

	fclose(file);

	CHECK( 0 == strcmp(buffer, "5.000 7\n") ); 
}
*/


TEST(LL_init_list) {
	cell_t *list; 

	printf("\nInitialization of the linked list : \n");
	LL_init_list(&list);

	REQUIRE ( list == NULL );
}


TEST(LL_create_cell) { // test de creation de cellule
	cell_t *new = NULL;
	char cle[] = "test1";
	char val[] = "test2";

	printf("\nCreate a new cell : \n");
	new = LL_create_cell(cle, val);
	REQUIRE ( NULL != new );
	CHECK ( NULL == new->next );

	char buffer[1024];
	FILE * file = fmemopen(buffer, 1024, "w");
	REQUIRE ( NULL != file);

	//monom_save2file(file, &(new->val));
	fprintf(file,"%s;%s\n",new->cle, new->val);
	fclose(file);
	CHECK( 0 == strcmp(buffer, "test1;test2\n") ); 

	LL_free_list(&new);
}



// test d'insertion de cellule - liste a une cellule
TEST(LL_add_cell) { 
	cell_t *list = NULL;
	cell_t *new = NULL;
	char cle[] = "test1";
	char val[] = "test2";

	printf("\nAdd a cell in a linked list : \n");

	new = LL_create_cell(cle, val);
	REQUIRE ( new != NULL );

	LL_add_cell(&list, new);
	CHECK( list == new );  // L'insertion en tête s'est-elle bien passée?

	char buffer[1024];
	FILE * file = fmemopen(buffer, 1024, "w");
	REQUIRE ( NULL != file);

	LL_save_list_toFile(list, file);
	fclose(file);
	CHECK( 0 == strcmp(buffer, "test1;test2\n") );

	LL_free_list(&list); // liberer la liste

}



// test d'insertion de cellule - liste a n cellules
TEST(LL_add_celln) { 

	cell_t *list = NULL;
	char cle[] = "test1";
	char val[] = "test2";

	cell_t *cell1 = LL_create_cell(cle, val);

	char cle2[] = "aa";
	char val2[] = "bbb";
	cell_t *cell2 = LL_create_cell(cle2, val2);

	char cle3[] = "ccc";
	char val3[] = "dd";
	cell_t *cell3 = LL_create_cell(cle3, val3);

	char cle4[] = "bonjour";
	char val4[] = "hello";
	cell_t *cell4 = LL_create_cell(cle4, val4);

	REQUIRE ( cell1 != NULL );

	// Ajout successif de cellules dans l'ordre indiqué 
	LL_add_cell(&list, cell1);
	LL_add_cell(&list, cell2);
	LL_add_cell(&list, cell3);
	LL_add_cell(&list, cell4);


	char buffer[1024];
	FILE * file = fmemopen(buffer, 1024, "w");
	REQUIRE ( NULL != file);

	LL_save_list_toFile(list, file);
	fclose(file);

	//printf("%s\n", buffer);

	CHECK( 0 == strcmp(buffer, "bonjour;hello\nccc;dd\naa;bbb\ntest1;test2\n") ); 

	LL_free_list(&list); // liberer la liste
}
/*
// test pour la creation d'un polynome a partir d'un fichier - exemple
TEST(LL_create_list_fromFileName0) {
	cell_t *list;

	printf("\nCreate a linked list from file name0: \n");

	char buffer[1024];
	FILE * file = fmemopen(buffer, 1024, "w");
	REQUIRE ( NULL != file );

	LL_create_list_fromFileName(&list, "notExist.txt");
	CHECK( NULL == list );

}



//test pour la creation d'un polynome a partir d'un fichier
TEST(LL_create_list_fromFileName) {
	cell_t *list;

	LL_create_list_fromFileName(&list, "toto.txt");

	char buffer[1024];
	FILE * file = fmemopen(buffer, 1024, "w");
	REQUIRE ( NULL != file);

	LL_save_list_toFile(list, file, monom_save2file);
	fclose(file);
	CHECK( 0 == strcmp(buffer, "5.678 3\n2.400 5\n5.000 8\n2.405 10\n") ); 

	LL_free_list(&list); // liberer la liste
}



TEST(LL_print_list) { // test pour l'affichage d'un polynome sur un flux de sortie
	cell_t *list;

	LL_create_list_fromFileName(&list, "toto.txt");

	char buffer[1024];
	FILE * file = fmemopen(buffer, 1024, "w");
	REQUIRE ( NULL != file);

	LL_print_list(file, list, monom_save2file);
	fclose(file);
	CHECK( 0 == strcmp(buffer, "5.678 3\n2.400 5\n5.000 8\n2.405 10\n") ); 

	LL_free_list(&list); // liberer la liste
}
*/


TEST(LL_free_list) { // test de la liberation de liste

	cell_t *list = NULL;
	char cle[] = "test1";
	char val[] = "test2";

	cell_t *cell1 = LL_create_cell(cle, val);

	char cle2[] = "aa";
	char val2[] = "bbb";
	cell_t *cell2 = LL_create_cell(cle2, val2);

	char cle3[] = "ccc";
	char val3[] = "dd";
	cell_t *cell3 = LL_create_cell(cle3, val3);

	char cle4[] = "bonjour";
	char val4[] = "hello";
	cell_t *cell4 = LL_create_cell(cle4, val4);

	REQUIRE ( cell1 != NULL );

	// Ajout successif de cellules dans l'ordre indiqué 
	LL_add_cell(&list, cell1);
	LL_add_cell(&list, cell2);
	LL_add_cell(&list, cell3);
	LL_add_cell(&list, cell4);

	LL_free_list(&list); // liberer la liste
	CHECK( list == NULL);
}


END_TEST_GROUP(linkedList)

int main(void) {
	RUN_TEST_GROUP(linkedList);
	return EXIT_SUCCESS;
}
