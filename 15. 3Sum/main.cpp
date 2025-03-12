#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        for (int cur = 0; cur < nums.size() - 2; cur++) {
            if (cur > 0 && nums[cur] == nums[cur - 1]) {
                continue;
            }

            int left = cur + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[cur] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[cur], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    left++;
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
    }
};