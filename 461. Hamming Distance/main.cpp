#include <bitset>

using std::bitset;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int n = x ^ y;

        while (n != 0) {
            count += n & 1;
            n >>= 1;
        }

        return count;
    }
};

class Solution {
public:
    int hammingDistance(int x, int y) {
        return bitset<32>(x ^ y).count();
    }
};