#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    bool canEating(vector<int> &piles, int h, int k) {
        int hours = 0;

        for (const auto &pile : piles) {
            hours += (pile + k - 1) / k;
        }

        return hours <= h;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int maxPile = piles[0];

        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > maxPile) {
                maxPile = piles[i];
            }
        }

        int left = 1;
        int right = maxPile;

        while (left < right) {
            int mid = (left + right) / 2;

            if (canEating(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }
};