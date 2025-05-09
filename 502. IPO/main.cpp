#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
        int size = profits.size();
        vector<pair<int, int>> ipo;

        for (int i = 0; i < size; i++) {
            ipo.emplace_back(capital[i], profits[i]);
        }

        sort(ipo.begin(), ipo.end());

        priority_queue<int> maxHeap;
        int i = 0;

        while (k-- > 0) {
            while (i < size && ipo[i].first <= w) {
                maxHeap.push(ipo[i].second);
                i++;
            }

            if (maxHeap.empty()) {
                break;
            }

            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};

#include <ranges>

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
        int size = profits.size();
        vector<pair<int, int>> ipo;

        for (auto [c, p] : views::zip(capital, profits)) {
            ipo.emplace_back(c, p);
        }

        sort(ipo.begin(), ipo.end());

        priority_queue<int> maxHeap;
        int i = 0;

        while (k-- > 0) {
            while (i < size && ipo[i].first <= w) {
                maxHeap.push(ipo[i].second);
                i++;
            }

            if (maxHeap.empty()) {
                break;
            }

            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};