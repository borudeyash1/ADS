public class ZeroMover {

    // Moves all zeroes to the end while preserving non-zero order
    public static void shiftZeroesToEnd(int[] nums) {
        if (nums == null || nums.length == 0) return;
        
        sortAndShift(nums, 0, nums.length - 1);
    }

    // Recursive divide-and-conquer sorting with zero handling
    private static void sortAndShift(int[] nums, int start, int end) {
        if (start < end) {
            int mid = start + (end - start) / 2;
            sortAndShift(nums, start, mid);
            sortAndShift(nums, mid + 1, end);
            combineArrays(nums, start, mid, end);
        }
    }

    // Merges two subarrays while prioritizing non-zero elements
    private static void combineArrays(int[] nums, int start, int mid, int end) {
        // Create temporary arrays for left and right halves
        int[] leftHalf = new int[mid - start + 1];
        int[] rightHalf = new int[end - mid];
        
        // Copy data to temporary arrays
        System.arraycopy(nums, start, leftHalf, 0, leftHalf.length);
        System.arraycopy(nums, mid + 1, rightHalf, 0, rightHalf.length);

        int leftIdx = 0, rightIdx = 0, mergedIdx = start;

        // Merge with zero handling
        while (leftIdx < leftHalf.length && rightIdx < rightHalf.length) {
            // Prefer non-zero elements from either array
            if (leftHalf[leftIdx] != 0) {
                nums[mergedIdx++] = leftHalf[leftIdx++];
            } else if (rightHalf[rightIdx] != 0) {
                nums[mergedIdx++] = rightHalf[rightIdx++];
            } else {
                // Both are zero, take from left first
                nums[mergedIdx++] = leftHalf[leftIdx++];
                rightIdx++;
            }
        }

        // Copy remaining elements from left half
        while (leftIdx < leftHalf.length) {
            nums[mergedIdx++] = leftHalf[leftIdx++];
        }

        // Copy remaining elements from right half
        while (rightIdx < rightHalf.length) {
            nums[mergedIdx++] = rightHalf[rightIdx++];
        }
    }

    public static void main(String[] args) {
        int[] numbers = {1, 2, 0, 4, 3, 0, 5, 0};
        shiftZeroesToEnd(numbers);
        
        System.out.print("Modified array: [");
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(numbers[i]);
            if (i < numbers.length - 1) System.out.print(", ");
        }
        System.out.println("]");
    }
}