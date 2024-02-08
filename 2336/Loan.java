//Yisak Worku Yxw190038

import java.util.Scanner;

public class Loan {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);// make new input scanner
        System.out.println("Input Annual Intrest Rate");
        double intrest = input.nextDouble();// input intrest
        System.out.println("Input Years");
        int years = input.nextInt();// input years
        System.out.println("Input Loan Amount");
        int loan = input.nextInt();// input loan amount
        intrest /= 12;// convert apr into monthlly intrest rate
        double monthly = loan * intrest / (1 - 1 / Math.pow((1 + intrest), years * 12));// calcutate monthly payments
        System.out.printf("$%.2f per month\n", monthly);// print monthly payments
        System.out.printf("$%.2f total\n", monthly * years * 12);// print total payment
        input.close();// close input
    }
}
