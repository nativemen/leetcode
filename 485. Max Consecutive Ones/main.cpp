#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int count = 0;
        int maxCount = 0;

        for (const auto &num : nums) {
            count = (num == 1) ? count + 1 : 0;
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};