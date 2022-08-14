class Solution {
    int search(vector<int>& arr, int x) {
        int n=arr.size();
        if (x<arr[0]) return 0;
        if (x>arr[n-1]) return n-1;
        int l=0, r=n-1;
        while (l<=r) {
            int mid=(l+r)/2;
            if (x<arr[mid]) {
                r = mid-1;
            } else if (x>arr[mid]) {
                l = mid+1;
            } else {
                return mid;
            }
        }
        if (abs(arr[l]-x) == abs(arr[r]-x)) {
            return min(l,r);
        }
        return abs(arr[l]-x) < abs(arr[r]-x) ? l : r;
    }
    
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int m=search(arr,x);
        vector<int> ans = {arr[m]};
        k--;
        
        int l=m-1, r=m+1;
        while (k>0 &&  l>=0 && r<=arr.size()-1) {
            int labs = abs(arr[l]-x), rabs = abs(arr[r]-x);
            if (labs<=rabs ) {
                ans.insert(ans.begin(),arr[l]);
                l--;
            } else {
                ans.push_back(arr[r]);
                r++;
            }
            k--;
        }
        
        // add all left side
        while (k>0 && l>=0) {
            ans.insert(ans.begin(), arr[l--]);
            k--;
        }
        
        // add all right side
        while (k>0 && r<=arr.size()-1) {
            ans.push_back(arr[r++]);
            k--;
        }
        
        return ans;
    }
};