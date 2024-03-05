//Yxw190038
import java.util.Scanner;

public class Fibonacci {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);// make new input scanner

        int f = input.nextInt();// N th fibonacci
        int counter = fib(f);// set counter to the return value of fibonacci function
        System.out.println(counter);// print fibonacci
        input.close(); // close scanner
    }

    public static int fib(int f) {
        if (f == 1) {// if Nth is 1 return 0
            return 0;
        } else if (f == 2) {// if Nth is 2 return 1
            return 1;
        }

        return fib(f - 1) + fib(f - 2);// recursive fibonacci function
    }
}
