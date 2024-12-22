#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    int firstUniqChar(string s) {
        const int ARRAY_SIZE = 26;
        int count[ARRAY_SIZE] = {0};

        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};

class Solution {
public:
    int firstUniqChar(string s) {
        const int ARRAY_SIZE = 26;
        int count[ARRAY_SIZE] = {0};

        for (const auto &c : s) {
            count[c - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;

        for (const auto &c : s) {
            map[c]++;
        }

        int i = 0;
        for (const auto &c : s) {
            if (map[c] == 1) {
                return i;
            }
            i++;
        }

        return -1;
    }
};