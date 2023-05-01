import java.util.*;

class Solution1 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // Click HELP above to see examples of handling input/debug/output
        // INPUT: int n = in.nextInt();
        // DEBUG: System.out.println(n);
        // OUTPUT: System.out.println(result);

        // Write the code to solve the problem below,
        // format the "result" as specified in the problem statement
        // and finally, write the result to stdout
        // IMPORTANT: Remove all debug statements for final submission

        int n = in.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }

        Arrays.sort(arr);

        int big = n/2;
        int small = n - big;

        int q = 0;
        int k = n - 1;;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                System.out.println(arr[q]);
                q++;
            } else {
                System.out.println(arr[k]);
                k--;
            }
        }
    }
} 