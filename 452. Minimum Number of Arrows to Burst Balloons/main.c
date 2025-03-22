static int compare(const void *a, const void *b) {
    int m = **(const int **)a;
    int n = **(const int **)b;

    if (m == n) {
        return 0;
    } else if (m < n) {
        return -1;
    } else {
        return 1;
    }
}

int findMinArrowShots(int **points, int pointsSize, int *pointsColSize) {
    qsort(points, pointsSize, sizeof(int *), compare);

    int index = 0;

    for (int i = 0; i < pointsSize; i++) {
        if (points[index][1] < points[i][0]) {
            index++;
            points[index][0] = points[i][0];
            points[index][1] = points[i][1];
        } else {
            points[index][0] = (points[index][0] > points[i][0]) ? points[index][0] : points[i][0];
            points[index][1] = (points[index][1] < points[i][1]) ? points[index][1] : points[i][1];
        }
    }

    return index + 1;
}


static int compare(const void *a, const void *b) {
    const int *m = *(const int **)a;
    const int *n = *(const int **)b;

    if (m[1] == n[1]) {
        return 0;
    } else if (m[1] < n[1]) {
        return -1;
    } else {
        return 1;
    }
}

int findMinArrowShots(int **points, int pointsSize, int *pointsColSize) {
    qsort(points, pointsSize, sizeof(int *), compare);

    int count = 1;
    int preEnd = points[0][1];

    for (int i = 1; i < pointsSize; i++) {
        if (points[i][0] > preEnd) {
            count++;
            preEnd = points[i][1];
        }
    }

    return count;
}