#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state, 
		int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);


/*
 Functions created to refactor the cardEFfect functions in the the dominion.c folder
 */
int card_Adventurer(int currentPlayer, int temphand[], struct gameState *state);
int card_Smithy(int currentPlayer, int handPos, struct gameState *state);
int card_Baron(int choice1, int currentPlayer, struct gameState *state);
int card_GreatHall(int currentPlayer, int handPos, struct gameState *state);
int card_Steward(int choice1, int choice2, int choice3,int currentPlayer, int handPos, struct gameState *state);
int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);

#endif
