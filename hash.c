#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "hash.h"
#include <string.h>
#include "linkedList.h"


unsigned int hash_string(const char *str)
{
    unsigned int hash = 5381; /*fonction de hachage de D.J. Bernstein*/
    const char *s;
    for (s = str; *s; s++)
    hash = ((hash << 5) + hash) + tolower(*s);
    return (hash & 0x7FFFFFFF)%HASH_MAX;
}


/** 
 * @brief Creer une table de hachage
 * @return : la table majeur de la table de hachage créée
 */
cell_t ** create_hash_table()
{
    cell_t** table_majeure = malloc(HASH_MAX * sizeof *table_majeure);

    if (table_majeure != NULL)
    {
        for (int i = 0; i<HASH_MAX; i++)
        {
            LL_init_list(&(table_majeure[i]));
        }
    }

    return table_majeure;
}


/** 
 * @brief Recherche dans une table de hachage
 * @param [in] key: la clé de la valeur à rechercher
 * @return la valeur correspondant à la clé fournie
 */

char * research_in_hash_table(cell_t ** table_majeure,char * key)
{
    unsigned int index = hash_string(key);    
    cell_t * cour = table_majeure[index];

    while (cour != NULL && strcmp(cour->cle,key) != 0)
    {
        cour = cour->next;
    }

    if (cour != NULL)
    {
        return cour->val;
    }

    return NULL;
}

void insert_in_hash_table(cell_t ** table_majeure, char * key, char * value)
{
    unsigned int index = hash_string(key);
    LL_add_cell(LL_search_prev(&(table_majeure[index]),key),LL_create_cell(key,value));
}

void free_hash_table(cell_t** table_majeure)
{
    for (unsigned int i = 0; i < HASH_MAX;i++)
    {
        LL_free_list(&(table_majeure[i]));
    }

    free(table_majeure);

}