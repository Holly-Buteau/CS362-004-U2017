#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main()
{
	int i;
    	int seed = 1000;
   	int numPlayer = 2;
    	int maxBonus = 10;
    	int p, r, handCount;
    	int bonus;
    	int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    	struct gameState G, T;
    	int maxHandCount = 5;

	initializeGame(numPlayer, k, seed, &G);
        memcpy(&T, &G, sizeof(struct gameState));
 
        printf("TESTING Village\n");
        printf("Should have 3 extra cards in hand and 1 extra action\n");
 
        cardEffect(village, 0, 0, 0, &T, 0, &bonus);
 
        printf("Hand Count = %d, expected = %d\n", T.handCount[0], G.handCount[0] + 3 - 1);
        if (T.handCount[0] == G.handCount[0] + 3 - 1)
                printf("Success\n");
        else
                printf("Failure\n");
 
        printf("Deck Count = %d, expected = %d\n", T.deckCount[0], G.handCount[0] - 3);
        if (T.deckCount[0] == G.deckCount[0] - 3)
                printf("Success\n");
        else
                printf("Failure\n");
 
        printf("Played Count = %d, expected = %d\n", T.playedCardCount, G.playedCardCount + 1);
        if (T.playedCardCount == G.playedCardCount + 1)
                printf("Success\n");
        else
                printf("Failure\n");
 
        if (T.numActions == G.numActions + 1)
		printf("Success, there is one extra action to take\n");
	else
		printf("Failure, no extra actions allowed\n");
 
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
