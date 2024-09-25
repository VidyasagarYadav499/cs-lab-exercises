
import java.util.Scanner;

public class sumOfNums {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();

        System.out.println("sum: " + (a + b));

        input.close();
    }
}
