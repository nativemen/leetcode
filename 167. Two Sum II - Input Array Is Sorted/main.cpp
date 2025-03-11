#include <vector>

using std::lower_bound;
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else {
                break;
            }
        }

        return {left + 1, right + 1};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int object = target - numbers[i];
            auto it = lower_bound(numbers.begin() + i + 1, numbers.end(), object);
            if (it != numbers.end() && *it == object) {
                return {i + 1, (int)(it - numbers.begin()) + 1};
            }
        }

        return {-1, -1};
    }
};