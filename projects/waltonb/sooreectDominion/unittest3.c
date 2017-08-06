//Test for whoseTurn

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

	printf("TESTING whoseTurn():\n");

	memset(&G, 23, sizeof(struct gameState));
	r = initializeGame(numPlayer, k, seed, &G);

	for (i = 0; i < numPlayer; i++) {
		G.whoseTurn = i;
		printf("Testing G->whoseTurn = %d:\n", i);
		t = whoseTurn(&G);

#if (NOISY == 1)
		printf("G->whoseTurn is %d, expected %d\n", t, i);
#endif

		if (t == i) {
			printf("TEST SUCCESSFUL\n");
		} else {
			printf("TEST FAILED\n");
		}
	}

	exit(0);
}
