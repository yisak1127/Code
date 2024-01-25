import java.util.Scanner;

public class ComputingTaxes {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int income = input.nextInt();
        double tax = 0;

        if (income > 82250) {

            tax = .10 * 8350;
            tax += (33950 - 8350) * .15;
            tax += (82250 - 33950) * .25;
            tax += .35 * (income - 82250);

        } else if (income > 33950) {

            tax += .10 * 8350;
            tax += (33950 - 8350) * .15;
            tax += .25 * (income - 33950);

        } else if (income > 8350) {

            tax = .10 * 8350;
            tax += .15 * (income - 8350);

        } else {

            tax = income * .10;

        }

        System.out.println(tax);
        input.close();

    }
}
