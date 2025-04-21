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
    static constexpr int ARRAY_SIZE = 10000;

    void inorder(TreeNode *node, int *array, int *count) {
        if (!node) {
            return;
        }

        inorder(node->left, array, count);
        array[(*count)++] = node->val;
        inorder(node->right, array, count);
    }

public:
    int kthSmallest(TreeNode *root, int k) {
        int array[ARRAY_SIZE];
        int count = 0;

        inorder(root, array, &count);

        if (k < 1 || k > count) {
            return -1;
        }

        return array[k - 1];
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
    void inorder(TreeNode *node, vector<int> &array) {
        if (!node) {
            return;
        }

        inorder(node->left, array);
        array.push_back(node->val);
        inorder(node->right, array);
    }

public:
    int kthSmallest(TreeNode *root, int k) {
        vector<int> array;
        int count = 0;

        inorder(root, array);

        if (k < 1 || k > array.size()) {
            return -1;
        }

        return array[k - 1];
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
    void inorder(TreeNode *node, int *result, int *count, int k) {
        if (!node) {
            return;
        }

        inorder(node->left, result, count, k);
        (*count)++;
        if (*count == k) {
            *result = node->val;
            return;
        }
        inorder(node->right, result, count, k);
    }

public:
    int kthSmallest(TreeNode *root, int k) {
        int result = -1;
        int count = 0;

        inorder(root, &result, &count, k);

        return result;
    }
};