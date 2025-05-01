#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int minVal = numeric_limits<int>::max();

        for (const auto &num : nums) {
            if (minVal > num) {
                minVal = num;
            }
        }

        return minVal;
    }
};

class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[left];
    }
};