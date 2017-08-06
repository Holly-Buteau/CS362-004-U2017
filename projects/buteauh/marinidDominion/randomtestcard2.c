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
			if (card == 0)
				prepGame.hand[x][y] = k[rand() % 10];	

			else
				prepGame.hand[x][y] = copper;
			
 		}

		
		for(y = 0; y < prepGame.deckCount[y]; y++)	
		{

			 card = (int)(rand () % 3);
			 coin = (int)(rand () % 3);
                         if (card == 0)
 	                 {     int ran = (rand() % 10); 
				
				prepGame.hand[x][y] = k[ran];
				 
			}

			 else
			{
				
				if (coin == 0)
                                {	prepGame.deck[x][y] = copper;
				
				}	
				if (coin == 1)
				{
					prepGame.deck[x][y] = silver;
				
				}

				if (coin == 2)
                                {
				        prepGame.deck[x][y] = gold;	
				
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
    	int seed;
	int loop = 10000;
    	int numPlayer;
    	int maxBonus = 10;
    	int p, r, handCount;
    	int bonus = 0;
	int currPlayer;
    	int cardDrawn;
	int countActions;
	int countCards;
	int numDiscount;
	int temphand[MAX_HAND];
	int drawntreasure = 0;
   	struct gameState G, T;

	srand(time(NULL));

	printf("Testing : Great Hall\n");

	for (i = 0; i < loop; i++)
	{
		
		numPlayer = rand() % (MAX_PLAYERS - 2 + 1) + 2;
		
		G = prepGame(numPlayer);
				
		currPlayer = (int)(rand () % numPlayer);
		G.whoseTurn = currPlayer;	
	
		memcpy(&T, &G, sizeof(struct gameState)); 	
		
		countActions = G.numActions;
		countCards = G.handCount[currPlayer];
		great_hallFunct(&G, 0);

		if (G.numActions != countActions + 1)
		{
			printf("Great Hall Card Test Fails for Test: %d on Action Count\n", i);
			printf("Initial Actions : %d\n", countActions);
			printf("Action Count now : %d\n", G.numActions);
			printf("Expected Actions : %d\n", countActions + 1);
		}
	
		
		else
			printf("Great Hall Card Test Passes for Action Count\n");

		 if (G.handCount[currPlayer] != countCards)
                 {
                         printf("Great Hall Card Test Fails for Test: %d on Hand Count\n", i);
                         printf("Initial Hand : %d\n", countCards);
                         printf("Hand Count now : %d\n", G.handCount[currPlayer]);
                         printf("Expected Hand Count : %d\n", countCards);
                 }

                 else
                         printf("Great Hall Card Test Passes for Hand Count\n");

		
		 
		
	}
		

	return 0;
}

