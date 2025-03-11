#include <string>

using std::string;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int size1 = s.size();
        int size2 = t.size();
        int si = 0;
        int ti = 0;

        for (ti = 0; ti < size2; ti++) {
            if (s[si] == t[ti] && si < size1) {
                si++;
            }
        }

        return si == size1;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int size1 = s.size();
        int size2 = t.size();
        int si = 0;
        int ti = 0;

        while (si < size1 && ti < size2) {
            if (s[si] == t[ti]) {
                si++;
            }
            ti++;
        }

        return si == size1;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int size1 = s.size();
        int size2 = t.size();
        if (size1 == 0 && size2 == 0) {
            return true;
        }

        int si = 0;

        for (const auto &c : t) {
            if (c == s[si]) {
                si++;
            }

            if (si == size1) {
                return true;
            }
        }

        return false;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s == t) {
            return true;
        }

        int si = 0;

        for (const auto &c : t) {
            if (c == s[si]) {
                si++;
            }

            if (si == s.size()) {
                return true;
            }
        }

        return false;
    }
};