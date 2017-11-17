// Unit test to test buyCard function
// Assignment 3

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>

int main() {
	struct gameState state;
	int result;	
	int k[10] = {adventurer, smithy, village, outpost, tribute, steward, minion, embargo, mine, cutpurse};

	initializeGame(2, k, 10, &state);
	// set up variables
	state.numBuys = 1;
	state.coins = 4;

	state.whoseTurn = 0;

	int currentCount = state.discardCount[0];
	//printf("discardCount: %d\n",state.discardCount[0]);
	printf("Test for buyCard()\n");
	// test the state after we buy a card - specifically the estate card
	result = buyCard(village, &state);
	//printf("result: %d", result);
	if(state.discardCount[0] == currentCount + 1) {
		printf("buyCard(): PASS discardCount was incremented\n");
	}
	else {
		printf("buyCard(): FAIL discardCount not incremented\n");
	}

	if(state.coins == 1) {
		printf("buyCard(): PASS coins reduced correctly\n");
	}
	else {
		printf("buyCard(): FAIL coins reduced incorrectly\n");
	}
	
	if(state.numBuys == 0) {
		printf("buyCard(): PASS numBuys decremented correctly\n");
	}
	else {
		printf("buyCard(): FAIL numBuys decremented incorrectly\n");
	}

	return 0;
}
