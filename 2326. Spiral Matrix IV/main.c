#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **spiralMatrix(int m, int n, struct ListNode *head, int *returnSize, int **returnColumnSizes) {
    int **result = (int **)calloc(m, sizeof(int *));
    *returnSize = m;
    *returnColumnSizes = (int *)calloc(m, sizeof(int));
    for (int i = 0; i < m; i++) {
        result[i] = (int *)calloc(n, sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    int left = 0;
    int right = n - 1;
    int top = 0;
    int bottom = m - 1;

    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) {
            if (head != NULL) {
                result[top][i] = head->val;
                head = head->next;
            } else {
                result[top][i] = -1;
            }
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            if (head != NULL) {
                result[i][right] = head->val;
                head = head->next;
            } else {
                result[i][right] = -1;
            }
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                if (head != NULL) {
                    result[bottom][i] = head->val;
                    head = head->next;
                } else {
                    result[bottom][i] = -1;
                }
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                if (head != NULL) {
                    result[i][left] = head->val;
                    head = head->next;
                } else {
                    result[i][left] = -1;
                }
            }
            left++;
        }
    }

    return result;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **spiralMatrix(int m, int n, struct ListNode *head, int *returnSize, int **returnColumnSizes) {
    int **result = (int **)calloc(m, sizeof(int *));
    *returnSize = m;
    *returnColumnSizes = (int *)calloc(m, sizeof(int));
    for (int i = 0; i < m; i++) {
        result[i] = (int *)calloc(n, sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    int left = 0;
    int right = n - 1;
    int top = 0;
    int bottom = m - 1;
    int total = m * n;
    int count = 0;
    int direction = 1;

    while (count < total) {
        switch (direction) {
            case 1: {
                for (int i = left; i <= right; i++) {
                    if (head != NULL) {
                        result[top][i] = head->val;
                        head = head->next;
                    } else {
                        result[top][i] = -1;
                    }
                    count++;
                }
                top++;
                direction = 2;
                break;
            }
            case 2: {
                for (int i = top; i <= bottom; i++) {
                    if (head != NULL) {
                        result[i][right] = head->val;
                        head = head->next;
                    } else {
                        result[i][right] = -1;
                    }
                    count++;
                }
                right--;
                direction = 3;
                break;
            }
            case 3: {
                for (int i = right; i >= left; i--) {
                    if (head != NULL) {
                        result[bottom][i] = head->val;
                        head = head->next;
                    } else {
                        result[bottom][i] = -1;
                    }
                    count++;
                }
                bottom--;
                direction = 4;
                break;
            }
            default: {
                for (int i = bottom; i >= top; i--) {
                    if (head != NULL) {
                        result[i][left] = head->val;
                        head = head->next;
                    } else {
                        result[i][left] = -1;
                    }
                    count++;
                }
                left++;
                direction = 1;
                break;
            }
        }
    }

    return result;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **spiralMatrix(int m, int n, struct ListNode *head, int *returnSize, int **returnColumnSizes) {
    int **result = (int **)calloc(m, sizeof(int *));
    *returnSize = m;
    *returnColumnSizes = (int *)calloc(m, sizeof(int));
    for (int i = 0; i < m; i++) {
        result[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            result[i][j] = -1;
        }
        (*returnColumnSizes)[i] = n;
    }

    int row = 0;
    int col = 0;
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int direction = 0;

    while (head != NULL) {
        result[row][col] = head->val;

        int nextRow = row + dirs[direction][0];
        int nextCol = col + dirs[direction][1];

        if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n || result[nextRow][nextCol] != -1) {
            direction = (direction + 1) % 4;
            nextRow = row + dirs[direction][0];
            nextCol = col + dirs[direction][1];
        }

        row = nextRow;
        col = nextCol;
        head = head->next;
    }

    return result;
}