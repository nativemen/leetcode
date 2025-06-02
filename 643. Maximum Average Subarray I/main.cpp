#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int maxSum = sum;
        int size = nums.size();

        for (int i = 0; i + k < size; i++) {
            sum += nums[i + k] - nums[i];
            maxSum = max(maxSum, sum);
        }

        return static_cast<double>(maxSum) / static_cast<double>(k);
    }
};

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int maxSum = sum;
        int size = nums.size();

        for (int i = k; i < size; i++) {
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }

        return static_cast<double>(maxSum) / static_cast<double>(k);
    }
};