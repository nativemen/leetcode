#include <algorithm>
#include <limits>
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
    int minDifference = numeric_limits<int>::max();
    int prevValue = -1;

    void inorder(TreeNode *node) {
        if (!node) {
            return;
        }

        inorder(node->left);

        if (prevValue >= 0) {
            minDifference = min(minDifference, node->val - prevValue);
        }

        prevValue = node->val;

        inorder(node->right);
    }

public:
    int getMinimumDifference(TreeNode *root) {
        inorder(root);

        return minDifference;
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
    void inorder(TreeNode *node, int &minDifference, int &prevValue) {
        if (!node) {
            return;
        }

        inorder(node->left, minDifference, prevValue);

        if (prevValue >= 0) {
            minDifference = min(minDifference, node->val - prevValue);
        }

        prevValue = node->val;

        inorder(node->right, minDifference, prevValue);
    }

public:
    int getMinimumDifference(TreeNode *root) {
        int minDifference = numeric_limits<int>::max();
        int prevValue = -1;

        inorder(root, minDifference, prevValue);

        return minDifference;
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
    void dfs(TreeNode *node, vector<int> &values) {
        if (!node) {
            return;
        }

        dfs(node->left, values);
        values.push_back(node->val);
        dfs(node->right, values);
    }

public:
    int getMinimumDifference(TreeNode *root) {
        vector<int> values;

        dfs(root, values);

        int minDifference = numeric_limits<int>::max();

        for (int i = 1; i < values.size(); i++) {
            minDifference = min(minDifference, values[i] - values[i - 1]);
        }

        return minDifference;
    }
};