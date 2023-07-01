class Solution {
    int ans=INT_MAX;

    void backtrack(int start, vector<int>& cookies, vector<int>& v, int k) {
        if (start==cookies.size()) {
            int maxm=INT_MIN;
            for (int i=0; i<k; ++i) maxm=max(maxm, v[i]);
            ans=min(ans, maxm);
            return;
        }
        for (int i=0; i<k; ++i) {
            v[i]+=cookies[start];
            backtrack(start+1, cookies, v, k);
            v[i]-=cookies[start];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> v(k,0);
        backtrack(0, cookies, v, k);
        return ans;
    }
};