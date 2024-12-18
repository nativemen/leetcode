#include <algorithm>
#include <vector>

using std::reverse;
using std::vector;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int size = nums.size();
        int count = k % size;
        vector<int> vec;

        while (vec.size() < count + size) {
            vec.insert(vec.end(), nums.begin(), nums.end());
        }

        nums.assign(vec.end() - size - count, vec.end() - count);
    }
};

class Solution {
public:
    void reverse(vector<int> &nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

    void rotate(vector<int> &nums, int k) {
        int size = nums.size();
        int count = k % size;

        reverse(nums, 0, size - 1);
        reverse(nums, 0, count - 1);
        reverse(nums, count, size - 1);
    }
};

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int size = nums.size();
        int count = k % size;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + count);
        reverse(nums.begin() + count, nums.end());
    }
};