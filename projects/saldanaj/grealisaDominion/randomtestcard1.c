/*
 Student: Joaquin Saldana
 Description: this is the random test generator for the
 Council Room Card.  The function code for the council room
 card is as follows:
 
 int council_roomCard(struct gameState *state, int handPosition)
 {
 int currentPlayer = whoseTurn(state);
 int i;
 
 //+4 Cards
 // DEBUG- changed the loop counter limit from 4 to 3
 // giving the player a disadvantage by drawing one less card
 for (i = 0; i < 3; i++)
 {
 drawCard(currentPlayer, state);
 }
 
 //+1 Buy
 state->numBuys++;
 
 //Each other player draws a card
 for (i = 0; i < state->numPlayers; i++)
 {
 if ( i != currentPlayer )
 {
 drawCard(i, state);
 }
 }
 
 //put played card in played card pile
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

#define MAX_ATTEMPTS 20


/*
 Funtion to random select the cards from the deck in the players hand which will
 be set to 5
 */

void setHands(struct gameState s, int * cards)
{
	// going to randomly set the 5 cards in player 1's hand
	// vs in the unit tests we set them manually but at least one of the cards
	// will be the council room card
	
	int randomNum = random_number(0, 9);
	s.hand[0][0] = cards[randomNum];
	
	randomNum = random_number(0, 9);
	s.hand[0][1] = cards[randomNum];
	
	randomNum = random_number(0, 9);
	s.hand[0][2] = cards[randomNum];
	
	randomNum = random_number(0, 9);
	s.hand[0][3] = cards[randomNum];
	
	randomNum = random_number(0, 9);
	s.hand[0][4] = cards[randomNum];
}

int main (int argc, char** argv)
{
	srand(time(NULL));
	
	printf("\n** Random Card Test 1: Random Testing function council_roomCard() **\n");
	
	struct gameState state;
	struct gameState temp;
	
	
	int a = 0;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int player1 = 0;
	int player2 = 1;
	int players = 2;
	int initHandSize, initNumBuys, initp2Hand;
	int position = 0;
	
	
	do
	{
		initializeGame(players, k, random_number(1, 1000), &state);
		
		memcpy(&temp, &state, sizeof(struct gameState));
		
		setHands(temp, k);
		
		temp.handCount[player1] = 5;
		
		
		initHandSize = temp.handCount[player1];
		initNumBuys = temp.numBuys;
		initp2Hand = temp.handCount[player2];
		
		char * msg1 = "Testing council_roomCard()";
		int testResult = council_roomCard(&temp, position);
		jqAssert(testResult, msg1);
		
		printf("Testing if player drew 4 cards\n\n");
		
		if (temp.handCount[player1] == initHandSize + 3)
		{
			printf("Test Passed\n");
			printf("Expecting a hand size of %d, actual hand size was %d\n\n", initHandSize+3, temp.handCount[player1]);
		}
		else
		{
			printf("Test Failed\n");
			printf("Expecting a hand size of %d, actual hand size was %d\n\n", initHandSize+3, temp.handCount[player1]);
		}
		
		printf("Testing number of buys incremented\n\n");
		
		if (temp.numBuys == initNumBuys + 1)
		{
			printf("Test Passed\n");
			printf("Expecting number of buys to be %d, actual number of buys is %d\n\n", initNumBuys+1, temp.numBuys);
		}
		else
		{
			printf("Test Failed\n");
			printf("Expecting number of buys to be %d, actual number of buys is %d\n\n", initNumBuys+1, temp.numBuys);
		}
		
		printf("Testing if another player drew cards\n\n");
		
		if (temp.handCount[player2] == initp2Hand + 1)
		{
			printf("Test Passed\n");
			printf("Expecting a player2 hand size of %d, actual player2 hand size was %d\n\n", initp2Hand+1, temp.handCount[player2]);
		}
		else
		{
			printf("Test Failed\n");
			printf("Expecting player 2 hand size of %d, actual player2 hand size was %d\n\n", initp2Hand+1, temp.handCount[player2]);
		}

		
		a++;
		
	}while(a < MAX_ATTEMPTS);
	
	
	printf("\n** End of Random Test Card 1 **\n");
	
	return 0; 
}









