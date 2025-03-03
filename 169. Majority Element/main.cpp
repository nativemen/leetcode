#include <algorithm>
#include <unordered_map>
#include <vector>

using std::sort;
using std::unordered_map;
using std::vector;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        return nums[nums.size() / 2];
    }
};

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int major = 0;
        int count = 0;

        for (const auto &num : nums) {
            if (count == 0) {
                major = num;
                count++;
            } else {
                if (major == num) {
                    count++;
                } else {
                    count--;
                }
            }
        }

        return major;
    }
};

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int size = nums.size();
        unordered_map<int, int> maps;

        for (const auto &num : nums) {
            maps[num]++;
            if (maps[num] > size / 2) {
                return num;
            }
        }

        return 0;
    }
};