#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

struct Solution;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size() - 1; i++) {
            int obj = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == obj) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int obj = target - nums[i];
            if (map.find(obj) != map.end()) {
                return {map[obj], i};
            }

            map[nums[i]] = i;
        }

        return {};
    }
};