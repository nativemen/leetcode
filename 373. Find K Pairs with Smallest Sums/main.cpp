#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        for (const auto num1 : nums1) {
            for (const auto num2 : nums2) {
                int sum = num1 + num2;

                if (maxHeap.size() >= k) {
                    if (maxHeap.top().first > sum) {
                        maxHeap.pop();
                    } else {
                        break;
                    }
                }
                maxHeap.push({sum, {num1, num2}});
            }
        }

        vector<vector<int>> result;

        while (!maxHeap.empty()) {
            result.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }

        return result;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<vector<int>> result;

        if (nums1.empty() || nums2.empty() || k <= 0) {
            return result;
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;

        for (int i = 0; i < nums1.size() && i < k; i++) {
            minHeap.push({nums1[i] + nums2[0], i, 0});
        }

        while (k-- > 0 && !minHeap.empty()) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();
            result.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size()) {
                minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return result;
    }
};