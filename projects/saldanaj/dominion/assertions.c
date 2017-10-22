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
