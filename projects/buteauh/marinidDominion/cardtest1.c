#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "rngs.h"

#define NOISY_TEST 1

int main(){
	int i;
    	int seed = 1000;
    	int numPlayer = 2;
    	int maxBonus = 10;
    	int p, r, handCount;
    	int bonus = 0;
	int maxHandCount = 5;
    	int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    	struct gameState G, T;
	//memset(&G, 0, sizeof(struct gameState));
	initializeGame(numPlayer, k, seed, &G);
	//memset(&G, 0, sizeof(struct gameState));

	memcpy(&T, &G, sizeof(struct gameState));

	printf("TESTING Smithy\n");

	printf("Hand Before Smithy = %d\n", T.handCount[0]);

	printf("Deck Before Smithy = %d\n", T.deckCount[0]);

	cardEffect(smithy, 0, 0, 0, &T, 0, &bonus);

	printf("Adding 3 cards\n");

	printf("Cards in Hand : %d, Expected : %d\n", T.handCount[0], G.handCount[0] + 2);
	
	printf("Cards in the Deck : %d, Expected : %d\n", T.deckCount[0], G.deckCount[0] - 3);

	if(T.handCount[0] == G.handCount[0] + 2)
		printf("Hand Count : Success\n");
	else
		printf("Hand Count : Failure\n");

	if(T.deckCount[0] == G.deckCount[0] + 3)
                printf("Deck Count : Success\n");
        else
                printf("Deck Count : Failure\n");
	
	 printf("Testing Player 2\n");
         if (T.handCount[1] == G.handCount[1])
         {
                 if (T.deckCount[1] == G.deckCount[1])
                         printf("Success : Player 2 Unaffected\n");
         }

         else
                 printf("Failure : Player 2 has been affected\n");


	return 0;

}
