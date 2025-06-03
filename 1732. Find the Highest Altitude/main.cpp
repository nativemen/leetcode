#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int> &gain) {
        int altitude = 0;
        int largest = 0;

        for (const auto &val : gain) {
            altitude += val;
            largest = max(largest, altitude);
        }

        return largest;
    }
};

class Solution {
public:
    int largestAltitude(vector<int> &gain) {
        vector<int> altitudes(1, 0);

        for (int i = 1; i <= gain.size(); i++) {
            altitudes.push_back(altitudes[i - 1] + gain[i - 1]);
        }

        return *max_element(altitudes.begin(), altitudes.end());
    }
};