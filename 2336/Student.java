public class Student {

    private String name;
    private String college;
    private Double currentGpa;
    private int[] weeklyHoursOfSleep;
    private Boolean isTired;

    public Student() {
        name = null;
        college = null;
        currentGpa = 0.0;
        weeklyHoursOfSleep = new int[] { 0, 0, 0, 0, 0, 0, 0 };
        isTired = false;
    }

    public Student(String name, String college, double currentGpa, int[] weeklyHoursOfSleep, boolean isTired) {
        this.name = name;
        this.college = college;
        this.currentGpa = currentGpa;
        for (int i = 0; i < 7; i++) {
            this.weeklyHoursOfSleep[i] = weeklyHoursOfSleep[i];
        }
        this.isTired = isTired;
    }

    public String getName() {
        return name;
    }

    public String getCollege() {
        return college;
    }

    public double getCurrentGpa() {
        return currentGpa;
    }

    public int[] getWeeklyHoursOfSleep() {
        return weeklyHoursOfSleep;
    }

    public boolean getIsTired() {
        return isTired;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setCollege(String college) {
        this.college = college;
    }

    public void setCurrentGpa(double currentGpa) {
        this.currentGpa = currentGpa;
    }

    public void setWeeklyHoursOfSleep(int[] weeklyHoursOfSleep) {
        for (int i = 0; i < 7; i++) {
            this.weeklyHoursOfSleep[i] = weeklyHoursOfSleep[i];
        }
    }

    public void setIsTired(boolean isTired) {
        this.isTired = isTired;
    }

    public String dayOfLeastSleep() {
        String[] day = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
        int j = 0;
        for (int i = 0; i < 7; i++) {
            if (this.weeklyHoursOfSleep[i] < this.weeklyHoursOfSleep[j]) {
                j = i;
            }
        }
        return day[j];
    }

    public int totalHoursSlept() {
        int sum = 0;
        for (int i = 0; i < 7; i++) {
            sum += this.weeklyHoursOfSleep[i];
        }
        return sum;
    }
}
