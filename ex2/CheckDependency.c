/*
 *CheckDependency.c
 *
 *
 *  Author: itay abulafia 303033286
 */
#include <stdio.h>
#include <string.h>

// defining consts as written
#define MAX_DEPENDENCY 100
#define MAX_FILES 1000
#define MAX_CHARS 64
//using ints to return the cycle condition. not in cycle- a struct havnt touched.
// has no cycle- struckt been checked allready and has no cycle (reduce time of double-checking)
# define NOT_IN_CYCLE 1
#define IN_CYCLE 2
#define HAS_NO_CYCLE 3
#define CYCLE_FOUND 4


/**
 * put 2 more ints to better control the struct on the run
 */
typedef struct depFile
{
	char name [MAX_CHARS];

	//pointers array for depfiles in the main array
	struct depFile *dependencis [MAX_DEPENDENCY];

	//count the number of pointers this depfile contain
	int pointersCount;
	int cycle;
}depfile;

/**
 * function recieve tow strings and return 0 if they are equal or 1 if they are not
 */
int stringCompare(char sOne[], char sTow[])
{
	int i = 0;
	while (sOne[i] != '\0' && sTow[i] != '\0')
	{
		if (sOne[i] != sTow[i])
		{
			return 0;
		}
		i++;
	}
	if (sOne[i] == '\0' && sTow[i] == '\0')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/**
 * function recive a pointer to depfile and a string and initialize the struct.
 * an initialized depfile is a one that has a name and its ints are initialized.
 */
void buildFile(depfile *file, char name [])
{
	strcpy(file->name, name);
	file->pointersCount = 0;
	file->cycle = 1;
}

/**
 * function recive a depfile array and a string and return a depfile place in the array.
 * if the array contain a struct with the same name as the string, it return this place.
 * if the array has no depfile with the same name, function build a new depfile.
 */
int checkAndBuildArray (depfile arr[], char name[])
{
	int i = 0;

	//every initialized depfile's 'cycle' is bigger than 0
	while (arr[i].cycle)
	{
		if (stringCompare (arr[i].name, name))
		{
			return i;
		}
		i ++;
	}

	// if there is no depfile at this name, initialize a new depfile
	buildFile (&arr[i], name);
	return i;
}

/**
 *function recurcively check for cycles in the array
 *using DFS, function check the array like a long tree graph
 */
int recCycleCheck(depfile *check)
{
	int i = 0;

	// handle the base case: if this is a cycled depfile, return cycle found
	if (check-> cycle == IN_CYCLE)
	{
		return CYCLE_FOUND;
	}

	// handle the base case: if already checked this  depfile and had no cycle,
	// there is no point in checking it again.
	if (check-> cycle == HAS_NO_CYCLE)
	{
		return HAS_NO_CYCLE;
	}

	// start a new cycle-check
	check-> cycle = IN_CYCLE;
	for (; i<check-> pointersCount; i++)
	{

		//recursively check 'down the tree' if there is a cycle
		if (recCycleCheck(check-> dependencis[i]) == CYCLE_FOUND)
		{
			return CYCLE_FOUND;
		}
	}

	//if there is no cycle in this depfile's dependency,
	//there is no reason to check it again afterward
	check-> cycle = HAS_NO_CYCLE;
	return HAS_NO_CYCLE;
}

/**
 * program program recieve a file containing list of files and their dependency files list
 * program check and print if there are cycles of dependency between all the files in the list.
 */
int main (int argc, char *argv[])
{
	//array of all the depfiles in the file.
	depfile dependencies [MAX_FILES];
	int i, mainFilePlace, dependedFilePlace;
	char newFileName[MAX_CHARS + 1], c;
	FILE *pFile;
	pFile = fopen (argv[1], "r");
	if (pFile == NULL)
	{
		printf("Can not open input file\n");
		return 1;
	}
	c = fgetc(pFile);
	i = 0;

	//I couldn't find a better loop style to seperate between all the cases.
	while (c != EOF)
	{
		//here we check for line seperation:
		while (c != EOF && c != '\n')
		{
			// here we check for names in a single line:
			i = 0;
			while (c != EOF && c != '\n' && c != ',' && c != ':')
			{
				newFileName[i] = c;
				c = fgetc(pFile);
				i++;
			}

			//once we have a word, it either 'main file' or 'dependency file':
			if (c == ':')
			{
				newFileName[i] = '\0';
				mainFilePlace = checkAndBuildArray(dependencies, newFileName);

				//skipping the space
				fgetc(pFile);
				c = fgetc(pFile);
				continue;

			}
			else
			{
				newFileName[i] = '\0';
				dependedFilePlace = checkAndBuildArray(dependencies, newFileName);

				//at the lates 'main file' dependency array, connect this depfile too.
				(dependencies[mainFilePlace].dependencis[dependencies[mainFilePlace].pointersCount] =
							&dependencies[dependedFilePlace]);
				dependencies[mainFilePlace].pointersCount++;
				c = fgetc (pFile);
			}
		}
	}

	//check for cycle all over the array using the recursive function
	i = 0;
	while (dependencies[i].cycle)
	{
		if (recCycleCheck(&dependencies[i]) == CYCLE_FOUND)
		{
			printf("Cyclic Dependencies Exist\n");
			return 0;
		}
		i++;
	}
	printf ("No Cyclic Dependencies Exist\n");
	return 0;
}



