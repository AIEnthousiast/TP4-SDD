/**
 * @file linkedList.c
 * @brief Implementation file of linked list module
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

/** Example
 * @fn void LL_init_list(cell_t **adrHeadPt)
 * @brief Initialize a void list
 * @param [in, out] adrHeadPt address of head pointer of the list 
 */
void LL_init_list(cell_t **adrHeadPt)
{
    *adrHeadPt = NULL;
}


/** 
 * @brief Create a new cell for linked list from its data 
 * @param [in] xxx address of the data
 * @return address of the new cell
 */
cell_t * LL_create_cell(char * cle, char * val)
{
    cell_t * newCell;

    newCell = (cell_t*) malloc(sizeof(cell_t));

    if (newCell != NULL)
    {
        newCell->cle = (char *) malloc(sizeof(char)*(strlen(cle) + 1));
        newCell->val = (char *) malloc(sizeof(char)*(strlen(val) + 1));
        strcpy(newCell->cle, cle);
        strcpy(newCell->val, val);
        newCell->next = NULL;
    }
    
    return newCell;
}


/** 
 * @brief Insert a cell into a linked list at the given position
 * @param [in, out]  xxx address of previous pointer of the cell
 * @param [in]  xxx address of the cell to be added to the linked list
 */
void LL_add_cell(cell_t** previous, cell_t* newCell)
{
    newCell->next = *previous;
    *previous = newCell;

}


/** 
 * @brief Create a linked list from a file
 * @param [in, out] xxx address of head pointer of a linked list
 * @param [in] xxx name of a file containing the data for a linked list
 * @param xxx fonction pointer for comparison of two cell's value
 * @return head pointer of the linked list
 */
/*
cell_t** LL_create_list_fromFileName(cell_t** head, char* filename)
{   
    int stop = !EOF;
    
    monom_t monom;
    cell_t* cell;
    FILE * file;
    LL_init_list(head);

    file = fopen(filename,"r");

    if (file != NULL)
    {
    
        while ((stop = fscanf(file,"%lf %d",&monom.coef,&monom.degree)) != EOF)
        {

            cell = LL_create_cell(&monom);
            LL_add_cell(LL_search_prev(head, cell, monom_degree_cmp), cell);
        }

        fclose(file);
    }
    return head;
}
*/


/** 
 * @brief Search a value in a linked list, and return the address of the previous pointer
 * @param [in] xxx address of the head pointer
 * @param [in] xxx address of the value to search
 * @param  xxx fonction pointer for comparison of two values
 * @return the address of the previous pointer
 */
cell_t** LL_search_prev(cell_t** head, char * key)
{

    cell_t** previous = head;
    cell_t* current;
    
    current = *head;

    while (current != NULL && strcmp(current->cle,key) < 0 )
    {
        previous = &(current->next);  //move the previous pointer inside of the data structure
        current = current->next;
    }

    return previous;
}


/** 
 * @brief Print/Write the linked list on/to an output stream
 * @param [in] xxx file pointer of an output stream
 * @param [in] xxx head pointer of a linked list
 */
void LL_print_list(FILE* file, cell_t* head)
{
    cell_t* current = head;

    while (current != NULL)
    {
        fprintf(file, "%s;%s\n",current->cle, current->val);
        current = current->next;
    }
}

/**
 *  @brief Save a linked list into an ouptput stream
 *  @param [in] xxx head pointer of a linked list
 *  @param [in] xxx file pointeur of an output stream
*/

void LL_save_list_toFile(cell_t* head, FILE * file)
{

    cell_t* current = head;
    if (file != NULL)
    {
        while (current != NULL)
        {
            fprintf(file, "%s;%s\n",current->cle, current->val);
            current = current->next;
        }
    }
}


/** 
 * @brief Save a linked list into a file
 * @param [in, out] xxx head pointer of a linked list
 * @param [in] xxx name of the backup file
 */
void LL_save_list_toFileName(cell_t* head, char* filename)
{
    FILE * file = fopen(filename, "w");

    
    if (file != NULL)
    {
        LL_save_list_toFile(head, file);
        fclose(file);
    }
}


/** 
 * @brief Free the memory location occupied by a linked list
 * @param [in, out] xxx address of head pointer of a linked list
 */
void LL_free_list(cell_t** head)
{
    cell_t * current = *head;
    cell_t * next;

    while (current != NULL)
    {
        next = current->next;
        free(current->val);
        current->val = NULL;
        free(current->cle);
        current->cle = NULL;

        free(current);
        current = next;
    }
    *head = NULL;
}
