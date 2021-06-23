class Solution {
    public String nearestPalindromic(String n) {
        long val = Long.parseLong(n);
        if (val <= 10) {
            return String.valueOf(val - 1);
        } else if (val == 11) {
            return String.valueOf(9);
        }
        String x = makePalindrome(n);
        return getOtherPalindrome(val, x);
    }

    boolean isPalindrome(String x) {
        int half = x.length() / 2;
        for (int i = 0; i < half; i++) {
            if (x.charAt(i) != x.charAt(x.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }

    String makePalindrome(String n) {
        char[] arr = n.toCharArray();
        int len = n.length();
        int half = len / 2;
        for (int i = 0; i < half; i++) {
            arr[len - i - 1] = arr[i];
        }
        return new String(arr);
    }

    String getOtherPalindrome(long m, String palindrome) {
        long palindromeVal = Long.parseLong(palindrome);
        char[] arrSmaller = palindrome.toCharArray();
        char[] arrLarger = palindrome.toCharArray();
        int len = palindrome.length();
        int half = len / 2;
        int a = Integer.parseInt("" + arrSmaller[half]) - 1;
        int b = Integer.parseInt("" + arrSmaller[half]) + 1;
        long diff1 = Math.abs(palindromeVal - m);
        if (diff1 == 0) {
            diff1 = Long.MAX_VALUE;
        }
        if (a == -1) {
            int pow = len % 2 == 0 ? half - 1 : half;
            String smallPalindrome = makePalindrome(String.valueOf(palindromeVal - (long) Math.pow(10, pow)));
            arrSmaller = smallPalindrome.toCharArray();
        } else {
            char x = Character.forDigit(a, 10);
            arrSmaller[half] = x;
            if (len % 2 != 1) {
                arrSmaller[half - 1] = x;
            }
        }
        String smaller = new String(arrSmaller);
        long s = Long.parseLong(smaller);
        if (b == 10) {
            String largePalindrome = makePalindrome(String.valueOf(palindromeVal + (long) Math.pow(10, half)));
            arrLarger = largePalindrome.toCharArray();
        } else {
            char y = Character.forDigit(b, 10);
            arrLarger[half] = y;
            if (len % 2 != 1) {
                arrLarger[half - 1] = y;
            }
        }
        String larger = new String(arrLarger);
        long l = Long.parseLong(larger);
        long diff2 = m - s;
        long diff3 = l - m;

        long minDiff = Math.min(diff1, Math.min(diff2, diff3));

        if (minDiff == diff1 && minDiff == diff2) {
            return s < palindromeVal ? smaller : palindrome; 
        }
        if (minDiff == diff3 && minDiff == diff1) {
            return palindromeVal < l ? palindrome : larger;
        }
        
        return minDiff == diff2
            ? smaller
            : minDiff == diff3
                ? larger
                : palindrome;
    }
}