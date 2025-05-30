#include <numeric>
#include <string>

using namespace std;

class Solution {
    size_t gcd(size_t a, size_t b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

public:
    string gcdOfStrings(string str1, string str2) {
        string result;

        if (str1 + str2 != str2 + str1) {
            return result;
        }

        size_t gcdLen = gcd(str1.size(), str2.size());
        result = str1.substr(0, gcdLen);

        return result;
    }
};

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string result;

        if (str1 + str2 != str2 + str1) {
            return result;
        }

        size_t gcdLen = gcd(str1.size(), str2.size());
        result = str1.substr(0, gcdLen);

        return result;
    }
};

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};