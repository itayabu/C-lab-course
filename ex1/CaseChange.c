/*
 * CaseChange.c
 *
 * Author: itay abulafia
 */

#include <stdio.h>
#include <math.h>

/**
 * program converts capital letters to small letters, small letters to capital and square an integer.
 * program recieve a char as input
 */
int main ()
{
	char letterToConvert;
	int letterAsNum, LOWER_NUM = 48, UPPER_NUM = 57, LOWER_SMALL = 65, UPPER_SMALL = 90,
		LOWER_BIG = 97, UPPER_BIG = 122, CHAR_DIFF = 32, CHAR_TO_VALS;

	scanf("%c", &letterToConvert);
	letterAsNum = (int) letterToConvert;

	// check if char is a number, and square it
	if ((letterAsNum >= LOWER_NUM) && (letterAsNum <= UPPER_NUM))
	{
		letterAsNum = letterAsNum-CHAR_TO_VALS;
		letterAsNum = letterAsNum * letterAsNum;
		printf("%d\n", letterAsNum );
	}

	// check if char is letters and change them
	else if ((letterAsNum >= LOWER_BIG) && (letterAsNum <= UPPER_BIG))
	{
		printf("%c->%c\n", letterToConvert, letterAsNum - CHAR_DIFF );
	}
	else if ((letterAsNum >= LOWER_SMALL) && (letterAsNum <= UPPER_SMALL))
	{
		printf("%c->%c\n", letterToConvert, letterAsNum + CHAR_DIFF );
	}

	//if char is not a number and not a letter
	else
	{
		printf("->Invalid Input\n");
	}
	return 0;
}

