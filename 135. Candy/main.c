int candy(int *ratings, int ratingsSize) {
    int candy[ratingsSize];

    candy[0] = 1;
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candy[i] = candy[i - 1] + 1;
        } else {
            candy[i] = 1;
        }
    }

    int sum = candy[ratingsSize - 1];
    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            if (candy[i] <= candy[i + 1]) {
                candy[i] = candy[i + 1] + 1;
            }
        }
        sum += candy[i];
    }

    return sum;
}