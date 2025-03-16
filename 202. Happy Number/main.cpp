#include <algorithm>
#include <vector>

using std::find;
using std::vector;

class Solution {
    int computeNext(int n) {
        int sum = 0;

        while (n != 0) {
            int num = n % 10;
            sum += num * num;
            n /= 10;
        }

        return sum;
    }

public:
    bool isHappy(int n) {
        vector<int> history;
        history.push_back(n);

        while (true) {
            int num = computeNext(history.back());
            if (num == 1) {
                return true;
            }

            if (find(history.begin(), history.end(), num) != history.end()) {
                break;
            }

            history.push_back(num);
        }

        return false;
    }
};

class Solution {
    int computeNext(int n) {
        int sum = 0;

        while (n != 0) {
            int num = n % 10;
            sum += num * num;
            n /= 10;
        }

        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while (fast != 1 && computeNext(fast) != 1) {
            slow = computeNext(slow);
            fast = computeNext(computeNext(fast));

            if (fast == slow) {
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool isHappy(int n) {
        if (n == 1 || n == 7) {
            return true;
        }

        if (n < 10) {
            return false;
        }

        int sum = 0;

        while (n != 0) {
            int num = n % 10;
            sum += num * num;
            n /= 10;
        }

        return isHappy(sum);
    }
};