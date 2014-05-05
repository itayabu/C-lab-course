/*
 * ChangeBase.c
 *
 * Author: itay abulafia 303033286
 */
#include <stdio.h>
#include <math.h>
int baseFrom, baseTo;

/**
 * function take a number at any base and return its value at base 10.
 */
unsigned long int changeBaseToTen(unsigned long int oriNum)
{
	int i;
	unsigned long int newNum = 0;
	i=0;
	while (oriNum > 0)
	{

		//check for legal input (a number cannot be equal or bigger than its base)
		if (oriNum%10 >= baseFrom)
		{
			printf ("Invalid");
			return(0);
		}

		//build a new "base ten" number
		newNum += (oriNum % 10) * pow(baseFrom, i);
		oriNum /= 10;
		i++;
	}
	return newNum;
}

/**
 * function build a new base chosen number
 */
unsigned long int changeBaseFromTen(unsigned long int oriNum){
	int i = 0;
	unsigned long int newNum = 0;
	while (oriNum > 0)
	{
		newNum += ((oriNum % baseTo) * (long) pow(10,i));
		oriNum /= baseTo;
		i++;
	}
	for (; i >= 0; i--)
	{

	}
	return newNum;
}

/**
 * program receive a number, and change its base.
 * program receive a number, its base and base to change to in the format of <num#base#basetochange>
 * and return the number in its new base.
 */
int main()
{
	unsigned long int num;
	unsigned long int newNum;
	scanf("%lu#%d#%d", &num, &baseFrom, &baseTo);
	num = changeBaseToTen(num);
	newNum = changeBaseFromTen(num);
	printf("%lu\n", newNum);
	return (0);
}

