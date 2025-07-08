#include <set>
#include <vector>

using namespace std;

class SmallestInfiniteSet {
    set<int> sets;
    int smallest;

public:
    SmallestInfiniteSet() {
        smallest = 1;
    }

    int popSmallest() {
        if (sets.empty()) {
            return smallest++;
        }

        auto it = sets.begin();
        int result = *it;
        sets.erase(it);

        return result;
    }

    void addBack(int num) {
        if (num >= smallest) {
            return;
        }

        sets.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

class SmallestInfiniteSet {
    static constexpr int VECTOR_SIZE = 1002;
    vector<bool> nums;
    size_t smallest;

public:
    SmallestInfiniteSet() {
        smallest = 1;
        nums.resize(VECTOR_SIZE);

        for (size_t i = 1; i < VECTOR_SIZE; i++) {
            nums[i] = true;
        }
    }

    int popSmallest() {
        int result = smallest;
        nums[smallest] = false;

        for (size_t i = smallest + 1; i < VECTOR_SIZE; i++) {
            if (nums[i]) {
                smallest = i;
                break;
            }
        }

        return result;
    }

    void addBack(int num) {
        nums[num] = true;

        if (num < smallest) {
            smallest = num;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */