/*
 * DrawPolynomial.c
 *
 *  Created on: Oct 23, 2013
 *      Author: itayabu
 */
#include <stdio.h>
#include <math.h>
const int Y_START = 10, Y_END = -10, X_START = -35, X_END = 35;
double a, b, c, d;

/**
 * draw a line (-) as in X axis
 * draw - for blank poit, + for point (0,0) and * for point with Y value in it
 */
void drawZeroLine ()
{
	int i = 0;
	for (i = X_START; i <= X_END; i ++ )
	{
		if (0 > (a + i*(b + i*(c + i*d)) -0.5) && 0 < (a + i * (b + i * (c + i * d)) + 0.5))
		{
			printf("*");
		}
		else if (i == 0)
		{
			printf("+");
		}
		else
		{
			printf("-");
		}
	}
	printf ("\n");
}

/**
 * draw a line
 * draw * if there is a Y value for equivalence at point
 * draw | on y axis
 * put a space if there is nothing
 */
void drawLine (int y)
{
	int i = 0;
	if (y == 0)
	{
		for (i = X_START; i <= X_END; i ++)
		{
			if ( i == 0)
			{
				printf("+");
			}
			else
			{
				printf("-");
			}
		}
	}
	for ( i = X_START; i <= X_END; i ++)
	{
		if (y > (a + i * (b + i * (c + i * d)) -0.5) && y < (a + i * (b + i * (c + i * d)) + 0.5))
		{
			printf("*");
		}
		else if (i == 0)
		{
			printf("|");
		}
		else
		{
			printf(" ");
		}
	}
	printf ("\n");
}

/**
 * program recieve 3 parameters and draw a polynome for equivalence a+b^x+cx^2+dx^3
 */
int main()
{
	int i;
	printf("y(x)=a+b*x+c*x^2+d*x^3\n");
	printf("Select a:\n");
	scanf("%lf", &a);
	printf("Select b:\n");
	scanf("%lf", &b);
	printf("Select c:\n");
	scanf("%lf", &c);
	printf("Select d:\n");
	scanf("%lf", &d);
	printf("y(x)=(%.3f)+(%.3f)*x+(%.3f)*x^2+(%.3f)*x^3\n", a, b, c, d);
	for (i = Y_START; i >= Y_END ; i--)
	{
		if (i == 0)
		{
			drawZeroLine();
		}
		else
		{
			drawLine (i);
		}
	}
	return (0);
}
