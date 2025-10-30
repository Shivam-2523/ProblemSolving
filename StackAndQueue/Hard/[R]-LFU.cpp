/*
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3
 

Constraints:

1 <= capacity <= 104
0 <= key <= 105
0 <= value <= 109
At most 2 * 105 calls will be made to get and put.
*/

struct Node {
    int key, val, freq;
    Node *prev, *next;
    Node(int k, int v) : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
};

struct DoubleList {
    Node *head, *tail;
    int size = 0;
    DoubleList() {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    void addFront(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }
    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
    Node* popBack() {
        if (size==0) return nullptr;
        Node* node = tail->prev;
        remove(node);
        return node;
    }
};

class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }
    
    int get(int key) {
        if (keyToNode.find(key) == keyToNode.end()) return -1;
        Node* node = keyToNode[key];
        // Need to move node to freq+1 list
        touch(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (keyToNode.find(key) != keyToNode.end()) {
            // Key exists, update val and touch (freq++)
            Node* node = keyToNode[key];
            node->val = value;
            touch(node);
        } else {
            if (keyToNode.size() == capacity) {
                // Remove LFU and LRU
                Node* nodeToRemove = freqToList[minFreq]->popBack();
                keyToNode.erase(nodeToRemove->key);
                delete nodeToRemove;
            }
            Node* node = new Node(key, value);
            minFreq = 1;
            if (freqToList[minFreq] == nullptr) freqToList[minFreq] = new DoubleList();
            freqToList[1]->addFront(node);
            keyToNode[key] = node;
        }
    }

private:
    int capacity, minFreq;
    unordered_map<int, Node*> keyToNode;
    unordered_map<int, DoubleList*> freqToList;

    void touch(Node *node) {
        int freq = node->freq;
        freqToList[freq]->remove(node);
        // update minFreq if removing last node in minFreq list
        if (freq == minFreq && freqToList[freq]->size == 0)
            minFreq++;

        node->freq++;
        if (freqToList[node->freq] == nullptr)
            freqToList[node->freq] = new DoubleList();
        freqToList[node->freq]->addFront(node);
    }
};