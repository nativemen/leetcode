#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int first = numeric_limits<int>::max();
        int second = numeric_limits<int>::max();

        for (const auto &num : nums) {
            if (num <= first) {
                first = num;
            } else if (num <= second) {
                second = num;
            } else {
                return true;
            }
        }

        return false;
    }
};