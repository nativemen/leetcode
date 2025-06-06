#include <queue>

using namespace std;

class RecentCounter {
    static constexpr int TIME_OFFSET = 3000;
    queue<int> q;

public:
    RecentCounter() {}

    int ping(int t) {
        q.push(t);

        while (q.front() + TIME_OFFSET < t) {
            q.pop();
        }

        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */