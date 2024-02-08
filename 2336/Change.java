//Yisak Worku Yxw190038

import java.util.Scanner;

public class Change {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);// make new input scanner
        System.out.println("Input conversion amount:");
        double money = input.nextDouble();// input money
        int cents = 100;// cents
        cents *= money;// convert dollars in to cents
        int dollor = cents / 100;// split cents into dollars
        cents -= dollor * 100;// remove dollars
        int quarter = cents / 25;// split cents into quarters
        cents -= quarter * 25;// remove quarters
        int dime = cents / 10;// split cents into dimes
        cents -= dime * 10;// remove dimes
        int nickel = cents / 5;// split cents into nickels
        cents -= nickel * 5;// remove nickels
        int pennies = cents;// only pennies remain
        System.out.println(dollor + " 1-Dollor bills\n" + quarter + " Quarters\n" + dime + " Dimes\n" + nickel
                + " Nickels\n" + pennies + " Pennies\n");// print the conversion
        input.close();// close input
    }
}
