#include <vector>

using namespace std;

class SnapshotArray {
    vector<vector<pair<int, int>>> array;
    int id;

public:
    SnapshotArray(int length) {
        array.resize(length);
        id = 0;
    }

    void set(int index, int val) {
        if (index < 0 || index >= array.size()) {
            return;
        }

        array[index].push_back({id, val});
    }

    int snap() {
        return id++;
    }

    int get(int index, int snap_id) {
        if (index < 0 || index >= array.size() || snap_id < 0 || snap_id > id) {
            return -1;
        }

        int left = 0;
        int right = array[index].size() - 1;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (array[index][mid].first <= snap_id) {
                result = array[index][mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */