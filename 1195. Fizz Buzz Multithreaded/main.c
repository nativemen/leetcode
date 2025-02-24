#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int n;
    int cur;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} FizzBuzz;

FizzBuzz *fizzBuzzCreate(int n) {
    FizzBuzz *obj = (FizzBuzz *)malloc(sizeof(FizzBuzz));
    if (obj == NULL) {
        return NULL;
    }

    obj->n = n;
    obj->cur = 1;
    pthread_mutex_init(&obj->mutex, NULL);
    pthread_cond_init(&obj->cond, NULL);
    return obj;
}

static bool hasFinished(FizzBuzz *obj) {
    return obj->cur > obj->n;
}

static bool isFizz(FizzBuzz *obj) {
    return (obj->cur % 3 == 0) && (obj->cur % 5 != 0);
}

static bool isBuzz(FizzBuzz *obj) {
    return (obj->cur % 3 != 0) && (obj->cur % 5 == 0);
}

static bool isFizzBuzz(FizzBuzz *obj) {
    return (obj->cur % 3 == 0) && (obj->cur % 5 == 0);
}

static bool isNumber(FizzBuzz *obj) {
    return (obj->cur % 3 != 0) && (obj->cur % 5 != 0);
}

// printFizz() outputs "fizz".
void fizz(FizzBuzz *obj) {
    bool looping = true;

    while (looping) {
        pthread_mutex_lock(&obj->mutex);
        while (!hasFinished(obj) && !isFizz(obj)) {
            pthread_cond_wait(&obj->cond, &obj->mutex);
        }

        if (hasFinished(obj)) {
            looping = false;
        } else {
            printFizz();
            obj->cur++;
        }
        pthread_cond_broadcast(&obj->cond);
        pthread_mutex_unlock(&obj->mutex);
    }
}

// printBuzz() outputs "buzz".
void buzz(FizzBuzz *obj) {
    bool looping = true;

    while (looping) {
        pthread_mutex_lock(&obj->mutex);
        while (!hasFinished(obj) && !isBuzz(obj)) {
            pthread_cond_wait(&obj->cond, &obj->mutex);
        }

        if (hasFinished(obj)) {
            looping = false;
        } else {
            printBuzz();
            obj->cur++;
        }
        pthread_cond_broadcast(&obj->cond);
        pthread_mutex_unlock(&obj->mutex);
    }
}

// printFizzBuzz() outputs "fizzbuzz".
void fizzbuzz(FizzBuzz *obj) {
    bool looping = true;

    while (looping) {
        pthread_mutex_lock(&obj->mutex);
        while (!hasFinished(obj) && !isFizzBuzz(obj)) {
            pthread_cond_wait(&obj->cond, &obj->mutex);
        }

        if (hasFinished(obj)) {
            looping = false;
        } else {
            printFizzBuzz();
            obj->cur++;
        }
        pthread_cond_broadcast(&obj->cond);
        pthread_mutex_unlock(&obj->mutex);
    }
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.
void number(FizzBuzz *obj) {
    bool looping = true;

    while (looping) {
        pthread_mutex_lock(&obj->mutex);
        while (!hasFinished(obj) && !isNumber(obj)) {
            pthread_cond_wait(&obj->cond, &obj->mutex);
        }

        if (hasFinished(obj)) {
            looping = false;
        } else {
            printNumber(obj->cur);
            obj->cur++;
        }
        pthread_cond_broadcast(&obj->cond);
        pthread_mutex_unlock(&obj->mutex);
    }
}

void fizzBuzzFree(FizzBuzz *obj) {
    if (obj == NULL) {
        return;
    }

    pthread_mutex_destroy(&obj->mutex);
    pthread_cond_destroy(&obj->cond);
    free(obj);
}