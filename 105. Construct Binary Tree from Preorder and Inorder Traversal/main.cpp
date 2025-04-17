#include <unordered_map>
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
    TreeNode *build(vector<int> &preorder, int preLeft, int preRight, vector<int> &inorder, int inLeft, int inRight) {
        if (preLeft > preRight || inLeft > inRight) {
            return nullptr;
        }

        int mid = 0;

        for (int i = inLeft; i <= inRight; i++) {
            if (inorder[i] == preorder[preLeft]) {
                mid = i;
            }
        }

        TreeNode *node = new TreeNode(preorder[preLeft]);
        node->left = build(preorder, preLeft + 1, preLeft + mid - inLeft, inorder, inLeft, mid - 1);
        node->right = build(preorder, preLeft + mid - inLeft + 1, preRight, inorder, mid + 1, inRight);

        return node;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int preorderSize = preorder.size();
        int inorderSize = inorder.size();

        return build(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
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
    unordered_map<int, int> map;
    int index = 0;

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int current = preorder[index++];
        TreeNode *node = new TreeNode(current);
        int idx = map[current];
        node->left = build(preorder, inorder, start, idx - 1);
        node->right = build(preorder, inorder, idx + 1, end);

        return node;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int size = inorder.size();

        for (int i = 0; i < size; i++) {
            map[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, size - 1);
    }
};