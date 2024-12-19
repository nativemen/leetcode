#include <algorithm>
#include <unordered_map>
#include <vector>

using std::min;
using std::sort;
using std::unordered_map;
using std::vector;

const int ARRAY_SIZE = 1001;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> count1(ARRAY_SIZE, 0);
        vector<int> count2(ARRAY_SIZE, 0);

        for (const auto &num : nums1) {
            count1[num]++;
        }

        for (const auto &num : nums2) {
            count2[num]++;
        }

        vector<int> result;
        for (int i = 0; i < ARRAY_SIZE; i++) {
            int count = min(count1[i], count2[i]);
            for (int j = 0; j < count; j++) {
                result.push_back(i);
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> hashmap1;
        unordered_map<int, int> hashmap2;

        for (const auto &num : nums1) {
            hashmap1[num]++;
        }

        for (const auto &num : nums2) {
            hashmap2[num]++;
        }

        vector<int> result;
        for (const auto &[key, val] : hashmap1) {
            if (hashmap2.count(key) > 0) {
                int count = min(val, hashmap2[key]);
                for (int j = 0; j < count; j++) {
                    result.push_back(key);
                }
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        int i = 0;
        int j = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();

        while (i < len1 && j < len2) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> result;
        int i = 0;
        int j = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();

        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (nums1[i] == nums2[j]) {
                    result.push_back(nums1[i]);
                    nums2[j] = INT_MIN;
                    break;
                }
            }
        }

        return result;
    }
};