#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int answer = 0;

        for (const auto &num : nums) {
            answer ^= num;
        }

        return answer;
    }
};

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> hashmap;

        for (const auto &num : nums) {
            if (hashmap.contains(num)) {
                hashmap.erase(num);
            } else {
                hashmap[num] = 1;
            }
        }

        return (*hashmap.begin()).first;
    }
};

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        unordered_set<int> hashset;

        for (const auto &num : nums) {
            if (hashset.contains(num)) {
                hashset.erase(num);
            } else {
                hashset.insert(num);
            }
        }

        return *hashset.begin();
    }
};