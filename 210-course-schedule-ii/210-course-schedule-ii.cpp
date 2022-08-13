class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses,0);
        
        for (auto& prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
            inDegree[prereq[0]]++;
        }
        
        queue<int> q;
        for (int i=0; i<numCourses; i++) {
            if (!inDegree[i]) q.push(i);
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            
            for (auto& v : graph[u]) {
                inDegree[v]--;
                if (!inDegree[v]) q.push(v);
            }
        }
        
        if (ans.size()!=numCourses) return {};
        
        return ans;
    }
};