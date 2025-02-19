#include <limits.h>
#include <stdio.h>

#define ARRAY_SIZE 100000

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxProfit(int *prices, int pricesSize) {
    int *left = (int *)calloc(ARRAY_SIZE, sizeof(int));
    if (left == NULL) {
        return 0;
    }

    int *right = (int *)calloc(ARRAY_SIZE, sizeof(int));
    if (right == NULL) {
        free(left);
        return 0;
    }

    int lowest = prices[0];

    for (int i = 1; i < pricesSize; i++) {
        left[i] = max(left[i - 1], prices[i] - lowest);
        lowest = min(lowest, prices[i]);
    }

    int highest = prices[pricesSize - 1];
    for (int i = pricesSize - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], highest - prices[i]);
        highest = max(highest, prices[i]);
    }

    int profit = right[0];
    for (int i = 1; i < pricesSize; i++) {
        profit = max(profit, left[i - 1] + right[i]);
    }

    free(left);
    free(right);
    return profit;
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxProfit(int *prices, int pricesSize) {
    if (pricesSize == 0) {
        return 0;
    }

    int buy1 = INT_MAX;
    int buy2 = INT_MAX;
    int profit1 = 0;
    int profit2 = 0;

    for (int i = 0; i < pricesSize; i++) {
        buy1 = min(buy1, prices[i]);
        profit1 = max(profit1, prices[i] - buy1);
        buy2 = min(buy2, prices[i] - profit1);
        profit2 = max(profit2, prices[i] - buy2);
    }

    return profit2;
}