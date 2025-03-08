#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::stack;
using std::string;
using std::vector;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> tokens;
        char delimiter = ' ';
        size_t start = 0;
        size_t end = s.find(delimiter);

        while (end != string::npos) {
            if (start != end) {
                tokens.push_back(s.substr(start, end - start));
            }
            start = end + 1;
            end = s.find(delimiter, start);
        }

        if (start != s.size()) {
            tokens.push_back(s.substr(start));
        }

        string result;
        for (auto it = tokens.rbegin(); it != tokens.rend(); it++) {
            if (!result.empty()) {
                result.append(" ");
            }
            result.append(*it);
        }

        return result;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        stack<string> tokens;
        char delimiter = ' ';
        size_t start = 0;
        size_t end = s.find(delimiter);

        while (end != string::npos) {
            if (start != end) {
                tokens.push(s.substr(start, end - start));
            }
            start = end + 1;
            end = s.find(delimiter, start);
        }

        if (start != s.size()) {
            tokens.push(s.substr(start));
        }

        string result;

        while (!tokens.empty()) {
            result.append(tokens.top());
            tokens.pop();
            if (!tokens.empty()) {
                result.append(" ");
            }
        }

        return result;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";

        for (const auto &c : s) {
            if (c != ' ') {
                word += c;
            } else {
                if (word != "") {
                    words.push_back(word);
                    word = "";
                }
            }
        }

        if (word != "") {
            words.push_back(word);
        }

        string result = "";
        for (auto it = words.rbegin(); it != words.rend(); it++) {
            if (!result.empty()) {
                result += " ";
            }

            result += *it;
        }

        return result;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        string word = "";

        for (const auto &c : s) {
            if (c != ' ') {
                word += c;
            } else {
                if (word != "") {
                    words.push(word);
                    word = "";
                }
            }
        }

        if (word != "") {
            words.push(word);
        }

        string result;

        while (!words.empty()) {
            result.append(words.top());
            words.pop();
            if (!words.empty()) {
                result.append(" ");
            }
        }

        return result;

        return result;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        string result;
        int size = s.size();
        int count = 0;
        int offset = 0;

        for (int i = size - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                count++;
                if (i == 0 || s[i - 1] == ' ') {
                    result.append(s.substr(i, count));
                    result.append(" ");
                    count = 0;
                }
            }
        }

        if (result[result.size() - 1] = ' ') {
            result.erase(result.size() - 1, 1);
        }

        return result;
    }
};
