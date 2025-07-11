#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    long long totalCost(vector<int> &costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        int left = 0;
        int right = costs.size() - 1;

        while (left <= right && pq1.size() < candidates) {
            pq1.push(costs[left++]);
        }

        while (left <= right && pq2.size() < candidates) {
            pq2.push(costs[right--]);
        }

        long long total = 0;

        while (k-- > 0) {
            if (pq2.empty() || (!pq1.empty() && pq1.top() <= pq2.top())) {
                total += (long long)pq1.top();
                pq1.pop();
                if (left <= right) {
                    pq1.push(costs[left++]);
                }
            } else if (pq1.empty() || (!pq2.empty() && pq1.top() > pq2.top())) {
                total += (long long)pq2.top();
                pq2.pop();
                if (left <= right) {
                    pq2.push(costs[right--]);
                }
            }
        }

        return total;
    }
};