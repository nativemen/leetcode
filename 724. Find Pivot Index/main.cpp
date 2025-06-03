#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        size_t numsSize = nums.size();

        if (numsSize == 0) {
            return -1;
        }

        vector<int> prefix(numsSize, 0);
        vector<int> suffix(numsSize, 0);

        for (size_t i = 1; i < numsSize; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
            suffix[numsSize - 1 - i] = suffix[numsSize - i] + nums[numsSize - i];
        }

        for (size_t i = 0; i < numsSize; i++) {
            if (prefix[i] == suffix[i]) {
                return i;
            }
        }

        return -1;
    }
};

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        size_t numsSize = nums.size();
        int left = 0;

        for (size_t i = 0; i < numsSize; i++) {
            int right = sum - nums[i] - left;

            if (left == right) {
                return i;
            }

            left += nums[i];
        }

        return -1;
    }
};