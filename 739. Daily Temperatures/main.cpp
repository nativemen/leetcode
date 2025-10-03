#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        size_t tempSize = temperatures.size();
        vector<int> result(tempSize, 0);
        vector<int> stack;

        for (int i = 0; i < tempSize; i++) {
            while (!stack.empty() && temperatures[i] > temperatures[stack.back()]) {
                int index = stack.back();
                stack.pop_back();
                result[index] = i - index;
            }

            stack.push_back(i);
        }

        return result;
    }
};