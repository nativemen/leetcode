#include <stdbool.h>

static int computeNext(int n) {
    int sum = 0;

    while (n != 0) {
        int num = n % 10;
        sum += num * num;
        n /= 10;
    }

    return sum;
}

#define ARRAY_SIZE 1000

bool isHappy(int n) {
    int history[ARRAY_SIZE] = {0};
    history[0] = n;
    int count = 1;

    while (true) {
        int num = computeNext(history[count - 1]);
        if (num == 1) {
            return true;
        }

        for (int i = 0; i < count; i++) {
            if (num == history[i]) {
                return false;
            }
        }

        history[count++] = num;
    }

    return false;
}

static int computeNext(int n) {
    int sum = 0;

    while (n != 0) {
        int num = n % 10;
        sum += num * num;
        n /= 10;
    }

    return sum;
}

bool isHappy(int n) {
    int slow = n;
    int fast = computeNext(n);

    while (fast != 1 && fast != slow) {
        slow = computeNext(slow);
        fast = computeNext(computeNext(fast));
    }

    return fast == 1;
}

static int computeNext(int n) {
    int sum = 0;

    while (n != 0) {
        int num = n % 10;
        sum += num * num;
        n /= 10;
    }

    return sum;
}

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