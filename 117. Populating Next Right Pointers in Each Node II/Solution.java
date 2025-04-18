import java.util.LinkedList;
import java.util.Queue;

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {
    }

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

/*
 * // Definition for a Node.
 * class Node {
 * public int val;
 * public Node left;
 * public Node right;
 * public Node next;
 *
 * public Node() {}
 *
 * public Node(int _val) {
 * val = _val;
 * }
 *
 * public Node(int _val, Node _left, Node _right, Node _next) {
 * val = _val;
 * left = _left;
 * right = _right;
 * next = _next;
 * }
 * };
 */
class Solution {
    public Node connect(Node root) {
        if (root == null) {
            return null;
        }

        Node node = root;

        while (node != null) {
            Node leftest_node = null;
            Node next_node = null;

            while (node != null) {
                if (node.left != null) {
                    if (leftest_node == null) {
                        next_node = node.left;
                        leftest_node = next_node;
                    } else {
                        next_node.next = node.left;
                        next_node = next_node.next;
                    }
                }

                if (node.right != null) {
                    if (leftest_node == null) {
                        next_node = node.right;
                        leftest_node = next_node;
                    } else {
                        next_node.next = node.right;
                        next_node = next_node.next;
                    }
                }

                node = node.next;
            }

            node = leftest_node;
        }

        return root;
    }
}

/*
 * // Definition for a Node.
 * class Node {
 * public int val;
 * public Node left;
 * public Node right;
 * public Node next;
 *
 * public Node() {}
 *
 * public Node(int _val) {
 * val = _val;
 * }
 *
 * public Node(int _val, Node _left, Node _right, Node _next) {
 * val = _val;
 * left = _left;
 * right = _right;
 * next = _next;
 * }
 * };
 */
class Solution {
    public Node connect(Node root) {
        if (root == null) {
            return null;
        }

        Queue<Node> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            int size = q.size();
            Node prev = null;

            for (int i = 0; i < size; i++) {
                Node node = q.poll();

                if (prev != null) {
                    prev.next = node;
                }
                prev = node;

                if (node.left != null) {
                    q.add(node.left);
                }

                if (node.right != null) {
                    q.add(node.right);
                }
            }
        }

        return root;
    }
}