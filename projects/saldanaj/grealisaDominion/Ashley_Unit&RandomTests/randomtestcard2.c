// Random Tester for Steward
// Assignment 4

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

// global variable for number of tests to run
#define MAX_TESTS 20

int main() {

	struct gameState state;
	int k[10] = {adventurer, smithy, village, outpost, tribute, steward, minion, embargo, mine, cutpurse};
	int testCount = 0;
	int numPlayers, gameSeed, player, bonus, choice;

	for (testCount = 0; testCount < MAX_TESTS; testCount++) {
		// seed the ranomd number generator
		srand(time(0));
		
		// now set the number of players between 2 and 4
		numPlayers = rand() % (MAX_PLAYERS-1)+2;
		
		// get a random seed value
		gameSeed = rand();
		
		// initialize the game
		initializeGame(numPlayers, k, gameSeed, &state);

		// set up other variables
		player = rand() % numPlayers;
		state.whoseTurn = player;
		bonus = 0; // we are not testing bonus in steward
		choice = rand() % 3;
		
		// from piazza, randomize certain parts of the gamestate, namely deck, discard, hand
		state.deckCount[player] = rand() % MAX_DECK;
		state.discardCount[player] = rand() % MAX_DECK;
		state.handCount[player] = rand() % MAX_DECK;

		// We want the original values of a couple variables to compare with
		int curDeckCount = state.deckCount[player];
		int curHandCount = state.handCount[player];
		int curDiscardCount = state.discardCount[player];
		int lastCard = state.hand[player][state.handCount[player]-1];
		int curCoins = state.coins;
		int choice2 = rand() % curHandCount;
		int choice3 = rand() % curHandCount;
		int handPos = rand() % curHandCount;


		// finally call the function and run the tests!
		cardEffect(steward, choice, choice2, choice3, &state, handPos, &bonus);


		if(choice == 1) {
			if(state.handCount[player] != curHandCount + 1) {
				printf("Steward: FAIL hand count did not increase appropriately\n");
				printf("Test # %d, deckCount = %d, discardCount = %d, handCount = %d\n", testCount, curDeckCount, curDiscardCount, curHandCount);
				printf("number of players = %d, current player = %d, game seed = %d, choice # %d\n", numPlayers, player, gameSeed, choice);
			}

			if(state.hand[player][state.handCount[player]-2] != lastCard) {
				printf("Steward: FAIL last card in original deck is not the card before the two drawn cards\n");
				printf("Test # %d, deckCount = %d, discardCount = %d, handCount = %d\n", testCount, curDeckCount, curDiscardCount, curHandCount);
				printf("number of players = %d, current player = %d, game seed = %d, choice # %d\n", numPlayers, player, gameSeed, choice);
			}
		}

		if(choice == 2) {
			if(state.handCount[player] != curHandCount - 1) {
				printf("Steward: FAIL hand count did not decrease appropriately\n");
				printf("Test # %d, deckCount = %d, discardCount = %d, handCount = %d\n", testCount, curDeckCount, curDiscardCount, curHandCount);
				printf("number of players = %d, current player = %d, game seed = %d, choice # %d\n", numPlayers, player, gameSeed, choice);
			}

			if(state.discardCount[player] != curDiscardCount + 1) {
				printf("Steward: FAIL discard count did not increase appropriately\n");
				printf("Test # %d, deckCount = %d, discardCount = %d, handCount = %d\n", testCount, curDeckCount, curDiscardCount, curHandCount);
				printf("number of players = %d, current player = %d, game seed = %d, choice # %d\n", numPlayers, player, gameSeed, choice);
			}

			if(state.coins != curCoins + 2) {
				printf("Steward: FAIL coins did not increase appropriately\n");
				printf("Test # %d, deckCount = %d, discardCount = %d, handCount = %d\n", testCount, curDeckCount, curDiscardCount, curHandCount);
				printf("number of players = %d, current player = %d, game seed = %d, choice # %d\n", numPlayers, player, gameSeed, choice);
			}
		}

		if(choice == 0) {
			if(state.handCount[player] != curHandCount - 3) {
				printf("Steward: FAIL hand count did not decrease appropriately\n");
				printf("Test # %d, deckCount = %d, discardCount = %d, handCount = %d\n", testCount, curDeckCount, curDiscardCount, curHandCount);
				printf("number of players = %d, current player = %d, game seed = %d, choice # %d\n", numPlayers, player, gameSeed, choice);
			}

			if(state.discardCount[player] != curDiscardCount + 3) {
				printf("Steward: FAIL discard count did not increase appropriately\n");
				printf("Test # %d, deckCount = %d, discardCount = %d, handCount = %d\n", testCount, curDeckCount, curDiscardCount, curHandCount);
				printf("number of players = %d, current player = %d, game seed = %d, choice # %d\n", numPlayers, player, gameSeed, choice);
			}
		}
	sleep(1);

	}

	return 0;
}
