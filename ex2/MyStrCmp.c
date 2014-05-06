/* MyStrCmp.c
 *
 *  Created on: Oct 31, 2013
 *      Author: itayabu
 */

#include <stdio.h>
#define MAX_CHARS 31

/**
 * function recieve a string 31 chars long from input.
 * function ignore any char after the thertiest one.
 */
int makeString(char newString[MAX_CHARS + 1])
{
	int i = 0;
	char c = getchar();

	//read to the end of line or to the 31th char
	while (c != '\n' && i < MAX_CHARS + 1)
	{
		newString[i] = c;
		c = getchar();
		i++;
	}
	newString[i] = '\0';
	i--;

	// if the string is longer than thirty one, finish reading the line without puting it to the string
	if (i == MAX_CHARS + 1)
	{
		while (c != '\n')
		{
			c = getchar();
		}
	}
	return i;
}

/**
 * program compare between tow strings
 * program receive 2 strings as input, and compare them.
 * if either string length is greater than 30 program return error note
 */
int main()
{
	// tow arrays of chars defining a sttring for each one
	char sOne[MAX_CHARS + 1], sTow[MAX_CHARS + 1];
	// oneLen,towLen are the lengths of each string
	int i = 0, oneLen, towLen;

	printf("Enter string 1:");
	oneLen = makeString (sOne);
	printf("Enter string 2:");
	towLen = makeString (sTow);

	//in case that the strings are too long
	if (oneLen > MAX_CHARS)
	{
		printf ("string one is illegal");
		return 0;
	}
	if (towLen > MAX_CHARS)
	{
		printf ("string tow is illegal");
		return 0;
	}

	//check witch string is greater
	i = 0;

	//check char to char to the end of both strings
	while (sOne[i] != '\0' && sTow[i] != '\0')
	{
		if (sOne[i] > sTow[i])
		{
			printf("String 1 is greater\n");
			return 0;
		}
		if (sOne[i] < sTow[i])
		{
			printf("String 2 is greater\n");
			return 0;
		}
		i++;
	}

	//check if either string is longer
	if (sOne[i] == '\0' && sTow[i] == '\0')
	{
		printf("Strings are equal\n");
		return 0;
	}
	else if (sOne[i] == '\0')
	{
		printf("String 2 is greater\n");
		return 0;
	}

	//if there is no difference
	else
	{
		printf("String 1 is greater\n");
		return 0;
	}
}

