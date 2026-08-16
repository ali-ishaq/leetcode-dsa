class LRUCache {
public:
    struct ListNode {
        int key;
        int val;
        ListNode* prev;
        ListNode* next;

        ListNode(int k = 0, int v = 0)
            : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int sz;
    unordered_map<int, ListNode*> mp;

    ListNode* head;
    ListNode* tail;

    LRUCache(int capacity) : sz(capacity) {
        head = new ListNode();
        tail = new ListNode();

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!mp.count(key))
            return -1;

        ListNode* node = mp[key];

        remove(node);
        addToTail(node);

        return node->val;
    }

    void put(int key, int value) {
        if (sz == 0)
            return;

        if (mp.count(key)) {
            ListNode* node = mp[key];

            node->val = value;

            remove(node);
            addToTail(node);
            return;
        }

        if (mp.size() == sz) {
            // Least recently used node
            ListNode* lru = head->next;

            remove(lru);
            mp.erase(lru->key);

            delete lru;
        }

        ListNode* node = new ListNode(key, value);
        mp[key] = node;

        addToTail(node);
    }

private:
    void remove(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToTail(ListNode* node) {
        node->prev = tail->prev;
        node->next = tail;

        tail->prev->next = node;
        tail->prev = node;
    }
};