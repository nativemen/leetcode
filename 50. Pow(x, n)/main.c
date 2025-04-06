#include <float.h>

double myPow(double x, int n) {
    if (fabs(x) < DBL_EPSILON) {
        return 0.0;
    }

    if (n == 0) {
        return 1.0;
    }

    if (n < 0) {
        return 1 / (x * myPow(x, -n - 1));
    }

    int mid = n / 2;
    double power = myPow(x, mid);

    if (n % 2 == 0) {
        return power * power;
    }

    return x * power * power;
}

double myPow(double x, int n) {
    return pow(x, n);
}

#include <float.h>

double myPow(double x, int n) {
    if (fabs(x) < DBL_EPSILON) {
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