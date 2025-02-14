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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return createTree(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *createTree(vector<int> &nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = (left + right + 1) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        if (node == nullptr) {
            return nullptr;
        }

        node->left = createTree(nums, left, mid - 1);
        node->right = createTree(nums, mid + 1, right);

        return node;
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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.empty()) {
            return nullptr;
        }

        int mid = nums.size() / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        if (node == nullptr) {
            return nullptr;
        }

        vector<int> leftSub(nums.begin(), nums.begin() + mid);
        node->left = sortedArrayToBST(leftSub);
        vector<int> rightSub(nums.begin() + mid + 1, nums.end());
        node->left = sortedArrayToBST(rightSub);

        return node;
    }
};