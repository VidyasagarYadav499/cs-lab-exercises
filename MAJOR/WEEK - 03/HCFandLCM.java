
import java.util.Scanner;

public class HCFandLCM {

    public static void main(String[] args) {
        int hcf = 0, lcm;
        System.out.println("Enter two positive numbers:");
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();

        input.close();

        for (int i = 1; i <= a; i++) {
            if (a % i == 0 && b % i == 0) {
                hcf = i;
            }
        }

        lcm = (a * b) / hcf;
        System.out.println("LCM: " + lcm);
        System.out.println("HCF: " + hcf);

    }
}
