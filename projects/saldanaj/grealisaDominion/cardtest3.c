// Card Test for Village card
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

	// set up variables
	
	int player = 0;
	state.whoseTurn = player;
	int bonus = 0;
	int curHandCount = state.handCount[player];
	int curActionCount = state.numActions;

	printf("Test for Village Card:\n");

	cardEffect(village, 0, 0, 0, &state, 0, &bonus);

	// check the handcount - should remain the same
	if(state.handCount[player] == curHandCount) {
		printf("Village: PASS hand count correct\n");
	}
	else {
		printf("Village: FAIL hand count not correct\n");
	}

	// check the action count
	if(state.numActions == curActionCount + 2) {
		printf("Village: PASS action count increased\n");
	}
	else {
		printf("Village: FAIL action count incorrect\n");
	}

	return 0;
}
