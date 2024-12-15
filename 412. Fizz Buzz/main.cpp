#include <string>
#include <vector>

using std::string;
using std::vector;

using std::to_string;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for (int i = 1; i <= n; i++) {
            answer.push_back(convert(i));
        }

        return answer;
    }

    string convert(int index) {
        string result;

        if (index % 3 == 0) {
            result += "Fizz";
        }

        if (index % 5 == 0) {
            result += "Buzz";
        }

        if (result.length() == 0) {
            result += to_string(index);
        }

        return result;
    }
};

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for (int i = 1; i <= n; i++) {
            string result;
            if (i % 3 == 0) {
                result += "Fizz";
            }

            if (i % 5 == 0) {
                result += "Buzz";
            }

            if (result.length() == 0) {
                result = to_string(i);
            }
            answer.push_back(result);
        }

        return answer;
    }
};