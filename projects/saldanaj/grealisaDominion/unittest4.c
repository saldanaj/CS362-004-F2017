/*
 Student: Joaquin Saldana
 Assignment 3
 
 Testing the fullDeckCount() function which takes a player number,
 card number, and the state of the game as arguments.  It's my understanding the
 function counts how many times the card is present in the deck, players hands,
 and in the discard pile.  From what i can also tell it returns the number of instances
 the card is present to see if we have a full deck.
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
	printf("\n** Unit Test 4: Testing Function fullDeckCount() **\n");
	
	int a, j, m;
	int thisPlayer = 0;
	struct gameState state;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room};
	char* cardName[] = {"adventurer", "embargo", "village", "minion", "mine", "cutpurse","sea_hag", "tribute", "smithy", "council_room"};
	int numCardTypes = 10;
	int minCards = 0;
	int maxCards = 12;
	int error = 0;
	
	initializeGame(2, k, 1000, &state);
	
	for (a = minCards; a <= maxCards; a+=4)
	{
		state.handCount[thisPlayer] = a;
		
		printf("Testing cards for count of %d:\n", a);
		
		for (j = 0; j < numCardTypes; j++)
		{
			for (m=0; m < a; m++)
			{
				state.hand[thisPlayer][m] = k[j];
			}
			
			printf("Total cards = %d, %12s = %d, expected = %d\n",a, cardName[j], fullDeckCount(thisPlayer, k[j], &state), a);
			
			if(fullDeckCount(thisPlayer, k[j], &state) != a)
			{
				error = 1;
				break;
			}

		}
	}
	
	if(error)
	{
		printf("FAILURE: Incorrect card count\n");
	}
	else
	{
		printf("SUCCESS: Correct number of cards\n");
	}
	
	return 0;
}

