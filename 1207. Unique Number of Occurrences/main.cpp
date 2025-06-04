#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int> &arr) {
        unordered_map<int, int> maps;

        for (const auto &num : arr) {
            maps[num]++;
        }

        unordered_set<int> sets;
        for (const auto &[key, val] : maps) {
            if (sets.contains(val)) {
                return false;
            }
            sets.insert(val);
        }

        return true;
    }
};