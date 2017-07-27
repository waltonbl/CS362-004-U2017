#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int testCard(int p, struct gameState *post) {

	int r, i, bonus = 0;
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));

	r = cardEffect(post->hand[p][0], 0, 0, 0, post, 0, &bonus);
	if (r != 0) {
		printf("Error in return value\n");
		return(1);
	}

	for (i = 0; i < 3; i++) {
		drawCard(p, &pre);
	}

	discardCard(0, p, &pre, 0);
	if (memcmp(&pre, post, sizeof(struct gameState)) == 0) {
		printf("PASSED\n");
		return(0);
	} else {
		return(1);
	}
}

int main() {

	int i, n, p, good = 0, bad = 0, ret;
	struct gameState G;
	

	printf("Testing Smithy Card...\n");

	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 2000; n++) {
		printf("iteration: %d\n", n);
		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = floor(Random() * 256);
		}
		G.numPlayers = 4;
		p = floor(Random() * 4);
		for (i = 0; i < G.numPlayers; i++) {
			G.deckCount[i] = floor(Random() * MAX_DECK);
			G.discardCount[i] = floor(Random() * MAX_DECK);
			while (G.deckCount[i] < 10 && G.discardCount[i] < 10) {
				G.deckCount[i] = floor(Random() * MAX_DECK);
				G.discardCount[i] = floor(Random() * MAX_DECK);
			}
			G.handCount[i] = floor(Random() * MAX_DECK) - 6;
		}
		if (G.handCount[p] < 1)
			G.handCount[p] = 1;
		G.hand[p][0] = 13;
		G.playedCardCount = 0;
		G.whoseTurn = p;
		ret = testCard(p, &G);
		if (ret == 0) {
			good++;
		} else {
			bad++;
		}
	}
	
	printf("%d tests passed, %d tests failed\n", good, bad);

	return(0);
}
