public class Fibonaccci {

    public static void main(String[] args) {
        int n = 10;
        for (int i = 0; i < n; i++) {
            System.out.println(fsequence(i));
        }
    }

    private static int fsequence(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            return fsequence(n - 1) + fsequence(n - 2);
        }
    }
}
