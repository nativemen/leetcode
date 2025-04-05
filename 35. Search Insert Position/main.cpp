#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int numsSize = nums.size();

        for (int i = 0; i < numsSize; i++) {
            if (nums[i] >= target) {
                return i;
            }
        }

        return numsSize;
    }
};

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        nums.push_back(target);

        sort(nums.begin(), nums.end());
        int numsSize = nums.size();

        for (int i = 0; i < numsSize; i++) {
            if (nums[i] == target) {
                return i;
            }
        }

        return numsSize;
    }
};

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int nums_size = nums.size();
        if (nums_size == 0) {
            return 0;
        }

        int mid = nums_size / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            vector<int> sub(nums.begin() + mid + 1, nums.end());
            return mid + 1 + searchInsert(sub, target);
        } else {
            vector<int> sub(nums.begin(), nums.begin() + mid);
            return searchInsert(sub, target);
        }
    }
};