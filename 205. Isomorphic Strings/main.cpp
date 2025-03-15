#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> directMapping;
        unordered_map<char, char> reverseMapping;

        for (size_t i = 0; i < s.size(); i++) {
            if (directMapping.count(s[i]) == 0 && reverseMapping.count(t[i]) == 0) {
                directMapping[s[i]] = t[i];
                reverseMapping[t[i]] = s[i];
            }

            if (directMapping[s[i]] != t[i] || reverseMapping[t[i]] != s[i]) {
                return false;
            }
        }

        return true;
    }
};