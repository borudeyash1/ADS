public class SmallestNumberWithTrailingZeros {

    public static int findSmallestNumber(int n) {
        if (n == 0) {
            return 0;
        }
        int low = 0;
        int high = 5 * n; 
        int answer = 0;
        
while (low <= high) {
    int mid = low + (high - low) / 2;
        int zeros = countLastZeroes(mid);
            
            if (zeros >= n) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }
    
    private static int countLastZeroes(int num) {
        int count = 0;
        while (num > 0) {
            num /= 5;
            count += num;
        }
        return count;
    }

    public static void main(String[] args) {
        int n = 5; 
        int result = findSmallestNumber(n);
        System.out.println("The smallest number with at least " + n + " trailing zeroes in its factorial is: " + result);
    }
}