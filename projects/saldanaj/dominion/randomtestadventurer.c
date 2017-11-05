/*
 Student: Joaquin Saldana
 Description: This is the random test generator
 for the adventurer card
 
 Below is the code for the adventurer card function that was refactored in assignment 2:
 
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
#include <time.h>

#define MAX_ATTEMPTS 50


int main (int argc, char** argv)
{
	
	srand(time(NULL));

	printf("\n** Random Test 1: Testing function adventureCard() **\n");
	
	int a = 0;
	int x;
	int treas = 0;
	int draw;
	int i = 0;
	int treasure1 = 0;
	int treasure2 = 0;
	int temp[MAX_HAND];
	int numPlayers = 2;
	struct gameState state;
	
	// Main purpose now is to start creating random values for the properties of the
	// gameState such as a random seed, and a random card value from the set of 10 selected
	// i dont think the set itself should be randomly selected since we can partition the set
	// with the inference that any set would be just as effective
	
	do
	{
		
		int seed = random_number(1, 1000);
		
		int k[10] = {minion, mine, adventurer, great_hall, cutpurse,sea_hag, tribute, smithy, council_room, copper};
		
		// now i'm randomly selecting my seed to start the game
		initializeGame(numPlayers, k, seed, &state);
		
		// Now, i'm randomly selecting the card to start with from the set above
		state.hand[state.whoseTurn][0] = k[random_number(0, 9)];
		
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
		
		a++;
		
	}while(a < MAX_ATTEMPTS);
	
	
	printf("\n** End of Random Testing for Adventurer Card **\n");
	
	return 0;
}


