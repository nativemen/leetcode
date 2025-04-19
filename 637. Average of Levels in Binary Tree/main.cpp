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
public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> result;

        if (!root) {
            return result;
        }

        vector<TreeNode *> q;
        q.push_back(root);

        while (!q.empty()) {
            int size = q.size();
            long long value = 0;

            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();

                q.erase(q.begin());
                value += (long long)node->val;

                if (node->left) {
                    q.push_back(node->left);
                }

                if (node->right) {
                    q.push_back(node->right);
                }
            }

            result.push_back((double)value / (double)size);
        }

        return result;
    }
};