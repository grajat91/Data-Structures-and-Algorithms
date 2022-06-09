/*Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.\
Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4*/

class Node {
public:
    int key;
    int value;
    Node *pre;
    Node *next;
    
    Node (int k, int v) {
        key = k;
        value = v;
        pre = NULL; 
        next = NULL;
    }
};
class LRUCache {
public:
    unordered_map<int, Node*> cache_unit;
    Node *head; 
    Node *tail;
    int c;
    int count;
    
    LRUCache(int capacity) {
        c = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->pre = head;
        head->pre = NULL;
        tail->next = NULL;
        count = 0;
    }
    
    void deleteNode(Node *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    
    void addNodetohead(Node *node) {
        node->next = head->next;
        head->next->pre = node;
        node->pre = head;
        head->next = node;
    }
    
    int get(int key) {
        if (cache_unit[key] != NULL) {
            Node *node = cache_unit[key];
            deleteNode(node);
            addNodetohead(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache_unit[key] != NULL) {
            Node *node = cache_unit[key];
            node->value = value;
            deleteNode(node);
            addNodetohead(node);
        } else {
            if (count < c) {
                Node *node = new Node(key, value);
                cache_unit[key] = node;
                count++;
                addNodetohead(node);
            } else {
                Node *node = new Node(key, value);
                cache_unit[key] = node;
                cache_unit.erase(tail->pre->key);
                deleteNode(tail->pre);
                addNodetohead(node);
            }
        }
    }
