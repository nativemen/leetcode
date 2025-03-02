#include <vector>

using std::vector;

class Solution {
public:
    int findKthPositive(vector<int> &arr, int k) {
        vector<bool> isMissing(ARRAY_SIZE, true);

        for (const auto &num : arr) {
            isMissing[num] = false;
        }

        for (int i = 1; i < ARRAY_SIZE; i++) {
            if (!isMissing[i]) {
                continue;
            }

            k--;
            if (k <= 0) {
                return i;
            }
        }

        return -1;
    }

private:
    static constexpr int ARRAY_SIZE = 2001;
};

class Solution {
public:
    int findKthPositive(vector<int> &arr, int k) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] - (mid + 1) < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left + k;
    }
};

class Solution {
public:
    int findKthPositive(vector<int> &arr, int k) {
        for (const auto &num : arr) {
            if (num <= k) {
                k++;
            }
        }

        return k;
    }
};