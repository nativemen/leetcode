#include <vector>

using std::pair;
using std::tie;
using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode()
        : val(0)
        , next(nullptr) {}
    ListNode(int x)
        : val(x)
        , next(nullptr) {}
    ListNode(int x, ListNode *next)
        : val(x)
        , next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
        vector<vector<int>> result(m, vector<int>(n, 0));

        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                if (head != nullptr) {
                    result[top][i] = head->val;
                    head = head->next;
                } else {
                    result[top][i] = -1;
                }
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                if (head != nullptr) {
                    result[i][right] = head->val;
                    head = head->next;
                } else {
                    result[i][right] = -1;
                }
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    if (head != nullptr) {
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
                    if (head != nullptr) {
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
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
        vector<vector<int>> result(m, vector<int>(n, 0));

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
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
        vector<vector<int>> result(m, vector<int>(n, -1));

        auto nextCell = [](int row, int col, int direction) -> pair<int, int> {
            switch (direction) {
                case 0:
                    col++;
                    break;
                case 1:
                    row++;
                    break;
                case 2:
                    col--;
                    break;
                default:
                    row--;
                    break;
            }

            return {row, col};
        };

        int row = 0;
        int col = 0;
        int direction = 0;

        while (head != nullptr) {
            result[row][col] = head->val;

            auto [nextRow, nextCol] = nextCell(row, col, direction);
            if (nextRow >= m || nextRow < 0 || nextCol >= n || nextCol < 0 || result[nextRow][nextCol] != -1) {
                direction = (direction + 1) % 4;
            }

            tie(row, col) = nextCell(row, col, direction);
            head = head->next;
        };

        return result;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
        vector<vector<int>> result(m, vector<int>(n, -1));
        int row = 0;
        int col = 0;
        int direction = 0;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (head != nullptr) {
            result[row][col] = head->val;

            int nextRow = row + dirs[direction][0];
            int nextCol = col + dirs[direction][1];

            if (nextRow >= m || nextRow < 0 || nextCol >= n || nextCol < 0 || result[nextRow][nextCol] != -1) {
                direction = (direction + 1) % 4;
                nextRow = row + dirs[direction][0];
                nextCol = col + dirs[direction][1];
            }

            row = nextRow;
            col = nextCol;
            head = head->next;
        };

        return result;
    }
};