#include <vector>

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
    void dfs(TreeNode *root, vector<int> &values) {
        if (!root) {
            return;
        }

        if (!root->left && !root->right) {
            values.push_back(root->val);
            return;
        }

        dfs(root->left, values);
        dfs(root->right, values);
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> values1;
        vector<int> values2;

        dfs(root1, values1);
        dfs(root2, values2);

        return values1 == values2;
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
    vector<int> dfs(TreeNode *root) {
        vector<int> result;

        if (!root) {
            return result;
        }

        if (!root->left && !root->right) {
            result.push_back(root->val);
            return result;
        }

        if (root->left) {
            vector<int> left = dfs(root->left);
            result.insert(result.end(), left.begin(), left.end());
        }

        if (root->right) {
            vector<int> right = dfs(root->right);
            result.insert(result.end(), right.begin(), right.end());
        }

        return result;
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        return dfs(root1) == dfs(root2);
    }
};