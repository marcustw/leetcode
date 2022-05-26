class RandomizedSet {
private:
    set<int> s;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (s.count(val) == 1) return false;
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if (s.count(val) == 0) return false;
        s.erase(val);
        return true;
    }
    
    int getRandom() {
        int ran = rand()%s.size();
        auto itr = s.begin();
        for (int i=0; i<ran; i++) {
            itr++;
        }
        return *itr;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */