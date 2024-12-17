int maxProfit(int *prices, int pricesSize) {
    int profit = 0;
    int min = prices[0];
    int prev = prices[0];

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < prev) {
            profit += prev - min;
            min = prices[i];
        }
        prev = prices[i];
    }
    profit += prev - min;

    return profit;
}

int maxProfit(int *prices, int pricesSize) {
    int profit = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }

    return profit;
}