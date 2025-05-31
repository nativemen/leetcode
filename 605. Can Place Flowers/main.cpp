#include <vector>

using namespace std;

class Solution {
    bool isEmpty(vector<int> &flowerbed, int pos) {
        return pos < 0 || pos >= flowerbed.size() || flowerbed[pos] == 0;
    }

public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int count = 0;

        for (size_t i = 0; i < flowerbed.size(); i++) {
            if (isEmpty(flowerbed, i - 1) && isEmpty(flowerbed, i) && isEmpty(flowerbed, i + 1)) {
                count++;
                flowerbed[i] = 1;
            }
        }

        return count >= n;
    }
};

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();

        for (int i = 0; i < flowerbed.size(); i++) {
            bool left = i - 1 < 0 || flowerbed[i - 1] == 0;
            bool right = i + 1 >= size || flowerbed[i + 1] == 0;

            if (left && right && flowerbed[i] == 0) {
                count++;
                flowerbed[i] = 1;
            }
        }

        return count >= n;
    }
};