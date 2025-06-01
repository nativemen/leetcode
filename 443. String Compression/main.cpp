#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char> &chars) {
        vector<char> s(chars.begin(), chars.end());

        chars.clear();
        size_t count = 0;
        size_t charsSize = s.size();

        for (size_t i = 0; i < charsSize; i++) {
            if (i == 0 || s[i - 1] == s[i]) {
                count++;
            }

            if (i == charsSize - 1 || s[i] != s[i + 1]) {
                chars.push_back(s[i]);

                if (count > 1) {
                    size_t len = chars.size();

                    while (count > 0) {
                        chars.push_back('0' + (count % 10));
                        count /= 10;
                    }

                    reverse(chars.begin() + len, chars.end());
                }

                count = 1;
            }
        }

        return chars.size();
    }
};

class Solution {
public:
    int compress(vector<char> &chars) {
        vector<char> s(chars.begin(), chars.end());

        chars.clear();
        size_t count = 0;
        size_t charsSize = s.size();

        for (size_t i = 0; i < charsSize; i++) {
            if (i == 0 || s[i - 1] == s[i]) {
                count++;
            }

            if (i == charsSize - 1 || s[i] != s[i + 1]) {
                chars.push_back(s[i]);

                if (count > 1) {
                    string buffer = to_string(count);

                    for (const auto &c : buffer) {
                        chars.push_back(c);
                    }
                }

                count = 1;
            }
        }

        return chars.size();
    }
};

class Solution {
public:
    int compress(vector<char> &chars) {
        int count = 0;
        int len = 0;
        int charsSize = chars.size();
        char prev = '\0';

        for (size_t i = 0; i < charsSize; i++) {
            if (i == 0 || prev == chars[i]) {
                count++;
            }

            prev = chars[i];

            if (i == charsSize - 1 || chars[i] != chars[i + 1]) {
                chars[len++] = chars[i];

                if (count > 1) {
                    string buffer = to_string(count);

                    for (const auto &c : buffer) {
                        chars[len++] = c;
                    }
                }

                count = 1;
            }
        }

        return len;
    }
};

class Solution {
public:
    int compress(vector<char> &chars) {
        int count = 1;
        int len = 0;
        int charsSize = chars.size();
        char current = chars[0];

        for (size_t i = 0; i < charsSize; i++) {
            if (i + 1 == charsSize || chars[i] != chars[i + 1]) {
                chars[len++] = current;

                if (count > 1) {
                    string buffer = to_string(count);

                    for (const auto &c : buffer) {
                        chars[len++] = c;
                    }
                }

                if (i + 1 < charsSize) {
                    current = chars[i + 1];
                    count = 1;
                }
            } else {
                count++;
            }
        }

        return len;
    }
};