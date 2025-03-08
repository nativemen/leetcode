#include <vector>

using std::vector;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int size = ratings.size();
        vector<int> candy(size, 1);

        for (int i = 1; i < size; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }

        int sum = candy[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                if (candy[i] <= candy[i + 1]) {
                    candy[i] = candy[i + 1] + 1;
                }
            }
            sum += candy[i];
        }

        return sum;
    }
};