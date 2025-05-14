#include <numeric>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> array;

    void backtrack(vector<int> &candidates, int target, int index) {
        if (accumulate(array.begin(), array.end(), 0) == target) {
            result.push_back(array);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (accumulate(array.begin(), array.end(), 0) + candidates[i] <= target) {
                array.push_back(candidates[i]);
                backtrack(candidates, target, i);
                array.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        backtrack(candidates, target, 0);

        return result;
    }
};

class Solution {
    vector<vector<int>> result;
    vector<int> array;

    void backtrack(vector<int> &candidates, int target, int index) {
        if (target < 0) {
            return;
        }

        if (target == 0) {
            result.push_back(array);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            array.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i);
            array.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        backtrack(candidates, target, 0);

        return result;
    }
};