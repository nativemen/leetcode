#include <limits>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tMap;

        for (const auto &c : t) {
            tMap[c]++;
        }

        int matched = 0;
        size_t left = 0;
        size_t right = 0;
        size_t minLen = numeric_limits<size_t>::max();
        size_t minLeft = 0;
        unordered_map<char, int> sMap;

        for (right = 0; right < s.size(); right++) {
            if (tMap.find(s[right]) == tMap.end()) {
                continue;
            }

            sMap[s[right]]++;

            if (sMap[s[right]] <= tMap[s[right]]) {
                matched++;
            }

            if (matched == t.size()) {
                while (tMap.find(s[left]) == tMap.end() || sMap[s[left]] > tMap[s[left]]) {
                    if (tMap.find(s[left]) != tMap.end()) {
                        sMap[s[left]]--;
                    }
                    left++;
                }

                size_t size = right - left + 1;
                if (size < minLen) {
                    minLen = size;
                    minLeft = left;
                }
            }
        }

        if (minLen == numeric_limits<size_t>::max()) {
            return "";
        }

        return s.substr(minLeft, minLen);
    }
};

class Solution {
    static constexpr size_t ARRAY_SIZE = 128;

public:
    string minWindow(string s, string t) {
        int count[ARRAY_SIZE] = {0};

        for (const auto &c : t) {
            count[c]++;
        }

        size_t left = 0;
        size_t right = 0;
        size_t needed = t.size();
        size_t sLen = s.size();
        size_t minLeft = 0;
        size_t minLen = numeric_limits<size_t>::max();

        while (left < sLen) {
            if (right >= sLen && needed > 0) {
                break;
            }

            if (needed > 0) {
                if (count[s[right++]]-- > 0) {
                    needed--;
                }
            } else {
                size_t size = right - left;
                if (size < minLen) {
                    minLen = size;
                    minLeft = left;
                }

                if (++count[s[left++]] > 0) {
                    needed++;
                }
            }
        }

        if (minLen == numeric_limits<size_t>::max()) {
            return "";
        }

        return s.substr(minLeft, minLen);
    }
};

class Solution {
    static constexpr size_t ARRAY_SIZE = 128;

public:
    string minWindow(string s, string t) {
        vector<int> count(ARRAY_SIZE, 0);

        for (const auto &c : t) {
            count[c]++;
        }

        size_t left = 0;
        size_t right = 0;
        size_t needed = t.size();
        size_t sLen = s.size();
        size_t minLeft = 0;
        size_t minLen = numeric_limits<size_t>::max();

        while (left < sLen) {
            if (right >= sLen && needed > 0) {
                break;
            }

            if (needed > 0) {
                if (count[s[right++]]-- > 0) {
                    needed--;
                }
            } else {
                size_t size = right - left;
                if (size < minLen) {
                    minLen = size;
                    minLeft = left;
                }

                if (++count[s[left++]] > 0) {
                    needed++;
                }
            }
        }

        if (minLen == numeric_limits<size_t>::max()) {
            return "";
        }

        return s.substr(minLeft, minLen);
    }
};

class Solution {
    static constexpr size_t ARRAY_SIZE = 128;

public:
    string minWindow(string s, string t) {
        int count[ARRAY_SIZE] = {0};

        for (const auto &c : t) {
            count[c]++;
        }

        size_t left = 0;
        size_t right = 0;
        size_t matched = 0;
        size_t sLen = s.size();
        size_t tLen = t.size();
        size_t minLeft = 0;
        size_t minLen = numeric_limits<size_t>::max();

        for (size_t right = 0; right < sLen; right++) {
            if (count[s[right]] > 0) {
                matched++;
            }

            count[s[right]]--;

            while (matched == tLen) {
                int size = right - left + 1;
                if (size < minLen) {
                    minLen = size;
                    minLeft = left;
                }

                count[s[left]]++;
                if (count[s[left]] > 0) {
                    matched--;
                }

                left++;
            }
        }

        if (minLen == numeric_limits<size_t>::max()) {
            return "";
        }

        return s.substr(minLeft, minLen);
    }
};
