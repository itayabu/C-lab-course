/*
 * ChangeBase.c
 * program recieve
 *
 * Author: itay abulafia 303033286
 */
#include <stdio.h>
#include <math.h>
int baseFrom, baseTo;

unsigned long int changeBaseToTen(unsigned long int oriNum)
{
	int i;
	unsigned long int newNum = 0;
	if (oriNum%10 >= baseFrom)
	{
		printf ("Invalid");
		return(0);
	}
	i=0;
	while (oriNum >0)
	{
		printf(" A %d -> %d\n", oriNum, newNum);
		newNum += (oriNum % 10) * pow(baseFrom,i);
		oriNum /= 10;
		i++;
	}
	printf(" A %d -> %d\n", oriNum, newNum);
	return newNum;
}
unsigned long int changeBaseFromTen(unsigned long int oriNum){
	int i = 0;
	unsigned long int numTow = oriNum;
	unsigned long int newNum = 0;
	while (oriNum >0)
	{

		printf(" B %lu -> %lu\n", oriNum, newNum);
		newNum += ((oriNum % baseTo) * pow(10,i));
		oriNum /= baseTo;
		i++;
	}
	for (;i >= 0;i--)
	{

	}
	printf(" %lu%lu\n", numTow, oriNum);
	return newNum;
}

int main()
{
	unsigned long int num;
	unsigned long int newNum;
	scanf("%lu#%d#%d", &num, &baseFrom, &baseTo);
	num= changeBaseToTen(num);
	newNum= changeBaseFromTen(num);
	printf("%lu\n", newNum);
	return (0);
}

