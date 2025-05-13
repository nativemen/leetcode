#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> result;

    void backtrack(int n, int k, vector<int> &array, int value) {
        if (array.size() == k) {
            result.push_back(array);
            return;
        }

        for (int i = value; i <= n; i++) {
            array.push_back(i);
            backtrack(n, k, array, i + 1);
            array.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0 || k > n) {
            return result;
        }

        vector<int> array;
        backtrack(n, k, array, 1);

        return result;
    }
};

class Solution {
    void backtrack(vector<vector<int>> &result, vector<int> &array, int n, int k, int value) {
        if (array.size() == k) {
            result.push_back(array);
            return;
        }

        for (int i = value; i <= n; i++) {
            array.push_back(i);
            backtrack(result, array, n, k, i + 1);
            array.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;

        if (n <= 0 || k <= 0 || k > n) {
            return result;
        }

        vector<int> array;
        backtrack(result, array, n, k, 1);

        return result;
    }
};