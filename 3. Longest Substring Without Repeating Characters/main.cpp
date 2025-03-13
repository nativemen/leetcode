#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::max;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
    static constexpr int ARRAY_SIZE = 256;

public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(ARRAY_SIZE, 0);

        int result = 0;
        int left = 0;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            count[s[i]]++;

            while (count[s[i]] > 1) {
                count[s[left]]--;
                left++;
            }
            result = max(result, i - left + 1);
        }

        return result;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int left = 0;
        int size = s.size();

        for (int right = 0; right < size; right++) {
            for (int start = left; start < right; start++) {
                if (s[start] == s[right]) {
                    left = start + 1;
                    break;
                }
            }
            result = max(result, right - left + 1);
        }

        return result;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> sets;
        int result = 0;
        int left = 0;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            while (sets.count(s[i]) > 0) {
                sets.erase(s[left]);
                left++;
            }
            sets.insert(s[i]);

            result = max(result, i - left + 1);
        }

        return result;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int result = 0;
        int left = 0;
        int size = s.size();

        for (int right = 0; right < size; right++) {
            if (map.find(s[right]) != map.end()) {
                if (map[s[right]] >= left) {
                    left = map[s[right]] + 1;
                }
            }
            map[s[right]] = right;

            result = max(result, right - left + 1);
        }

        return result;
    }
};