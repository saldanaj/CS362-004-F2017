// Random Tester for Adventurer Card
// Assignment 4

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <time.h>
#include <math.h>

// global variable for number of tests to run
#define MAX_TESTS 20 

int main() {

	struct gameState state;
	int k[10] = {adventurer, smithy, village, outpost, tribute, steward, minion, embargo, mine, cutpurse};
	int testCount = 0;
	int numPlayers, gameSeed, player, bonus;	


	for (testCount=0; testCount < MAX_TESTS; testCount++) {
		

		// seed the random number generator
		srand(time(0));
		
		// now set the number of players between 2 and 4
		numPlayers = rand() % (MAX_PLAYERS-1)+2;
	
		// get a random seed value...
		gameSeed = rand();
		// initialize the game
		initializeGame(numPlayers, k, gameSeed, &state);
	
				// set up other variables
		player = rand() % numPlayers;
		state.whoseTurn = player;
		bonus = 0; // we are not testing bonus in adventurer
		
		// from piazza, randomize certain parts of the gamestate, namely deck, hand, hand position, discard
		state.deckCount[player] = rand() % MAX_DECK;
		state.discardCount[player] = rand() % MAX_DECK;
		state.handCount[player] = rand() % MAX_DECK;
	
		// since we want to cover all branches of the adventure card, we will need to have instances where the deckCount
		// is equal to zero (to call the shuffle function). So put in code to make that happen more often than it will
		// with just hte random valeus generated
		if(state.deckCount[player] % 5 == 0) 
			state.deckCount[player] = 0;
	
		// Now we will want the original values of a lot of hte variables we created to compare
		int curDeckCount = state.deckCount[player];
		int curHandCount = state.handCount[player];
		int curDiscardCount = state.discardCount[player];
		int lastCard = state.hand[player][state.handCount[player]-1];

		// and finally, call the function and run the tests
		// note we do not use handPos in adventurer, so that was
		// not randomized
		cardEffect(adventurer, 0, 0, 0, &state, 0, &bonus);

		// First, check if deck was shuffled when we passed a 0 deckCount
		// These tests cocus on failures since the passes would take up a lot of
		// printing room with hte random test generator.
		if(curDeckCount == 0 && state.deckCount[player] <= curDeckCount) {
			printf("Adventurer: FAIL Shuffle function call failed\n");
			printf("Test # %d: deckCount = %d, discardCount = %d, handCount = %d\n", testCount, curDeckCount, curDiscardCount, curHandCount);
			printf("number of players = %d, current player = %d, game seed = %d\n", numPlayers, player, gameSeed);
		}

		if(state.handCount[player] != curHandCount + 2) {
			printf("Adventurer: FAIL hand count did not increase appropriately\n");
			printf("Test # %d, deckCount = %d, discardCount = %d, handCount = %d\n", testCount, curDeckCount, curDiscardCount, curHandCount);
			printf("number of players = %d, current player = %d, game seed = %d\n", numPlayers, player, gameSeed);
		}

		// now for the teeasure card test
		int cardOne = state.hand[player][state.handCount[player]-1];
		int cardTwo = state.hand[player][state.handCount[player]-2];

		if(cardOne != copper && cardOne != silver && cardOne != gold) {
			if(cardTwo != copper && cardTwo != silver && cardTwo != gold) {
				printf("Adventurer: FAIL last two cards in hand are not treasure\n");
				printf("Test # %d, deckCount = %d, discardCount = %d, handCount = %d\n", testCount, curDeckCount, curDiscardCount, curHandCount);
				printf("number of players = %d, current player = %d, game seed = %d\n", numPlayers, player, gameSeed);
			}
		}

		// this test is different than the unit tests previously conducted.
		// it will test something that was identified as lacking in the unit tests
		if(lastCard != state.hand[player][state.handCount[player]-3]) {
			printf("Adventurer: FAIL last card in original deck does not match card before two treasurer cards\n");
			printf("Test # %d, deckCount = %d, discardCount = %d, handcount = %d\n", testCount, curDeckCount, curDiscardCount, curHandCount);
			printf("number of players = %d, current player = %d, game seed = %d\n", numPlayers, player, gameSeed);
		}

	}
	// Note: some things like the discardCount increasing for deckCount<> 0 tests were not tested because the
	// discard count decrease if 'shuffle' was called in the middle of drawing cards in the regular function play
	// Though the shuffle function looks like it should error out for the adventurer card.

	return 0;
}
