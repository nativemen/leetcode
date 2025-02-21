#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using std::bitset;
using std::string;
using std::vector;

#define ARRAY_SIZE 16

class Solution {
public:
    string findDifferentBinaryString(vector<string> &nums) {
        bool exists[1 << ARRAY_SIZE] = {false};
        size_t size = nums.size();
        for (size_t i = 0; i < size; i++) {
            bitset<32> bits(nums[i]);
            unsigned long value = bits.to_ulong();
            if (value >= 1 << size) {
                return "";
            }

            exists[value] = true;
        }

        size_t val = 0;
        while (val < 1 << size) {
            if (!exists[val]) {
                break;
            }
            val++;
        }

        std::bitset<32> bits(val);
        std::string binaryString = bits.to_string().substr(32 - size);

        return binaryString;
    }
};

#define ARRAY_SIZE 16

class Solution {
public:
    string findDifferentBinaryString(vector<string> &nums) {
        bool exists[1 << ARRAY_SIZE] = {false};
        size_t size = nums.size();
        for (size_t i = 0; i < size; i++) {
            unsigned int value = 0;
            for (const auto &c : nums[i]) {
                value = (value << 1) | (c - '0');
            }

            exists[value] = true;
        }

        size_t val = 0;
        while (val < 1 << size) {
            if (!exists[val]) {
                break;
            }
            val++;
        }

        string res;
        size_t index = 0;
        while (index < size) {
            char c = ((val >> (size - 1 - index)) & 1) + '0';
            res.push_back(c);
            index++;
        }

        return res;
    }
};

class Solution {
public:
    string findDifferentBinaryString(vector<string> &nums) {
        string res;
        size_t size = nums.size();

        for (size_t i = 0; i < size; i++) {
            if (nums[i][i] == '0') {
                res.push_back('1');
            } else {
                res.push_back('0');
            }
        }

        return res;
    }
};