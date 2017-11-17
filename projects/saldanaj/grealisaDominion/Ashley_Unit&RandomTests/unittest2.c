// Unit test to test getCost()
// Assignment 3

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"


int main() {
	// test a few different card for getCost as well as a 
	// card that doesn't exist
	printf("Test for getCost()\n");
	
	if(getCost(curse) == 0) {
		printf("getCost(): PASS for curse card\n");
	}
	else {
		printf("getCost(): FAIL for curse card\n");
	}

	if(getCost(duchy) == 5) {
		printf("getCost(): PASS for duchy card\n");
	}
	else {
		printf("getCost(): FAIL for duchy card\n");
	}

	if(getCost(feast) == 4) {
		printf("getCost(): PASS for feast card\n");
	}
	else {
		printf("getCost(): FAIL for feast card\n");
	}

	if(getCost(village) == 3) {
		printf("getCost(): PASS for village card\n");
	}
	else {
		printf("getCost(): FAIL for village card\n");
	}
	
	if(getCost(embargo) == 2) {
		printf("getCost(): PASS for embargo card\n");
	}
	else {
		printf("getCost(): FAIL for embargoo card\n");
	}

	if(getCost(-1) == -1) {
		printf("getCost(): PASS for nonexistent card\n");
	}
	else {
		printf("getCost(): FAIL for nonexistent card\n");
	}

	return 0;
}
