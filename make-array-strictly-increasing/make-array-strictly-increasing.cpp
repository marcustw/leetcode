class Solution {
public:
    int recurse(int i,int j, int p,vector<vector<int>> &dp,vector<int> &arr1,vector<int> &arr2){
        if (i==arr1.size()) return 0;
        int n=arr1.size();
        j=upper_bound(arr2.begin()+j, arr2.end(), p)-arr2.begin();
        if(dp[i][j] != -1)return dp[i][j];
        if(j==arr2.size() && arr1[i]<=p)return 2001;
        int swap=2001, noSwap=2001;
        if(j<arr2.size())
            swap=recurse(i+1,j+1,arr2[j],dp,arr1,arr2)+1;
        if(arr1[i]>p)
            noSwap=recurse(i+1,j,arr1[i],dp,arr1,arr2);
        // cout << "i = " << i << ", idx = " << j << ", swap = " << swap << ", noSwap = " << noSwap << endl;
        return dp[i][j]=min(swap, noSwap);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(),m=arr2.size();
        vector<vector<int>> dp(2001,vector<int>(2001,-1));
        sort(arr2.begin(),arr2.end());
        int ans = recurse(0,0,-1,dp,arr1,arr2);
        return ans>n ? -1 : ans;
    }
};