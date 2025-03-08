int trap(int *height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int leftMax = 0;
    int rightMax = 0;
    int total = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] <= leftMax) {
                total += leftMax - height[left];
            } else {
                leftMax = height[left];
            }
            left++;
        } else {
            if (height[right] <= rightMax) {
                total += rightMax - height[right];
            } else {
                rightMax = height[right];
            }
            right--;
        }
    }

    return total;
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int min(int a, int b) {
    return (a < b) ? a : b;
}

int trap(int *height, int heightSize) {
    int prefixMax[heightSize];
    prefixMax[0] = 0;

    for (int i = 1; i < heightSize; i++) {
        prefixMax[i] = max(prefixMax[i - 1], height[i - 1]);
    }

    int suffixMax[heightSize];
    suffixMax[heightSize - 1] = 0;

    for (int i = heightSize - 2; i >= 0; i--) {
        suffixMax[i] = max(suffixMax[i + 1], height[i + 1]);
    }

    int total = 0;

    for (int i = 0; i < heightSize; i++) {
        int top = min(prefixMax[i], suffixMax[i]);
        total += (top >= height[i]) ? (top - height[i]) : 0;
    }

    return total;
}