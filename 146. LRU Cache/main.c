#include <stdio.h>

#define ARRAY_SIZE 10001

typedef struct _Node {
    int key;
    int val;
    struct _Node *prev;
    struct _Node *next;
} Node;

typedef struct {
    int cap;
    int count;
    Node *head;
    Node *tail;
    Node *maps[ARRAY_SIZE];
} LRUCache;

LRUCache *lRUCacheCreate(int capacity) {
    LRUCache *cache = (LRUCache *)calloc(1, sizeof(LRUCache));
    cache->cap = capacity;
    cache->head = (Node *)calloc(1, sizeof(Node));
    cache->tail = (Node *)calloc(1, sizeof(Node));
    cache->head->key = -1;
    cache->head->val = -1;
    cache->head->next = cache->tail;
    cache->tail->key = -1;
    cache->tail->val = -1;
    cache->tail->prev = cache->head;

    return cache;
}

static void addNode(LRUCache *obj, Node *node) {
    node->next = obj->head->next;
    node->prev = obj->head;
    obj->head->next->prev = node;
    obj->head->next = node;
}

static void delNode(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

int lRUCacheGet(LRUCache *obj, int key) {
    if (obj->count == 0) {
        return -1;
    }

    if (obj->maps[key] == NULL) {
        return -1;
    }

    Node *node = obj->maps[key];
    int val = node->val;

    delNode(node);
    addNode(obj, node);

    return val;
}

void lRUCachePut(LRUCache *obj, int key, int value) {
    if (obj->maps[key] == NULL) {
        if (obj->count >= obj->cap) {
            Node *node = obj->tail->prev;
            int delKey = node->key;
            delNode(node);
            free(obj->maps[delKey]);
            obj->maps[delKey] = NULL;
        } else {
            obj->count++;
        }

        obj->maps[key] = (Node *)calloc(1, sizeof(Node));
        obj->maps[key]->key = key;
        obj->maps[key]->val = value;
        addNode(obj, obj->maps[key]);
    } else {
        obj->maps[key]->val = value;
        delNode(obj->maps[key]);
        addNode(obj, obj->maps[key]);
    }
}

void lRUCacheFree(LRUCache *obj) {
    if (obj != NULL) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            if (obj->maps[i] != NULL) {
                free(obj->maps[i]);
                obj->maps[i] = NULL;
            }
        }

        free(obj->head);
        free(obj->tail);
        free(obj);
    }
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 * lRUCachePut(obj, key, value);
 * lRUCacheFree(obj);
 */