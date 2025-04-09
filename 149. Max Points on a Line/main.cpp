#include <limits>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        size_t size = points.size();

        if (size == 1) {
            return 1;
        }

        int maxPoints = 0;

        for (size_t i = 0; i < size; i++) {
            unordered_map<double, int> slopes;
            for (size_t j = 0; j != i && j < size; j++) {
                double slope;
                if (points[j][0] == points[i][0]) {
                    slope = numeric_limits<double>::infinity();
                } else {
                    slope = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                }
                slopes[slope]++;
            }

            for (const auto &pair : slopes) {
                maxPoints = max(maxPoints, pair.second + 1);
            }
        }

        return maxPoints;
    }
};

class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        size_t size = points.size();
        int maxPoints = 1;

        for (size_t i = 0; i < size; i++) {
            unordered_map<double, int> slopes;
            for (size_t j = 0; j != i && j < size; j++) {
                double slope;
                if (points[j][0] == points[i][0]) {
                    slope = numeric_limits<double>::infinity();
                } else {
                    slope = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                }
                slopes[slope]++;
            }

            for (const auto &pair : slopes) {
                maxPoints = max(maxPoints, pair.second + 1);
            }
        }

        return maxPoints;
    }
};

class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        size_t size = points.size();
        int maxPoints = 1;

        for (size_t i = 0; i < size; i++) {
            unordered_map<double, int> slopes;
            for (size_t j = i + 1; j < size; j++) {
                double slope;
                if (points[j][0] == points[i][0]) {
                    slope = numeric_limits<double>::infinity();
                } else {
                    slope = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                }
                slopes[slope]++;
            }

            for (const auto &pair : slopes) {
                maxPoints = max(maxPoints, pair.second + 1);
            }
        }

        return maxPoints;
    }
};

class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        int maxPoints = 1;
        size_t size = points.size();

        for (size_t i = 0; i < size; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (size_t j = i + 1; j < size; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int total = 2;

                for (size_t k = 0; k < size && k != i && k != j; k++) {
                    int x = points[k][0];
                    int y = points[k][1];

                    if (((y1 - y) * (x2 - x)) == ((y2 - y) * (x1 - x))) {
                        total++;
                    }
                }

                maxPoints = max(maxPoints, total);
            }
        }

        return maxPoints;
    }
};