int maxProfit(int *prices, int pricesSize) {
    int max_profit = 0;
    int buy = prices[0];
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < buy) {
            buy = prices[i];
            continue;
        }

        int profit = prices[i] - buy;
        if (max_profit < profit) {
            max_profit = profit;
        }
    }

    return max_profit;
}