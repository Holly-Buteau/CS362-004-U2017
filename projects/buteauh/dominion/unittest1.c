/********************************************************************
 * Testing getCost
 * testGetCost: unittest1.c dominion.o rngs.o
 * gcc -o unit1test -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 *****************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//with help from testUpdateCoints.c
//set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1


int main()
{
	int cardValue;
	printf ("TESTING : getCost\n");
	cardValue = getCost(curse);

	#if (NOISY_TEST == 1)
		printf ("Testing Curse\n");
		printf ("Card Value : %d True Value : 0\n", cardValue);
	
		if (cardValue == 0)
			printf ("Pass\n");
		else 
			printf ("Fail\n");

	#endif


	cardValue = getCost(estate);
 
        #if (NOISY_TEST == 1)
               printf ("Testing Estate\n");
               printf ("Card Value : %d True Value : 2\n", cardValue);
 
               if (cardValue == 2)
                       printf ("Pass\n");
               else
                       printf ("Fail\n");
        #endif

	
	cardValue = getCost(duchy);
 
        #if (NOISY_TEST == 1)
                printf ("Testing Duchy\n");
                printf ("Card Value : %d True Value : 5\n", cardValue);
 
                if (cardValue == 5)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif


	 cardValue = getCost(province);
 
         #if (NOISY_TEST == 1)
                printf ("Testing Province\n");
                printf ("Card Value : %d True Value : 8\n", cardValue);
 
                if (cardValue == 8)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
        #endif
	
	
	cardValue = getCost(copper);
 
        #if (NOISY_TEST == 1)
                printf ("Testing Copper\n");
                printf ("Card Value : %d True Value : 0\n", cardValue);
 
                if (cardValue == 0)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif

	
	 cardValue = getCost(silver);
 
         #if (NOISY_TEST == 1)
                printf ("Testing Silver\n");
                printf ("Card Value : %d True Value : 3\n", cardValue);
 
                if (cardValue == 3)
                        printf ("Pass\n");
                else
                         printf ("Fail\n");
 
        #endif


	 cardValue = getCost(gold);
         #if (NOISY_TEST == 1)
                printf ("Testing Gold\n");
                printf ("Card Value : %d True Value : 6\n", cardValue);
 
                if (cardValue == 6)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif

	
	 cardValue = getCost(adventurer);
 
        #if (NOISY_TEST == 1)
               printf ("Testing Adventurer\n");
               printf ("Card Value : %d True Value : 6\n", cardValue);
 
               if (cardValue == 6)
                       printf ("Pass\n");
               else
                       printf ("Fail\n");
 
       #endif


	cardValue = getCost(council_room);
 
        #if (NOISY_TEST == 1)
                printf ("Testing Council Room\n");
                printf ("Card Value : %d True Value : 5\n", cardValue);
 
                if (cardValue == 5)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif


	 cardValue = getCost(feast);
 
         #if (NOISY_TEST == 1)
                 printf ("Testing Feast\n");
                 printf ("Card Value : %d True Value : 4\n", cardValue);
 
                 if (cardValue == 4)
                         printf ("Pass\n");
                 else
                         printf ("Fail\n");
 
        #endif


	cardValue = getCost(gardens);
 
        #if (NOISY_TEST == 1)
                printf ("Testing Gardens\n");
                printf ("Card Value : %d True Value : 4\n", cardValue);
 
                if (cardValue == 4)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif


	cardValue = getCost(mine);
 
        #if (NOISY_TEST == 1)
                printf ("Testing Mine\n");
                printf ("Card Value : %d True Value : 5\n", cardValue);
 
                if (cardValue == 5)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif


	cardValue = getCost(remodel);
 
        #if (NOISY_TEST == 1)
                printf ("Testing Remodel\n");
                printf ("Card Value : %d True Value : 4\n", cardValue);
 
                if (cardValue == 4)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif

	cardValue = getCost(smithy);
 
        #if (NOISY_TEST == 1)
                printf ("Testing Smithy\n");
                printf ("Card Value : %d True Value : 4\n", cardValue);
 
               if (cardValue == 4)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif

	cardValue = getCost(village);
        
	#if (NOISY_TEST == 1)
                printf ("Testing Village\n");
                printf ("Card Value : %d True Value : 3\n", cardValue);
 
                if (cardValue == 3)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
       #endif

	 cardValue = getCost(baron);
 
        #if (NOISY_TEST == 1)
                printf ("Testing Baron\n");
                printf ("Card Value : %d True Value : 4\n", cardValue);
 
                if (cardValue == 4)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif

	 cardValue = getCost(great_hall);
 
        #if (NOISY_TEST == 1)
                printf ("Testing Great Hall\n");
                printf ("Card Value : %d True Value : 3\n", cardValue);
 
               if (cardValue == 3)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif

	cardValue = getCost(minion);
 
        #if (NOISY_TEST == 1)
                printf ("Testing Minion\n");
                printf ("Card Value : %d True Value : 5\n", cardValue);
 
                if (cardValue == 5)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif


	 cardValue = getCost(steward);
 
        #if (NOISY_TEST == 1)
                printf ("Testing Steward\n");
                printf ("Card Value : %d True Value : 3\n", cardValue);
 
                if (cardValue == 3)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif

	 cardValue = getCost(tribute);
         #if (NOISY_TEST == 1)
                printf ("Testing Tribute\n");
                printf ("Card Value : %d True Value : 5\n", cardValue);
 
                if (cardValue == 5)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif

	 cardValue = getCost(ambassador);
 
        #if (NOISY_TEST == 1)
                printf ("Testing Ambassador\n");
                printf ("Card Value : %d True Value : 3\n", cardValue);
 
                if (cardValue == 3)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif

	 cardValue = getCost(cutpurse);
 
        #if (NOISY_TEST == 1)
                printf ("Testing CutPurse\n");
                printf ("Card Value : %d True Value : 4\n", cardValue);
 
                if (cardValue == 4)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif

	 cardValue = getCost(embargo);
 
        #if (NOISY_TEST == 1)
                printf ("Testing Embargo\n");
                printf ("Card Value : %d True Value : 2\n", cardValue);
 
                if (cardValue == 2)
                       printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif


	 cardValue = getCost(outpost);
 
        #if (NOISY_TEST == 1)
                printf ("Testing Outpost\n");
                printf ("Card Value : %d True Value : 5\n", cardValue);
 
                if (cardValue == 5)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif

	 cardValue = getCost(salvager);
         #if (NOISY_TEST == 1)
                printf ("Testing Salvager\n");
                printf ("Card Value : %d True Value : 4\n", cardValue);
 
                if (cardValue == 4)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif

	 cardValue = getCost(sea_hag);
 
        #if (NOISY_TEST == 1)
                printf ("Testing Sea Hag\n");
                printf ("Card Value : %d True Value : 4\n", cardValue);
 
                if (cardValue == 4)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif

	 cardValue = getCost(treasure_map);
 
        #if (NOISY_TEST == 1)
                printf ("Testing Treasure Map\n");
                printf ("Card Value : %d True Value : 4\n", cardValue);
 
                if (cardValue == 4)
                        printf ("Pass\n");
                else
                        printf ("Fail\n");
 
       #endif

	printf ("Tests Finished\n");

	return 0;
}
