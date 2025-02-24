#include <condition_variable>
#include <functional>
#include <mutex>
#include <pthread.h>

using std::condition_variable;
using std::mutex;
using std::unique_lock;

class FizzBuzz {
private:
    int n;
    int cur;
    pthread_cond_t cond;
    pthread_mutex_t mutex;

    bool hasFinished() {
        return cur > n;
    }

    bool isFizz() {
        return (cur % 3 == 0) && (cur % 5 != 0);
    }

    bool isBuzz() {
        return (cur % 3 != 0) && (cur % 5 == 0);
    }

    bool isFizzBuzz() {
        return (cur % 3 == 0) && (cur % 5 == 0);
    }

    bool isNumber() {
        return (cur % 3 != 0) && (cur % 5 != 0);
    }

public:
    FizzBuzz(int n)
        : n(n)
        , cur(1) {
        pthread_cond_init(&cond, nullptr);
        pthread_mutex_init(&mutex, nullptr);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        bool looping = true;

        while (looping) {
            pthread_mutex_lock(&mutex);
            while (!hasFinished() && !isFizz()) {
                pthread_cond_wait(&cond, &mutex);
            }

            if (hasFinished()) {
                looping = false;
            } else {
                printFizz();
                cur++;
            }
            pthread_cond_broadcast(&cond);
            pthread_mutex_unlock(&mutex);
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        bool looping = true;

        while (looping) {
            pthread_mutex_lock(&mutex);
            while (!hasFinished() && !isBuzz()) {
                pthread_cond_wait(&cond, &mutex);
            }

            if (hasFinished()) {
                looping = false;
            } else {
                printBuzz();
                cur++;
            }
            pthread_cond_broadcast(&cond);
            pthread_mutex_unlock(&mutex);
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        bool looping = true;

        while (looping) {
            pthread_mutex_lock(&mutex);
            while (!hasFinished() && !isFizzBuzz()) {
                pthread_cond_wait(&cond, &mutex);
            }

            if (hasFinished()) {
                looping = false;
            } else {
                printFizzBuzz();
                cur++;
            }
            pthread_cond_broadcast(&cond);
            pthread_mutex_unlock(&mutex);
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        bool looping = true;

        while (looping) {
            pthread_mutex_lock(&mutex);
            while (!hasFinished() && !isNumber()) {
                pthread_cond_wait(&cond, &mutex);
            }

            if (hasFinished()) {
                looping = false;
            } else {
                printNumber(cur);
                cur++;
            }
            pthread_cond_broadcast(&cond);
            pthread_mutex_unlock(&mutex);
        }
    }
};

class FizzBuzz {
private:
    int n;
    int cur;
    mutex mtx;
    condition_variable cv;

    bool hasFinished() {
        return cur > n;
    }

    bool isFizz() const {
        return (cur % 3 == 0) && (cur % 5 != 0);
    }

    bool isBuzz() const {
        return (cur % 3 != 0) && (cur % 5 == 0);
    }

    bool isFizzBuzz() const {
        return (cur % 3 == 0) && (cur % 5 == 0);
    }

    bool isNumber() const {
        return (cur % 3 != 0) && (cur % 5 != 0);
    }

public:
    FizzBuzz(int n)
        : n(n)
        , cur(1) {}

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return hasFinished() || isFizz(); });
            if (hasFinished()) {
                return;
            }

            printFizz();
            cur++;

            lock.unlock();
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return hasFinished() || isBuzz(); });
            if (hasFinished()) {
                return;
            }

            printBuzz();
            cur++;

            lock.unlock();
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return hasFinished() || isFizzBuzz(); });
            if (hasFinished()) {
                return;
            }

            printFizzBuzz();
            cur++;

            lock.unlock();
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return hasFinished() || isNumber(); });
            if (hasFinished()) {
                return;
            }

            printNumber(cur);
            cur++;

            lock.unlock();
            cv.notify_all();
        }
    }
};

class FizzBuzz {
private:
    int n;
    int cur;
    mutex mtx;
    condition_variable cv;

    bool hasFinished() {
        return cur > n;
    }

    bool isFizz() const {
        return (cur % 3 == 0) && (cur % 5 != 0);
    }

    bool isBuzz() const {
        return (cur % 3 != 0) && (cur % 5 == 0);
    }

    bool isFizzBuzz() const {
        return (cur % 3 == 0) && (cur % 5 == 0);
    }

    bool isNumber() const {
        return (cur % 3 != 0) && (cur % 5 != 0);
    }

    template <typename Checker, typename Action> void execute(Checker checker, Action action) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this, &checker] { return hasFinished() || checker(); });
            if (hasFinished()) {
                return;
            }

            action();
            cur++;

            lock.unlock();
            cv.notify_all();
        }
    }

public:
    FizzBuzz(int n)
        : n(n)
        , cur(1) {}

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        execute([this] { return isFizz(); }, [printFizz] { printFizz(); });
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        execute([this] { return isBuzz(); }, [printBuzz] { printBuzz(); });
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        execute([this] { return isFizzBuzz(); }, [printFizzBuzz] { printFizzBuzz(); });
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        execute([this] { return isNumber(); }, [this, printNumber] { printNumber(cur); });
    }
};