#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

static int max(int a, int b) {
    return (a >= b) ? a : b;
}

int maxProfit(int *prices, int pricesSize, int fee) {
    int buy = INT_MIN;
    int profit = 0;

    for (int i = 0; i < pricesSize; i++) {
        buy = max(buy, profit - prices[i]);
        profit = max(profit, buy + prices[i] - fee);
    }

    return profit;
}