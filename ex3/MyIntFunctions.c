/*
 * MyintFunctions.c
 *
 *  Created on: Nov 18, 2013
 *      Author: itayabu
 */
#include <stdlib.h>
#include <stdio.h>

/*
 * return hashed-to-table place for each number
 */
int IntFcn (const void *key, size_t tableSize)
{
	int hashed;
	int num = *((int*) key);

	//if negative, needs to be withrawd from the table number
	if ((num < 0) && (abs (num) % tableSize) != 0)
	{
		hashed = tableSize - (abs(num) % tableSize);
	}
	else
	{
		hashed = abs(num) % tableSize;
	}

	return hashed;
}

/*
 * print the number at key
 */
void IntPrint (const void *key)
{
	printf ("%d", *(int*)key);
}

/*
 * compare two numbers. return 1 if the equal, 0 if not
 */
int IntCompare (const void *key1, const void *key2)
{
	int numOne, numTow;
	numOne = *((int*) key1);
	numTow = *((int*) key2);

	if (numOne == numTow)
	{
		return 1;
	}
	return 0;
}


