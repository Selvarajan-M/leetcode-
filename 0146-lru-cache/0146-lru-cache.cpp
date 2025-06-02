#include <map>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    map<int, Node*> mpp;
    int cap;

    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        Node* before = node->prev;
        Node* after = node->next;
        before->next = after;
        after->prev = before;
    }

    void moveToFront(Node* node) {
        removeNode(node);
        addToFront(node);
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!mpp.count(key)) return -1;
        Node* node = mpp[key];
        moveToFront(node);  // make it most recently used
        return node->val;
    }

    void put(int key, int value) {
        if (mpp.count(key)) {
            Node* node = mpp[key];
            node->val = value;
            moveToFront(node);
        } else {
            if (mpp.size() == cap) {
                Node* lru = tail->prev;
                mpp.erase(lru->key);
                removeNode(lru);
                delete lru;
            }
            Node* node = new Node(key, value);
            mpp[key] = node;
            addToFront(node);
        }
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};
