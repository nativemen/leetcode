#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr) {}
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x)
        , left(left)
        , right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxCount = 0;

    void zigZag(TreeNode *root, bool goRight, int steps) {
        if (!root) {
            return;
        }

        maxCount = max(maxCount, steps);

        if (goRight) {
            zigZag(root->left, false, steps + 1);
            zigZag(root->right, true, 1);
        } else {
            zigZag(root->right, true, steps + 1);
            zigZag(root->left, false, 1);
        }
    }

public:
    int longestZigZag(TreeNode *root) {
        if (!root) {
            return 0;
        }

        zigZag(root->right, true, 1);
        zigZag(root->left, false, 1);

        return maxCount;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxCount = 0;

    void zigRight(TreeNode *root, int steps) {
        if (!root) {
            return;
        }

        maxCount = max(maxCount, steps);

        zigLeft(root->left, steps + 1);
        zigRight(root->right, 1);
    }

    void zigLeft(TreeNode *root, int steps) {
        if (!root) {
            return;
        }

        maxCount = max(maxCount, steps);

        zigRight(root->right, steps + 1);
        zigLeft(root->left, 1);
    }

public:
    int longestZigZag(TreeNode *root) {
        if (!root) {
            return 0;
        }

        zigRight(root->right, 1);
        zigLeft(root->left, 1);

        return maxCount;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxCount = 0;

    void zigZag(TreeNode *root, int left, int right) {
        if (!root) {
            return;
        }

        maxCount = max(maxCount, max(left, right));

        zigZag(root->left, right + 1, 0);
        zigZag(root->right, 0, left + 1);
    }

public:
    int longestZigZag(TreeNode *root) {
        if (!root) {
            return 0;
        }

        zigZag(root->right, 0, 1);
        zigZag(root->left, 1, 0);

        return maxCount;
    }
};
