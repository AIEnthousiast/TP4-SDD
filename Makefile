CC = gcc-11
CFLAGS = -Wall -Wextra -g
LDFLAGS =

#repertoire des fichiers d'unitests teZZt.[ch]
#DIRUTEST = ./

#repertoire des fichiers communs : eltPile.[ch], eltsArbre.h pile.[ch]
DIRCOMM = ./

#liste des fichiers source
SRC = $(wildcard *.c) teZZt.c

HEADERS = $(wildcard *.h) teZZt.h

#liste des fichiers objets
OBJ = $(SRC:%.c=%.o)

OBJ_LL = linkedList_main.o linkedList.o teZZt.o
HEADERS_LL = teZZt.h linkedList.h

#hash_table_main: $(OBJ) $(HEADERS)
#	$(CC) $(OBJ) -o $@ $(LDFLAGS)

loading.o: hash.c loading.c loading.h linkedList.h
	$(CC) -c $< -o $@

hash_main: hash_main.o hash.o linkedList.o teZZt.o
	$(CC) hash_main.o hash.o linkedList.o teZZt.o -o $@

hash_main.o: hash_main.c teZZt.h hash.h
	$(CC) $(CFLAGS) -c $< -o $@

hash.o: hash.c hash.h
	$(CC) $(CFLAGS) -c $< -o $@


linkedList: $(OBJ_LL) $(HEADERS_LL)
	$(CC) $(OBJ_LL) -o $@ $(LDFLAGS)

linkedList_main.o: linkedList_main.c teZZt.h linkedList.h
	$(CC) $(CFLAGS) -o $@ -c $<

linkedList.o: linkedList.c linkedList.h
	$(CC) $(CFLAGS) -o $@ -c $<

teZZt.o: teZZt.c teZZt.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean reclean

clean:
	rm -f $(OBJ)

reclean:
	rm -f $(OBJ) table_hashage_main
