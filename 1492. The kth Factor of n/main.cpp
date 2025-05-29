class Solution {
public:
    int kthFactor(int n, int k) {
        int num = 1;

        while (num <= n) {
            if (n % num == 0) {
                k--;
                if (k == 0) {
                    return num;
                }
            }

            num++;
        }

        return -1;
    }
};

class Solution {
public:
    int kthFactor(int n, int k) {
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
                if (count == k) {
                    return i;
                }
            }
        }

        return -1;
    }
};