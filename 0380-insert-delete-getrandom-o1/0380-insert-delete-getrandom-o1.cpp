class RandomizedSet {
    unordered_map<int, int> m;
    vector<int> v;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (m.find(val) == m.end()) {
            m[val] = v.size();
            v.emplace_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        int id = m[val];
        int last = v[v.size() - 1];
        m[last] = id;
        v[id] = last;
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */