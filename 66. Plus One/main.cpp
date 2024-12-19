#include <vector>

using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int size = digits.size();
        int addition = 1;

        if (digits[size - 1] < 9) {
            digits[size - 1] += addition;
            return digits;
        }

        for (int i = size - 1; i >= 0; i--) {
            int digit = digits[i];
            digits[i] = (digit + addition) % 10;
            addition = (digit + addition) / 10;
        }

        if (addition == 1) {
            digits.insert(digits.begin(), addition);
        }

        return digits;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int size = digits.size();

        for (int i = size - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);

        return digits;
    }
};