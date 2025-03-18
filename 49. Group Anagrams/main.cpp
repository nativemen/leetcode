#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using std::sort;
using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> maps;

        for (const auto &str : strs) {
            string word = str;
            sort(word.begin(), word.end());
            maps[word].push_back(str);
        }

        vector<vector<string>> result;

        for (const auto &pair : maps) {
            result.push_back(pair.second);
        }

        return result;
    }
};