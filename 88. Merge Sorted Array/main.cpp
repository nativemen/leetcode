#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> vec(m + n);
        std::merge(nums1.begin(), nums1.begin() + m, nums2.begin(), nums2.begin() + n, vec.begin());
        nums1 = vec;
    }
};

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> vec;
        vec.reserve(m + n);
        std::merge(nums1.begin(), nums1.begin() + m, nums2.begin(), nums2.begin() + n, std::back_inserter(vec));
        nums1 = vec;
    }
};

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> vec;
        vec.reserve(m + n);
        vec.insert(vec.end(), nums1.begin(), nums1.begin() + m);
        vec.insert(vec.end(), nums2.begin(), nums2.begin() + n);
        std::sort(vec.begin(), vec.end());
        nums1 = vec;
    }
};

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = n - 1;
        int j = m + n - 1;

        while (i >= 0) {
            nums1[j] = nums2[i];
            i--;
            j--;
        }

        std::sort(nums1.begin(), nums1.end());
    }
};