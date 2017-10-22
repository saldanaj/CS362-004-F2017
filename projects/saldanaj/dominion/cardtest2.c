/*
 Student: Joaquin Saldana
 Assignment 3
 
 Testing the smithy card
 
 - Main test is to see if it increases a players handsize by 3
 but w/ bug introduced in week 2 assignment it will only give the player
 2 cards instead of 3
 
 function code:
 
 int smithyCard(struct gameState *state, int handPosition)
 {
	 int currentPlayer = whoseTurn(state);
	 int i;
 
	 //+3 Cards
 
	 // DEBUG changed i from 0 to 1 in the for loop counter
	 for (i = 1; i < 3; i++)
	 {
	 drawCard(currentPlayer, state);
	 }
 
	 //discard card from hand
	 discardCard(handPosition, currentPlayer, state, 0);
 
	 return 0;
 }
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assertions.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


int main (int argc, char** argv)
{
	printf("\n** Card Test 2: Testing function smithyCard() **\n");
	
	struct gameState state;
	struct gameState temp;
	
	int k[10] = {copper, minion, mine, silver, gold, cutpurse,sea_hag, tribute, smithy, council_room};
	
	initializeGame(2, k, 1000, &state);
	
	memcpy(&temp, &state, sizeof(struct gameState));
	
	smithyCard(&temp, 0);
	
	printf("Expected number of cards: %d, Result: %d\n", state.handCount[state.whoseTurn] + 3, temp.handCount[temp.whoseTurn]);
	
	state.discardCount[state.whoseTurn] = 5;
	
	memcpy(&temp, &state, sizeof(struct gameState));
	
	smithyCard(&temp, 0);
	
	discardCard(0, state.whoseTurn, &state, 0);
	
	printf("Expected total card count: %d, Result: %d\n", state.discardCount[state.whoseTurn], temp.discardCount[temp.whoseTurn]);
	
	printf("\n** End of Card Test 2 **\n");
	
	return 0;
}
