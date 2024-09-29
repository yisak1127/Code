//Yisak Worku y5xw190038
//CS 3345.503
//A java program using Sieve of Erotosthenes to compute all prime numbers less than or equal to  N20.
import java.util.Scanner;

public class Primes {

    public static void main(String[] args) {

        System.out.println("Input: an integer n > 1.");// print input prompt for n

        Scanner input = new Scanner(System.in);// make new input scanner
        int N = input.nextInt();// max integer checked for prime

        boolean[] A = new boolean[N - 1];// bool array from 2 to N

        for (int i = 0; i < A.length; i++) {// loop through the whole array
            A[i] = true;// and initialize to true
        }

        for (int i = 2; i <= Math.sqrt(N); i++) {// loop through 2 to sqrt(N)

            if (A[i - 2]) {// if index is prime/ true
                for (int j = i * i; j <= N; j += i)// loop through multiples of currnt prime starting at prime squared
                    A[j - 2] = false;// and set them false/ not prime
            }

        }

        for (int i = 2; i <= N; i++) {// loop from 2 to n
            if (A[i - 2]) { // if index is true
                System.out.print(i + ", ");// print all numbers still true
            }

        }

        input.close(); // close scanner

    }
}