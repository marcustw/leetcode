class Solution {
public:
    int minJumps(vector<int>& arr) {
        int l = arr.size();
        if (l == 1) return 0;
        if (arr[0] == arr[l-1]) return 1;
        unordered_map<int, vector<int>> mem;
        for (int i = 0; i < l; i++) {
            mem[arr[i]].push_back(i);
        }
        
        queue<int> q;
        q.push(0);
        int res = 0;
        
       while(!q.empty()){
            res++;
            int size = q.size();
            
            for(int i = 0; i<size; i++){
                int j = q.front();
                q.pop();
                
                if(j-1 >= 0 && mem.count(arr[j-1]) != 0) {
                    q.push(j-1);
                }
                
                if(j+1 < l && mem.count(arr[j+1]) != 0) {
                    if(j+1 == l-1) return res;
                    q.push(j+1);
                }
                
                if(mem.count(arr[j]) != 0){
                    for(auto k: mem[arr[j]]){
                        if(k != j){
                            if(k == l-1) return res;
                            q.push(k);
                        }
                    }
                }
                mem.erase(arr[j]);
            }
        }
        
        return res;
    }
};