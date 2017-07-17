/************************************************************************
 * UpdateCoin Test
 * put in makefile : 
 * testUpdateCoin: unittest2.c dominion.o rngs.o
 * 	gcc -o unit2test -g  unittest2.c dominion.o rngs.o $(CFLAGS)
 ***********************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    int testBonus = 0;
    struct gameState G, T;

	initializeGame(numPlayer, k, seed, &G);
	
	printf("TESTING : updateCoins\n");
	memcpy(&T, &G, sizeof(struct gameState));
	
	printf("Testing Only Treasure\n");
	T.hand[0][0] = smithy;
	T.hand[0][1] = village;
	T.hand[0][2] = copper;
	T.hand[0][3] = silver;
	T.hand[0][4] = gold;
	updateCoins(0, &T, testBonus);
	printf("Coin Worth = %d, expected = %d\n", T.coins, 6);
	if (T.coins == 6)
		printf("Success\n");
	else
		printf("Fail\n");


	//memset(&T, &G, sizeof(struct gameState));	


	printf("Testing Treasure and Bonuses\n");
	T.hand[0][0] = smithy;
        T.hand[0][1] = village;
        T.hand[0][2] = copper;
        T.hand[0][3] = silver;
        T.hand[0][4] = gold;
	testBonus = 10; 	
	updateCoins(0, &T, testBonus);
   	printf("Coin Worth = %d, expected = %d\n", T.coins, 16);
	if (T.coins == 16)
                printf("Success\n");
        else
                printf("Fail\n");
	 

	//memset(&T, &G, sizeof(struct gameState));

	printf("Testing Only Bonuses\n");		
	T.hand[0][0] = smithy;
        T.hand[0][1] = village;
        T.hand[0][2] = adventurer;
        T.hand[0][3] = gardens;
        T.hand[0][4] = remodel;
	testBonus = 10;
	updateCoins(0, &T, testBonus);
	printf("Coin Worth = %d, expected = %d\n", T.coins, 10);
	 if (T.coins == 10)
                 printf("Success\n");
         else
                 printf("Fail\n");
			
	
	return 0;

}		
