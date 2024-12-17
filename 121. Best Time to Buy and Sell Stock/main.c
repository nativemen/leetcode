int maxProfit(int *prices, int pricesSize) {
    int maxProf = 0;
    int buy = prices[0];
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < buy) {
            buy = prices[i];
            continue;
        }

        int profit = prices[i] - buy;
        if (maxProf < profit) {
            maxProf = profit;
        }
    }

    return maxProf;
}