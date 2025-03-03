#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        vector<bool> canReach(nums.size(), false);

        canReach[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            if (!canReach[i]) {
                return false;
            }

            for (int j = i; j <= i + nums[i] && j < nums.size(); j++) {
                canReach[j] = true;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int maxReach = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) {
                return false;
            }

            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int size = nums.size();
        int start = size - 2;
        int target = size - 1;

        while (start >= 0) {
            if (start + nums[start] >= target) {
                target = start;
            }

            start--;
        }

        return target == 0;
    }
};