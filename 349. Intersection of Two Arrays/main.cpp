#include <algorithm>
#include <set>
#include <unordered_set>
#include <vector>

using std::find;
using std::set;
using std::unordered_set;
using std::vector;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        vector<int> result;

        for (const auto &num1 : nums1) {
            for (const auto &num2 : nums2) {
                if (num1 == num2 && find(result.begin(), result.end(), num1) == result.end()) {
                    result.push_back(num1);
                    break;
                }
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        vector<int> result;

        for (const auto &num : set1) {
            if (set2.contains(num)) {
                result.push_back(num);
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        vector<int> result;

        for (const auto &num : set1) {
            if (set2.find(num) != set2.end()) {
                result.push_back(num);
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());
        vector<int> result;

        set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(result));

        return result;
    }
};