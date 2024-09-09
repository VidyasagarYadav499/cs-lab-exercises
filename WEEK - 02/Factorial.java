
import java.util.Scanner;

public class Factorial {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int fac = 1;

        for (int i = 1; i <= n; i++) {
            fac = fac * i;
        }

        System.out.println(fac);
    }
}
