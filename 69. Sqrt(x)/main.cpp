class Solution {
public:
    int mySqrt(int x) {
        long long left = 0;
        long long right = x;
        long long result = 0;

        while (left <= right) {
            long long mid = (left + right) / 2;

            if (x == mid * mid) {
                result = mid;
                break;
            } else if (x > mid * mid) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};