// Unit test to test supplyCount function
// Assignment 3

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>


int main() {
	struct gameState state;
	int k[10] = {adventurer, smithy, village, outpost, tribute, steward, minion, embargo, mine, cutpurse};
	initializeGame(2, k, 10, &state);

	// set up variables to test the supplyCount function
	state.supplyCount[curse] = 1;
	state.supplyCount[estate] = 2;

	printf("Test for supplyCount():\n");
	
	if(supplyCount(curse, &state) == 1) {
		printf("supplyCount(): PASS count of curse\n");
	}
	else {
		printf("supplyCount(): FAIL count of curse\n");
	}

	if(supplyCount(estate, &state) == 2) {
		printf("supplyCount(): PASS count of estate\n");
	}
	else {
		printf("supplyCount(): FAIL count of estate\n");
	}

	return 0;
}
