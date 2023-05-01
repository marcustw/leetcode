import java.util.*;

class Solution2 {

    static class Pair {
        int a;
        int b;

        Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public String toString() {
            return String.format("[%d:%d]", a, b);
        }
    }


    private static Pair parseSingle(String s) {
        String[] split = s.split(":");

        String first = split[0].replaceAll("[\\[\\]]", "");
        String second = split[1].replaceAll("[\\[\\]]", "");

        return new Pair(Integer.parseInt(first), Integer.parseInt(second));
    }

    private static List<Pair> intervalMerge(List<Pair> pairs) {
        pairs.sort((p1, p2) -> (p1.a - p2.a));

        int q = pairs.get(0).a;
        int k = pairs.get(0).b;

        List<Pair> result = new ArrayList<>();

        for (int i = 0; i < pairs.size(); i++) {
            Pair p = pairs.get(i);
            if (p.a >= q && p.a <= k) {
                k = Math.max(p.b, k);
            } else {
                result.add(new Pair(q, k));
                q = p.a;
                k = p.b;
            }
        }
        result.add(new Pair(q, k));
        return result;
    }


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

        String input = in.nextLine();

        if (input.equals("[]")) {
            System.out.println(input);
        } else {
            String[] split = input.split(",");

            List<Pair> l = new ArrayList<>();

            for (String x : split) {
                l.add(parseSingle(x));
            }

            List<Pair> res = intervalMerge(l);
            String resString = "[";
            for (int i = 0; i < res.size(); i++) {
                resString += res.get(i).toString();
                resString += ",";
            }
            resString = resString.substring(0, resString.length() - 1);
            resString += "]";
            System.out.println(resString);
        }

    }
} 
