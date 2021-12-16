class Solution {
    public int rob(int[] nums) {
        if(nums.length==1){
            return nums[0];
        }
        
        int n = nums.length;
        int currMax = 0;
        int prevMax = 0;
        int prevMax2 = 0;
        int currMax2 = 0;
        for(int i = 0; i<n; i++){
            if (i>=0 && i<n-1){
                int temp = currMax;
                currMax = Math.max(prevMax+nums[i],currMax);
                prevMax = temp;
            }
            if (i>0){
                int temp2 = currMax2;
                currMax2 = Math.max(prevMax2+nums[i],currMax2);
                prevMax2 = temp2;  
            }
        }
       
        return Math.max(currMax, currMax2);
    }
}