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
    bool isSymmetric(TreeNode *root) {
        vector<int> v;

        toVec(v, root, 1);
        size_t len = v.size();
        for (size_t i = 0; i < len / 2; i++) {
            if (v[i] != v[len - 1 - i]) {
                return false;
            }
        }

        return true;
    }

private:
    const int NULL_VAL = 1 << 8;
    void toVec(vector<int> &v, TreeNode *node, int layer) {
        if (node == nullptr) {
            v.push_back(NULL_VAL + layer);
            return;
        }

        toVec(v, node->left, layer + 1);
        v.push_back(node->val);
        toVec(v, node->right, layer + 1);
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
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode *left, TreeNode *right) {
        if (left == nullptr || right == nullptr) {
            return left == right;
        }

        if (left->val != right->val) {
            return false;
        }

        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};