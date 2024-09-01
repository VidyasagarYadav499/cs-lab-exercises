
public class SortAnArray {

    public static void main(String[] args) {
        int arr[] = {5, 67, 2, 3, 65, 7, 4};
        int[] arrSorted = ArrayOperations.bubbleSort(arr);

        for (int i : arrSorted) {
            System.out.println(i);
        }
    }

    
}
