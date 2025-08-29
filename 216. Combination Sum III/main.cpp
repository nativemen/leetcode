
#include <vector>

using namespace std;

class Solution {
    void backtrace(vector<vector<int>> &result, vector<int> &array, int k, int n, int start) {
        if (k == 0) {
            if (n == 0) {
                result.push_back(array);
            }

            return;
        }

        for (int i = start; i <= 9; i++) {
            if (i > n) {
                break;
            }

            array.push_back(i);
            backtrace(result, array, k - 1, n - i, i + 1);
            array.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> array;

        backtrace(result, array, k, n, 1);

        return result;
    }
};