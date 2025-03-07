#include <algorithm>
#include <vector>

using std::reverse;
using std::sort;
using std::vector;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        vector<int> dp(ARRAY_SIZE + 1, 0);

        for (const auto &citation : citations) {
            dp[citation]++;
        }

        for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
            dp[i] += dp[i + 1];
            if (dp[i] >= i) {
                return i;
            }
        }

        return 0;
    }

private:
    static constexpr int ARRAY_SIZE = 1001;
};

class Solution {
public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end(), [](int a, int b) { return a > b; });

        int h = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] < i + 1) {
                break;
            }

            h = i + 1;
        }

        return h;
    }
};

class Solution {
public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end());
        reverse(citations.begin(), citations.end());

        int h = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] < i + 1) {
                break;
            }

            h = i + 1;
        }

        return h;
    }
};