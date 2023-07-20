class Solution {
public:
    vector<int> asteroidCollision(vector<int>& A) {
        stack<int> stek;
        int n=A.size();
        for (int i=0; i<n; ++i) {
            if (A[i]>0 || stek.empty()) stek.push(A[i]);
            else {
                while (!stek.empty() && stek.top()>0 && stek.top()<abs(A[i])) {
                    stek.pop();
                }
                if (!stek.empty() && stek.top()==abs(A[i])) stek.pop();
                else if (stek.empty() || stek.top()<0) stek.push(A[i]);
            }
        }
        vector<int> ans(stek.size());
        for (int i=stek.size()-1; i>=0; --i) {
            ans[i]=stek.top();
            stek.pop();
        }
        return ans;
    }
};