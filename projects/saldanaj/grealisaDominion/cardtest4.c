// Card Test for Outpost Card
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
	int curOutpostFlag = state.outpostPlayed;

	printf("Test for Outpost Card:\n");

	cardEffect(outpost, 0, 0, 0, &state, 0, &bonus);

	// chekc the hand count - we disarded a card
	if(state.handCount[player] == curHandCount - 1) {
		printf("Outpost: PASS hand count decreased\n");
	}
	else {
		printf("Outpost: FAIL hand count did not decrease\n");
	}

	// chekc the oustpost flag
	if(state.outpostPlayed == curOutpostFlag + 1) {
		printf("Outpost: PASS outpost played increased\n");
	}
	else {
		printf("Outpost: FAIL outpost played incorrect\n");
	}

	return 0;
}
