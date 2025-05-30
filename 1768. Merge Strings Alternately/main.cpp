#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        size_t len1 = word1.size();
        size_t len2 = word2.size();
        size_t index = 0;
        string result;

        while (index < len1 || index < len2) {
            if (index < len1) {
                result.push_back(word1[index]);
            }

            if (index < len2) {
                result.push_back(word2[index]);
            }

            index++;
        }

        return result;
    }
};

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        size_t len1 = word1.size();
        size_t len2 = word2.size();
        size_t i = 0;
        size_t j = 0;
        string result;

        while (i < len1 || j < len2) {
            if (i < len1) {
                result.push_back(word1[i++]);
            }

            if (j < len2) {
                result.push_back(word2[j++]);
            }
        }

        return result;
    }
};