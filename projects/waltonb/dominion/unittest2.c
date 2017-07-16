//Test for playCard

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

	printf("TESTING playCard():\n");

	memset(&G, 23, sizeof(struct gameState));
	r = initializeGame(numPlayer, k, seed, &G);
	G.phase = 1;
	G.whoseTurn = 0;
	G.numActions = 1;
	G.hand[0][0] = 7;

	printf("Testing: G->phase = 0:\n");
	t = playCard(0, 0, 0, 0, &G);

#if (NOISY == 1)
	printf("Return value is %d, expected %d\n", t, -1);
#endif

	if (t == -1) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

#if (NOISY == 1)
	printf("G->numActions is %d, expected %d\n", G.numActions, 1);
#endif

	if (G.numActions == 1) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

#if (NOISY == 1)
	printf("G->hand[0][0] is %d, expected %d\n", G.hand[0][0], 7);
#endif

	if (G.hand[0][0] == 7) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

	G.phase = 0;
	G.numActions = 0;

	printf("Testing: G->numActions = 0:\n");
	t = playCard(0, 0, 0, 0, &G);

#if (NOISY == 1)
	printf("Return value is %d, expected %d\n", t, -1);
#endif

	if (t == -1) {
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
	printf("G->hand[0][0] is %d, expected %d\n", G.hand[0][0], 7);
#endif

	if (G.hand[0][0] == 7) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

	G.numActions = 1;
	G.hand[0][0] = 6;

	printf("Testing: G->hand[0][0] = 6:\n");
	t = playCard(0, 0, 0, 0, &G);

#if (NOISY == 1)
	printf("Return value is %d, expected %d\n", t, -1);
#endif

	if (t == -1) {
		printf("TEST SUCCESSFUL\n");
	} else {

		printf("TEST FAILED\n");
	}

#if (NOISY == 1)
	printf("G->numActions is %d, expected %d\n", G.numActions, 1);
#endif

	if (G.numActions == 1) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

#if (NOISY == 1)
	printf("G->hand[0][0] is %d, expected %d\n", G.hand[0][0], 6);
#endif

	if (G.hand[0][0] == 6) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

	G.hand[0][0] = 7;

	printf("Testing: Good play:\n");
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
	printf("G->numActions is %d, expected %d\n", G.numActions, 0);
#endif

	if (G.numActions == 0) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

	exit(0);
}
