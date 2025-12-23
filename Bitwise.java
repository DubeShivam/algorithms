public class Bitwise {

    // Find if the given number is even or odd
    public static String isEvenOrOdd(int number) {
        if ((number & 1) == 0) {
            return "Even";
        } else {
            return "Odd";
        }
    }

    // Find the only non-repeating number in a given array
    public static int findNonRepeating(int[] arr) {
        int nonRepeating = 0;

        for(int num: arr) {
            nonRepeating ^= num;
        }
        return nonRepeating;
    }


    public static void main(String[] args) {

        System.out.println(isEvenOrOdd(2345));

    }
}
