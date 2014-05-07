/*
 * GenericHashTable.c
 *
 *  Created on: Nov 17, 2013
 *      Author: itayabu
 */

#include "GenericHashTable.h"
#include <stdio.h>
#include <string.h>
#include "TableErrorHandle.h"
#define NO_OBJECT -1
#define DOUBLE_ARRAY_FACTOR 2

typedef struct Object* ObjectP;
typedef struct Table* TableP;
typedef const struct Table* ConstTableP;



/*
 * Allocate memory for an object which points to the given key.
 * If run out of memory, free all the memory that was already allocated by the function,
 * report error MEM_OUT to the standard error and return NULL.
 */
ObjectP CreateObject(void *key)
{
	ObjectP newObject;

	//allocate room for object
	newObject = (ObjectP) malloc (sizeof (Object));
	if (newObject == NULL)
	{
		ReportError(MEM_OUT);
		return NULL;
	}

	//initialize pointers
	newObject->key = key;
	newObject->next = NULL;
	return newObject;
}


/*
 * Allocate memory for a hash table with which uses the given functions.
 * tableSize is the number of cells in the hash table.
 * If run out of memory, free all the memory that was already allocated by the function,
 * report error MEM_OUT to the standard error and return NULL.
 */
TableP CreateTable(size_t tableSize, HashFcn hfun, PrintFcn pfun, ComparisonFcn fcomp)
{
	int i;
	TableP myTable;
	//make place for table struct
	myTable = malloc (sizeof(Table));
	if (myTable == NULL)
	{
		ReportError(MEM_OUT);
		return NULL;
	}

	//	make place for pointers array
	myTable->tableOfObjects = malloc(sizeof (ObjectP)*tableSize);
	if (myTable->tableOfObjects == NULL)
	{
		FreeTable(myTable);
		ReportError(MEM_OUT);
		return NULL;
	}

	//	initialize every pointer in table
	for (i = 0; i < tableSize; i++)
	{
		myTable->tableOfObjects[i] = NULL;
	}

	//initialize all the values and functions in Table
	myTable->dim = 1;
	myTable->hashFun = hfun;
	myTable->compFun = fcomp;
	myTable->printFun = pfun;
	myTable->arrSize = tableSize;
	return myTable;
}


/**
 *double the the size of the ObjectP array for a given table
 */
Boolean doubleTable (TableP table)
{
	int i;

	//allocate place for doubled array
	ObjectP* newOne = (ObjectP*)malloc(sizeof (ObjectP) * table->arrSize*DOUBLE_ARRAY_FACTOR);
	if (newOne == NULL)
	{
		ReportError(MEM_OUT);
		return FALSE;
	}

	//initialize every pointer in table
	for (i = 0; i < table->arrSize * 2; i++)
	{
		newOne[i] = NULL;
	}

	//copy pointers from old array to new one
	for (i = 0; i<table->arrSize; i++)
	{
		newOne[i*2] = table->tableOfObjects[i];
	}


	//update dimention and size of table
	table->dim = table->dim * DOUBLE_ARRAY_FACTOR;
	table->arrSize *= DOUBLE_ARRAY_FACTOR;

	//replace pointer array
	free (table->tableOfObjects);
	(table->tableOfObjects) = newOne;
	return TRUE;
}



/*
 * Insert an object to the table.
 * If all the cells appropriate for this object are full, duplicate the table.
 * If run out of memory during the table duplication, report
 * MEM_OUT and do nothing (the table should stay at the same situation
 * as it was before the duplication).
 * If everything is OK, return TRUE. Otherwise (an error occured) return FALSE.
 */
Boolean InsertObject(TableP table, ObjectP object)
{
	int i = 	0;
	//find the original table's cell and multiply by dimentions the table grew so far.
	int place = table->hashFun(object->key, (table->arrSize / table->dim)) * table->dim;

	//search for a cell in the updated table.
	for (i = place; i < (place + table->dim); i++)
	{
		//check cell one
		if (table->tableOfObjects[i] == NULL)
		{
			table->tableOfObjects[i] = object;
			return TRUE;
		}

		//if occupied, check cell two
		if ( table->tableOfObjects[i]->next == NULL)
		{
			table->tableOfObjects[i]->next = object;
			return TRUE;
		}
	}

	//if there is no place, need to double the length
	if(!doubleTable(table))
	{
		return FALSE;
	}
	table->tableOfObjects[place * DOUBLE_ARRAY_FACTOR  + 1] =  object;
	return TRUE;
}



/*
 * Search the table and look for an object with the given key.
 * If such object is found fill its cell number into arrCell (where 0 is the
 * first cell), and its placement in the list into listNode (when 0 is the
 * first node in the list, i.e. the node that is pointed from the table
 * itself).
 * If the key was not found, fill both pointers with value of -1.
 */
void FindObject(ConstTableP table, const void* key, int* arrCell, int* listNode)
{
	int i;
	//find the original table's cell and multiply by dimentions the table grew so far.
	int place = table->hashFun(key, (table->arrSize / table->dim)) * table->dim;

	for (i = place; i < place + table->dim; i++)
	{
		// if there is no objects in cell continue to next cell
		if (table->tableOfObjects[i] == NULL)
		{
			continue;
		}

		//if the first object in cell is the key
		if (table->compFun(table->tableOfObjects[i]->key, key))
		{
			*arrCell = i;
			*listNode = 0;
			return;
		}

		//if the second object in cell is the key
		if ((table->tableOfObjects[i]->next != NULL)
			&& (table->compFun(table->tableOfObjects[i]->next->key, key)))
		{
			*arrCell = i;
			*listNode = 1;
			return;
		}
	}

	//if no object is the key (NO_OBJECT=-1)
	*arrCell = NO_OBJECT;
	*listNode = NO_OBJECT;
	return;
}


/*
 * Print the table.
 */
void PrintTable(ConstTableP table)
{
	int i;
	for (i = 0; i< table->arrSize; i++)
	{
		printf ("[%d]\t", i);
		if (table->tableOfObjects[i] != NULL)
		{
			table->printFun(table->tableOfObjects[i]->key);
			printf ("\t-->\t");
			if (table->tableOfObjects[i]->next != NULL)
			{
				table->printFun(table->tableOfObjects[i]->next->key);
				printf ("\t-->\t");
			}
		}
		printf ("\n");
	}
}


/*
 * Free all the memory allocated for an object, including the memory allocated
 * for the key.
 * Use this function when you free the memory of the table.
 */
void FreeObject(ObjectP object)
{
	if (object != NULL)
	{
		if (object->next != NULL)
		{
			free (object->next->key);
		}
		free (object->next);
		free (object->key);
	}
	free (object);
}


/*
 * Free all the memory allocated for the table.
 * It's the user responsibility to call this function before exiting the program.
 */
void FreeTable(TableP table)
{
	int i;
	for (i = 0; i<table->arrSize; i++)
	{
		if (table->tableOfObjects[i] != NULL)
		{
			FreeObject(table->tableOfObjects[i]);
		}
	}
	free (table->tableOfObjects);
	free (table);
}

