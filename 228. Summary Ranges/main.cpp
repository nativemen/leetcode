#include <format>
#include <iostream>
#include <string>
#include <vector>

using std::format;
using std::string;
using std::to_string;
using std::vector;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> result;
        size_t size = nums.size();

        for (size_t i = 0; i < size; i++) {
            string s;
            int start = nums[i];

            while (i + 1 < size && nums[i + 1] == nums[i] + 1) {
                i++;
            }

            if (start == nums[i]) {
                s = format("{}", start);
            } else {
                s = format("{}->{}", start, nums[i]);
            }

            result.push_back(s);
        }

        return result;
    }
};

class Solution {
    static constexpr size_t ARRAY_SIZE = 25;

public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> result;
        size_t size = nums.size();

        for (size_t i = 0; i < size; i++) {
            int start = nums[i];

            while (i + 1 < size && nums[i + 1] == nums[i] + 1) {
                i++;
            }

            char buffer[ARRAY_SIZE] = {0};
            if (start == nums[i]) {
                sprintf(buffer, "%d", start);
            } else {
                sprintf(buffer, "%d->%d", start, nums[i]);
            }

            string s(buffer);
            result.push_back(s);
        }

        return result;
    }
};

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> result;
        size_t size = nums.size();

        for (size_t i = 0; i < size; i++) {
            int start = nums[i];

            while (i + 1 < size && nums[i + 1] == nums[i] + 1) {
                i++;
            }

            if (start == nums[i]) {
                result.push_back(to_string(start));
            } else {
                result.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
        }

        return result;
    }
};