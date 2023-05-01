import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

class WES {
    static class E implements Comparable<E> {
        int start;
        int end;
        int profit;

        E(int start, int end, int profit) {
            this.start = start;
            this.end = end;
            this.profit = profit;
        }

        public int compareTo(E e) {
            if (this.end == e.end) {
                return this.start - e.start;
            } else {
                return this.end - e.end;
            }
        }

        public boolean isOverlap(E e) {
            return (this.start >= e.start && this.start < e.end)
                    || (this.end > e.start && this.end <= e.end)
                    || (this.start <= e.start && this.end >= e.end);
        }

        public String toString() {
            return String.format("(%d,%d), profit = %d", start, end, profit);
        }
    }

    public static int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        List<E> l = new ArrayList<>();
        int n = startTime.length;
        for (int i = 0; i < n; i++) {
            l.add(new E(startTime[i], endTime[i], profit[i]));
        }
        Collections.sort(l);
        int[] DP = new int[n];
        for (int i = 0; i < n; i++) {
            DP[i] = l.get(i).profit;
        }
        for (int i = n - 2; i >= 0; i--) {
            E e = l.get(i);
            int id = binarySearch(l, e.end, i);
            int pf = id == -1 ? 0 : DP[id];
            DP[i] = Math.max(DP[i+1], pf + e.profit);
        }
        for (E e : l) {
            System.out.println(e);
        }
        System.out.println(Arrays.toString(DP));
        return DP[0];
    }

    static public int binarySearch(List<E> list, int val, int l){
        int r=list.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(list.get(mid).start>=val){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] startTime = new int[n];
        int[] endTime = new int[n];
        int[] profit = new int[n];
        for (int i = 0; i < n; i++) {
            startTime[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            endTime[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            profit[i] = sc.nextInt();
        }
        System.out.println(jobScheduling(startTime, endTime, profit));
    }
}