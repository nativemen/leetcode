#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        vector<int> nums;
        nums.resize(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums.begin());

        int numsSize = nums.size();
        if (numsSize % 2 != 0) {
            return (double)nums[numsSize / 2];
        } else {
            return (double)(nums[numsSize / 2 - 1] + nums[numsSize / 2]) / 2.0;
        }
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        vector<int> nums;

        for (const auto &num : nums1) {
            nums.push_back(num);
        }

        for (const auto &num : nums2) {
            nums.push_back(num);
        }

        sort(nums.begin(), nums.end());

        int numsSize = nums.size();
        if (numsSize % 2 != 0) {
            return (double)nums[numsSize / 2];
        } else {
            return (double)(nums[numsSize / 2 - 1] + nums[numsSize / 2]) / 2.0;
        }
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int nums1Size = nums1.size();
        int nums2Size = nums2.size();
        int numsSize = nums1Size + nums2Size;
        int i = 0;
        int j = 0;
        int m1 = 0;
        int m2 = 0;

        for (int count = 0; count <= numsSize / 2; count++) {
            m1 = m2;

            if (i == nums1Size) {
                m2 = nums2[j++];
            } else if (j == nums2Size) {
                m2 = nums1[i++];
            } else if (nums1[i] < nums2[j]) {
                m2 = nums1[i++];
            } else {
                m2 = nums2[j++];
            }
        }

        if (numsSize % 2 != 0) {
            return (double)m2;
        } else {
            return (double)(m1 + m2) / 2.0;
        }
    }
};