class Solution {
public:    
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int, int> m;
        vector<int> ltr(n,nums[0]);
        vector<int> rtl(n,nums[n-1]);
        m[nums[0]]=1;
        m[nums[n-1]]=1;
        for (int i=1; i<n; i++) {
            ltr[i]=ltr[i-1]+nums[i];
        }
        for (int j=n-2; j>=0; j--) {
            rtl[j]=rtl[j+1]+nums[j];
            if (!m.count(rtl[j])) {
                m[rtl[j]]=n-j;
            } else {
                m[rtl[j]]=min(m[rtl[j]],n-j);
            }
        }
        if (m[x]) return m[x];
        int ans=INT_MAX;
        for (int i=0; i<n; i++) {
            int y=ltr[i];
            if (y==x) ans=min(ans,i+1);
            else if (m[x-y]) ans=min(ans,i+1+m[x-y]);
        }
        return ans>n ? -1 : ans;
    }
};


// [1 , 2 , 6 , 8, 11]
// [11, 10, 9 , 5, 3 ]