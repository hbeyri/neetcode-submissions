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
        // cout<<"get "<<key<<endl;

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
        // cout<<"eviction "<<last->key<<endl;
        // cout<<"pre ";
        //     printHeadTail();

        remove(last);
        m.erase(last->key);
        // cout<<"p ";
        // printHeadTail();
    }

    void updateTail(ListNode* node){
        ListNode* before_tail = tail->prev;
        before_tail->next = node;
        node->prev = before_tail;
        node->next = tail;
        tail->prev = node;
        // cout<<"update tail "<<node->key<<endl;
    }

    void printHeadTail()
    {
        ListNode* node = head;
        while(node)
        {
            cout<<node->key<<" ";
            node = node->next;
        }
        cout<<endl;
    }

    void put(int key, int value) {
        // cout<<"put "<<key<<" "<<value<<endl;
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
