import java.util.Scanner;

public class QueueMain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Queue q = new Queue(5);
        int choice = 0;

        while (choice != 4) {
            System.out.print("\n1.Add\n" + "2.Delete\n" + "3.Print\n" + "4.Exit\n" + "Choose Operation: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value: ");
                    int value = sc.nextInt();
                    q.enqueue(value);
                    break;
                case 2:
                    q.dequeue();
                    break;
                case 3:
                    q.print();
                    break;
                case 4:
                    choice = 5;
                    break;
                default:
                    System.out.println("Invalid Operation");
                    break;
            }
        }
    }
}
