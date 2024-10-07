public class MissingNumber {
    public static void main(String[] args) {
        int[] nums = { 3, 0, 1, 4, 6, 2 };
        System.out.println("Missing: " + getMissingNum(nums));
    }

    public static int getMissingNum(int[] nums) {
        int n = nums.length;
        int trueSum = n * (n + 1) / 2;

        int arrSum = 0;
        for (int num : nums) {
            arrSum += num;
        }

        return trueSum - arrSum;
    }
}
