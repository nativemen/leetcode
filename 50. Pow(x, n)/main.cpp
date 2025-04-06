#include <cmath>
#include <limits>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        return pow(x, n);
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        if (fabs(x) < numeric_limits<double>::epsilon()) {
            return 0.0;
        }

        if (n == 0) {
            return 1.0;
        }

        if (n < 0) {
            return 1 / (x * myPow(x, -1 - n));
        }

        double power = myPow(x, n / 2);

        if (n % 2 == 0) {
            return power * power;
        }

        return x * power * power;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        if (fabs(x) < numeric_limits<double>::epsilon()) {
            return 0.0;
        }

        if (n == 0) {
            return 1.0;
        }

        long long num = n;
        if (num < 0) {
            x = 1 / x;
            num = -num;
        }

        double result = 1.0;
        while (num > 0) {
            if (num % 2 == 1) {
                result *= x;
            }

            x *= x;
            num /= 2;
        }

        return result;
    }
};