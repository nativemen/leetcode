class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;

        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }

        return left << shift;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            right &= right - 1;
        }

        return right;
    }
};