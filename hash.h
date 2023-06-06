#ifndef HASH_C
#define HASH_C


#define HASH_MAX 29 

#include "linkedList.h"



/** 
 * @brief Fonction de hachage
 * @param [in] str : chaine à hacher
 * @return le hash de la chaîne d'entrée
 */

unsigned int hash_string(const char *str);


/** 
 * @brief Creer une table de hachage
 * @return : la table majeur de la table de hachage créée
 */
cell_t ** create_hash_table();


/** 
 * @brief Recherche dans une table de hachage
 * @param [in] key: la clé de la valeur à rechercher
 * @return la valeur correspondant à la clé fournie
 */

char * research_in_hash_table(cell_t ** table_majeure,char * key);


/** 
 * @brief Insertion dans une table de hachage
 * @param [in] table_majeure: la table majeure de la table de hachage
 * @param [in] key: la clé de la valeur à insérer
 * @param [in] value: la valeur de l'élément à insérer
 */

void insert_in_hash_table(cell_t ** table_majeure, char * key, char * value,int nbOcc);


void load_dictionnary(cell_t** table_majeure, char * filename);

void translate(cell_t ** table_majeure, char * phrase);


/** 
 * @brief Libération d'une table de hachage
 * @param [in] table_majeure: la table majeure de la table de hachage
 */
void free_hash_table(cell_t** table_majeure);




#endif