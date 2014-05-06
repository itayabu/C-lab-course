/*
 * MyStrLen.c
 *
 *  Created on: Oct 31, 2013
 *      Author: itayabu
 */

#include<stdio.h>

/**
 * a stirng length counter
 * function receive an array of chars representing a string and return its length.
 */
int stringLength (char s[] )
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}

	return i;
}

/**
 * program read a string from consule and and return its length
 * if string is bigger than 25, program return error note.
 */
int main (int argc, char* argv[])
{
	int const MAX_LENGTH = 25;
	int sLength;

	// for empty input, program return zero
	if (argv[1] == NULL)
	{
		printf("0\n");
		return 1;
	}

	// get the length from outside function
	sLength = stringLength(argv[1]);

	if (sLength >= MAX_LENGTH)
	{
		printf("INVALID STRING TOO LONG!\n");
	}
	else
	{
		printf("%d\n", sLength);
	}
	return 0;
}

