#include <algorithm>
#include <random>
#include <stdlib.h>
#include <vector>

using std::vector;

class Solution {
public:
    Solution(vector<int> &nums)
        : orig(nums)
        , shuf(nums) {}

    vector<int> reset() {
        return this->orig;
    }

    vector<int> shuffle() {
        for (size_t i = 0; i < this->orig.size(); i++) {
            this->shuf[i] = std::numeric_limits<int>::max();
        }

        for (size_t i = 0; i < this->orig.size(); i++) {
            size_t index = rand() % this->orig.size();
            while (this->shuf[index] != std::numeric_limits<int>::max()) {
                index = rand() % this->orig.size();
            }
            this->shuf[index] = this->orig[i];
        }

        return this->shuf;
    }

private:
    vector<int> orig;
    vector<int> shuf;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

class Solution {
public:
    Solution(vector<int> &nums)
        : orig(nums)
        , shuf(nums) {}

    vector<int> reset() {
        return orig;
    }

    vector<int> shuffle() {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine rng(seed);
        std::shuffle(shuf.begin(), shuf.end(), rng);
        return shuf;
    }

private:
    vector<int> orig;
    vector<int> shuf;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */