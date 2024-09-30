import java.util.Arrays;

public class SecondLargest {
    public static void main(String[] args) {
        int arr[] = { 1, 2, 3, 4, 5, 6, 7, 7, 7,7,7,7,7,6,8 };
        Arrays.sort(arr);
        int secondLargest = 0;

        System.out.println(arr.toString());

        for (int i = arr.length - 1; i > 0; i--) {
            if (arr[i] != arr[i-1]) {
                secondLargest = arr[i-1];
                break;
            }
        }

        System.out.println(secondLargest);
    }
}
