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
    	int bonus = 0;
    	int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    	struct gameState G, T;
    	int maxHandCount = 5;
	
	initializeGame(numPlayer, k, seed, &G);
	memcpy(&T, &G, sizeof(struct gameState));

	printf("TESTING Adventurer\n");
	printf("Should have 2 extra treasure in hand\n");
	
	cardEffect(adventurer, 0, 0, 0, &T, 0, &bonus);
	
	printf("Hand Count = %d, expected = %d\n", T.handCount[0], G.handCount[0] + 2);
	if (T.handCount[0] == G.handCount[0] + 2)
		printf("Success\n");
	else
		printf("Failure\n");

	printf("Deck Count = %d, expected = %d\n", T.deckCount[0], G.handCount[0] - 1);
	if (T.deckCount[0] == G.deckCount[0] - 1)
                printf("Success\n");
        else
                printf("Failure\n");

 	printf("Played Count = %d, expected = %d\n", T.playedCardCount, G.playedCardCount + 1);
        if (T.playedCardCount == G.playedCardCount + 1)
                printf("Success\n");
        else
                printf("Failure\n");
	
	if(T.coins > G.coins)
		printf("Success, treasure amount has increased\n");
	else
		printf("Failure, treasure remained the same\n");

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
	
 
