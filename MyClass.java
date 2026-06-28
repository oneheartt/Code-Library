import java.util.*;
import java.nio.file.Paths;
import static java.lang.System.out;

public class MyClass{
    public static void main(String[] args) {
        Pet lucy = new Pet("Lucy", "golden retriever");
        Person leo = new Person("Leo", lucy);

        System.out.println(leo);
    }
}