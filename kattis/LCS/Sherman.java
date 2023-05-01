import java.util.List;
import java.util.ArrayList;
import java.util.HashSet;
public class Sherman {
    static class TestCase {
        int n;
        int [][] finalEdges;
        public TestCase(int n, int... edges) {
            this.n = n;
            if(edges.length % 2 != 0) {
                throw new RuntimeException("Bad Example");
            }
            this.finalEdges = new int[edges.length / 2][2];
            for(int i = 0; i < edges.length; i++) {
                if(edges[i] >= n || edges[i] < 0) {
                    throw new RuntimeException("Out of bounds");
                }
                this.finalEdges[i/2][i%2] = edges[i];
                if(i%2 == 1) {
                    if(edges[i] == edges[i-1]) {
                        throw new RuntimeException("Circular Edge");
                    }

                    if(edges[i-1] > edges[i]) {
                        int temp = this.finalEdges[i/2][1];
                        this.finalEdges[i/2][1] = this.finalEdges[i/2][0];
                        this.finalEdges[i/2][0] = temp;
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        List<TestCase> allTests = new ArrayList<>();
        allTests.add(new TestCase(2, 0,1)); //A-B
        allTests.add(new TestCase(3, 0,1, 1,2)); //A-B-C
        allTests.add(new TestCase(4, 0,1, 1,2, 3,2));//A-B-C-D
        allTests.add(new TestCase(3, 1,2, 1,0, 2,0));//3 nodes linked all together
        allTests.add(new TestCase(4, 3,0, 2,0, 1,0));//3 nodes linked to one central node No.0
        allTests.add(new TestCase(4, 3,0, 1,0));//Remove one node from the case above
        allTests.add(new TestCase(4, 1,2, 1,3, 1,0));//3 nodes linked to one central node No.1
        allTests.add(new TestCase(4, 1,3, 1,0));//Remove one node from case above
        allTests.add(new TestCase(4, 1,3));//4 nodes, 2 of them linked together
        for(TestCase test : allTests) {
            int groundTruth = directSolve(test.n, test.finalEdges);
            if ( indirectSolve(test.n, test.finalEdges) != groundTruth ) {
                System.out.println("Wrong algorithm");
                throw new RuntimeException();
            }
        }
    }

    public static int directSolve(int numOfVertices, int[][] edgeList)
    {
        ArrayList<Integer> vertices = new ArrayList<>();
        HashSet<String> edges = new HashSet<>();

        HashSet<ArrayList<Integer>> independentSets = new HashSet<>();
        for (int i = 0; i < numOfVertices; i++) {
            vertices.add(i);
        }
        for (int[] edge : edgeList) {
            edges.add(pairString(edge[0], edge[1]));
        }
        HashSet<Integer> SolnSet = new HashSet<>();

        // this function call adds all sets to the global
        // solution set
        findAllIndependentSets(1, numOfVertices, SolnSet, vertices, edges, independentSets);

        // to find the largest result set
        ArrayList<Integer> Max = new ArrayList<>();

        for (ArrayList<Integer> i : independentSets) {
            System.out.println(i);

            // comparing lengths of all
            // independent sets
            if (i.size() > Max.size())
                Max = i;
        }

        System.out.println("Maximal Independent Set = "
                + Max);
        return Max.size();
    }

    // this function finds all independent set s and adds them to the solution object
    static void findAllIndependentSets(int currentVertice, int setSize,
                                       HashSet<Integer> SolnSet,
                                       ArrayList<Integer> vertices,
                                       HashSet<String> edges,
                                       HashSet<ArrayList<Integer>> independentSets)
    {
        for (int i = currentVertice; i <= setSize; i++)
        {
            // checking if vertex is independent
            if (checkSafety(vertices.get(i - 1), SolnSet, edges)) {

                // adding to the temporary solution set
                SolnSet.add(vertices.get(i - 1));

                findAllIndependentSets(i + 1, setSize,
                        SolnSet, vertices,
                        edges, independentSets);

                // removing previous set
                SolnSet.remove(vertices.get(i - 1));
            }
        }

        // appending the temporary solution set to the
        // solution object
        independentSets.add(new ArrayList<Integer>(SolnSet));
    }

    // this function checks if there exists an edge between 2 vertices
    static boolean checkSafety(int vertex,
                               HashSet<Integer> SolnSet,
                               HashSet<String> edges) {
        for (int i : SolnSet) {
            if (edges.contains(pairString(i, vertex)))
                return false;
        }
        return true;
    }
    static String pairString(int a, int b) {
        int lower = Math.min(a,b);
        int higher = Math.max(a,b);
        return (new StringBuilder()).append(lower).append(',').append(higher).toString();
    }

    //Key algorithm begins here:
    public static int indirectSolve(int n, int[][] edges) {
        List<String> strings = new ArrayList<>();
        strings.add(generateBase(n));
        for (int[] edge : edges) {
            strings.add(generateEdge(n, edge[0], edge[1]));
        }
        String[] values = strings.toArray(new String[0]);
        for(int i = 0 ; i < values.length; i++) {
            System.out.println(values[i]);
        }

        String output = lcs(values);
        System.out.println(output);
        System.out.println(output.length());
        System.out.println(output.length() - n*n);
        return output.length() - n*n;
    }
    public static String generateBase(int n) {
        return ("0".repeat(n) + "1").repeat(n);
    }
    public static String generateEdge(int n, int u, int v) {
        //Note: this section of the code is taken from the original source for Q2:
        //  "Hardness of Longest Common Subsequence for Sequences with Bounded Run-Lengths"
        StringBuilder builder = new StringBuilder();
        for(int i = 0; i < n+1; i++) {
            for(int j = 0; j < n; j++) {
                builder.append(0);
            }
            if ((i != u && i != v+1)) { //TODO: Understand why its v+1 rather than v that we exclude the 1.
                builder.append(1);
            }
        }
        final int desiredLength = (n+1) * (n+1) - 2;
        boolean validString = builder.length() == desiredLength;
        if(!validString) {
            throw new RuntimeException("Bad Algorithm");
        }
        return builder.toString();
    }
    //Key algorithm ends.
    public static String lcs(String[] strings) {
        if (strings.length == 0)
            return "";
        if (strings.length == 1)
            return strings[0];
        int max = -1;//max length of a string
        int cacheSize = 1; //multiplied length size of array with each other.
        for (int i = 0; i < strings.length; i++) {
            cacheSize *= strings[i].length();
            if (strings[i].length() > max)
                max = strings[i].length();
        }
        String[] cache = new String[cacheSize];
        int[] indexes = new int[strings.length];
        for (int i = 0; i < indexes.length; i++)
            indexes[i] = strings[i].length() - 1;
        return lcsBack(strings, indexes, cache);
    }

    public static String lcsBack(String[] strings, int[] indexes, String[] cache) {
        for (int i = 0; i < indexes.length; i++)
            if (indexes[i] == -1)
                return "";
        boolean match = true;
        for (int i = 1; i < indexes.length; i++) {
            if (strings[0].charAt(indexes[0]) != strings[i].charAt(indexes[i])) {
                match = false;
                break;
            }
        }
        if (match) {
            int[] newIndexes = new int[indexes.length];
            for (int i = 0; i < indexes.length; i++)
                newIndexes[i] = indexes[i] - 1;
            String result = lcsBack(strings, newIndexes, cache) + strings[0].charAt(indexes[0]);
            cache[calcCachePos(indexes, strings)] = result;
            return result;
        } else {
            String[] subStrings = new String[strings.length];
            for (int i = 0; i < strings.length; i++) {
                if (indexes[i] <= 0)
                    subStrings[i] = "";
                else {
                    int[] newIndexes = new int[indexes.length];
                    for (int j = 0; j < indexes.length; j++)
                        newIndexes[j] = indexes[j];
                    newIndexes[i]--;
                    int cachePos = calcCachePos(newIndexes, strings);
                    if (cache[cachePos] == null)
                        subStrings[i] = lcsBack(strings, newIndexes, cache);
                    else
                        subStrings[i] = cache[cachePos];
                }
            }
            String longestString = "";
            int longestlength = 0;
            for (int i = 0; i < subStrings.length; i++) {
                if (subStrings[i].length() > longestlength) {
                    longestString = subStrings[i];
                    longestlength = longestString.length();
                }
            }
            cache[calcCachePos(indexes, strings)] = longestString;
            return longestString;
        }
    }

    static int calcCachePos(int[] indexes, String[] strings) {
        int factor = 1;
        int pos = 0;
        for (int i = 0; i < indexes.length; i++) {
            pos += indexes[i] * factor;
            factor *= strings[i].length();
        }
        return pos;
    }
}