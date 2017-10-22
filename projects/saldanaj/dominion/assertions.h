/*
 Student: Joaquin Saldana
 
 Description: This is my own personal .h and .c files for creating assertions that will aid
 in my testing of the dominion.c files.  This will help avoid the program from crashing
 w/ the assert.h functions.
 */

#ifndef ASSERTIONS_H
#define ASSERTIONS_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void jqAssert(int returnedInt, char * message); 

#endif /* assertions_h */
