class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses,0);
        for (auto& prereq: prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
            inDegree[prereq[0]]++;
        }
        
        queue<int> q;
        for (int i=0; i<numCourses; i++) {
            if (!inDegree[i]) q.push(i);
        }
        
        while (!q.empty()) {
            int u=q.front();
            q.pop();
            for (auto& v : graph[u]) {
                inDegree[v]--;
                if (!inDegree[v]) q.push(v);
            }
        }
        
        for (int i=0; i<numCourses; i++) {
            if (inDegree[i]) return false;
        }
        
        return true;
    }
};