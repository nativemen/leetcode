#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
        size_t size = nums1.size();
        vector<pair<int, int>> nums;

        for (size_t i = 0; i < size; i++) {
            nums.push_back({nums1[i], nums2[i]});
        }

        sort(nums.begin(), nums.end(), [](pair<int, int> x, pair<int, int> y) { return x.second > y.second; });

        priority_queue<long long> q;
        long long result = 0;
        long long sum = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            sum += nums[i].first;
            q.push(-nums[i].first);

            if (q.size() > k) {
                sum -= -q.top();
                q.pop();
            }

            if (q.size() == k) {
                result = max(result, (long long)nums[i].second * sum);
            }
        }

        return result;
    }
};