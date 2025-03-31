#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
    static constexpr int ARRAY_SIZE = 1001;

public:
    Node *copyRandomList(Node *head) {
        if (!head) {
            return nullptr;
        }

        vector<Node *> array(ARRAY_SIZE);
        Node *current = head;
        size_t count = 0;

        while (current) {
            array[count++] = new Node(current->val);
            current = current->next;
        }

        current = head;
        size_t index = 0;

        while (current) {
            array[index]->next = array[index + 1];

            if (current->random) {
                size_t idx = 0;
                Node *p = head;

                while (current->random != p) {
                    p = p->next;
                    idx++;
                }

                array[index]->random = array[idx];
            }

            current = current->next;
            index++;
        }

        return array[0];
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
    static constexpr int ARRAY_SIZE = 1001;

public:
    Node *copyRandomList(Node *head) {
        if (!head) {
            return nullptr;
        }

        static vector<Node> array(ARRAY_SIZE, Node(0));
        Node *current = head;
        size_t count = 0;

        while (current) {
            current = current->next;
            count++;
        }

        current = head;
        count = 0;

        while (current) {
            array[count].val = current->val;
            array[count].next = nullptr;
            array[count].random = nullptr;
            count++;
            current = current->next;
        }

        for (size_t i = 0; i < count - 1; i++) {
            array[i].next = &array[i + 1];
        }
        array[count - 1].next = nullptr;

        current = head;
        for (size_t i = 0; i < count; i++) {
            if (current->random) {
                Node *p = head;
                size_t idx = 0;
                while (current->random != p) {
                    p = p->next;
                    idx++;
                }
                array[i].random = &array[idx];
            }
            current = current->next;
        }

        return &array[0];
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
    static constexpr int ARRAY_SIZE = 1001;

public:
    Node *copyRandomList(Node *head) {
        if (!head) {
            return nullptr;
        }

        unordered_map<Node *, Node *> maps;
        Node *node = head;

        while (node) {
            maps[node] = new Node(node->val);
            node = node->next;
        }

        node = head;

        while (node) {
            maps[node]->next = maps[node->next];
            maps[node]->random = maps[node->random];
            node = node->next;
        }

        return maps[head];
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
    static constexpr int ARRAY_SIZE = 1001;

public:
    Node *copyRandomList(Node *head) {
        if (!head) {
            return nullptr;
        }

        Node *current = head;

        while (current) {
            Node *node = new Node(current->val);
            node->next = current->next;
            current->next = node;
            current = node->next;
        }

        current = head;

        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        Node **pNode = &head;

        while (*pNode) {
            *pNode = (*pNode)->next;
            pNode = &(*pNode)->next;
        }

        return head;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
    static constexpr int ARRAY_SIZE = 1001;

public:
    Node *copyRandomList(Node *head) {
        if (!head) {
            return nullptr;
        }

        Node *current = head;

        while (current) {
            Node *node = new Node(current->val);
            node->next = current->next;
            current->next = node;
            current = node->next;
        }

        current = head;

        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        Node *newHead = head->next;
        current = head;

        while (current) {
            Node *node = current->next;
            current->next = node->next;
            if (node->next) {
                node->next = node->next->next;
            }
            current = current->next;
        }

        return newHead;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
    static constexpr int ARRAY_SIZE = 1001;

public:
    Node *copyRandomList(Node *head) {
        if (!head) {
            return nullptr;
        }

        unordered_map<Node *, Node *> maps;
        maps[nullptr] = nullptr;
        Node *current = head;

        while (current) {
            if (maps.find(current) == maps.end()) {
                maps[current] = new Node(current->val);
            }

            if (maps.find(current->next) == maps.end()) {
                maps[current->next] = new Node(current->next->val);
            }
            maps[current]->next = maps[current->next];

            if (maps.find(current->random) == maps.end()) {
                maps[current->random] = new Node(current->random->val);
            }
            maps[current]->random = maps[current->random];

            current = current->next;
        }

        return maps[head];
    }
};