#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        for (const auto &num : set1) {
            if (set2.contains(num)) {
                set1.erase(num);
                set2.erase(num);
            }
        }

        vector<vector<int>> result;
        vector<int> r1(set1.begin(), set1.end());
        result.push_back(r1);
        vector<int> r2(set2.begin(), set2.end());
        result.push_back(r2);

        return result;
    }
};