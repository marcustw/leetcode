class Solution {
    
    public boolean canJump(int[] nums) {
        int len = nums.length;
        if (len == 1) {
            return true;
        } else if (nums[0] == 0) {
            return false;
        }
        int[] arr = new int[len];
        arr[len-1] = len-1;
        for (int i = len - 2; i >= 0; i--) {
            int steps = nums[i];
            for (int j = 1; i+j < len && j <= steps; j++) {
                if (arr[i+j] >= len-1) {
                    arr[i] = len-1;
                    break;
                }
            }
        }
        return arr[0] >= len-1;
    }
}