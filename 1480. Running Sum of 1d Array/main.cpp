#include <vector>

class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {
        vector<int> result;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            result.push_back(sum);
        }

        return result;
    }
};


class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            nums[i] = sum;
        }

        return nums;
    }
};

class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        return nums;
    }
};