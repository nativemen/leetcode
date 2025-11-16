class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 1;
        long long right = num;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;

            if (square == num) {
                return true;
            } else if (square < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        for (long long i = 0; i * i <= num; i++) {
            if (i * i == num) {
                return true;
            }
        }

        return false;
    }
};
