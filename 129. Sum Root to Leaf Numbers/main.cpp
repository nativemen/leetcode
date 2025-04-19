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
    void dfs(TreeNode *node, int num, int &sum) {
        if (!node) {
            return;
        }

        num = num * 10 + node->val;

        if (!node->left && !node->right) {
            sum += num;
            return;
        }

        dfs(node->left, num, sum);
        dfs(node->right, num, sum);
    }

public:
    int sumNumbers(TreeNode *root) {
        int sum = 0;

        dfs(root, 0, sum);

        return sum;
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
    int sum(TreeNode *node, int num) {
        if (!node) {
            return 0;
        }

        num = num * 10 + node->val;

        if (!node->left && !node->right) {
            return num;
        }

        return sum(node->left, num) + sum(node->right, num);
    }

public:
    int sumNumbers(TreeNode *root) {
        return sum(root, 0);
    }
};