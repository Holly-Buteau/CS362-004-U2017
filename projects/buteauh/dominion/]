#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1
int main() {
	int i;
	int seed = 1000;
	int numPlayer = 2;
	int maxBonus = 10;
	int p, r, handCount;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int cardCount;
	struct gameState G, T;
	initializeGame(numPlayer, k, seed, &G);
	
	memcpy(&T, &G, sizeof(struct gameState));
	printf("TESTING : fullDeckCount\n");
	T.deckCount[0] = 0;
	T.handCount[0] = 0;
	T.discardCount[0] = 0;
	cardCount = fullDeckCount(0, adventurer, &T);
	printf("Testing with all decks empty\n");
	printf("Full Deck = %d, expected = %d\n", cardCount, 0);
	if(cardCount == 0)
		printf("Success\n");
	else
		printf("Failure\n");

	memcpy(&T, &G, sizeof(struct gameState));
	T.deckCount[0] = 1;
        T.handCount[0] = 5;
        T.discardCount[0] = 3;
	T.deck[0][0] = copper;
	T.hand[0][0] = gold;
	T.hand[0][1] = gold;
	T.hand[0][2] = silver;
	T.hand[0][3] = copper;
	T.hand[0][4] = mine;
	T.discard[0][0] = silver;
	T.discard[0][1] = copper;
	T.discard[0][2] = copper; 
	cardCount = fullDeckCount(0, copper, &T);
	printf("Testing : Looking For Copper\n");
	printf("In Discard : 2 Copper. In Deck : 1 Copper. In Hand : 1 Copper\n");
	printf("Full Deck = %d, expected = %d\n", cardCount, 4);
	
	if(cardCount == 4)
                  printf("Success\n");
        else
                  printf("Failure\n");
	

	return 0;
}	
		
	
