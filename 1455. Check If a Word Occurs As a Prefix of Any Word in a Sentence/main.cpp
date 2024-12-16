#include <sstream>
#include <string>
#include <vector>

using std::istringstream;
using std::string;
using std::vector;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int num = 0;
        int start = 0;
        for (size_t i = 0; i <= sentence.length(); i++) {
            if (sentence[i] == ' ' || sentence[i] == '\0') {
                num++;
                if (sentence.substr(start, i - start).find(searchWord) == 0) {
                    return num;
                }
                start = i + 1;
            }
        }

        return -1;
    }
};

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int strLen = sentence.length();
        int searchLen = searchWord.length();
        int num = 0;
        int start = 0;
        for (size_t i = 0; i <= strLen; i++) {
            if (sentence[i] == ' ' || sentence[i] == '\0') {
                num++;
                if (i - start >= searchLen && sentence.compare(start, searchLen, searchWord) == 0) {
                    return num;
                }
                start = i + 1;
            }
        }

        return -1;
    }
};

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss(sentence);
        string word;

        for (int i = 1; iss >> word; i++) {
            if (word.starts_with(searchWord)) {
                return i;
            }
        }

        return -1;
    }
};