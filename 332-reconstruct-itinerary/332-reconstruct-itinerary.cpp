class Solution {
    vector<string> ans;
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> edges;
    
    void recurse(string airport) {
        while (edges[airport].size()) {
            string next = edges[airport].top();
            edges[airport].pop();
            recurse(next);
        }
        ans.insert(ans.begin(),airport);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket : tickets) edges[ticket[0]].push(ticket[1]);
        recurse("JFK"); // "JFK" is starting
        return ans;
    }
};