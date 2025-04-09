#include <stdio.h>

int maxPoints(int **points, int pointsSize, int *pointsColSize) {
    int maxPoints = 1;

    for (int i = 0; i < pointsSize; i++) {
        int x1 = points[i][0];
        int y1 = points[i][1];

        for (int j = i + 1; j < pointsSize; j++) {
            int x2 = points[j][0];
            int y2 = points[j][1];
            int total = 2;

            for (int k = 0; k < pointsSize && k != i && k != j; k++) {
                int x = points[k][0];
                int y = points[k][1];

                if (((y1 - y) * (x2 - x)) == ((y2 - y) * (x1 - x))) {
                    total++;
                }
            }

            maxPoints = (maxPoints < total) ? total : maxPoints;
        }
    }

    return maxPoints;
}