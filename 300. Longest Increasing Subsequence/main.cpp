#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        size_t numsSize = nums.size();
        int maxLen = 1;
        vector<int> dp(numsSize, 1);

        for (size_t i = 0; i < numsSize; i++) {
            for (size_t j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxLen = max(maxLen, dp[i]);
                }
            }
        }

        return maxLen;
    }
};

class Solution {
    int binarySearch(vector<int> &seq, int seqSize, int num) {
        int left = 0;
        int right = seqSize;

        while (left < right) {
            int mid = (left + right) / 2;

            if (seq[mid] < num) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

public:
    int lengthOfLIS(vector<int> &nums) {
        int numsSize = nums.size();

        if (numsSize == 0) {
            return 0;
        }

        int len = 0;
        vector<int> seq(numsSize);

        for (int i = 0; i < numsSize; i++) {
            int index = binarySearch(seq, len, nums[i]);
            seq[index] = nums[i];
            if (index == len) {
                len++;
            }
        }

        return len;
    }
};

class Solution {
    int binarySearch(vector<int> &seq, int num) {
        int left = 0;
        int right = seq.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;

            if (seq[mid] < num) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

public:
    int lengthOfLIS(vector<int> &nums) {
        int numsSize = nums.size();

        if (numsSize == 0) {
            return 0;
        }

        vector<int> seq;
        seq.push_back(0);

        for (int i = 1; i < numsSize; i++) {
            if (nums[i] > seq.back()) {
                seq.push_back(nums[i]);
            } else {
                int index = binarySearch(seq, nums[i]);
                seq[index] = nums[i];
            }
        }

        return seq.size();
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int len = 0;

        for (const auto &cur : nums) {
            if (len == 0 || nums[len - 1] < cur) {
                nums[len++] = cur;
            } else {
                *lower_bound(nums.begin(), nums.begin() + len, cur) = cur;
            }
        }

        return len;
    }
};