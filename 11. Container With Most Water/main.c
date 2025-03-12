static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxArea(int *height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxStorage = (right - left) * min(height[left], height[right]);

    while (left < right) {
        int offset = 1;
        if (height[left] < height[right]) {
            while (left + offset < right && height[left] >= height[left + offset]) {
                offset++;
            }
            if (left + offset >= right) {
                return maxStorage;
            }
            left += offset;
        } else {
            while (right - offset > left && height[right] >= height[right - offset]) {
                offset++;
            }
            if (right - offset <= left) {
                return maxStorage;
            }
            right -= offset;
        }
        maxStorage = max(maxStorage, (right - left) * min(height[left], height[right]));
    }

    return maxStorage;
}

static int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxArea(int *height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int mArea = 0;

    while (left < right) {
        int area = (right - left) * min(height[left], height[right]);
        if (area > mArea) {
            mArea = area;
        }

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return mArea;
}