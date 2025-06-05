#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string result;
        vector<int> nVec;
        int num = 0;

        for (const auto &c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                result.push_back(c);
                nVec.push_back(num);
                num = 0;
            } else if (c == ']') {
                string str;
                while (result.back() != '[') {
                    str.insert(str.begin(), result.back());
                    result.pop_back();
                }
                result.pop_back();
                int number = nVec.back();
                nVec.pop_back();

                for (int i = 0; i < number; i++) {
                    result.append(str);
                }
            } else {
                result.push_back(c);
            }
        }

        return result;
    }
};

class Solution {
public:
    string decodeString(string s) {
        vector<tuple<string, int>> v;
        int curNum = 0;
        string curStr;

        for (const auto &c : s) {
            if (isdigit(c)) {
                curNum = curNum * 10 + (c - '0');
            } else if (c == '[') {
                v.push_back(tuple(curStr, curNum));
                curNum = 0;
                curStr = "";
            } else if (c == ']') {
                auto [prevStr, num] = v.back();
                v.pop_back();

                for (int i = 0; i < num; i++) {
                    prevStr.append(curStr);
                }

                curStr.assign(prevStr);
            } else {
                curStr.push_back(c);
            }
        }

        return curStr;
    }
};