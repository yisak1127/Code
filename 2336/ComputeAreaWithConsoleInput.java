import java.util.Scanner;

public class ComputeAreaWithConsoleInput {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.print("enter radius");
        int radius = input.nextInt();


        double area = radius * 3.14 * radius;

        System.out.println(area);
        input.close();
    }
}