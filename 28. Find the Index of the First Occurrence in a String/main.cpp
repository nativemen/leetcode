#include <string>

using std::string;

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t found = haystack.find(needle);
        if (found == std::string::npos) {
            return -1;
        }

        return (int)found;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = (int)haystack.size();
        int len2 = (int)needle.size();

        for (int i = 0; i < len1; i++) {
            int j = 0;
            while (j < len2 && haystack[i + j] == needle[j]) {
                j++;
            }

            if (j == len2) {
                return i;
            }
        }

        return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = (int)haystack.size();
        int len2 = (int)needle.size();

        for (int i = 0; i < len1; i++) {
            if (haystack.substr(i, len2) == needle) {
                return i;
            }
        }

        return -1;
    }
};