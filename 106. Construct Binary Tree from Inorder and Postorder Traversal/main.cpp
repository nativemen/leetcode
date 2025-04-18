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
    TreeNode *build(
            vector<int> &inorder, int inLeft, int inRight, vector<int> &postorder, int postLeft, int postRight) {
        if (inLeft > inRight || postLeft > postRight) {
            return nullptr;
        }

        int mid = 0;

        for (int i = inLeft; i <= inRight; i++) {
            if (inorder[i] == postorder[postRight]) {
                mid = i;
            }
        }

        TreeNode *node = new TreeNode(postorder[postRight]);
        node->right = build(inorder, mid + 1, inRight, postorder, postLeft + mid - inLeft, postRight - 1);
        node->left = build(inorder, inLeft, mid - 1, postorder, postLeft, postLeft + mid - inLeft - 1);

        return node;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
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
    int index;

    TreeNode *build(vector<int> &inorder, int start, int end, vector<int> &postorder) {
        if (start > end) {
            return nullptr;
        }

        int current = postorder[index--];
        TreeNode *node = new TreeNode(current);
        int index = map[current];
        node->right = build(inorder, index + 1, end, postorder);
        node->left = build(inorder, start, index - 1, postorder);

        return node;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int size = inorder.size();
        for (int i = 0; i < size; i++) {
            map[inorder[i]] = i;
        }

        index = postorder.size() - 1;
        return build(inorder, 0, size - 1, postorder);
    }
};