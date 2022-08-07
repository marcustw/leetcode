class Solution {
    int INF = 1000001;
    int N_INF = -1000001;
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if (m>n) return findMedianSortedArrays(nums2, nums1);
        
        int total=m+n;
        int lo=0, hi=m;
        int halfRoundUp=(total+1)/2;
        while (lo <= hi) {
            int mid1=lo+(hi-lo)/2;
            int mid2=halfRoundUp-mid1;
            int x1=mid1<=0 ? N_INF : nums1[mid1-1];
            int x2=mid2<=0 ? N_INF : nums2[mid2-1];
            int y1=mid1>=m ? INF : nums1[mid1];
            int y2=mid2>=n ? INF : nums2[mid2];
            
            if (x1<=y2 && x2<=y1) {
                if (total%2==1) {
                    return (double) max(x1,x2);
                } else {
                    return (double) (max(x1,x2) + min(y1,y2))/2.0;
                }
            } else if (x1>y2) {
                hi=mid1-1;
            } else {
                lo=mid1+1;
            }
        }

        return INF;
    }
};