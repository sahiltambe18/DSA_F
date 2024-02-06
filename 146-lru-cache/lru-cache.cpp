class LRUCache {
    int cap ;
public:

    class node{
        public:
        int key;
        int value;
        node* next , *prev;
        node(int key , int value){
            this->key = key;
            this->value = value;
        }
    };

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    void addNode(node* newer){
        node* temp = head->next;

        head->next = newer;
        newer->prev = head;
        
        newer->next = temp;
        temp->prev = newer;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    unordered_map<int, node*> umap;

    void delNode(node* toDelete){
        node* prv = toDelete->prev;
        node* nxt = toDelete->next;

        prv->next = nxt;
        nxt->prev = prv;
        // delete(toDelete);
    }
    
    int get(int key) {
        if(umap.find(key)!=umap.end()){
            node* resNode = umap[key];
            delNode(resNode);
            addNode(resNode);

            umap[key] = resNode;
            return resNode->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(umap.find(key)!=umap.end()){
            node* current = umap[key];
            umap.erase(key);
            delNode(current);
        }

        if(umap.size()==cap){
            umap.erase(tail->prev->key);
            delNode(tail->prev);
        }

        addNode(new node(key , value));
        umap[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */