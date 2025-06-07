#include <deque>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        deque<int> rq;
        deque<int> dq;
        size_t size = senate.size();

        for (size_t i = 0; i < size; i++) {
            if (senate[i] == 'R') {
                rq.push_back(i);
            } else {
                dq.push_back(i);
            }
        }

        while (!rq.empty() && !dq.empty()) {
            int r = rq.front();
            rq.pop_front();
            int d = dq.front();
            dq.pop_front();

            if (r < d) {
                rq.push_back(r + size);
            } else {
                dq.push_back(d + size);
            }
        }

        if (rq.empty()) {
            return "Dire";
        }

        return "Radiant";
    }
};

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rq;
        queue<int> dq;
        size_t size = senate.size();

        for (size_t i = 0; i < size; i++) {
            if (senate[i] == 'R') {
                rq.push(i);
            } else {
                dq.push(i);
            }
        }

        while (!rq.empty() && !dq.empty()) {
            int r = rq.front();
            rq.pop();
            int d = dq.front();
            dq.pop();

            if (r < d) {
                rq.push(r + size);
            } else {
                dq.push(d + size);
            }
        }

        if (rq.empty()) {
            return "Dire";
        }

        return "Radiant";
    }
};