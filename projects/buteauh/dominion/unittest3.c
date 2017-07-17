#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, T;
    
    initializeGame(numPlayer, k, seed, &G);

    printf("TESTING isGameOver\n");

    memcpy(&T, &G, sizeof(struct gameState));
    G.supplyCount[province] = 1;
 
    printf("Testing if game is over with 1 province card\n");
 
    if (isGameOver(&G) == 1)
        printf("Game Ends - Failure\n");
 
    else
        printf("Game Continues - Success\n"); 

    G.supplyCount[province] = 0;

    printf("Testing if game is over with 0 province cards\n");

    if (isGameOver(&G) == 1)
	printf("Game Ends - Success\n");

    else 
	printf("Game Continues - Failure\n"); 
 
    memcpy(&G, &T, sizeof(struct gameState)); //clearing state again


    printf("Testing if game is over with 2 empty supply piles\n");
    G.supplyCount[gold] = 0;
    G.supplyCount[baron] = 0;
	
    if(isGameOver(&G) == 1)
          printf("Game Ends - Failure\n");
    else
          printf("Game Continues - Success\n");

    printf("Testing if game is over with 3 empty supply piles\n");

    G.supplyCount[remodel] = 0;
    
    if(isGameOver(&G) == 1)
	printf("Game Ends - Success\n");

    else
	printf("Game Continues - Failure\n");


    return 0;

}
    
