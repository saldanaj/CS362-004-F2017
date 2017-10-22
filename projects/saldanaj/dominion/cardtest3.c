/*
 Student: Joaquin Saldana
 Assignment 3
 
 Testing of the greatHall card
 
 original function in the dominion.c file
 
 int great_hallCard(struct gameState *state, int handPosition)
 {
	 int currentPlayer = whoseTurn(state);
 
	 //+1 Card
	 drawCard(currentPlayer, state);
 
	 //+1 Actions
	 state->numActions++;
 
	 //discard card from hand
	 discardCard(handPosition, currentPlayer, state, 0);
 
	 // DEBUG - changed return statement from 0 to 1
	 return 1;
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
	printf("\n** Card Test 3: Testing function greatHallCard() **\n");
	
	struct gameState state;
	struct gameState temp;
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	
	int j;
	int player1 = 0;
	int player2 = 1;
	int players = 2;
	int initHandSize;
	int initNumActions;
	int position = 3;
	int postNumActions;
	
	// initialize the game
	initializeGame(players, k, 1000, &state);
	memcpy(&temp, &state, sizeof(struct gameState));
	
	temp.hand[player1][0] = council_room;
	temp.hand[player1][1] = estate;
	temp.hand[player1][2] = minion;
	temp.hand[player1][3] = great_hall;         // handPos = 3
	temp.hand[player1][4] = feast;
	
	initHandSize = temp.handCount[player1];
	initNumActions = temp.numActions;
	
	char * msg1 = "Testing Great Hall Card with Position 3.  Possible error due to bug in Week 2 Assignment";
	int testResult = great_hallCard(&temp, position);
	jqAssert(testResult, msg1);
	
	// checking how many cards the player will have (drawn vs discarded)
	int postHandSize1;
	int postHandSize2 = 0;
	
	postHandSize1 = temp.handCount[player1];
	
	for (j = 0; j < temp.handCount[player1]; j++)
	{
		postHandSize2++;
	}
	
	printf("Testing Hand Size\n\n");
	
	if ((postHandSize1 == initHandSize) && (postHandSize2 == initHandSize))
	{
		printf("Test Passed\n");
		printf("Expected hand size of %d; function check was %d and iterative check was %d\n\n", initHandSize, postHandSize1, postHandSize2);
	}
	else
	{
		printf("Test Failed\n");
		printf("Expected hand size of %d; function check was %d and iterative check was %d\n\n", initHandSize, postHandSize1, postHandSize2);
	}
	
	printf("Testing the number of actions increased\n\n");
	
	postNumActions = temp.numActions;
	
	if (postNumActions == initNumActions + 1)
	{
		printf("Test Passed\n");
		printf("Expected numActions of %d, actual numActions was %d\n\n", initNumActions, postNumActions);
	}
	else
	{
		printf("Test Failed\n");
		printf("Expected numActions of %d, actual numActions was %d\n\n", initNumActions, postNumActions);
	}
	
	printf("Testing other player hands were not affected\n\n");
	
	if (temp.handCount[player2] == state.handCount[player2])
	{
		printf("Test Passed\n");
		printf("Expected hand size of %d for player2, actual hand size was %d\n\n", state.handCount[player2], temp.handCount[player2]);
	}
	else
	{
		printf("Test Failed\n");
		printf("Expected hand size of %d for player2, actual hand size was %d\n\n", state.handCount[player2], temp.handCount[player2]);
	}
	
	printf("\n** End of Unit Test 3 **\n");
	
	return 0;
}
