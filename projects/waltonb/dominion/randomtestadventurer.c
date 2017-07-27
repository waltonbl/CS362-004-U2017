#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int testCard(int p, struct gameState *post) {

	int r, drawnTreasure = 0, cardDrawn, bonus = 0;
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));

	r = cardEffect(post->hand[p][0], 0, 0, 0, post, 0, &bonus);
	if (r != 0) {
		printf("Error in return value\n");
		return(1);
	}

	while(drawnTreasure < 2) {
		if (pre.deckCount[p] < 1) {
			shuffle(p, &pre);
		}
		drawCard(p, &pre);
		cardDrawn = pre.hand[p][pre.handCount[p] - 1];
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) {
			drawnTreasure++;
		} else {
			pre.discard[p][pre.discardCount[p]++] = pre.hand[p][pre.handCount[p] - 1];
			pre.handCount[p]--;
		}
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

	int i, n, p, good = 0, bad = 0, ret, cop;
	struct gameState G;
	

	printf("Testing Adventurer Card...\n");

	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 2000; n++) {
		printf("iteration: %d\n", n);
		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = floor(Random() * 256);
		}
		p = floor(Random() * 2);
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * (MAX_DECK - G.deckCount[p]));
		while (G.deckCount[p] < 10 && G.discardCount[p] < 10) {
			G.deckCount[p] = floor(Random() * MAX_DECK);
			G.discardCount[p] = floor(Random() * (MAX_DECK - G.deckCount[p]));
		}
		if (G.deckCount[p] > 9) {
			cop = floor(Random() * G.deckCount[p]) - 2;
			if (cop < 0) cop = 0;
			G.deck[p][cop] = copper;
			G.deck[p][cop + 1] = copper;
		} else {
			cop = floor(Random() * G.discardCount[p]) - 2;
			if (cop < 0) cop = 0;
			G.discard[p][cop] = copper;
			G.discard[p][cop + 1] = copper;
		}
		G.handCount[p] = floor(Random() * MAX_DECK);
		if (G.handCount[p] < 1)
			G.handCount[p] = 1;
		G.hand[p][0] = 7;
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
