#include <limits>
#include <vector>

using std::min;
using std::numeric_limits;
using std::vector;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int result = numeric_limits<int>::max();
        int left = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            while (sum >= target) {
                result = min(result, i - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (result == numeric_limits<int>::max()) ? 0 : result;
    }
};