class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return 0;
        }
        int[] arr = new int[n];
        for (int i = n-2; i>= 0; i--) {
            int min = Integer.MAX_VALUE - 1;
            for (int j = 1; i+j < n && j <= nums[i]; j++) {
                min = Math.min(1 + arr[i+j], min);                
            }
            arr[i] = min;
        } 
        return arr[0];
    }
}