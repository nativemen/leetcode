#include <stdbool.h>
#include <stdio.h>

int countPrimes(int n) {
    if (n <= 1) {
        return 0;
    }

    bool *is_primes = (bool *)malloc(n * sizeof(bool));
    if (is_primes == NULL) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        is_primes[i] = true;
    }

    int count = 0;
    for (long long i = 2; i < n; i++) {
        if (!is_primes[i]) {
            continue;
        }
        count++;
        for (long long mult = i * i; mult < n; mult += i) {
            is_primes[mult] = false;
        }
    }

    free(is_primes);
    return count;
}