#include <queue>

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
    int calSum(TreeNode *root, long long targetSum, bool started) {
        if (!root) {
            return 0;
        }

        int count = 0;

        if (targetSum == (long long)root->val) {
            count++;
        }

        if (!started) {
            count += calSum(root->left, targetSum, started);
            count += calSum(root->right, targetSum, started);
        }

        count += calSum(root->left, targetSum - (long long)root->val, true);
        count += calSum(root->right, targetSum - (long long)root->val, true);

        return count;
    }

public:
    int pathSum(TreeNode *root, int targetSum) {
        return calSum(root, (long long)targetSum, false);
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
    int dfs(TreeNode *root, int targetSum, vector<int> &q) {
        if (!root) {
            return 0;
        }

        q.push_back(root->val);

        int count = 0;
        long long sum = 0;

        for (int i = q.size() - 1; i >= 0; i--) {
            sum += q[i];
            if (sum == (long long)targetSum) {
                count++;
            }
        }

        count += dfs(root->left, targetSum, q);
        count += dfs(root->right, targetSum, q);

        q.pop_back();

        return count;
    }

public:
    int pathSum(TreeNode *root, int targetSum) {
        vector<int> q;

        return dfs(root, targetSum, q);
    }
};