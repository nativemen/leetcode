#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());

        return nums[nums.size() - k];
    }
};

class Solution {
    static constexpr int ARRAY_SIZE = 20001;
    static constexpr int INDEX_OFFSET = 10000;

public:
    int findKthLargest(vector<int> &nums, int k) {
        vector<int> count = vector<int>(ARRAY_SIZE, 0);

        for (const auto &num : nums) {
            count[num + INDEX_OFFSET]++;
        }

        for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
            if (k <= count[i]) {
                return i - INDEX_OFFSET;
            }

            k -= count[i];
        }

        return 0 - INDEX_OFFSET;
    }
};