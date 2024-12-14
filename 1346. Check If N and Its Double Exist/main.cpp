#include <stddef.h>

#include <vector>

class Solution {
  public:
    bool checkIfExist(vector<int> &arr) {
        size_t arr_size = arr.size();
        for (size_t i = 0; i < arr_size; i++) {
            for (size_t j = i + 1; j < arr_size; j++) {
                if ((arr[i] == arr[j] * 2) || (arr[j] == arr[i] * 2)) {
                    return true;
                }
            }
        }

        return false;
    }
};