public class MergeTwoSortedArrays {
    public static void main(String[] args) {
        // Array 1.
        int[] a = {1, 2, 3, 4, 7, 12, 30};
        // Array 2.
        int[] b = {7, 8, 9, 10, 11, 12};
        // Index i pointing to the end of array a.
        int i = a.length - 1;
        // Index j pointing to the end of array b.
        int j = b.length - 1;
        // Array 3 that will contain the sorted and merged elements of both array 1 and array 2.
        int[] c = new int[a.length + b.length];
        // Index k pointing at the end of array c.
        int k = c.length - 1;

        // Keep putting the largest element at the end of array c untill one of indices: i or j exhausts.
        while (i >= 0 && j >= 0) {
            if (a[i] > b[j]) {
                c[k] = a[i];
                i--;
                k--;
            }else if(a[i] == b[j]){
                c[k] = a[i];
                i--;
                k--;
            }else{
                c[k] = b[j];
                j--;
                k--;
            }
        }

        // index j exhausted first.
        while(i >= 0){
            c[k] = a[i];
            i--;
            k--;
        }

        // Index i exhausted first.
        while(j >= 0){
            c[k] = b[j];
            j--;
            k--;
        }

        // prints array c.
        for (int num : c){
            System.out.print(num + " ");
        }
    }
}
