#include <climits>
#include <cstdlib>
#include <vector>

using std::vector;

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
    bool isValidBST(TreeNode *root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }

private:
    bool helper(TreeNode *root, long long min, long long max) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= min || root->val >= max) {
            return false;
        }

        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }
};

const size_t ARRAY_SIZE = 10000;

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
    bool isValidBST(TreeNode *root) {
        TreeNode **array = (TreeNode **)calloc(ARRAY_SIZE, sizeof(TreeNode *));
        if (array == nullptr) {
            return false;
        }

        size_t i = 0;
        toArray(array, root, &i);
        for (i = 1; i < ARRAY_SIZE; i++) {
            if (array[i] == nullptr) {
                break;
            }

            if (array[i - 1]->val >= array[i]->val) {
                free(array);
                return false;
            }
        }

        free(array);
        return true;
    }

private:
    void toArray(TreeNode **array, TreeNode *node, size_t *index) {
        if (node == nullptr) {
            return;
        }

        toArray(array, node->left, index);
        array[*index] = node;
        *index += 1;
        toArray(array, node->right, index);
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
    bool isValidBST(TreeNode *root) {
        vector<int> v;

        scan(v, root);
        for (size_t i = 1; i < v.size(); i++) {
            if (v[i - 1] >= v[i]) {
                return false;
            }
        }

        return true;
    }

private:
    void scan(vector<int> &v, TreeNode *node) {
        if (node == nullptr) {
            return;
        }

        scan(v, node->left);
        v.push_back(node->val);
        scan(v, node->right);
    }
};