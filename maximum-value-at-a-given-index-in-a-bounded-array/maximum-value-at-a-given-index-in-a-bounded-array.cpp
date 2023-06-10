class Solution {
    long fact(long n) {
        return (n*(n+1))/2;
    }
    long getSum(int len, int val) {
        long total=0;
        int decreasingLen=val;
        if (len>=decreasingLen) {
            long curSum=fact(val);
            int remainingSum = len - decreasingLen;
            total = curSum + remainingSum;
        } else {
            long lastVal=decreasingLen-len;
            total=fact(val)-fact(lastVal);
        }
        return total;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        int lo=1, hi=maxSum;
        int left=index, right=n-index-1;
        int ans=-1;
        while (lo<=hi) {
            int mid=lo+(hi-lo)/2;
            long leftSum=getSum(left, mid-1);
            long rightSum=getSum(right, mid-1);
            long totalSum=leftSum+mid+rightSum;
            if (totalSum>maxSum) {
                hi=mid-1;
            } else {
                ans=mid;
                lo=mid+1;
            }
        }
        return ans;
    }
};