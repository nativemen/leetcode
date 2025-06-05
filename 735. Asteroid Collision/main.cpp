#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        vector<int> result;
        int i = 0;
        int asteroidsSize = asteroids.size();

        while (i < asteroidsSize) {
            if (result.empty() || result.back() < 0 || asteroids[i] >= 0) {
                result.push_back(asteroids[i]);
                i++;
            } else if (result.back() + asteroids[i] < 0) {
                result.pop_back();
            } else if (result.back() + asteroids[i] == 0) {
                result.pop_back();
                i++;
            } else {
                i++;
            }
        }

        return result;
    }
};