//Testing for smithy

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

	printf("TESTING smithy:\n");

	memset(&G, 23, sizeof(struct gameState));
	r = initializeGame(numPlayer, k, seed, &G);
	G.whoseTurn = 0;
	G.numActions = 1;
	G.phase = 0;
	G.hand[0][0] = 13;
	G.handCount[0] = 1;

	t = playCard(0, 0, 0, 0, &G);

#if (NOISY == 1)
	printf("Return value is %d, expected %d\n", t, 0);
#endif

	if (t == 0) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

#if (NOISY == 1)
	printf("G->whoseTurn is %d, expected %d\n", G.whoseTurn, 0);
#endif

	if (G.whoseTurn == 0) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

#if (NOISY == 1)
	printf("G->numActions is %d, expected %d\n", G.numActions, 0);
#endif

	if (G.numActions == 0) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

#if (NOISY == 1)
	printf("G->handCount[0] is %d, expected %d\n", G.handCount[0], 3);
#endif

	if (G.handCount[0] == 3) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

	exit(0);
}
