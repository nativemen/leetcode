#include <vector>

using std::vector;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int sum = 0;

        for (const auto &n : nums) {
            sum += n;
        }

        int size = nums.size();
        return (size + 1) * size / 2 - sum;
    }
};

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int size = nums.size();
        int result = size;

        for (int i = 0; i < size; i++) {
            result ^= i ^ nums[i];
        }

        return result;
    }
};

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int size = nums.size();
        int result = size;

        for (int i = 0; i < size; i++) {
            result += i - nums[i];
        }

        return result;
    }
};