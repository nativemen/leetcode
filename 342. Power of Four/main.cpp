class Solution {
public:
    bool isPowerOfFour(int n) {
        long long val = 1;

        while (val < n) {
            val *= 4;
        }

        if (val == n) {
            return true;
        }

        return false;
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1) {
            return true;
        } else if (n < 1) {
            return false;
        } else if (n % 4 == 0) {
            return isPowerOfFour(n / 4);
        } else {
            return false;
        }
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1) {
            return true;
        }

        if (n < 1 || n % 4 != 0) {
            return false;
        }

        return isPowerOfFour(n / 4);
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }

        while (n % 4 == 0) {
            n /= 4;
        }

        return n == 1;
    }
};
