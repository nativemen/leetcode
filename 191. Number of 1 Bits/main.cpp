#include <bitset>

using std::bitset;

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while (n != 0) {
            count += n & 1;
            n >>= 1;
        }

        return count;
    }
};

class Solution {
public:
    int hammingWeight(int n) {
        return bitset<32>(n).count();
    }
};