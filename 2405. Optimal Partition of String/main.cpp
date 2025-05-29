#include <cstring>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int partitionString(string s) {
        unsigned int mask = 0;
        int num = 1;

        for (const auto &c : s) {
            size_t shift = c - 'a';
            if ((mask & (1 << shift)) != 0) {
                mask = 0;
                num++;
            }

            mask |= 1 << shift;
        }

        return num;
    }
};

class Solution {
    static constexpr size_t ALPHABET_SIZE = 26;

public:
    int partitionString(string s) {
        vector<unsigned int> count(ALPHABET_SIZE, 0);
        int num = 1;

        for (const auto &c : s) {
            size_t index = c - 'a';
            if (count[index] == 1) {
                count.assign(ALPHABET_SIZE, 0);
                num++;
            }

            count[index]++;
        }

        return num;
    }
};

class Solution {
public:
    int partitionString(string s) {
        unordered_map<char, int> maps;
        int num = 1;

        for (const auto &c : s) {
            if (maps.contains(c)) {
                maps.clear();
                num++;
            }

            maps.emplace(c, 1);
        }

        return num;
    }
};

class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> sets;
        int num = 1;

        for (const auto &c : s) {
            if (sets.contains(c)) {
                sets.clear();
                num++;
            }

            sets.emplace(c);
        }

        return num;
    }
};