#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

//Define some globals
#define TESTEDCARD "outpost"
#define GAINED 2
#define DRAW 3
#define DISCARD 1
#define NUM_TESTS 100
#define ACTION 1

void printTorF(int condition, char *test, int *passed) {
	//If the condition passed is true, print that the test passed
	if (condition) {
		printf("PASS: %s\n", test);
	}
	//If the condition passed is false, print that the test failed and that all the tests did not pass
	else {
		printf("FAIL: %s\n", test);
		*passed = 0;
	}
}

void checkOutpost(int player, struct gameState *post, int handPos, int *passed, int iterator) {
	//Initialize a game
	struct gameState game1;
	memcpy(&game1, post, sizeof(struct gameState));

	int r, i, bonus = 0;
	r = outpostFunct(post, handPos);
	//Print which test we are on
	printf("Iteration #%d:\n", iterator + 1);

	//Check that our outpost card passes
	printTorF(r == 0, "outpostEffect(): returns correctly", passed);

	//Check that the player gains one card
	printTorF(post->handCount[player] == game1.handCount[player] + NET_GAINED, "Hand count is correct", passed);

	//Set the drawn cards correctly
	int cardDrawn = post->handCount[player] - game1.handCount[player] + DISCARD;

	//Check to see that the deck was affected by the amount of cards drawn
	printTorF(post->deckCount[player] + cardDrawn == game1.deckCount[player], "Deck count is correct", passed);

	//Check that the amount of coins increased
	//r = updateCoins(player, post, bonus);
	//printTorF(r == 0, "updateCoins(): returns correctly", passed);
	printTorF(post->coins > game1.coins, "Player gained coins correctly", passed);

	//Check that cards added to hand are treasures
	printTorF(treasureCard(post->hand[player][post->handCount[player] - 1]) && treasureCard(post->hand[player][post->handCount[player] - 2]) , "Player gained correct treasures", passed);

	//Check that the correct amount of cards were played
	printTorF(game->playedCardCount == game1.playedCardCount + DISCARD, "Played card count is correct", passed);

	//Check that the last played card was outpost
	printTorF(game->playedCards[game->playedCardCount - 1] == TESTEDCARD, "outpost was last card played", passed);

	//Create a copy of our game1
	struct gameState copyGame;
	memcpy(&copyGame, &game1, sizeof(struct gameState));
	
	//Copy all the changes from game to our copy of game
	copyGame.handCount[player] = game->handCount[player];
	copyGame.deckCount[player] = game->deckCount[player];
	copyGame.playedCardCount = game->playedCardCount;
	copyGame.discardCount[player] = game->discardCount[player];
	copyGame.numActions = post->numActions;
	copyGame.coins = post->coins;

	//Copy the cards in the players deck
	memcpy(copyGame.deck[player], game->deck[player], sizeof(int) * copyGame.deckCount[player]);
	//Copy the cards in the players discard
	memcpy(copyGame.discard[player], game->discard[player], sizeof(int) * copyGame.discardCount[player]);
	//Copy the cards that the player played
	memcpy(copyGame.playedCards, game->playedCards, sizeof(int) * copyGame.playedCardCount);
	//For each of the players cards
	for (i = 0; i < MAX_HAND; i++) {
		//Copy the cards in the player's hand
		copyGame.hand[player][i] = game->hand[player][i];
	}
	//Print if the game state has been changed
	printTorF(memcmp(&copyGame, game, sizeof(struct gameState)) == 0, "Game state is overall correct", passed);

	printf("\n");
}

int main() {
	int i, n, p, handPos;
	int passed = 1;
	//Initialize the game
	struct gameState game;
	//Print that we are testing whatever card was set
	printf("Random Testing: %s\n\n", TESTEDCARD);
	//Sets current random number generator stream
	SelectStream(5);
	//Sets state of current random number generator
	PutSeed(10);
	//For all the tests
	for (n = 0; n < NUM_TESTS; n++) {
		//random byte for gamestate
		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&game)[i] = floor(Random() * 256);
		}
		//Pick a random amount of players between 1 and 3
		p = floor(Random() * 3);

		//Randomize the amount in the deck
		game.deckCount[p] = floor(Random() * MAX_DECK);

		//Randomize the amount in the discard
		game.discardCount[p] = floor(Random() * MAX_DECK);

		//Randomize the amount in a players hand
		game.handCount[p] = floor(Random() * MAX_HAND);

		//Randomize the count of cards played
		game.playedCardCount = floor(Random() * MAX_DECK);

		//Randomize the number of cards played
		game.playedCards[p] = floor(Random() * MAX_DECK);

		//Randomize where the outpost will be in the hand 
		handPos = floor(Random() * game.handCount[p]);

		//Put the outpost in the hand at the random position
		game.hand[p][handPos] = TESTEDCARD;
		
		//Randomize the amount of coins in the game
		game.coins = floor(Random() * 100);
		
		//Call our test function
		checkOutpost(p, &game, handPos, &passed, n);
	}
	//If the tests passed
	if (passed)
		printf("All tests passed\n");

	return 0;
}