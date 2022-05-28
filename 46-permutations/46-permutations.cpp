class Solution {
private:
    vector<vector<int>> ans;
    
    void permutate(vector<int>& arr, int l, int r) {
        if (l==r) {
            ans.push_back(arr);
            return;
        }
        
        for (int i=l; i<=r; i++) {
            swap(arr[i],arr[l]);
            permutate(arr,l+1,r);
            swap(arr[i],arr[l]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        permutate(nums,0,n-1);
        return ans;
    }
};