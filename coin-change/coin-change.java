class Solution {
    
    public int helper(int[] coins, int amount, int index, int[][] mem) {
        if (amount == 0) {
            return 0;
        } else if (amount < 0 || index >= coins.length) {
            return Integer.MAX_VALUE - 1;
        }
        
        if (mem[index][amount] != -2) {
            return mem[index][amount];
        }
        mem[index][amount] = Math.min(1 + helper(coins, amount - coins[index], index, mem), helper(coins, amount, index + 1, mem));
        return mem[index][amount];
    }
    
    public int coinChange(int[] coins, int amount) {
        if (amount == 0) {
            return 0;
        } else if (coins.length == 0) {
            return -1;
        }
        int[][] mem = new int[coins.length + 1][amount + 1];
        for (int i = 0; i <= coins.length; i++) {
            for (int j = 0; j <= amount; j++) {
                mem[i][j] = -2;
            }
        }
        int min = helper(coins, amount, 0, mem);
        if (min == Integer.MAX_VALUE - 1) {
            return -1;
        }
        return min;
    }
}