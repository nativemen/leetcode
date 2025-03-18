#include <algorithm>
#include <unordered_set>
#include <vector>

using std::max;
using std::sort;
using std::unordered_set;
using std::vector;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int count = 1;
        int maxCount = 1;

        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            } else if (nums[i] == nums[i - 1] + 1) {
                count++;
            } else {
                count = 1;
            }

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        unordered_set<int> sets(nums.begin(), nums.end());

        int maxCount = 1;

        for (const auto &num : sets) {
            if (sets.find(num - 1) != sets.end()) {
                continue;
            }

            int count = 1;
            int last = num;

            while (sets.find(last + 1) != sets.end()) {
                count++;
                last++;
            }

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};