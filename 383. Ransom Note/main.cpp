#include <string>
#include <vector>

using std::string;
using std::vector;

#define LETTERS_NUM 26

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int from[LETTERS_NUM] = {0};
        int to[LETTERS_NUM] = {0};

        for (int i = 0; i < magazine.length(); i++) {
            from[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ransomNote.length(); i++) {
            to[ransomNote[i] - 'a']++;
            if (to[ransomNote[i] - 'a'] > from[ransomNote[i] - 'a']) {
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[LETTERS_NUM] = {0};

        for (int i = 0; i < magazine.length(); i++) {
            count[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ransomNote.length(); i++) {
            count[ransomNote[i] - 'a']--;
            if (count[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(LETTERS_NUM);

        for (auto c : magazine) {
            count[c - 'a']++;
        }

        for (auto c : ransomNote) {
            count[c - 'a']--;
            if (count[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};