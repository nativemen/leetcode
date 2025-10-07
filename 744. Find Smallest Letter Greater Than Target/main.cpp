#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        if (letters.front() > target || letters.back() <= target) {
            return letters.front();
        }

        int left = 0;
        int right = letters.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (letters[mid] == target) {
                if (letters[mid + 1] > target) {
                    return letters[mid + 1];
                }

                left = mid + 1;
            } else if (letters[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return letters[left];
    }
};

class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        int left = 0;
        int right = letters.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return letters[left % letters.size()];
    }
};