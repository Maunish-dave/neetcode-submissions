class LRUCache {
public:

    struct Dlist {
        int val;
        int key;
        Dlist* next;
        Dlist* prev;

        Dlist(int key,int val){
            this->key = key;
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }
    };

    int curr_cap;
    int org_cap;
    Dlist* front=nullptr;
    Dlist* back=nullptr;
    unordered_map<int,Dlist*> hash;
    LRUCache(int capacity) {
        curr_cap = 0;
        org_cap = capacity;
    }

    void addFront(Dlist* node){
        node->next = front;
        if(front) front->prev = node;
        front = node;
        if(!back) back = node; // back was empty
    }

    void removeNode(Dlist* node){
        Dlist* n = node->next;
        Dlist* p = node->prev;
        if(p) p->next = n; else front = n;
        if(n) n->prev = p; else back = p;
        node->prev = node->next = nullptr;
    }
    
    int get(int key) {
        if(hash.find(key)!=hash.end()){
            Dlist* node = hash[key];
            removeNode(node);
            addFront(node);
            return node->val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(hash.find(key) != hash.end()){
            Dlist* node = hash[key];
            node->val = value;
            removeNode(node);
            addFront(node);
        }
        else{
            Dlist* node = new Dlist(key,value);
            hash[key] = node;
            addFront(node);
            curr_cap++;

            if(curr_cap > org_cap){
                Dlist* lru = back;
                hash.erase(lru->key);   // erase by key, not value
                removeNode(lru);
                delete lru;             // free it — your original leaked
                curr_cap--;
            }
        }
    }
};
