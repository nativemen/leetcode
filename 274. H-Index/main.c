#define ARRAY_SIZE 1001

int hIndex(int *citations, int citationsSize) {
    int dp[ARRAY_SIZE + 1] = {0};

    for (int i = 0; i < citationsSize; i++) {
        dp[citations[i]]++;
    }

    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        dp[i] += dp[i + 1];
        if (dp[i] >= i) {
            return i;
        }
    }

    return 0;
}

static int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

int hIndex(int *citations, int citationsSize) {
    int h = 0;

    qsort(citations, citationsSize, sizeof(int), compare);

    for (int i = 0; i < citationsSize; i++) {
        if (citations[i] < i + 1) {
            break;
        }

        h = i + 1;
    }

    return h;
}