import java.util.Scanner;

public class SimpleCalc {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("a: ");
        int a = input.nextInt();
        System.out.println("b: ");
        int b = input.nextInt();

        System.out.println("operation (+, -, /, *): ");
        char op = input.next().charAt(0);

        switch (op) {
            case '+':
                System.out.println(a + b);
                break;
            case '-':
                System.out.println(a - b);
                break;
            case '/':
                if (b == 0) {
                    System.out.println("invalid division");
                } else {
                    System.out.println(a / b);
                }
                break;
            case '*':
                System.out.println(a * b);
                break;
            default:
                System.out.println("not a valid operation");
        }

        input.close();
    }
}
