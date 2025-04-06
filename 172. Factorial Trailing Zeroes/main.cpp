class Solution {
public:
    int trailingZeroes(int n) {
        if (n == 0) {
            return 0;
        }

        int count = 0;
        int num = n;

        while (num % 5 == 0) {
            count++;
            num /= 5;
        }

        return count + trailingZeroes(n - 1);
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        return (n == 0) ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;

        while (n >= 5) {
            n /= 5;
            count += n;
        }

        return count;
    }
};