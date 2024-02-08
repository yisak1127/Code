import java.util.Scanner;

public class GCD {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num1 = input.nextInt();
        int num2 = input.nextInt();
        int remain = 0;
        if (num2 > num1) {
            remain = num1;
            num1 = num2;
            num2 = remain;

        }

        do {
            remain = num1 % num2;
            num1 = num2;
            num2 = remain;
        } while (remain != 0);
        System.out.println(num1);
        input.close();
    }
}