public class Checksum {
    public static char generateCheckSum(String prefix, int suffix) {
        String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String chars = "AZYXUTSRPMLKJHGEDCB";
        int[] keys = {9, 4, 5, 4, 3, 2};
        int[] nums = new int[6];
        if (prefix.length() == 1) {
            nums[0] = 0;
            nums[1] = alphabet.indexOf(prefix.charAt(0)) + 1;
        } else {
            nums[0] = alphabet.indexOf(prefix.charAt(prefix.length() - 2)) + 1;
            nums[1] = alphabet.indexOf(prefix.charAt(prefix.length() - 1)) + 1;
        }
        for (int i = 5; i >= 2; i--) {
            nums[i] = suffix % 10;
            suffix /= 10;
        }
        for (int i = 0; i < 6; i++) {
            nums[i] = nums[i] * keys[i];
        }
        int sumNums = 0;
        for (int x : nums) {
            sumNums += x;
        }
        return chars.charAt(sumNums % 19);
    }

    public static void main(String[] args) {
        System.out.println(generateCheckSum("SBS", 3229));
        System.out.println(generateCheckSum("E", 23));
    }
}
