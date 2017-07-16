//Test for council room

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

#define NOISY 1

int main() {
	int i, r, t;
	int seed = 200;
	int numPlayer = 4;
	int k[10] = {adventurer, smithy, council_room, feast, gardens
			, mine, remodel, village, baron, great_hall};
	struct gameState G;

	printf("TESTING council room:\n");

	memset(&G, 23, sizeof(struct gameState));
	r = initializeGame(numPlayer, k, seed, &G);
	G.whoseTurn = 0;
	G.numActions = 1;
	G.numBuys = 0;
	G.phase = 0;
	G.hand[0][0] = 8;
	G.handCount[0] = 1;
	for (i = 1; i < numPlayer; i++) {
		G.handCount[i] = 0;
	}

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
	printf("G->numBuys is %d, expected %d\n", G.numBuys, 1);
#endif

	if (G.numBuys == 1) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

#if (NOISY == 1)
	printf("G->handCount[0] is %d, expected %d\n", G.handCount[0], 4);
#endif

	if (G.handCount[0] == 4) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

	for (i = 1; i < numPlayer; i++) {

#if (NOISY == 1)
		printf("G->handCount[%d] is %d, expected %d\n", i, G.handCount[i], 1);
#endif

		if (G.handCount[i] == 1) {
			printf("TEST SUCCESSFUL\n");
		} else {
			printf("TEST FAILED\n");
		}
	}

	exit(0);
}
