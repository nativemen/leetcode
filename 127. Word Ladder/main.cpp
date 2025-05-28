#include <algorithm>
#include <cstdint>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    static constexpr size_t HASH_SHIFT_BITS = 5;
    static constexpr size_t ALPHABET_SIZE = 26;

    uint64_t word2Hash(string word) {
        size_t wordLen = word.size();
        uint64_t hash = 0;

        for (const auto &c : word) {
            hash = (hash << HASH_SHIFT_BITS) | (c - 'a');
        }

        return hash;
    }

    static void genWordTrans(uint64_t wordHash, size_t wordLen, vector<uint64_t> &wordTrans) {
        wordTrans.clear();

        for (size_t i = 0; i < wordLen; i++) {
            uint64_t mask = 0x1FULL << (i * HASH_SHIFT_BITS);

            for (uint64_t j = 0; j < ALPHABET_SIZE; j++) {
                uint64_t transHash = (wordHash & ~mask) | (j << (i * HASH_SHIFT_BITS));

                if (transHash == wordHash) {
                    continue;
                }

                wordTrans.push_back(transHash);
            }
        }
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<uint64_t> wordListSet;

        for (const auto &word : wordList) {
            wordListSet.emplace(word2Hash(word));
        }

        uint64_t endWordHash = word2Hash(endWord);

        if (!wordListSet.contains(endWordHash)) {
            return 0;
        }

        queue<pair<uint64_t, int>> q;
        q.push({word2Hash(beginWord), 1});

        unordered_set<uint64_t> visited;
        size_t wordLen = beginWord.size();

        while (!q.empty()) {
            pair<uint64_t, int> current = q.front();
            uint64_t currentHash = current.first;
            int steps = current.second;
            q.pop();

            if (currentHash == endWordHash) {
                return steps;
            }

            vector<uint64_t> wordTrans;

            genWordTrans(currentHash, wordLen, wordTrans);

            for (const auto &transHash : wordTrans) {
                if (!visited.contains(transHash) && wordListSet.contains(transHash)) {
                    q.push({transHash, steps + 1});
                    visited.emplace(transHash);
                }
            }
        }

        return 0;
    }
};

class Solution {
    static constexpr size_t ALPHABET_SIZE = 26;

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> wordListSet(wordList.begin(), wordList.end());

        if (!wordListSet.contains(endWord)) {
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        size_t wordLen = beginWord.size();

        while (!q.empty()) {
            pair<string, int> current = q.front();
            string currentWord = current.first;
            int steps = current.second;
            q.pop();

            if (currentWord == endWord) {
                return steps;
            }

            for (size_t i = 0; i < wordLen; i++) {
                char original = currentWord[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    currentWord[i] = c;

                    if (currentWord[i] != original && wordListSet.contains(currentWord)) {
                        q.push({currentWord, steps + 1});
                        wordListSet.erase(currentWord);
                    }
                }

                currentWord[i] = original;
            }
        }

        return 0;
    }
};

class Solution {
    bool isValid(string s1, string s2) {
        size_t len1 = s1.size();
        size_t len2 = s2.size();

        if (len1 != len2) {
            return false;
        }

        size_t diff = 0;

        for (size_t i = 0; i < len1; i++) {
            if (s1[i] != s2[i]) {
                diff++;
            }
        }

        return diff == 1;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        vector<bool> visited(wordList.size(), false);
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        size_t wordLen = beginWord.size();
        size_t wordListSize = wordList.size();

        while (!q.empty()) {
            pair<string, int> current = q.front();
            string currentWord = current.first;
            int steps = current.second;
            q.pop();

            if (currentWord == endWord) {
                return steps;
            }

            for (size_t i = 0; i < wordListSize; i++) {
                if (!visited[i] && isValid(currentWord, wordList[i])) {
                    q.push({wordList[i], steps + 1});
                    visited[i] = true;
                }
            }
        }

        return 0;
    }
};