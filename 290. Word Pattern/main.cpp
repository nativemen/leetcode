#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using std::getline;
using std::istringstream;
using std::string;
using std::stringstream;
using std::unordered_map;
using std::vector;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        istringstream iss(s);
        string word;
        char deimiter = ' ';
        while (getline(iss, word, deimiter)) {
            if (!word.empty()) {
                words.push_back(word);
            }
        }

        size_t patternLen = pattern.size();
        size_t wordsLen = words.size();
        if (patternLen != wordsLen) {
            return false;
        }

        unordered_map<char, string> directMapping;
        unordered_map<string, char> reverseMapping;

        for (size_t i = 0; i < patternLen; i++) {
            if ((directMapping.find(pattern[i]) != directMapping.end() && directMapping[pattern[i]] != words[i]) ||
                (reverseMapping.find(words[i]) != reverseMapping.end() && reverseMapping[words[i]] != pattern[i])) {
                return false;
            }

            directMapping[pattern[i]] = words[i];
            reverseMapping[words[i]] = pattern[i];
        }

        return true;
    }
};

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        istringstream iss(s);
        string word;

        while (iss >> word) {
            words.push_back(word);
        }

        size_t patternLen = pattern.size();
        size_t wordsLen = words.size();
        if (patternLen != wordsLen) {
            return false;
        }

        unordered_map<char, string> directMapping;
        unordered_map<string, char> reverseMapping;

        for (size_t i = 0; i < patternLen; i++) {
            if ((directMapping.find(pattern[i]) != directMapping.end() && directMapping[pattern[i]] != words[i]) ||
                (reverseMapping.find(words[i]) != reverseMapping.end() && reverseMapping[words[i]] != pattern[i])) {
                return false;
            }

            directMapping[pattern[i]] = words[i];
            reverseMapping[words[i]] = pattern[i];
        }

        return true;
    }
};

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        size_t patternLen = pattern.size();
        size_t wordsLen = words.size();
        if (patternLen != wordsLen) {
            return false;
        }

        unordered_map<char, string> directMapping;
        unordered_map<string, char> reverseMapping;

        for (size_t i = 0; i < patternLen; i++) {
            if ((directMapping.find(pattern[i]) != directMapping.end() && directMapping[pattern[i]] != words[i]) ||
                (reverseMapping.find(words[i]) != reverseMapping.end() && reverseMapping[words[i]] != pattern[i])) {
                return false;
            }

            directMapping[pattern[i]] = words[i];
            reverseMapping[words[i]] = pattern[i];
        }

        return true;
    }
};

class Solution {
    static constexpr size_t ARRAY_SIZE = 26;

public:
    bool wordPattern(string pattern, string s) {
        size_t patternLen = pattern.size();
        vector<string> hashmap(ARRAY_SIZE, "");
        stringstream ss(s);
        string word;
        size_t idx = 0;

        while (ss >> word) {
            if (idx >= patternLen) {
                return false;
            }

            size_t index = pattern[idx] - 'a';
            if (hashmap[index].empty()) {
                for (size_t i = 0; i < ARRAY_SIZE; i++) {
                    if (!hashmap[i].empty() && hashmap[i] == word) {
                        return false;
                    }
                }
                hashmap[index] = word;
            } else {
                if (hashmap[index] != word) {
                    return false;
                }
            }

            idx++;
        }

        return idx == patternLen;
    }
};