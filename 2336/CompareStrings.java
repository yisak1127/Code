import java.util.Scanner;

public class CompareStrings {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String City1 = input.nextLine();
        String City2 = input.nextLine();

        if (City2.compareTo(City1) > 40) {
            System.out.println(City1 + " " + City2);

        } else
            System.out.println(City2 + " " + City1);

        input.close();
    }
}
