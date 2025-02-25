#include <vector>

using std::vector;

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<int> is_primes(n, true);

        for (long long i = 2; i < (long long)n; i++) {
            if (!is_primes[i]) {
                continue;
            }
            count++;

            for (long long mult = i * i; mult < (long long)n; mult += i) {
                is_primes[mult] = false;
            }
        }

        return count;
    }
};