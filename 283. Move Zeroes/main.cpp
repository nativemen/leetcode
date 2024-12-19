#include <vector>

using std::vector;
using std::swap;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        size_t non_zero_index = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[non_zero_index], nums[i]);
                non_zero_index++;
            }
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        size_t zero_pos = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[zero_pos] = nums[i];
                zero_pos++;
            }
        }

        for (int i = zero_pos; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int index = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[index] == 0) {
                nums.erase(nums.begin() + index);
                nums.push_back(0);
            } else {
                index++;
            }
        }
    }
};