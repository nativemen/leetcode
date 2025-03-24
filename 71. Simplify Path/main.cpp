#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stacks;
        istringstream iss(path);
        string word;

        while (getline(iss, word, '/')) {
            if (word == "..") {
                if (!stacks.empty()) {
                    stacks.pop_back();
                }
            } else {
                if (!word.empty() && word != ".") {
                    stacks.push_back(word);
                }
            }
        }

        string result;
        for (const auto &dir : stacks) {
            result.push_back('/');
            result.append(dir);
        }

        if (stacks.empty()) {
            result.push_back('/');
        }

        return result;
    }
};