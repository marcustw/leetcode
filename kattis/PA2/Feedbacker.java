import java.util.ArrayList;
import java.util.List;

public class Feedbacker {

    List<Console> consoles = new ArrayList<>();

    void feedback(String fb) {
        consoles.stream().forEach((x) -> x.feedback(fb));
    }
}
