class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;


    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
}

/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;


    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
}
*/
class Solution {
    boolean checkAllSame(int[][] grid, int x, int y, int width) {
        for (int i = x; i < x + width; i++) {
            for (int j = y; j < y + width; j++) {
                if (grid[i][j] != grid[x][y]) {
                    return false;
                }
            }
        }

        return true;
    }

    Node helper(int[][] grid, int x, int y, int width) {
        if (checkAllSame(grid, x, y, width)) {
            return new Node(grid[x][y] == 1, true);
        }

        Node node = new Node(true, false);
        node.topLeft = helper(grid, x, y, width / 2);
        node.topRight = helper(grid, x, y + width / 2, width / 2);
        node.bottomLeft = helper(grid, x + width / 2, y, width / 2);
        node.bottomRight = helper(grid, x + width / 2, y + width / 2, width / 2);

        return node;
    }

    public Node construct(int[][] grid) {
        return helper(grid, 0, 0, grid.length);
    }
}