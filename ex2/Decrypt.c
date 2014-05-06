/*
 * Decrypt.c
 *
 *  Created on: Oct 31, 2013
 *      Author: itayabu
 */

#include <stdio.h>
#include <math.h>
#define MAX_LEN 100

/**
 * struct contains the number to shift and the string to be ciphered
 */
typedef struct cipher
{
	int shift;
	char str[MAX_LEN];
}cipher;

/**
 * program recive a number and a string and retunt its coded string.
 * every char in the string is moving by the shift value in a circled way.
 */
int main ()
{
	cipher caesar;
	int MAX_DIF = 26;
	int i = 0;

	printf("Enter Shift:");
	scanf("%d", &caesar.shift);

	//check for valid input
	while ((caesar.shift > MAX_DIF) || (caesar.shift < -MAX_DIF))
	{
		printf("cipher only in range of +-26.\n");
		printf("Enter Shift:");
		scanf("%d", &caesar.shift);
	}

	printf("Enter String to Decrypt:");
	scanf("%s", caesar.str);

	//changing each letter's value by the shift num and check its validity.
	while (caesar.str[i] != '\0')
	{
		if (caesar.str[i] < 'A' || caesar.str[i] > 'Z')
		{
			printf("invalid input\n");
			return 1;
		}

		caesar.str[i] += caesar.shift;
		if (caesar.str[i] < 'A')
		{
			caesar.str[i ] += MAX_DIF;
		}
		if (caesar.str[i] > 'Z')
		{
			caesar.str[i] -= MAX_DIF;
		}
		i++;
	}
	printf("%s\n", caesar.str);
	return 0;
}
