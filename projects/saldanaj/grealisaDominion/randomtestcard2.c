/*
 Student: Joaquin Saldana
 Description: this random test is testing the sea_hag card and it's
 effects when passed to the cardEffect function.
 
 Doing various tests with various random variables the include number of players, deck size and
 hand.
 
 We are testing to make sure the opponents top card in their deck is a curse card.
 
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


#define MAX_TESTS 20


int main (int argc, char** argv)
{
	
	srand(random_number(1, 1000));
	
	printf("Random Test 2 (sea_hag) Starting \n");
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy};
	int  a, i, players, player, handCount, deckCount, seed;
	struct gameState state;

	player = 0;
	
	seed = random_number(1, 1000);
	players = random_number(1, 4);
	
	for(i = 0; i < MAX_TESTS; i++)
	{
		
		initializeGame(players,k,seed,&state);
		
		for(a = 0; a < players; a++)
		{
			state.deckCount[a] = rand() % MAX_DECK;
			state.discardCount[a] = rand() % MAX_DECK;
			state.handCount[a] = rand() % MAX_HAND;
		
			handCount = state.handCount[player];
			deckCount = state.deckCount[player];
			
		}
		cardEffect(sea_hag,1,1,1,&state,0, 0);
		
	}
	
	
	for(a = 0; a < players; a++)
	{
		printf("The hand count for player %d is %d\n", a, state.handCount[a]);
		printf("The deck count for player %d is %d\n", a, state.handCount[a]);
	}

	
	printf("\n** End of Random Test Card 2 **\n");
	
	return 0;
}

