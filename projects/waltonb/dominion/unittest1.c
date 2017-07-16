//Test for buyCard

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

#define NOISY 1

int main() {
	int i, r, t;
	int seed = 200;
	int numPlayer = 2;
	int k[10] = {adventurer, smithy, council_room, feast, gardens
			, mine, remodel, village, baron, great_hall};
	struct gameState G;

	printf("TESTING buyCard():\n");

	memset(&G, 23, sizeof(struct gameState));
	r = initializeGame(numPlayer, k, seed, &G);
	G.whoseTurn = 0;
	G.numBuys = 0;
	G.coins = 10;
	G.supplyCount[7] = 1;

	printf("Testing: numBuys = 0:\n");
	t = buyCard(7, &G);

#if (NOISY == 1)
	printf("Return value is %d, expected %d\n", t, -1);
#endif
	if (t == -1) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

#if (NOISY == 1)
	printf("G->numBuys is %d, expected %d\n", G.numBuys, 0);
#endif

	if (G.numBuys == 0) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

#if (NOISY == 1)
	printf("G->supplyCount[7] is %d, expected %d\n", G.supplyCount[7], 1);
#endif

	if (G.supplyCount[7] == 1) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

#if (NOISY == 1)
	printf("G->coins is %d, expected %d\n", G.coins, 10);
#endif

	if (G.coins == 10) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

	G.numBuys = 1;
	G.supplyCount[7] = 0;

	printf("Testing: supplyCount = 0:\n");
	t = buyCard(7, &G);

#if (NOISY == 1) 
	printf("Return value is %d, expected %d\n", t, -1);
#endif

	if (t == -1) {
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
	printf("G->supplyCount[7] is %d, expected %d\n", G.supplyCount[7], 0);
#endif

	if (G.supplyCount[7] == 0) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

#if (NOISY == 1)
	printf("G->coins is %d, expected %d\n", G.coins, 10);
#endif

	if (G.coins == 10) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

	G.supplyCount[7] = 1;
	G.coins = 0;

	printf("Testing G->coins = 0:\n");

	t = buyCard(7, &G);

#if (NOISY == 1)
	printf("Return value is %d, expected %d\n", t, -1);
#endif

	if (t == -1) {
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
	printf("G->supplyCount[7] is %d, expected %d\n", G.supplyCount[7], 1);
#endif

	if (G.supplyCount[7] == 1) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

#if (NOISY == 1)
	printf("G->coins is %d, expected %d\n", G.coins, 0);
#endif

	if (G.coins == 0) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

	G.coins = 10;

	printf("Testing: Good buy:\n");

	t = buyCard(7, &G);

#if (NOISY == 1)
	printf("Return value is %d, expected %d\n", t, 0);
#endif

	if (t == 0) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

#if (NOISY == 1)
	printf("G->numBuys is %d, expected %d\n", G.numBuys, 0);
#endif

	if (G.numBuys == 0) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

#if (NOISY == 1)
	printf("G->supplyCount[7] is %d, expected %d\n", G.supplyCount[7], 0);
#endif

	if (G.supplyCount[7] == 0) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

#if (NOISY == 1)
	printf("G->coins is %d, expected %d\n", G.coins, 4);
#endif

	if (G.coins == 4) {
		printf("TEST SUCCESSFUL\n");
	} else {
		printf("TEST FAILED\n");
	}

	exit(0);
}
