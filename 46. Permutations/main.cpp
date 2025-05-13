#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> array;

    void backtrack(vector<int> &nums) {
        if (array.size() == nums.size()) {
            result.push_back(array);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (find(array.begin(), array.end(), nums[i]) == array.end()) {
                array.push_back(nums[i]);
                backtrack(nums);
                array.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        backtrack(nums);

        return result;
    }
};

class Solution {
    void backtrack(vector<int> &nums, vector<vector<int>> &result, vector<int> &array) {
        if (array.size() == nums.size()) {
            result.push_back(array);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (find(array.begin(), array.end(), nums[i]) == array.end()) {
                array.push_back(nums[i]);
                backtrack(nums, result, array);
                array.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> array;

        backtrack(nums, result, array);

        return result;
    }
};

class Solution {
    void backtrack(vector<int> &nums, vector<vector<int>> &result, vector<int> &array, vector<bool> &visited) {
        if (array.size() == nums.size()) {
            result.push_back(array);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            array.push_back(nums[i]);
            backtrack(nums, result, array, visited);
            array.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> array;
        vector<bool> visited(nums.size(), false);

        backtrack(nums, result, array, visited);

        return result;
    }
};