import java.util.stream.Stream;
import java.util.stream.IntStream;

public class StreamLab {

    static long countRepeats(int... x) {

        return IntStream.rangeClosed(1, x.length - 2).reduce(0, (a, b) -> {
            a += (x[b] == x[b + 1] && x[b] != x[b-1] ? 1 : 0);
            return a;
        });
    }


    public static void main(String[] args) {
        System.out.println(countRepeats(0, 1, 1, 2, 2, 1, 1, 3));
    }
}
