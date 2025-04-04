#include <queue>
#include <unordered_map>

using namespace std;

class LRUCache {
    class Node {
    public:
        int key;
        int val;
        Node *prev;
        Node *next;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
            this->prev = nullptr;
            this->next = nullptr;
        }
    };

    int cap;
    Node *head;
    Node *tail;
    unordered_map<int, Node *> maps;

    void delNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNode(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (maps.size() == 0) {
            return -1;
        }

        if (maps.find(key) == maps.end()) {
            return -1;
        }

        int val = maps[key]->val;

        delNode(maps[key]);
        addNode(maps[key]);

        return val;
    }

    void put(int key, int value) {
        if (maps.find(key) == maps.end()) {
            if (maps.size() >= cap) {
                Node *node = tail->prev;
                delNode(node);
                maps.erase(node->key);
            }

            Node *node = new Node(key, value);
            addNode(node);
            maps.emplace(key, node);
        } else {
            maps[key]->val = value;
            delNode(maps[key]);
            addNode(maps[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache {
    class Node {
    public:
        int key;
        int val;
        Node *prev;
        Node *next;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
            this->prev = nullptr;
            this->next = nullptr;
        }
    };

    static constexpr int ARRAY_SIZE = 10001;
    int cap;
    int count;
    Node *head;
    Node *tail;
    Node *maps[ARRAY_SIZE];

    void delNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNode(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        count = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;

        for (int i = 0; i < ARRAY_SIZE; i++) {
            maps[i] = nullptr;
        }
    }

    int get(int key) {
        if (count == 0) {
            return -1;
        }

        if (!maps[key]) {
            return -1;
        }

        int val = maps[key]->val;

        delNode(maps[key]);
        addNode(maps[key]);

        return val;
    }

    void put(int key, int value) {
        if (!maps[key]) {
            if (count >= cap) {
                Node *node = tail->prev;
                delNode(node);
                int delKey = node->key;
                delete maps[delKey];
                maps[delKey] = nullptr;
            } else {
                count++;
            }

            Node *node = new Node(key, value);
            addNode(node);
            maps[key] = node;
        } else {
            maps[key]->val = value;
            delNode(maps[key]);
            addNode(maps[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache {
    static constexpr int ARRAY_SIZE = 10001;

    queue<int> que;
    vector<int> values;
    vector<int> freq;
    int cap;
    int count;

public:
    LRUCache(int capacity) {
        cap = capacity;
        count = 0;
        values.resize(ARRAY_SIZE, -1);
        freq.resize(ARRAY_SIZE, 0);
    }

    int get(int key) {
        if (count == 0) {
            return -1;
        }

        if (values[key] == -1) {
            return -1;
        }

        freq[key]++;
        que.push(key);

        return values[key];
    }

    void put(int key, int value) {
        if (values[key] == -1) {
            while (count >= cap) {
                int delKey = que.front();
                que.pop();

                if (freq[delKey] == 1) {
                    values[delKey] = -1;
                    count--;
                }

                freq[delKey]--;
            }

            freq[key] = 1;
            count++;
        } else {
            freq[key]++;
        }

        values[key] = value;
        que.push(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */