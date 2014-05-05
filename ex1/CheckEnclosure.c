/*
 * CheckEnclosure.c
 *
 *
 *  Author: itay abulafia 303033286
 */

# include <stdio.h>
# define OPEN_ROUND 40
# define CLOSE_ROUND 41
# define OPEN_SQUARE 91
# define CLOSE_SQUARE 93
# define OPEN_TRI 60
# define CLOSE_TRI 62
# define OPEN_WEIRD 123
# define CLOSE_WEIRD 125

/**
 * program check a file for enclosures and check if they are legal.
 * a legal enclosure is that every "close" enclosure comes after "open" enclosure and that are no "open"s at the
 * end of the file.
 */
int main (int argc, char *argv[])
{
	FILE *pFile;
	int INT_SIZE = sizeof(int), HALF_WAY = 2500;
	int openClosure[HALF_WAY];
	int ARR_START = 40, CLOSURE_COUNT = 0, c;
	pFile = fopen(argv[1], "r");
	if (pFile == NULL)
	{
		printf("error opening the file\n");
		return 1;
	}
	openClosure[ARR_START] = 0;
	c= fgetc(pFile);
	while ((CLOSURE_COUNT >= 0) && (CLOSURE_COUNT <= HALF_WAY) && c != EOF){
		switch (c)
		{
		// handle round enclosures
		case OPEN_ROUND:
			openClosure[ARR_START + (CLOSURE_COUNT * INT_SIZE)] = c;
			CLOSURE_COUNT++;
			break;
		case CLOSE_ROUND:
			if (openClosure[ARR_START + ((CLOSURE_COUNT -1) * INT_SIZE)] == OPEN_ROUND)
			{
				CLOSURE_COUNT -= 1;
				break;
			}
			else
			{
				printf("Bad structure\n");
				return 1;
			}
			//			 handle square enclosures
		case OPEN_SQUARE:
			openClosure[ARR_START + (CLOSURE_COUNT * INT_SIZE)] = c;
			CLOSURE_COUNT++;
			break;
		case CLOSE_SQUARE:
			if (openClosure[ARR_START + ((CLOSURE_COUNT -1) * INT_SIZE)] == OPEN_SQUARE)
			{
				CLOSURE_COUNT -= 1;
				break;
			}
			else
			{
				printf("Bad structure\n");
				return 1;
			}

			//handle triangle enclosures
		case OPEN_TRI:
			openClosure[ARR_START + (CLOSURE_COUNT * INT_SIZE)] = c;
			CLOSURE_COUNT++;
			break;
		case CLOSE_TRI:
			if (openClosure[ARR_START + ((CLOSURE_COUNT -1) * INT_SIZE)] == OPEN_TRI)
			{
				CLOSURE_COUNT -= 1;
				break;
			}
			else
			{
				printf("Bad structure\n");
				return 1;
			}
			//handle weird enclosures
		case OPEN_WEIRD:
			openClosure[ARR_START + (CLOSURE_COUNT * INT_SIZE)] = c;
			CLOSURE_COUNT++;
			break;
		case CLOSE_WEIRD:
			if (openClosure[ARR_START + ((CLOSURE_COUNT -1) * INT_SIZE)] == OPEN_WEIRD)
			{
				CLOSURE_COUNT -= 1;
				break;
			}
			else
			{
				printf("Bad structure\n");
				return 1;
			}
		default:
			break;
		}

		// take the next char to check
		c = fgetc(pFile);
	}

	// after EOF, check if the count is good
	if (CLOSURE_COUNT != 0)
	{
		printf ("Bad structure\n");
		return 0;
	}
	printf ("Ok\n");
	return 1;
}


