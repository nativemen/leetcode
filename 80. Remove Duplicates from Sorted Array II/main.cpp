#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int count = 1;
        int repeat = 0;
        int prev = nums[0];
        int size = nums.size();

        for (int i = 1; i < size; i++) {
            if (nums[i] == prev) {
                repeat++;
            } else {
                repeat = 0;
                prev = nums[i];
            }

            if (repeat <= 1) {
                nums[count++] = nums[i];
            }
        }

        return count;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int size = nums.size();
        if (size <= 2) {
            return size;
        }

        int count = 2;

        for (const auto &num : nums) {
            if (num != nums[count - 2]) {
                nums[count++] = num;
            }
        }

        return count;
    }
};