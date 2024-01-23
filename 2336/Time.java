import java.util.Scanner;

public class Time {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.print("enter secs");
        int secs = input.nextInt();

        int mins = secs / 60;
        secs %= 60;

        System.out.println(mins + " " + secs);
        input.close();
    }
}