/*
 Student: Joaquin Saldana
 Assignment 3
 
 Testing the isGameOver() function
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
	printf("\n** Unit Test 3: Testing Function isGameOver() **\n");
	
	// creating two game states to preserve the information
	struct gameState state;
	struct gameState temp;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	
	// initialize the game
	initializeGame(2, k, 1000, &state);
	
	// copy over to test the game state
	memcpy(&temp, &state, sizeof(struct gameState));
	
	// purposefully set provinces to 0 to see if game ends
	char * msg1 = "Testing isGameOver with 0 provinces.  FAILURE IS GOOD HERE.  Means isGameOver() worked";
	temp.supplyCount[province] = 0;
	int a = isGameOver(&temp);
	jqAssert(a, msg1);
	
	memcpy(&temp, &state, sizeof(struct gameState));
	
	// purposely set three piles of cards to 0 to see if isGameOver() returns 1
	temp.supplyCount[estate] = 0;
	temp.supplyCount[copper] = 0;
	temp.supplyCount[duchy] = 0;
	int b = isGameOver(&temp);
	char * msg2 = "Testing isGameOver with three depleted supplies.  FAILURE IS GOOD HERE.  Means isGameOver() worked";
	jqAssert(b, msg2);

	
	printf("\n** End of Unit Test 3 **\n");
	
	return 0;
}
