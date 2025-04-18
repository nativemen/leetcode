#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node()
        : val(0)
        , left(nullptr)
        , right(nullptr)
        , next(nullptr) {}

    Node(int _val)
        : val(_val)
        , left(nullptr)
        , right(nullptr)
        , next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val)
        , left(_left)
        , right(_right)
        , next(_next) {}
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
    Node *getNext(Node *node) {
        while (node) {
            if (node->left) {
                return node->left;
            }

            if (node->right) {
                return node->right;
            }

            node = node->next;
        }

        return nullptr;
    }

public:
    Node *connect(Node *root) {
        if (!root) {
            return nullptr;
        }

        if (root->left) {
            if (root->right) {
                root->left->next = root->right;
            } else {
                root->left->next = getNext(root->next);
            }
        }

        if (root->right) {
            root->right->next = getNext(root->next);
        }

        connect(root->right);
        connect(root->left);

        return root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
    static constexpr int ARRAY_SIZE = 6000;

public:
    Node *connect(Node *root) {
        if (!root) {
            return nullptr;
        }

        Node *array[ARRAY_SIZE] = {NULL};
        array[0] = root;
        int head = 0;
        int tail = 1;

        while (head < tail) {
            int next = tail;

            for (int i = head; i < next; i++) {
                if (array[i]->left) {
                    array[tail++] = array[i]->left;
                }

                if (array[i]->right) {
                    array[tail++] = array[i]->right;
                }

                if (i < next - 1) {
                    array[i]->next = array[i + 1];
                }
            }

            array[next - 1]->next = nullptr;
            head = next;
        }

        return root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
    static constexpr int ARRAY_SIZE = 6000;

public:
    Node *connect(Node *root) {
        if (!root) {
            return nullptr;
        }

        Node *node = root;

        while (node) {
            Node *leftestNode = nullptr;
            Node *nextNode = nullptr;

            while (node) {
                if (node->left) {
                    if (!leftestNode) {
                        nextNode = node->left;
                        leftestNode = nextNode;
                    } else {
                        nextNode->next = node->left;
                        nextNode = nextNode->next;
                    }
                }

                if (node->right) {
                    if (!leftestNode) {
                        nextNode = node->right;
                        leftestNode = nextNode;
                    } else {
                        nextNode->next = node->right;
                        nextNode = nextNode->next;
                    }
                }

                node = node->next;
            }

            node = leftestNode;
        }

        return root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node *connect(Node *root) {
        if (!root) {
            return nullptr;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            Node *prev = nullptr;

            for (int i = 0; i < size; i++) {
                Node *node = q.front();
                q.pop();

                if (prev) {
                    prev->next = node;
                }

                prev = node;

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};