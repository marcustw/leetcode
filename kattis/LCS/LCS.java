import java.util.ArrayList;

public class LCS {
    public static String formX(int u, int v, int n) {
        StringBuilder zeron = new StringBuilder();
        for (int i = 0; i < n; i++) {
            zeron.append(0);
        }
        StringBuilder zeron1 = new StringBuilder(zeron);
        zeron.append("  ");
        zeron1.append(1);
        zeron1.append(" ");
        StringBuilder result = new StringBuilder();
        for (int i = u-1; i > 0; i--) {
            result.append(zeron1);
        }
        result.append(zeron);
        for (int i = v - u; i > 0; i--) {
            result.append(zeron1);
        }
        result.append(zeron);
        for (int i = n - v; i > 0; i--) {
            result.append(zeron1);
        }
        return result.toString();
    }

    public static String formX0(int n) {
        StringBuilder zeron = new StringBuilder();
        for (int i = 0; i < n; i++) {
            zeron.append(0);
        }
        StringBuilder zeron1 = new StringBuilder(zeron);
        zeron1.append(1 + " ");
        StringBuilder result = new StringBuilder();
//        for (int i = 0; i < n+2; i++) {
//            result.append(" ");
//        }
        for (int i = 0; i < n; i++) {
            result.append(zeron1);
        }
        return result.toString();
    }

    public static void main(String[] args) {
        int n = 5;
        int m = 6;
        int[] edges = {1,2, 2,3, 2,5, 3,4, 3,5, 1,4};
        //input edges[i] = u, edges[i+1] = v
        ArrayList<String> strings = new ArrayList<>();
        strings.add(formX0(n));
        for (int i = 0; i < edges.length; i+= 2) {
            int u = edges[i];
            int v = edges[i+1];
            strings.add(formX(u, v, n));
        }
        for (String xi : strings) {
            System.out.println(xi);
        }
    }
}
