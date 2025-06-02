#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int maxCount = 0;
        int zeros = 0;
        int slow = 0;
        int fast = 0;
        int len = nums.size();

        for (; fast < len; fast++) {
            if (nums[fast] == 0) {
                if (zeros == k) {
                    if (maxCount < fast - slow) {
                        maxCount = fast - slow;
                    }

                    while (zeros == k) {
                        if (nums[slow] == 0) {
                            zeros--;
                        }
                        slow++;
                    }
                }

                zeros++;
            }
        }

        if (maxCount < fast - slow) {
            maxCount = fast - slow;
        }

        return maxCount;
    }
};

class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int maxCount = 0;
        int zeros = 0;
        int slow = 0;
        int len = nums.size();

        for (int fast = 0; fast < len; fast++) {
            if (nums[fast] == 0) {
                zeros++;
            }

            while (zeros > k) {
                if (nums[slow] == 0) {
                    zeros--;
                }
                slow++;
            }

            if (maxCount < fast - slow + 1) {
                maxCount = fast - slow + 1;
            }
        }

        return maxCount;
    }
};