#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        auto maxIt = max_element(candies.begin(), candies.end());
        int maxCandies = *maxIt;
        vector<bool> result;

        for (const auto &current : candies) {
            result.push_back(current + extraCandies >= maxCandies);
        }

        return result;
    }
};

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        int maxCandies = 0;

        for (const auto &current : candies) {
            maxCandies = max(maxCandies, current);
        }

        vector<bool> result;

        for (const auto &current : candies) {
            result.push_back(current + extraCandies >= maxCandies);
        }

        return result;
    }
};