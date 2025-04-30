#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int size = nums.size();

        if (size <= 0) {
            return -1;
        }

        if (size == 1) {
            return 0;
        }

        for (int i = 0; i < size - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return i;
            }
        }

        return size - 1;
    }
};

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;

            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};