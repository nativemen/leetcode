#include <algorithm>
#include <random>
#include <unordered_set>
#include <vector>

using std::find;
using std::unordered_set;
using std::vector;

class RandomizedSet {
public:
    RandomizedSet() {
        set = unordered_set<int>();
    }

    bool insert(int val) {
        auto result = set.insert(val);

        return result.second;
    }

    bool remove(int val) {
        return set.erase(val) != 0;
    }

    int getRandom() {
        vector<int> vec(set.begin(), set.end());
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, vec.size() - 1);
        int random = dis(gen);

        return vec[random];
    }

private:
    unordered_set<int> set;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

class RandomizedSet {
    unordered_set<int> set;
    vector<int> vec;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (set.find(val) != set.end()) {
            return false;
        }

        set.insert(val);
        vec.push_back(val);

        return true;
    }

    bool remove(int val) {
        if (set.find(val) == set.end()) {
            return false;
        }

        set.erase(val);
        auto it = find(vec.begin(), vec.end(), val);
        vec.erase(it);
        return true;
    }

    int getRandom() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, vec.size() - 1);

        return vec[dis(gen)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */