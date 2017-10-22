/*
 Student: Joaquin Saldana
 Assignment 3
 
 Testing the adventure card
 
 function code:
 
 int adventurerCard(struct gameState *state)
 {
	 int drawntreasure = 0;
	 int currentPlayer = whoseTurn(state);
	 int cardDrawn;
	 int temphand[MAX_HAND];
	 int z = 0;
 
	 while(drawntreasure<2)
	 {
	 if (state->deckCount[currentPlayer] <1)
	 {//if the deck is empty we need to shuffle discard and add to deck
	 shuffle(currentPlayer, state);
	 }
 
	 drawCard(currentPlayer, state);
 
	 cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
 
	 // DEBUG removed the "cardDrawn == silver" statement from the if statement below
	 if (cardDrawn == copper || cardDrawn == gold)
	 drawntreasure++;
	 else
	 {
	 temphand[z]=cardDrawn;
	 state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
	 z++;
	 }
	 }
 
	 while(z-1 >= 0)
	 {
	 state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
	 z=z-1;
	 }
 
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
	printf("\n** Card Test 1: Testing function adventureCard() **\n");
	
	int x;
	int treas = 0;
	int draw;
	int i = 0;
	int treasure1 = 0;
	int treasure2 = 0;
	int temp[MAX_HAND];
	int seed = 500;
	int numPlayers = 2;
	struct gameState state;
	
	int k[10] = {minion, mine, adventurer, great_hall, cutpurse,sea_hag, tribute, smithy, council_room, copper};
	
	initializeGame(numPlayers, k, seed, &state);
	
	state.hand[state.whoseTurn][0] = minion;
	
	adventurerCard(&state);
	
	printf("Expected value: %d, Result: %d\n", state.handCount[state.whoseTurn] + 2, state.handCount[state.whoseTurn]);
	
	state.discardCount[state.whoseTurn] = 5;
	
	adventurerCard(&state);
	
	while(treas < 2)
	{
		drawCard(state.whoseTurn, &state);
		
		draw = state.hand[state.whoseTurn][state.handCount[state.whoseTurn]-1];
		
		if (draw == copper || draw == silver || draw == gold)
		{
			treas++;
		}
		else
		{
			temp[i] = draw;
			
			state.handCount[state.whoseTurn]--;
			
			i++;
		}
	}
	
	printf("Expected card count: %d, Result: %d\n", state.discardCount[state.whoseTurn] + i, state.discardCount[state.whoseTurn]);
	
	for(x = 0; x < state.handCount[state.whoseTurn]; x++)
	{
		if (state.hand[state.whoseTurn][x] == copper || state.hand[state.whoseTurn][x] == silver || state.hand[state.whoseTurn][x] == gold)
		{
			treasure1++;
		}
		
	}
	
	for(x = 0; x < state.handCount[state.whoseTurn]; x++)
	{
		
		if (state.hand[state.whoseTurn][x] == copper || state.hand[state.whoseTurn][x] == silver || state.hand[state.whoseTurn][x] == gold)
		{
			treasure2++;
		}
		
	}
	
	printf("Final expected treasure count: %d, Result: %d\n", treasure1, treasure2);

	printf("\n** End of Card Test 1 **\n");
	
	return 0;
}

