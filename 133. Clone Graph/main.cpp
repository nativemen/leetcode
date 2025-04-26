#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    static constexpr size_t VECTOR_SIZE = 101;
    vector<Node *> visited = vector<Node *>(VECTOR_SIZE, nullptr);

public:
    Node *cloneGraph(Node *node) {
        if (!node) {
            return nullptr;
        }

        if (visited[node->val]) {
            return visited[node->val];
        }

        visited[node->val] = new Node(node->val);
        if (!node->neighbors.empty()) {
            for (const auto &neighbor : node->neighbors) {
                visited[node->val]->neighbors.push_back(cloneGraph(neighbor));
            }
        }

        return visited[node->val];
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    unordered_map<Node *, Node *> visited;

public:
    Node *cloneGraph(Node *node) {
        if (!node) {
            return nullptr;
        }

        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        visited[node] = new Node(node->val);
        if (!node->neighbors.empty()) {
            for (const auto &neighbor : node->neighbors) {
                visited[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }

        return visited[node];
    }
};