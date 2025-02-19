#include <stdio.h>

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxProfit(int k, int *prices, int pricesSize) {
    int *buys = (int *)malloc(k * sizeof(int));
    if (buys == NULL) {
        return 0;
    }

    for (int i = 0; i < k; i++) {
        buys[i] = INT_MAX;
    }

    int *profits = (int *)malloc(k * sizeof(int));
    if (profits == NULL) {
        free(buys);
        return 0;
    }

    for (int i = 0; i < pricesSize; i++) {
        int prev_profit = 0;
        for (int j = 0; j < k; j++) {
            if (j != 0) {
                prev_profit = profits[j - 1];
            }
            buys[j] = min(buys[j], prices[i] - prev_profit);
            profits[j] = max(profits[j], prices[i] - buys[j]);
        }
    }

    int res = profits[k - 1];
    free(profits);
    free(buys);
    return res;
}