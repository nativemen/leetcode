#include <string>
#include <unordered_set>

using namespace std;

class Solution {
    int vowelCheck(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return 1;
        }

        return 0;
    }

public:
    int maxVowels(string s, int k) {
        int count = 0;

        for (int i = 0; i < k; i++) {
            count += vowelCheck(s[i]);
        }

        int maxCount = count;
        int size = s.size();

        for (int i = k; i < size; i++) {
            count -= vowelCheck(s[i - k]);
            count += vowelCheck(s[i]);
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};

class Solution {
    int vowelCheck(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? 1 : 0;
    }

public:
    int maxVowels(string s, int k) {
        int count = 0;
        int maxCount = 0;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            count += vowelCheck(s[i]);
            if (i >= k) {
                count -= vowelCheck(s[i - k]);
            }
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};

class Solution {
public:
    int maxVowels(string s, int k) {
        int vowels[26] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
        int sLen = s.size();
        int count = 0;

        for (int i = 0; i < k; i++) {
            count += vowels[s[i] - 'a'];
        }

        int maxCount = count;

        for (int i = k; i < sLen; i++) {
            count -= vowels[s[i - k] - 'a'];
            count += vowels[s[i] - 'a'];

            if (count > maxCount) {
                maxCount = count;
            }
        }

        return maxCount;
    }
};

class Solution {
public:
    int maxVowels(string s, int k) {
        int vowels[26] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
        int sLen = s.size();
        int count = 0;
        int maxCount = 0;

        for (int i = 0; i < sLen; i++) {
            count += vowels[s[i] - 'a'];
            if (i >= k) {
                count -= vowels[s[i - k] - 'a'];
            }

            if (count > maxCount) {
                maxCount = count;
            }
        }

        return maxCount;
    }
};

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> sets = {'a', 'e', 'i', 'o', 'u'};
        int sLen = s.size();
        int count = 0;

        for (int i = 0; i < k; i++) {
            if (sets.contains(s[i])) {
                count++;
            }
        }

        int maxCount = count;

        for (int i = k; i < sLen; i++) {
            if (sets.contains(s[i - k])) {
                count--;
            }

            if (sets.contains(s[i])) {
                count++;
            }

            if (count > maxCount) {
                maxCount = count;
            }
        }

        return maxCount;
    }
};

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> sets = {'a', 'e', 'i', 'o', 'u'};
        int sLen = s.size();
        int count = 0;
        int maxCount = 0;

        for (int i = 0; i < sLen; i++) {
            count += sets.contains(s[i]) ? 1 : 0;
            if (i >= k) {
                count -= sets.contains(s[i - k]) ? 1 : 0;
            }

            if (count > maxCount) {
                maxCount = count;
            }
        }

        return maxCount;
    }
};