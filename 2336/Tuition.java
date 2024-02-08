// Yisak Worku Yxw190038

public class Tuition {
    public static void main(String[] args) {
        double tuition = 10000; // base tution
        double intrest = 1.07; // intrest rate
        int counter = 0;// year counter

        while (tuition < 20000) {// loop till tuition is doubled
            tuition *= intrest; // update tution with intrest
            counter++;// update years of intrest
        }
        System.out.println(counter + " Years Tuition"); // print years till tuitiom is doubled
    }
}
