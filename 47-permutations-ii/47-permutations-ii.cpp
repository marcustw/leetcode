class Solution {
private:
    vector<vector<int>> ans;
    
    void permutate(vector<int>& arr, int l, int r) {
        if (l==r) {
            ans.push_back(arr);
            return;
        }
        unordered_set<int> uset;
        for (int i=l; i<=r; i++) {
            if (uset.count(arr[i]) > 0) continue;
            uset.insert(arr[i]);
            swap(arr[i], arr[l]);
            permutate(arr,l+1,r);
            swap(arr[i], arr[l]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int r=nums.size()-1;
        permutate(nums,0,r);
        return ans;
    }
};