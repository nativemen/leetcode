#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> result(2, -1);

        int left = 0;
        int size = nums.size();
        int right = size - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (target <= nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (left >= size || nums[left] != target) {
            return result;
        }

        result[0] = left;
        right = size - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        result[1] = right;

        return result;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> result(2, -1);
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (target == nums[i]) {
                result[0] = i;
                break;
            }
        }

        for (int i = size - 1; i >= 0; i--) {
            if (target == nums[i]) {
                result[1] = i;
                break;
            }
        }

        return result;
    }
};