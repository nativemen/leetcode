class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long square = (long long)mid * (long long)mid;

            if (square == (long long)x) {
                return mid;
            } else if (square < (long long)x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        long long i = 0;

        while (i * i <= (long long)x) {
            i++;
        }

        return (int)(i - 1);
    }
};