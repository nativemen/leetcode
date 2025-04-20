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
class BSTIterator {
    vector<TreeNode *> array;
    int index;

    void inorder(TreeNode *node, vector<TreeNode *> &array) {
        if (!node) {
            return;
        }

        inorder(node->left, array);
        array.push_back(node);
        inorder(node->right, array);
    }

public:
    BSTIterator(TreeNode *root) {
        inorder(root, array);
        index = 0;
    }

    int next() {
        if (!hasNext()) {
            return -1;
        }

        return array[index++]->val;
    }

    bool hasNext() {
        return index < array.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

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
class BSTIterator {
    vector<TreeNode *> array;

    void inorder(TreeNode *node, vector<TreeNode *> &array) {
        if (!node) {
            return;
        }

        inorder(node->left, array);
        array.push_back(node);
        inorder(node->right, array);
    }

public:
    BSTIterator(TreeNode *root) {
        inorder(root, array);
    }

    int next() {
        if (!hasNext()) {
            return -1;
        }

        int value = array[0]->val;

        array.erase(array.begin());
        return value;
    }

    bool hasNext() {
        return !array.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */