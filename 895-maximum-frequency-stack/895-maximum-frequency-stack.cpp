class FreqStack {
    unordered_map<int, int> count;
    unordered_map<int, stack<int>> m;
    int maxFreq=0;
public:
    FreqStack() {}
    
    void push(int val) {
        count[val]++;
        maxFreq = max(maxFreq,count[val]);
        m[count[val]].push(val);
    }
    
    int pop() {
        int ans = m[maxFreq].top();
        m[maxFreq].pop();
        count[ans]--;
        if (!m[maxFreq].size()) maxFreq--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */