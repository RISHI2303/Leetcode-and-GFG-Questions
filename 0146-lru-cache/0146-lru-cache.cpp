class LRUCache {
public:
    
    class Node{
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int _key, int _value){
            key = _key;
            value = _value;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int, Node*>cache;
    int capacity;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    void delNode(Node* delNode){
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delNext->prev = delPrev;
        delPrev->next = delNext;
    }
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* targetNode = cache[key];
            int targetVal = targetNode->value;
            cache.erase(key);
            delNode(targetNode);
            addNode(targetNode); 
            cache[key] = head->next;

            return targetVal;
        }
        return -1;
         
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* existingKey = cache[key];
            cache.erase(key);
            delNode(existingKey);
        }
        if(cache.size() == capacity){
            cache.erase(tail->prev->key);
            delNode(tail->prev);
        }
        addNode(new Node(key, value));
        cache[key] = head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */