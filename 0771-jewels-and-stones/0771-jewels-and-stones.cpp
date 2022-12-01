class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> s;
        int ans=0;
        for (int i=0; i<jewels.length(); i++) {
            s.insert(jewels[i]);
        }
        for (int i=0; i<stones.length(); i++) {
            if (s.find(stones[i]) != s.end()) ans++;
        }
        return ans;
    }
};