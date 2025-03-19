#include <algorithm>
#include <string>

using std::reverse;
using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int index1 = a.size() - 1;
        int index2 = b.size() - 1;
        int carry = 0;

        while (index1 >= 0 || index2 >= 0 || carry > 0) {
            int digit1 = (index1 >= 0) ? a[index1--] - '0' : 0;
            int digit2 = (index2 >= 0) ? b[index2--] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            result.push_back('0' + (sum & 1));
            carry = sum >> 1;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
