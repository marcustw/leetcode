class RandomizedSet {
private:
    vector<int> v;
    unordered_map<int,int> m; //val, index
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (m.count(val)) return false;
        m[val]=v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (m.count(val) == 0) return false;
        int last = v.back();
        v[m[val]]=last;
        m[last]=m[val];
        v.pop_back();
        m.erase(val);
        return true;
    }
 
    // O(1)
    int getRandom() {
        int ranIdx = rand()%v.size();
        return v[ranIdx];
    }
};
