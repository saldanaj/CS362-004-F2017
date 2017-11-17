// Random Tester for Smithy Card
// Assignment 4

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <math.h>
#include <time.h>


// global variable for number of tests to run
#define MAX_TESTS 5

int main() {
	
	struct gameState state;
	int k[10] = {adventurer, smithy, village, outpost, tribute, steward, minion, embargo, mine, cutpurse};
	int testCount = 0;
	int numPlayers, gameSeed, player, bonus;

	for(testCount = 0; testCount < MAX_TESTS; testCount++) {
		// seed the random number generator
		srand(time(0));
		
		// now set the number of players between 2 and 4
		numPlayers = rand() % (MAX_PLAYERS-1)+2;
		
		// get a random seed value for the game...
		gameSeed = rand();

		// initialize the game
		initializeGame(numPlayers, k, gameSeed, &state);

		// set up other variables
		player = rand() % numPlayers;
		state.whoseTurn = player;
		bonus = 0; // we are not testing bonus in smithy

		// from piazza, randomize certain parts of the gamestate, namely deck, hand, discard
		state.deckCount[player] = rand() % MAX_DECK;
		state.discardCount[player] = rand() % MAX_DECK;
		state.handCount[player] = rand() % MAX_DECK;

		// we will want the original values of some variables
		int curDeckCount = state.deckCount[player];
		int curHandCount = state.handCount[player];
		int lastCard = state.hand[player][state.handCount[player]-1];

		// finally call the function and run the tests!
		cardEffect(smithy, 0, 0, 0, &state, 0, &bonus);

		if(state.handCount[player] != curHandCount + 2) {
			printf("Smithy: FAIL hand count did not increase appropriately\n");
			printf("Test # %d, deckCount = %d, handCount = %d\n", testCount, curDeckCount, curHandCount);
			printf("number of players = %d, current player = %d, game seed = %d\n", numPlayers, player, gameSeed);
		}

		if(curDeckCount > 3 && state.deckCount[player] != curDeckCount-3) {
			printf("Smithy: FAIL deckCount was not reduced appropriately\n");
			printf("Test # %d, deckCount = %d, handCount = %d\n", testCount, curDeckCount, curHandCount);
			printf("number of players = %d, current player = %d, game seed = %d\n", numPlayers, player, gameSeed);
		}

		if(lastCard != state.hand[player][state.handCount[player]-3]) {
			printf("Smithy: FAIL last card in original deck does not match card before three drawn cards\n");
			printf("Test # %d, deckCount = %d, handcount = %d\n", testCount, curDeckCount, curHandCount);
			printf("number of players = %d, current player = %d, game seed = %d\n", numPlayers, player, gameSeed);
		}

	}

	return 0;
}
