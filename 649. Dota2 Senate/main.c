#include <stdbool.h>
#include <stdio.h>

#define QUEUE_SIZE 10000

char *predictPartyVictory(char *senate) {
    size_t len = strlen(senate);
    int rq[QUEUE_SIZE];
    int rHead = 0;
    int rTail = 0;
    int dq[QUEUE_SIZE];
    int dHead = 0;
    int dTail = 0;

    for (size_t i = 0; i < len; i++) {
        if (senate[i] == 'R') {
            rq[rTail++] = i;
        } else {
            dq[dTail++] = i;
        }
    }

    while (rHead != rTail && dHead != dTail) {
        if (rq[rHead] < dq[dHead]) {
            rq[rTail++] = len + rq[rHead];
        } else {
            dq[dTail++] = len + dq[dHead];
        }

        rHead++;
        dHead++;
    }

    if (rHead == rTail) {
        return "Dire";
    }

    return "Radiant";
}