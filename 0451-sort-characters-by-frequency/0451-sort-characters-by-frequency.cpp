class Solution {
    typedef pair<int,char> pi;
public:
    string frequencySort(string s) {
        string ans="";
        priority_queue<pi> pq;
        unordered_map<char,int> m;
        for (int i=0; i<s.length(); i++) 
            m[s[i]]++;   
        for (auto& c : m)
            pq.push({c.second,c.first});
        while (!pq.empty()) {
            pi p=pq.top();
            for (int i=0; i<p.first; i++) ans+=p.second;
            pq.pop();
        }
        return ans;
    }
};