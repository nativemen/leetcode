#include <stack>
#include <stdexcept>
#include <vector>
#include <utility>

using std::stack;
using std::vector;
using std::pair;

class MinStack {
public:
    MinStack()
        : count(0) {
        for (int i = 0; i < STACK_SIZE; i++) {
            val_stack[i] = 0;
            min_stack[i] = 0;
        }
    }

    void push(int val) {
        if (count >= STACK_SIZE) {
            if (count == 0) {
                throw std::out_of_range("Stack is full.");
            }
        }

        val_stack[count] = val;
        if (count == 0) {
            min_stack[count] = 0;
        } else if (val < val_stack[min_stack[count - 1]]) {
            min_stack[count] = count;
        } else {
            min_stack[count] = min_stack[count - 1];
        }

        count++;
    }

    void pop() {
        if (count == 0) {
            throw std::out_of_range("Stack is empty.");
        }

        count--;
    }

    int top() {
        if (count == 0) {
            throw std::out_of_range("Stack is empty.");
        }

        return val_stack[count - 1];
    }

    int getMin() {
        if (count == 0) {
            throw std::out_of_range("Stack is empty.");
        }

        return val_stack[min_stack[count - 1]];
    }

private:
    static constexpr int STACK_SIZE = 30000;
    int val_stack[STACK_SIZE];
    int min_stack[STACK_SIZE];
    int count;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
public:
    MinStack()
        : count(0) {
        val_stack.reserve(STACK_SIZE);
        min_stack.reserve(STACK_SIZE);
    }

    void push(int val) {
        if (count >= STACK_SIZE) {
            throw std::out_of_range("Stack is full.");
        }

        val_stack.push_back(val);
        if (count == 0) {
            min_stack.push_back(0);
        } else {
            int idx = (val < val_stack[min_stack[count - 1]]) ? count : min_stack[count - 1];
            min_stack.push_back(idx);
        }

        count++;
    }

    void pop() {
        if (count == 0) {
            throw std::out_of_range("Stack is empty.");
        }

        val_stack.pop_back();
        min_stack.pop_back();
        count--;
    }

    int top() {
        if (count == 0) {
            throw std::out_of_range("Stack is empty.");
        }

        return val_stack[count - 1];
    }

    int getMin() {
        if (count == 0) {
            throw std::out_of_range("Stack is empty.");
        }

        return val_stack[min_stack[count - 1]];
    }

private:
    static constexpr int STACK_SIZE = 30000;
    vector<int> val_stack;
    vector<int> min_stack;
    int count;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
public:
    MinStack() {}

    void push(int val) {
        if (val_stack.size() >= STACK_SIZE) {
            throw std::out_of_range("Stack is full.");
        }

        if (val_stack.empty()) {
            min_stack.push(val);
        } else {
            int min_val = (val < min_stack.top()) ? val : min_stack.top();
            min_stack.push(min_val);
        }
        val_stack.push(val);
    }

    void pop() {
        if (val_stack.empty()) {
            throw std::out_of_range("Stack is empty.");
        }

        val_stack.pop();
        min_stack.pop();
    }

    int top() {
        if (val_stack.empty()) {
            throw std::out_of_range("Stack is empty.");
        }

        return val_stack.top();
    }

    int getMin() {
        if (val_stack.empty()) {
            throw std::out_of_range("Stack is empty.");
        }

        return min_stack.top();
    }

private:
    static constexpr int STACK_SIZE = 30000;
    stack<int> val_stack;
    stack<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
public:
    MinStack() {}

    void push(int val) {
        if (stacks.size() >= STACK_SIZE) {
            throw std::out_of_range("Stack is full.");
        }

        if (stacks.empty()) {
            stacks.push({val, val});
        } else {
            int prev = stacks.top().second;
            if (val < prev) {
                stacks.push({val, val});
            } else {
                stacks.push({val, prev});
            }
        }
    }

    void pop() {
        if (stacks.empty()) {
            throw std::out_of_range("Stack is empty.");
        }

        stacks.pop();
    }

    int top() {
        if (stacks.empty()) {
            throw std::out_of_range("Stack is empty.");
        }

        return stacks.top().first;
    }

    int getMin() {
        if (stacks.empty()) {
            throw std::out_of_range("Stack is empty.");
        }

        return stacks.top().second;
    }

private:
    static constexpr int STACK_SIZE = 30000;
    stack<pair<int, int>> stacks;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */