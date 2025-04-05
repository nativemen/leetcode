int mySqrt(int x) {
    if (x == 0 || x == 1) {
        return x;
    }

    long long right = 1;

    while ((long long)x > right * right) {
        right *= 2;
    }

    long long left = right / 2;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if ((long long)x == mid * mid) {
            return mid;
        } else if ((long long)x > mid * mid) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (x < left * left) {
        return left - 1;
    }

    return left;
}

int mySqrt(int x) {
    long long left = 0;
    long long right = x;
    long long result = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if ((long long)x == mid * mid) {
            result = mid;
            break;
        } else if ((long long)x > mid * mid) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}
