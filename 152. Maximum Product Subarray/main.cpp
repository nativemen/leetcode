#include <vector>

using std::vector;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int max_product = std::numeric_limits<int>::min();
        int left_product = 1;
        int right_product = 1;
        int size = nums.size();

        for (size_t i = 0; i < size; i++) {
            left_product *= nums[i];
            right_product *= nums[size - 1 - i];
            max_product = std::max(max_product, left_product);
            max_product = std::max(max_product, right_product);
            left_product = (left_product == 0) ? 1 : left_product;
            right_product = (right_product == 0) ? 1 : right_product;
        }

        return max_product;
    }
};

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int max_product = std::numeric_limits<int>::min();
        int cur_max = 1;
        int cur_min = 1;

        for (const auto &num : nums) {
            int temp = cur_max * num;
            cur_max = std::max(std::max(temp, cur_min * num), num);
            cur_min = std::min(std::min(temp, cur_min * num), num);
            max_product = std::max(max_product, cur_max);
        }

        return max_product;
    }
};