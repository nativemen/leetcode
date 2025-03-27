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
public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) {
            return false;
        }

        if (!root->left && !root->right) {
            return root->val == targetSum;
        }

        if (!root->left) {
            return hasPathSum(root->right, targetSum - root->val);
        }

        if (!root->right) {
            return hasPathSum(root->left, targetSum - root->val);
        }

        return hasPathSum(root->right, targetSum - root->val) || hasPathSum(root->left, targetSum - root->val);
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
public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) {
            return false;
        }

        targetSum -= root->val;

        if (!root->left && !root->right) {
            return targetSum == 0;
        }

        return hasPathSum(root->right, targetSum) || hasPathSum(root->left, targetSum);
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
    bool helper(TreeNode *root, int targetSum, int currentSum) {
        if (!root) {
            return false;
        }

        currentSum += root->val;
        if (!root->left && !root->right) {
            return targetSum == currentSum;
        }

        return helper(root->right, targetSum, currentSum) || helper(root->left, targetSum, currentSum);
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        return helper(root, targetSum, 0);
    }
};