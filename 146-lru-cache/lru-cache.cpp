class Node {
public:
    int key, value;
    Node *prev, *next;
    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = NULL;
    }
};
class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void deleteNode(Node *node) {
        Node *left = node->prev;
        Node *right = node->next;

        left->next = right;
        right->prev = left;
    }
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node *node = mp[key];

        deleteNode(node);
        addNode(node);

        return node->value;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {

            Node *node = mp[key];
            node->value = value;

            deleteNode(node);
            addNode(node);

            return;
        }

        Node *node = new Node(key, value);

        mp[key] = node;
        addNode(node);

        if (mp.size() > cap) {

            Node *lru = tail->prev;

            deleteNode(lru);

            mp.erase(lru->key);

            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */