#include <algorithm>
#include <limits>

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
    int dfs(TreeNode *root, int &maxSum) {
        if (!root) {
            return 0;
        }

        int left = max(dfs(root->left, maxSum), 0);
        int right = max(dfs(root->right, maxSum), 0);
        int currentSum = left + right + root->val;

        maxSum = max(maxSum, currentSum);

        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode *root) {
        int maxSum = numeric_limits<int>::min();

        dfs(root, maxSum);

        return maxSum;
    }
};