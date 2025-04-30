#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int minVal = numeric_limits<int>::max();
        int index = -1;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (minVal > nums[i]) {
                minVal = nums[i];
                index = i;
            }
        }

        int left = index;
        int right = left + size - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (target == nums[mid % size]) {
                return mid % size;
            } else if (target < nums[mid % size]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (target == nums[mid]) {
                return mid;
            }

            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};