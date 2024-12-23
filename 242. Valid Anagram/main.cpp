#include <algorithm>
#include <string>
#include <unordered_map>

using std::sort;
using std::string;
using std::unordered_map;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;

        for (const auto &c : s) {
            count[c] += 1;
        }

        for (const auto &c : t) {
            count[c] -= 1;
        }

        for (int i = 'a'; i <= 'z'; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> count;

        for (int i = 0; i < s.length(); i++) {
            count[s[i]] += 1;
            count[t[i]] -= 1;
        }

        for (int i = 'a'; i <= 'z'; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s.compare(t) != 0) {
            return false;
        }

        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};