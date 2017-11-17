// Card Test for Adventurer Card
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

	printf("Test for Adventurer Card:\n");

	cardEffect(adventurer, 0, 0, 0, &state, 0, &bonus);

	// check the handcount
	if(state.handCount[player] == curHandCount + 2) {
		printf("Adventurer: PASS hand count increased\n");
	}
	else {
		printf("Adventurer: FAIL hand count not correct\n");
	}

	// check to see if added cards were treasure cards.
	int cardOne = state.hand[player][state.handCount[player]-1];
	int cardTwo = state.hand[player][state.handCount[player]-2];

	if(cardOne == copper || cardOne == silver || cardOne == gold) {
		if(cardTwo == copper || cardTwo == silver || cardTwo == gold) {
			printf("Adventurer: PASS added cards are treasure\n");
		}
	}
	else {
		printf("Adventurer: FAIL added cards are not treasure\n");
	}

	return 0;
}
