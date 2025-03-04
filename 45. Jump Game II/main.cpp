#include <algorithm>
#include <limits>
#include <vector>

using std::max;
using std::min;
using std::vector;

class Solution {
public:
    int jump(vector<int> &nums) {
        int size = nums.size();
        if (size <= 1) {
            return 0;
        }

        int jumps = 0;
        int curFarthest = 0;
        int nextFarthest = 0;

        for (int i = 0; i < size; i++) {
            nextFarthest = max(nextFarthest, i + nums[i]);
            if (i == curFarthest) {
                jumps++;
                curFarthest = nextFarthest;
                if (curFarthest >= size - 1) {
                    break;
                }
            }
        }

        return jumps;
    }
};

class Solution {
public:
    int jump(vector<int> &nums) {
        int size = nums.size();
        vector<int> jumps(size, std::numeric_limits<int>::max());

        jumps[0] = 0;
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j <= i + nums[i] && j < size; j++) {
                jumps[j] = min(jumps[j], jumps[i] + 1);
            }
        }

        return jumps[size - 1];
    }
};


class Solution {
public:
    int jump(vector<int> &nums) {
        int size = nums.size();
        int left = 0;
        int right = 0;
        int jumps = 0;

        while (right < size - 1) {
            int farReach = 0;
            for (int i = left; i <= right; i++) {
                farReach = max(farReach, i + nums[i]);
            }

            left = right + 1;
            right = farReach;
            jumps++;
        }

        return jumps;
    }
};