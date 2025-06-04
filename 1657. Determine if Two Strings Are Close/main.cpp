#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    static constexpr size_t ALPHABET_SIZE = 26;

public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq1(ALPHABET_SIZE, 0);
        vector<int> freq2(ALPHABET_SIZE, 0);

        for (const auto &c : word1) {
            freq1[c - 'a']++;
        }

        for (const auto &c : word2) {
            freq2[c - 'a']++;
        }

        for (size_t i = 0; i < ALPHABET_SIZE; i++) {
            if (freq1[i] != freq2[i] && (freq1[i] == 0 || freq2[i] == 0)) {
                return false;
            }
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};