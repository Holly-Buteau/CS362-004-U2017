#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "math.h"
#include <time.h>

struct gameState prepGame(int numPlayer)
{
	int x;
	int y;
	int seed = 1000;
	struct gameState prepGame;
	int k[10] = {adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall};
	int card;
	int coin;
	memset(&prepGame, 23, sizeof(struct gameState));
	initializeGame(numPlayer, k, seed,&prepGame);
	
	for(x = 0; x < numPlayer; x++)
	{
		prepGame.deckCount[x] = (int)(rand () % MAX_DECK);
		prepGame.discardCount[x] = (int)(rand() % MAX_DECK);
		prepGame.handCount[x] = (int)(rand () % MAX_HAND);
		
		

		for(y = 0; y < prepGame.handCount[y]; y++)
		{
			card = (int)(rand () % 3);
			coin = (int)(rand () % 3);
			
			if (card == 0)
				prepGame.hand[x][y] = k[rand() % 10];	

			else
			{
				if (coin == 0)
	                                 prepGame.deck[x][y] = copper;					
				if (coin == 1)
                                         prepGame.deck[x][y] = silver;
				if (coin == 2)
                                        prepGame.deck[x][y] = gold;
			}

					
	
                              
			
 		}

		
		for(y = 0; y < prepGame.deckCount[y]; y++)	
		{

			 card = (int)(rand () % 3);
			 coin = (int)(rand () % 3);
                         if (card == 0)
 	                 {     int ran = (rand() % 10); 
				//printf("Adding card %d\n", ran);
				prepGame.hand[x][y] = k[ran];
				 //printf("Adding card %d\n", prepGame.hand[x][y]);
			}

			 else
			{
				//coin = (int)(rand () % 3);
				if (coin == 0)
                                {	prepGame.deck[x][y] = copper;
				//	printf("Copper Added\n");
				}	
				if (coin == 1)
				{
					prepGame.deck[x][y] = silver;
				//	printf("Silver Added\n");
				}

				if (coin == 2)
                                {
				        prepGame.deck[x][y] = gold;	
				//	printf("Copper Added\n");
				}
			}
		
		}
		
	
		for(y = 0; y < prepGame.discardCount[y]; y++)
                {
			card = (int)(rand () % 3);
                        if (card == 0)
                               prepGame.discard[x][y] = k[rand() % 10];
                        else
			{
                               coin = (int)(rand () % 3);
                               if (coin == 0)
                                       prepGame.discard[x][y] = copper;
                               if (coin == 1)
                                       prepGame.discard[x][y] = silver;
                               if (coin == 2)
                                       prepGame.discard[x][y] = gold;
			}
               }

	}
	
	return prepGame;


}
int main()
{
	int i;
	int x;
    	int seed;
	int loop = 10000;
    	int numPlayer;
    	int maxBonus = 10;
    	int p, r, handCount;
    	int bonus = 0;
	int currPlayer;
    	int cardDrawn;
	int numCoins;
	int numDiscard;
	int temphand[MAX_HAND];
	int drawntreasure = 0;
   	struct gameState G, T;
	int error;
	srand(time(NULL));

	printf("Testing : Adventurer\n");

	for (x = 0; x < loop; x++)
	{
		numPlayer = rand() % (MAX_PLAYERS - 2 + 1) + 2;
		
		G = prepGame(numPlayer);
				
		currPlayer = (int)(rand () % numPlayer);
		G.whoseTurn = currPlayer;	
		memcpy(&T, &G, sizeof(struct gameState)); 	
		
		numCoins = G.coins;
		numDiscard = G.discardCount[currPlayer];
		callAdventurer(&G, currPlayer);
				

		if (G.coins != numCoins + 1)
		{
			printf("Adventure Card Test Fails for Test: %d on Coin Count\n", i);
			printf("Initial Coins : %d\n", numCoins);
			printf("Coins now : %d\n", G.coins);
			printf("Expected Coins : %d\n", numCoins + 1);
			error++;	
		}

		printf("Adventure Card Test Complete\n");
		printf("There were %d errors found\n", error);
		
		 
		
	}
		

	return 0;
}
