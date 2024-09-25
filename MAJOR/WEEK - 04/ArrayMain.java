
import java.util.Scanner;

public class ArrayMain {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int arr[] = { 2, 5, 10, 45, 100, 200, 456 };
        System.out.println("arr[] = {2, 5, 10, 45, 100, 200, 456};");

        int exit = 1;
        while (exit != 0) {
            System.out.println("Choose Operation(integer): " + "\n" + " 1. sum" + "\n" + " 2. Average" + "\n"
                    + " 3. min" + "\n" + " 4. max" + "\n" + " 5. exit");
            int op = input.nextInt();

            switch (op) {
                case 1:
                    System.out.println("sum: " + ArrayOperations.sum(arr) + "\n");
                    break;
                case 2:
                    System.out.println("Average: " + ArrayOperations.Average(arr) + "\n");
                    break;
                case 3:
                    System.out.println("Min: " + ArrayOperations.min(arr) + "\n");
                    break;
                case 4:
                    System.out.println("Max: " + ArrayOperations.max(arr) + "\n");
                    break;
                case 5:
                    exit = 0;
                    break;
                default:
                    System.out.println("Invalid operation" + "\n");
                    break;
            }

            input.close();

        }
    }
}
