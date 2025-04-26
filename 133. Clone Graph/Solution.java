import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }

    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }

    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}

/*
 * // Definition for a Node.
 * class Node {
 * public int val;
 * public List<Node> neighbors;
 * public Node() {
 * val = 0;
 * neighbors = new ArrayList<Node>();
 * }
 * public Node(int _val) {
 * val = _val;
 * neighbors = new ArrayList<Node>();
 * }
 * public Node(int _val, ArrayList<Node> _neighbors) {
 * val = _val;
 * neighbors = _neighbors;
 * }
 * }
 */
class Solution {
    HashMap<Node, Node> visited = new HashMap<>();;

    public Node cloneGraph(Node node) {
        if (node == null) {
            return null;
        }

        if (visited.containsKey(node)) {
            return visited.get(node);
        }

        Node current = new Node(node.val);
        visited.put(node, current);

        for (int i = 0; i < node.neighbors.size(); i++) {
            current.neighbors.add(cloneGraph(node.neighbors.get(i)));
        }

        return current;
    }
}