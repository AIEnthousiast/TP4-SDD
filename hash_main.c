#include "stdio.h"
#include "stdlib.h"
#include "teZZt.h"
#include "hash.h"
#include "string.h"

BEGIN_TEST_GROUP(hashtable)

TEST(create_hash_table) {

    cell_t ** table_majeure = create_hash_table();


    CHECK(NULL == *table_majeure);
    free_hash_table(table_majeure);
}

TEST(insert_in_hash_table)
{
    cell_t ** table_majeure = create_hash_table();

    insert_in_hash_table(table_majeure,"aaa","A");

    REQUIRE(NULL != table_majeure[hash_string("aaa")]);
    CHECK(0 == strcmp(research_in_hash_table(table_majeure,"aaa"),"A"));

    free_hash_table(table_majeure);
}

TEST(load_dictionnary)
{

    cell_t ** table_majeure = create_hash_table();
    REQUIRE(NULL != table_majeure);

    load_dictionnary(table_majeure,"fr_ang.txt");
    
    REQUIRE(NULL != table_majeure[hash_string("le")]);

    CHECK(0 == strcmp(research_in_hash_table(table_majeure,"de"),"of"));

    free_hash_table(table_majeure);
}


TEST(translate)
{
    cell_t ** table_majeure = create_hash_table();
    REQUIRE(NULL != table_majeure);

    load_dictionnary(table_majeure,"fr_ang.txt");

    translate(table_majeure,"le soleil");

    free_hash_table(table_majeure);
}






END_TEST_GROUP(hashtable)


int main(int argc, char ** argv)
{
    
    RUN_TEST_GROUP(hashtable);
	return EXIT_SUCCESS;
}