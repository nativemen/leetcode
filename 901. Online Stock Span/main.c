#include <stdbool.h>
#include <stdio.h>

#define STOCK_SIZE 10000

typedef struct {
    int stock[STOCK_SIZE];
    int spanner[STOCK_SIZE];
    int count;
} StockSpanner;

StockSpanner *stockSpannerCreate(void) {
    StockSpanner *obj = (StockSpanner *)malloc(sizeof(StockSpanner));
    obj->count = 0;
    return obj;
}

int stockSpannerNext(StockSpanner *obj, int price) {
    int span = 1;
    int count = 0;

    while (count < obj->count && obj->stock[obj->count - 1 - count] <= price) {
        span += obj->spanner[obj->count - 1 - count];
        count += obj->spanner[obj->count - 1 - count];
    }

    obj->stock[obj->count] = price;
    obj->spanner[obj->count] = span;
    obj->count++;

    return span;
}

void stockSpannerFree(StockSpanner *obj) {
    if (obj == NULL) {
        return;
    }

    free(obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 * stockSpannerFree(obj);
 */

#define STOCK_SIZE 10000

typedef struct {
    int stock[STOCK_SIZE];
    int spanner[STOCK_SIZE];
    int top;
} StockSpanner;

StockSpanner *stockSpannerCreate(void) {
    StockSpanner *obj = (StockSpanner *)malloc(sizeof(StockSpanner));
    obj->top = -1;
    return obj;
}

int stockSpannerNext(StockSpanner *obj, int price) {
    int span = 1;

    while (obj->top >= 0 && obj->stock[obj->top] <= price) {
        span += obj->spanner[obj->top];
        obj->top--;
    }

    obj->top++;
    obj->stock[obj->top] = price;
    obj->spanner[obj->top] = span;

    return span;
}

void stockSpannerFree(StockSpanner *obj) {
    if (obj == NULL) {
        return;
    }

    free(obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 * stockSpannerFree(obj);
 */