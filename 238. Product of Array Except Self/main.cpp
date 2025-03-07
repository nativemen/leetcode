#include <vector>

using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int size = nums.size();
        vector<int> prefix(size);
        vector<int> suffix(size);

        prefix[0] = 1;
        suffix[size - 1] = 1;
        for (int i = 1; i < size; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        vector<int> answer(size);
        for (int i = 0; i < size; i++) {
            answer[i] = prefix[i] * suffix[i];
        }

        return answer;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int size = nums.size();
        vector<int> answer(size);

        int prefix = 1;
        for (int i = 0; i < size; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = size - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};