#include <vector>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
    bool checkAllSame(vector<vector<int>> &grid, int x, int y, int width) {
        for (int i = x; i < x + width; i++) {
            for (int j = y; j < y + width; j++) {
                if (grid[i][j] != grid[x][y]) {
                    return false;
                }
            }
        }

        return true;
    }

    Node *helper(vector<vector<int>> &grid, int x, int y, int width) {
        if (checkAllSame(grid, x, y, width)) {
            return new Node(grid[x][y] == 1, true);
        }

        Node *node = new Node(true, false);
        node->topLeft = helper(grid, x, y, width / 2);
        node->topRight = helper(grid, x, y + width / 2, width / 2);
        node->bottomLeft = helper(grid, x + width / 2, y, width / 2);
        node->bottomRight = helper(grid, x + width / 2, y + width / 2, width / 2);

        return node;
    }

public:
    Node *construct(vector<vector<int>> &grid) {
        return helper(grid, 0, 0, grid.size());
    }
};