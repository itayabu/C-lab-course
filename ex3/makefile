
.PHONY: clean

#GenericHashTable
GenericHashTable.a: GenericHashTable.o 
	ar rcs GenericHashTable.a GenericHashTable.o
	
GenericHashTable.o: GenericHashTable.c GenericHashTable.h TableErrorHandle.h MyIntFunctions.h MyStringFunctions.h
	gcc GenericHashTable.c -c -Wall

#HashIntSearch
HashIntSearch : HashIntSearch.o MyIntFunctions.o TableErrorHandle.o GenericHashTable.a GenericHashTable.o	
	gcc HashIntSearch.o MyIntFunctions.o TableErrorHandle.o GenericHashTable.o -o HashIntSearch -Wall -lm
HashIntSearch.o : HashIntSearch.c MyIntFunctions.h GenericHashTable.h
	gcc HashIntSearch.c -c -Wall
	
#HashStrSearch
HashStrSearch : HashStrSearch.o MyStringFunctions.o TableErrorHandle.o GenericHashTable.a GenericHashTable.o
	gcc HashStrSearch.o MyStringFunctions.o TableErrorHandle.o GenericHashTable.o -o HashStrSearch -Wall -lm
HashStrSearch.o : HashStrSearch.c MyStringFunctions.h GenericHashTable.h
	gcc HashStrSearch.c -c -Wall

#MyStringFunctions
MyStringFunctions.o: MyStringFunctions.c MyStringFunctions.h
	gcc MyStringFunctions.c -c -Wall

#MyIntFunctions
MyIntFunctions.o: MyIntFunctions.c MyIntFunctions.h
	gcc MyIntFunctions.c -c -Wall

#TableErrorHandle
TableErrorHandle.o: TableErrorHandle.c TableErrorHandle.h
	gcc TableErrorHandle.c -c -Wall


all: GenericHashTable.a HashIntSearch HashStrSearch

clean:
	rm *.o HashIntSearch HashStrSearch *.a
