#include <vector>

using std::max;
using std::min;
using std::vector;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int left = 0;
        int right = height.size() - 1;
        int mArea = 0;

        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            mArea = max(mArea, area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return mArea;
    }
};