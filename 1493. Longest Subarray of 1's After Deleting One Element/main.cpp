#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums) {
        int size = nums.size();
        int slow = 0;
        int maxCount = 0;
        int zeros = 0;

        for (int fast = 0; fast < size; fast++) {
            if (nums[fast] == 0) {
                zeros++;
            }

            while (zeros > 1) {
                if (nums[slow] == 0) {
                    zeros--;
                }
                slow++;
            }

            maxCount = max(maxCount, fast - slow + 1 - zeros);
        }

        if (zeros == 0) {
            maxCount--;
        }

        return maxCount;
    }
};