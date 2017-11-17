// Card Test for Smithy card
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

	// set up the variables
	int player = 0;
	state.whoseTurn = player;
	int bonus = 0;
	int curHandCount = state.handCount[player];
	int curDeckCount = state.deckCount[player];

	printf("Test for Smithy Card:\n");

	cardEffect(smithy, 0, 0, 0, &state, 0, &bonus);

	if(state.handCount[player] == curHandCount + 2) {
		printf("Smithy: PASS handCount increased\n");
	}
	else {
		printf("Smithy: FAIL handCount not correct\n");
	}

	if(state.deckCount[player] == curDeckCount - 3) {
		printf("Smithy: PASS deckCount decreased\n");
	}
	else {
		printf("Smithy: FAIL deckCount not correct\n");
	}

	return 0;
}
