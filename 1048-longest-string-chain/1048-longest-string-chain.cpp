class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // sort list according to length of string (biggest comes first)
        sort(words.begin(), words.end(),  []
            (const std::string& first, const std::string& second){
                return first.size() > second.size();
            });
        
        unordered_map<string, int> mem;
        
        for (string x : words) mem[x] = 1;
        
        for (string x : words) {
            for (int i = 0; i < x.size(); i++) {
                string t = x;
                t.erase(t.begin()+i);
                mem[t] = max(mem[t], 1 + mem[x]);
            }
        }
        int res = 0;
        for (string x : words) res = max(res, mem[x]); 
        return res;
    }
};