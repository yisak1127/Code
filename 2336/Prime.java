//yxw190038
import java.util.Scanner;

public class Prime {
    public static void main(String[] args) {

        // Check if a number is prime
        Scanner input = new Scanner(System.in);// make new input scanner
        int numberToCheck = input.nextInt();// input money
        boolean isPrimeResult = isPrime(numberToCheck, (int) Math.sqrt(numberToCheck));
        System.out.println(numberToCheck + " is prime: " + isPrimeResult);
        input.close();
    }

    // Check if a number is prime using recursion
    public static boolean isPrime(int n, int divisor) {
        if (n <= 1) {
            return false;
        } else if (divisor == 1) {
            return true;
        } else if (n % divisor == 0) {
            return false;
        } else {
            return isPrime(n, divisor - 1);
        }
    }

   
}