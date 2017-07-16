//Test for fullDeckCount

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

#define NOISY 1

int main() {
	int r, t;
	int seed = 200;
	int numPlayer = 2;
	int k[10] = {adventurer, smithy, council_room, feast, gardens
			, mine, remodel, village, baron, great_hall};
	struct gameState G;

	printf("TESTING fullDeckCount():\n");

	memset(&G, 23, sizeof(struct gameState));
	r = initializeGame(numPlayer, k, seed, &G);
	G.hand[0][0] = 0;
	G.deck[0][0] = 0;
	G.discard[0][0] = 0;
	G.discardCount[0] = 1;

	printf("Testing: Card not in hand, deck or discard:\n");
	t = fullDeckCount(0, 7, &G);

#if (NOISY == 1)
	printf("Card Count is %d, expected %d\n", t, 0);
#endif

	if (t == 0) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

	G.hand[0][0] = 7;

	printf("Testing: Card in hand but not in deck or discard:\n");
	t = fullDeckCount(0, 7, &G);

#if (NOISY == 1)
	printf("Card Count is %d, expected %d\n", t, 1);
#endif

	if (t == 1) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

	G.hand[0][0] = 0;
	G.deck[0][0] = 7;

	printf("Testing: Card in deck but not in hand or discard:\n");
	t = fullDeckCount(0, 7, &G);

#if (NOISY == 1)
	printf("Card Count is %d, expected %d\n", t, 1);
#endif

	if (t == 1) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

	G.deck[0][0] = 0;
	G.discard[0][0] = 7;

	printf("Testing: Card in discard but not in hand or deck:\n");
	t = fullDeckCount(0, 7, &G);

#if (NOISY == 1)
	printf("Card Count is %d, expected %d\n", t, 1);
#endif

	if (t == 1) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

	G.hand[0][0] = 7;
	G.deck[0][0] = 7;

	printf("Testing: Card in hand, deck and discard:\n");
	t = fullDeckCount(0, 7, &G);

#if (NOISY == 1)
	printf("Card Count is %d, expected %d\n", t, 3);
#endif

	if (t == 3) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

	exit(0);
}
