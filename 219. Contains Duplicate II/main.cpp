#include <algorithm>
#include <deque>
#include <unordered_map>
#include <vector>

using std::deque;
using std::pair;
using std::sort;
using std::unordered_map;
using std::vector;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        vector<pair<int, int>> maps;

        for (int i = 0; i < nums.size(); i++) {
            maps.push_back({nums[i], i});
        }

        sort(maps.begin(), maps.end(), [](const pair<int, int> a, const pair<int, int> b) {
            return a.first < b.first;
        });

        for (int i = 1; i < maps.size(); i++) {
            if (maps[i].first == maps[i - 1].first && abs(maps[i].second - maps[i - 1].second) <= k) {
                return true;
            }
        }

        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size() && j <= i + k; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }

        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> maps;

        for (int i = 0; i < nums.size(); i++) {
            if (maps.find(nums[i]) != maps.end() && i - maps[nums[i]] <= k) {
                return true;
            }
            maps[nums[i]] = i;
        }

        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        vector<int> seen;

        for (int i = 0; i < nums.size(); i++) {
            if (seen.size() > k) {
                seen.erase(seen.begin());
            }

            if (find(seen.begin(), seen.end(), nums[i]) != seen.end()) {
                return true;
            }

            seen.push_back(nums[i]);
        }

        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        vector<int> seen;

        for (const auto &num : nums) {
            if (seen.size() > k) {
                seen.erase(seen.begin());
            }

            if (find(seen.begin(), seen.end(), num) != seen.end()) {
                return true;
            }

            seen.push_back(num);
        }

        return false;
    }
};
