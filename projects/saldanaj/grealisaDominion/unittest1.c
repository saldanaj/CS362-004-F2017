/*
 Student: Joaquin Saldana
 Assignment 3
 
 In this unit test case we are testing the initializeGame function to ensure the state struct is
 correctly implemented and errors are detected with the if statements in function
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assertions.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


int main (int argc, char** argv)
{
	printf("\n** Unit Test 1: Testing function initializeGame() **\n");
	
	struct gameState state;
	
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };
	int wrongK[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, adventurer };
	
	
	char * gameInitWrongPlayerNum = "Testing Initialization With Wrong # of Player (5).  FAILURE IS GOOD THING HERE";
	int a = initializeGame(5, k, 3, &state);
	jqAssert(a, gameInitWrongPlayerNum);
	
	char * gameInitWrongCardSet = "Testing Initialization with card set with one or more same card.  FAILURE IS GOOD THING HERE";
	int b = initializeGame(2, wrongK, 3, &state);
	jqAssert(b, gameInitWrongCardSet);
	
	
	char * gameInitialization = "Test of Game Intialization";
	int c = initializeGame(2, k, 3, &state);
	jqAssert(c, gameInitialization);
	
	if(state.numPlayers != 2)
	{
		printf("initializeGame() function did not initialize the correct number of players\n");
	}
	else
	{
		printf("initializeGame() function initialized the correct number of players\n");
	}
	
	if(state.whoseTurn != 0)
	{
		printf("initializeGame() function did not initialize correctly the whoseTurn property\n");
	}
	else
	{
		printf("initializeGame() function initialized correctly the whoseTurn property\n");
	}

	printf("\n** End of Unit Test 1 **\n");
	
	return 0;
}


