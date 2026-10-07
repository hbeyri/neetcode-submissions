struct ListNode {
    int key;
    int val;
    ListNode *next = nullptr;
    ListNode *prev = nullptr;
    ListNode() : key(0), val(0) {}
    ListNode(int x, int y) : key(x), val(y) {}
};

class LRUCache {
public:
    int cap;
    unordered_map<int, ListNode*> m;
    ListNode* head = new ListNode();
    ListNode* tail = new ListNode();

    LRUCache(int capacity)
     : cap(capacity)
    {
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        auto iter = m.find(key);
        if(iter == m.end())
            return -1;

        remove(iter->second);
        updateTail(iter->second);
        return iter->second->val;
    }

    void remove(ListNode* node){
        ListNode* prev = node->prev;
        ListNode* next = node->next;
        prev->next = next;
        next->prev = prev;

        node->prev = nullptr;
        node->next = nullptr;
    }

    void evictLast()
    {
        ListNode* last = head->next;

        remove(last);
        m.erase(last->key);
    }

    void updateTail(ListNode* node){
        ListNode* before_tail = tail->prev;
        before_tail->next = node;
        node->prev = before_tail;
        node->next = tail;
        tail->prev = node;
    }

    void put(int key, int value) {
        auto iter = m.find(key);
        ListNode* node = nullptr;
        if(iter != m.end())
        {
            iter->second->val = value;
            node = iter->second;
            remove(node);
        }
        else
        {
            if(m.size() == cap)
            {
                evictLast();
            }
            node = new ListNode(key, value);
            m[key] = node;
        }

        updateTail(node);
    }
};
