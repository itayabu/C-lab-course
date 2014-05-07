/*
 * MyStringFunctions.c
 *
 *  Created on: Nov 24, 2013
 *      Author: itayabu
 */
#include <stdio.h>
#include <string.h>


/*
 * return hashed-to-table place for each string
 */
int StringFcn (const void *key, size_t tableSize)
{
	int asciiSum = 0, hashed;
	char* word = (char*) key;

	//sum the ascii values
	while (*word != '\0')
	{
		asciiSum += (int) *word;
		word++;
	}

	hashed = asciiSum % tableSize;
	return hashed;
}

/*
 * print the string in key
 */
void StringPrint (const void *key)
{
	printf ("%s", (char*)key);
}

/*
 * compare two strings. return 1 if they are equal, 0 if not.
 */
int StringCompare (const void *key1, const void *key2)
{
	char* sOne = (char*) key1;
	char* sTow = (char*) key2;
	// return the opposite of compare: 0 if they are not equal
	if(strcmp(sOne, sTow) == 0)
	{
		return 1;
	}
	return 0;

}
