/*
 Student: Joaquin Saldana
 Assignment 3
 
 In this unit test case we are testing the buyCard() function to determine if we
 buy the card and test the card is present
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
	printf("\n** Unit Test 2: Testing Function buyCard() **\n");
	
	struct gameState state;
	
	state.numBuys = 3;
	state.coins = 4;
	
	char * buyTest1 = "Attempting to buy with 4 coins";
	int a = buyCard(2, &state);
	jqAssert(a, buyTest1);
	
	// Now attempting to buy with 10 coins
	state.coins = 10;
	char * buyTest2 = "Attempting to buy with 10 coins";
	int b = buyCard(2, &state);
	jqAssert(b, buyTest2);
	
	// Check if the function allows him to buy with 0 coins
	state.coins = 0;
	
	char * buyTest3 = "Attempting to buy with 0 coins";
	int c = buyCard(2, &state);
	jqAssert(c, buyTest3);
	
	// Attempting to buy with 3 coins and 0 number of buys
	state.numBuys = 0;
	state.coins = 3;
	char * buyTest4 = "Attempting to buy with 3 coins but 0 buys";
	int d = buyCard(2, &state);
	jqAssert(d, buyTest4);
	
	printf("\n** End of Unit Test 2 **\n");
	
	return 0;
}
