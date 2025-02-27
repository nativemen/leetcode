#include <bitset>
#include <vector>

using std::bitset;
using std::vector;

class Solution {
public:
    int totalHammingDistance(vector<int> &nums) {
        int total = 0;
        int size = nums.size();

        for (int i = 0; i < 32; i++) {
            int bitCount = 0;
            for (int j = 0; j < size; j++) {
                bitCount += (nums[j] >> i) & 1;
            }
            total += bitCount * (size - bitCount);
        }

        return total;
    }
};

class Solution {
public:
    int totalHammingDistance(vector<int> &nums) {
        int total = 0;
        int size = nums.size();

        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                total += bitset<32>(nums[i] ^ nums[j]).count();
            }
        }

        return total;
    }
};