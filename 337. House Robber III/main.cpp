#include <algorithm>
#include <utility>

using std::max;
using std::pair;

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
    int rob(TreeNode *root) {
        int with_root = 0;
        int without_root = 0;

        robHelper(root, &with_root, &without_root);

        return max(with_root, without_root);
    }

private:
    void robHelper(TreeNode *root, int *with_root, int *without_root) {
        if (root == nullptr) {
            *with_root = 0;
            *without_root = 0;
            return;
        }

        int left_with_root = 0;
        int left_without_root = 0;
        robHelper(root->left, &left_with_root, &left_without_root);
        int right_with_root = 0;
        int right_without_root = 0;
        robHelper(root->right, &right_with_root, &right_without_root);

        *with_root = root->val + left_without_root + right_without_root;
        *without_root = max(left_with_root, left_without_root) + max(right_with_root, right_without_root);
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
    int rob(TreeNode *root) {
        int with_root = 0;
        int without_root = 0;

        robHelper(root, with_root, without_root);

        return max(with_root, without_root);
    }

private:
    void robHelper(TreeNode *root, int &with_root, int &without_root) {
        if (root == nullptr) {
            with_root = 0;
            without_root = 0;
            return;
        }

        int left_with_root = 0;
        int left_without_root = 0;
        robHelper(root->left, left_with_root, left_without_root);
        int right_with_root = 0;
        int right_without_root = 0;
        robHelper(root->right, right_with_root, right_without_root);

        with_root = root->val + left_without_root + right_without_root;
        without_root = max(left_with_root, left_without_root) + max(right_with_root, right_without_root);
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
    int rob(TreeNode *root) {
        auto pair = robHelper(root);

        return max(pair.first, pair.second);
    }

private:
    pair<int, int> robHelper(TreeNode *root) {
        if (root == nullptr) {
            return {0, 0};
        }

        auto left = robHelper(root->left);
        auto right = robHelper(root->right);
        int with_root = root->val + left.second + right.second;
        int without_root = max(left.first, left.second) + max(right.first, right.second);

        return {with_root, without_root};
    }
};