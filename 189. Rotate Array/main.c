void reverse(int *array, int start, int end) {
    while (start < end) {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

void rotate(int *nums, int numsSize, int k) {
    int count = k % numsSize;

    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, count - 1);
    reverse(nums, count, numsSize - 1);
}