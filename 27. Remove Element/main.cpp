#include <vector>

using std::vector;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            if (nums[left] != val) {
                left++;
                continue;
            }

            if (nums[right] == val) {
                right--;
                continue;
            }

            nums[left] = nums[right];
            nums[right] = val;
        }

        return left;
    }
};

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        vector<int> remain;

        for (const auto &num : nums) {
            if (num != val) {
                remain.push_back(num);
            }
        }

        nums.clear();

        for (const auto &num : remain) {
            nums.push_back(num);
        }

        return nums.size();
    }
};

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int count = 0;

        for (const auto &num : nums) {
            if (num != val) {
                nums[count++] = num;
            }
        }

        return count;
    }
};