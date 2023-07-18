typedef pair<int,int> P;
class LRUCache {
    int capacity;
    unordered_map<int, list<P>::iterator> m;
    list<P> lst;

public:
    LRUCache(int capacity) { this->capacity=capacity; }
    
    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        lst.splice(lst.begin(), lst, m[key]);
        return m[key]->second;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            /*
            Put m[key] from lst to front of the lst
            */
            lst.splice(lst.begin(), lst, m[key]);
            m[key]->second=value;
            return;
        }
        if (lst.size()==capacity) {
            auto evict=lst.back().first;
            /*
            Remove the least recently used
            */
            lst.pop_back();
            m.erase(evict);
        }
        lst.push_front({key, value});
        m[key]=lst.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */