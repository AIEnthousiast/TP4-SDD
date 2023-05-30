#ifndef HASH_C
#define HASH_C


#define HASH_MAX 29 

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

char * research_in_hash_table();



#endif