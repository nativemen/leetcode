#include <algorithm>
#include <unordered_map>
#include <vector>

using std::sort;
using std::unordered_map;
using std::vector;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        int index = 0;
        int size = nums.size();

        while (index < size - 2) {
            if (nums[index] != nums[index + 1]) {
                return nums[index];
            }

            index += 3;
        }

        return nums[size - 1];
    }
};

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        size_t size = nums.size();

        for (size_t i = 1; i < size; i += 3) {
            if (nums[i] != nums[i - 1]) {
                return nums[i - 1];
            }
        }

        return nums[size - 1];
    }
};

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ones = 0;
        int twos = 0;

        for (const auto &num : nums) {
            twos |= ones & num;
            ones ^= num;

            int mask = ~(ones & twos);
            ones &= mask;
            twos &= mask;
        }

        return ones;
    }
};

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int result = 0;

        for (size_t i = 0; i < 32; i++) {
            size_t mask = 1 << i;
            int count = 0;

            for (const auto &num : nums) {
                if ((num & mask) != 0) {
                    count++;
                }
            }

            if (count % 3 != 0) {
                result |= mask;
            }
        }

        return result;
    }
};

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ones = 0;
        int multi = 0;

        for (const auto &num : nums) {
            ones = (ones ^ num) & (~multi);
            multi = (multi ^ num) & (~ones);
        }

        return ones;
    }
};

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ones = 0;
        int twos = 0;

        for (const auto &num : nums) {
            ones ^= num & ~twos;
            twos ^= num & ~ones;
        }

        return ones;
    }
};

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> maps;

        for (const auto &num : nums) {
            maps[num]++;
        }

        for (const auto &pair : maps) {
            if (pair.second == 1) {
                return pair.first;
            }
        }

        return -1;
    }
};
