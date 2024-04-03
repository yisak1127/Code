import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Student[] students = readStudentsFromFile("/home/yisak/Code/2336/student.txt");

        // Print total hours slept for each student
        for (Student student : students) {
            System.out.println(student.getName() + " slept for " + student.totalHoursSlept() + " hours this week.");
        }

        // Print least amount of sleep for each student in the week
        for (Student student : students) {
            System.out.println(student.getName() + "'s least sleep was on " + student.dayOfLeastSleep());
        }
    }

    public static Student[] readStudentsFromFile(String fileName) {
        Student[] students = null; // Initialize the array of students
        try {
            Scanner scanner = new Scanner(new File(fileName));
            // Read data and create Student objects
            StringBuilder studentData = new StringBuilder();
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                if (!line.isEmpty()) {
                    studentData.append(line).append("\n");
                } else {
                    // Process student data
                    Student student = createStudentFromString(studentData.toString());
                    // Reset StringBuilder for next student data
                    studentData = new StringBuilder();
                    // Add student to the array
                    students = addStudentToArray(students, student);
                }
            }
            // Process last student data
            if (studentData.length() > 0) {
                Student student = createStudentFromString(studentData.toString());
                students = addStudentToArray(students, student);
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return students;
    }

    public static Student createStudentFromString(String data) {
        String[] lines = data.split("\n");
        String name = lines[0];
        String college = lines[1];
        double gpa = Double.parseDouble(lines[2]);
        String[] sleepHoursStr = lines[3].split(" ");
        int[] sleepHours = new int[sleepHoursStr.length];
        for (int i = 0; i < sleepHoursStr.length; i++) {
            sleepHours[i] = Integer.parseInt(sleepHoursStr[i]);
        }
        boolean isTired = Boolean.parseBoolean(lines[4]);
        
        // Create and return Student object
        Student student = new Student();
        student.setName(name);
        student.setCollege(college);
        student.setCurrentGpa(gpa);
        student.setWeeklyHoursOfSleep(sleepHours);
        student.setIsTired(isTired);
        
        return student;
    }

    public static Student[] addStudentToArray(Student[] students, Student student) {
        if (students == null) {
            return new Student[]{student};
        } else {
            Student[] newStudents = new Student[students.length + 1];
            System.arraycopy(students, 0, newStudents, 0, students.length);
            newStudents[students.length] = student;
            return newStudents;
        }
    }
}