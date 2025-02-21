#include <vector>

using std::vector;

class Solution {
public:
    vector<int> shuffle(vector<int> &nums, int n) {
        vector<int> res(2 * n);

        for (int i = 0; i < n; i++) {
            res[2 * i] = nums[i];
            res[2 * i + 1] = nums[n + i];
        }

        return res;
    }
};

class Solution {
public:
    vector<int> shuffle(vector<int> &nums, int n) {
        vector<int> res;

        for (int i = 0; i < n; i++) {
            res.push_back(nums[i]);
            res.push_back(nums[n + i]);
        }

        return res;
    }
};