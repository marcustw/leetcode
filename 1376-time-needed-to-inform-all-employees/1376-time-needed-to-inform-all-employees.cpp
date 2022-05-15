class Solution {
public:
    int recurse(int id, vector<int>& manager, vector<int>& informTime, unordered_map<int,int>& map) {
        int t = 0;
        if (id == -1) return t;
        if (map.count(id) != 0) return map[id];
        t = informTime[id];
        t += recurse(manager[id], manager, informTime, map);
        map[id] = t;
        return t;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if (n == 1) {
            return informTime[0];
        }
        int time = 0;
        unordered_map<int,int> map;
        for (int i = 0; i < n; i++) {
            if (i != headID) {
                time = max(time, recurse(i, manager, informTime, map));
            }
        }
        return time;
    }
};