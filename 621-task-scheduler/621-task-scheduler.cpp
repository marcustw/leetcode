class Solution {
    typedef pair<int,char> pi;
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size=tasks.size();
        if (n==0) return size;
        int maxFreq=0;
        unordered_map<char,int> m;
        for (char& c : tasks) {
            m[c]++;
            maxFreq=max(maxFreq,m[c]);
        }
        int ans=(maxFreq-1) * (n+1);
        for (auto it=m.begin(); it!=m.end(); it++) {
            if (it->second==maxFreq) ans++;
        }
        return size>ans ? size : ans;
    }
};