/*
 Student: Joaquin Saldana
 
 Description: This is my own personal .h and .c files for creating assertions that will aid
 in my testing of the dominion.c files.  This will help avoid the program from crashing
 w/ the assert.h functions.
 */

#include "assertions.h"


void jqAssert(int returnedInt, char * message)
{
	if(returnedInt != 0)
	{
		printf("FAILED ASSERTION: %s\n", message);
	}
	else
	{
		printf("TEST SUCCESSFULLY COMPLETED: %s\n",message);
	}
}

// helper function to generate a random number between a specified range 

int random_number(int min_num, int max_num)
{
	int result = 0, low_num = 0, hi_num = 0;
	
	if (min_num < max_num)
	{
		low_num = min_num;
		hi_num = max_num + 1; // include max_num in output
	} else {
		low_num = max_num + 1; // include max_num in output
		hi_num = min_num;
	}
	
	srand(time(NULL));
	result = (rand() % (hi_num - low_num)) + low_num;
	return result;
}
