#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());

        int count = 0;
        int left = 0;
        int right = nums.size() - 1;

        while (right >= 0 && nums[right] >= k) {
            right--;
        }

        while (left < right) {
            int target = k - nums[left];

            if (target == nums[right]) {
                count++;
                left++;
                right--;
            } else if (target < nums[right]) {
                right--;
            } else {
                left++;
            }
        }

        return count;
    }
};

class Solution {
public:
    int maxOperations(vector<int> &nums, int k) {
        unordered_map<int, int> freq;

        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < k) {
                int target = k - nums[i];

                if (freq[target] == 0) {
                    freq[nums[i]]++;
                } else {
                    count++;
                    freq[target]--;
                }
            }
        }

        return count;
    }
};