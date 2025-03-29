#include <algorithm>
#include <cstdint>
#include <functional>
#include <numeric>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    bool isAllMatched(vector<int> checked) {
        for (const auto &check : checked) {
            if (check == 0) {
                return false;
            }
        }

        return true;
    }

public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> result;

        if (s.empty() || words.empty()) {
            return result;
        }

        const size_t sLen = s.size();
        const size_t wordLen = words[0].size();
        const size_t wordsSize = words.size();
        const size_t total = wordLen * wordsSize;

        if (sLen < total) {
            return result;
        }

        const size_t searchSize = sLen - total;
        vector<int> checked(wordsSize);

        for (size_t i = 0; i <= searchSize; i++) {
            int offset = i;
            string subStr = s.substr(offset, wordLen);
            int count = 0;

            while (!isAllMatched(checked)) {
                bool found = false;

                for (size_t j = 0; j < wordsSize; j++) {
                    if (checked[j] == 1) {
                        continue;
                    }

                    if (subStr == words[j]) {
                        checked[j] = 1;
                        found = true;
                        count++;
                        offset += wordLen;
                        subStr = s.substr(offset, wordLen);
                    }
                }

                if (!found) {
                    break;
                }
            }

            if (count == wordsSize) {
                result.push_back(i);
            }

            checked = vector<int>(wordsSize);
        }

        return result;
    }
};

typedef struct {
    string word;
    int count;
} WordCount;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> result;

        if (s.empty() || words.empty()) {
            return result;
        }

        const size_t sLen = s.size();
        const size_t wordLen = words[0].size();
        const size_t wordsSize = words.size();
        const size_t total = wordLen * wordsSize;

        if (sLen < total) {
            return result;
        }

        sort(words.begin(), words.end());

        vector<WordCount> wordCount;
        int uniqueCount = 0;

        for (size_t i = 0; i < wordsSize;) {
            size_t j = i + 1;
            while (j < wordsSize && words[i] == words[j]) {
                j++;
            }
            wordCount.emplace_back(words[i], j - i);
            uniqueCount++;
            i = j;
        }

        vector<int> count;
        const size_t searchSize = sLen - total;

        for (size_t i = 0; i <= searchSize; i++) {
            int matched = 0;
            count = vector<int>(uniqueCount);

            for (size_t j = 0; j < wordsSize; j++) {
                string subStr = s.substr(i + j * wordLen, wordLen);
                int foundIndex = -1;
                int left = 0;
                int right = uniqueCount - 1;

                while (left <= right) {
                    int mid = (left + right) / 2;
                    int cmp = subStr.compare(wordCount[mid].word);
                    if (cmp == 0) {
                        foundIndex = mid;
                        break;
                    } else if (cmp > 0) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }

                if (foundIndex == -1) {
                    break;
                }

                count[foundIndex]++;
                if (count[foundIndex] > wordCount[foundIndex].count) {
                    break;
                }

                matched++;
            }

            if (matched == wordsSize) {
                result.push_back(i);
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> result;

        if (s.empty() || words.empty()) {
            return result;
        }

        const size_t sLen = s.size();
        const size_t wordLen = words[0].size();
        const size_t wordsSize = words.size();
        const size_t total = wordLen * wordsSize;

        if (sLen < total) {
            return result;
        }

        const string_view sv(s);
        const auto hasher = hash<string_view>{};
        const uint64_t targetHash = transform_reduce(words.begin(), words.end(), 0ULL, plus{}, hasher);

        for (size_t i = 0; i < wordLen; i++) {
            uint64_t currentHash = 0ULL;

            for (size_t j = 0; j < wordsSize; j++) {
                currentHash += hasher(sv.substr(i + j * wordLen, wordLen));
            }

            if (currentHash == targetHash) {
                result.push_back(i);
            }

            for (size_t j = i + wordLen; j + total <= sLen; j += wordLen) {
                currentHash -= hasher(sv.substr(j - wordLen, wordLen));
                currentHash += hasher(sv.substr(j + total - wordLen, wordLen));

                if (currentHash == targetHash) {
                    result.push_back(j);
                }
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> result;

        if (s.empty() || words.empty()) {
            return result;
        }

        const size_t sLen = s.size();
        const size_t wordLen = words[0].size();
        const size_t wordsSize = words.size();
        const size_t total = wordLen * wordsSize;

        if (sLen < total) {
            return result;
        }

        unordered_map<string, int> maps1;
        for (const auto &word : words) {
            maps1[word]++;
        }

        for (size_t i = 0; i < wordLen; i++) {
            size_t start = i;
            unordered_map<string, int> maps2;

            for (size_t end = i + wordLen; end <= sLen; end += wordLen) {
                string subStr = s.substr(end - wordLen, wordLen);

                if (maps1.find(subStr) != maps1.end()) {
                    maps2[subStr]++;

                    int requredCount = maps1[subStr];
                    while (maps2[subStr] > requredCount) {
                        string toDrop = s.substr(start, wordLen);
                        maps2[toDrop]--;
                        start += wordLen;
                    }

                    if (end - start == total) {
                        result.push_back(start);
                    }
                } else {
                    start = end;
                    maps2.clear();
                }
            }
        }

        return result;
    }
};