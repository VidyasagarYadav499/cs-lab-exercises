import java.util.Scanner;

public class PrimeNumsInRange {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter start: ");
        int start = sc.nextInt();
        if (start < 2) start = 2;

        System.out.print("Enter end: ");
        int end = sc.nextInt();

        for (int i = start; i < end; i++) {
            if (isPrime(i)) {
                System.out.print(i + " ");
            }
        }
    }

    private static boolean isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }

        return true;
    }
}
