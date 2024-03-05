import java.util.Scanner;

public class Factorial {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("enter N");
        int N = input.nextInt();
        N = factorial(N);
        System.out.println(N);
        input.close();

    }

    public static int factorial(int n) {

        if (n == 0) {
            return 1;
        }

        return n * factorial(n - 1);

    }
}
