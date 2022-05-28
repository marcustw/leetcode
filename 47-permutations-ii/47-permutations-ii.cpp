class Solution {
private:
    vector<vector<int>> ans;
    unordered_set<string> s;
    
    void permutate(vector<int>& arr, int l, int r) {
        if (l==r) {
            stringstream ss;
            copy(arr.begin(),arr.end(),ostream_iterator<int>(ss,""));
            string st = ss.str();
            if (s.count(st) == 0) {
                ans.push_back(arr);
                s.insert(st);
            }
            return;
        }
        for (int i=l; i<=r; i++) {
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