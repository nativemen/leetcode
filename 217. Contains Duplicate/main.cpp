#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::sort;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> hashset;

        for (const auto &num : nums) {
            if (!hashset.insert(num).second) {
                return true;
            }
        }

        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_map<int, int> hashmap;

        for (const auto &num : nums) {
            if (hashmap.contains(num)) {
                return true;
            }
            hashmap[num]++;
        }

        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        stable_sort(nums.begin(), nums.end());

        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        return false;
    }
};

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        qsort(nums.data(), nums.size(), sizeof(int), compare);

        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        return false;
    }
};