import java.util.Scanner;

public class Palindrome {
    public static void main(String[] args) {

        int rev = 0;
        System.out.println("Enter a number: ");
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        int numcopy = num;

        input.close();

        while (num != 0) {
            rev = rev * 10 + num % 10;
            num = num / 10;
        }

        if (numcopy == rev) {
            System.out.println("palindrome!");
        } else {
            System.out.println("not a palinrome!");
        }

    }
}
