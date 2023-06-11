class Solution {
    long long ans=0L;
public:
    long long wonderfulSubstrings(string word) {
        long long ans=0L;
        unordered_map<int, long long> count;
        count[0]=1;
        int mask=0;
        for (char& c : word) {
            int idx=c-'a';
            mask^=(1<<idx);
            ans+=count[mask];
            count[mask]++;  // map[mask]++
            for (int i=0; i<10; i++) ans+=count[mask ^ (1<<i)];  // flip one
        }
        return ans;
    }
};