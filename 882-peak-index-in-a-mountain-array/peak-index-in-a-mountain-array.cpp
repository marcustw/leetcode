class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo=0, hi=arr.size()-1;
        while (lo<hi) {
            int mid=lo+(hi-lo)/2;
            if (mid==0) {
                lo+=1;
                continue;
            } else if (mid==arr.size()-1) {
                hi-=1;
                continue;
            }
            if (arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
            if (arr[mid]>arr[mid-1]) lo=mid+1;
            else hi=mid-1;
        }
        return lo;
    }
};