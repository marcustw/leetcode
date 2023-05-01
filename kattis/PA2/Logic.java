import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Logic {
    private List<Console> consoles = new ArrayList<>();

    void addConsole(Console c) {
        consoles.add(c);
    }

    void invoke(String command) {
        //do something

        consoles.stream().forEach((x) -> x.feedback(command));
    }

}
