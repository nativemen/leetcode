#include <algorithm>
#include <queue>
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

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.begin() + k);

        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }

        return minHeap.top();
    }
};

class Solution {
    int quickSelect(vector<int> &nums, int k) {
        int numsSize = nums.size();
        int pivot = nums[rand() % numsSize];
        vector<int> left;
        vector<int> right;
        vector<int> mid;
        int i = 0;

        while (i < numsSize) {
            if (nums[i] < pivot) {
                left.push_back(nums[i++]);
            } else if (nums[i] > pivot) {
                right.push_back(nums[i++]);
            } else {
                mid.push_back(nums[i++]);
            }
        }

        if (right.size() >= k) {
            return quickSelect(right, k);
        } else if (right.size() + mid.size() < k) {
            return quickSelect(left, k - right.size() - mid.size());
        } else {
            return pivot;
        }
    }

public:
    int findKthLargest(vector<int> &nums, int k) {
        if (nums.empty() || k < 0 || k > nums.size()) {
            return -1;
        }

        return quickSelect(nums, k);
    }
};