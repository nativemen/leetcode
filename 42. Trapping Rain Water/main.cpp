#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::vector;

class Solution {
public:
    int trap(vector<int> &height) {
        int size = height.size();
        int left = 0;
        int right = size - 1;
        int leftMax = 0;
        int rightMax = 0;
        int total = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] <= leftMax) {
                    total += leftMax - height[left];
                } else {
                    leftMax = height[left];
                }
                left++;
            } else {
                if (height[right] <= rightMax) {
                    total += rightMax - height[right];
                } else {
                    rightMax = height[right];
                }
                right--;
            }
        }

        return total;
    }
};

class Solution {
public:
    int trap(vector<int> &height) {
        int size = height.size();
        vector<int> prefixMax(size);

        prefixMax[0] = 0;
        for (int i = 1; i < size; i++) {
            prefixMax[i] = max(prefixMax[i - 1], height[i - 1]);
        }

        vector<int> suffixMax(size);

        suffixMax[size - 1] = 0;
        for (int i = size - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i + 1]);
        }

        int total = 0;

        for (int i = 0; i < size; i++) {
            int top = min(prefixMax[i], suffixMax[i]);
            total += (top >= height[i]) ? (top - height[i]) : 0;
        }

        return total;
    }
};