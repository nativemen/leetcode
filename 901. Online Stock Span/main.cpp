#include <stack>
#include <vector>

using namespace std;

class StockSpanner {
    vector<int> stock;
    vector<int> spanner;

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;

        while (!stock.empty() && stock[stock.size() - 1] <= price) {
            span += spanner.back();
            spanner.pop_back();
            stock.pop_back();
        }

        stock.push_back(price);
        spanner.push_back(span);

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

class StockSpanner {
    stack<pair<int, int>> stk;

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;

        while (!stk.empty() && stk.top().first <= price) {
            span += stk.top().second;
            stk.pop();
        }

        stk.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */