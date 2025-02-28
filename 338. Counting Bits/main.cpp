#include <bitset>
#include <vector>

using std::bitset;
using std::vector;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counter(n + 1, 0);

        for (int i = 0; i < 32; i++) {
            for (int j = 0; j <= n; j++) {
                counter[j] += (j >> i) & 1;
            }
        }

        return counter;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counter(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            counter[i] = bitset<32>(i).count();
        }

        return counter;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counter(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            counter[i] = counter[i >> 1] + (i & 1);
        }

        return counter;
    }
};