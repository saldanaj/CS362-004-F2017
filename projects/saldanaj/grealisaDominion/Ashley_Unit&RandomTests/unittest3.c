// Unit test to test updateCoins function
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

	// set up variables for test
	int player = 0;
	state.handCount[player] = 1;
	state.hand[player][0] = copper;

	printf("Test for updateCoins():\n");

	updateCoins(player, &state, 0);
	if(state.coins == 1) {
		printf("updateCoins(): PASS copper coin updated\n");
	}
	else {
		printf("updateCoins(): FAIL copper coin not updated\n");
	}

	state.hand[player][0] = silver;

	updateCoins(player, &state, 0);
	if(state.coins == 2) {
		printf("updateCoins(): PASS silver coin updated\n");
	}
	else {
		printf("updateCoins(): FAIL silver coin not updated\n");
	} 

	state.hand[player][0] = gold;

	updateCoins(player, &state, 0);
	if(state.coins == 3) {
		printf("updateCoins(): PASS gold coin updated\n");
	}
	else {
		printf("updateCoins(): FAIL gold coin not updated\n");
	}

	state.hand[player][0] = mine;

	updateCoins(player, &state, 5);
	if(state.coins == 5) {
		printf("updateCoins(): PASS bonus updated no other coins\n");
	}
	else {
		printf("updateCoins(): FAIL bonus failed\n");
	}
	
	return 0;
}
