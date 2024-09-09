
import java.util.Scanner;

public class PrimeNum {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();

        if (num < 2) {
            System.out.println("not a prime!");
            return;
        }

        int count = 0;
        for (int i = 1; i < num / 2; i++) {
            if (num % i == 0) {
                count++;
            }
        }

        if (count > 2) {
            System.out.println("not a prime!");
        } else {
            System.out.println("prime!");
        }

    }
}
