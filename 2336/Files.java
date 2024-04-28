
//yisak worku yxw190038
import java.io.File;
import java.util.Scanner;

public class Files {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);// input scanner
        System.out.println("Please enter the directory name with full path:");// print prompt
        String directoryPath = scanner.nextLine();// take next line input

        File directory = new File(directoryPath);// make new folder object to look for
        while (!directory.isDirectory()) {// if it doesn't exit
            System.out.println("Error: The provided path is not a directory.");// error
            System.out.println("Please retype a directory name with full path (e.g., C:\\public\\myname):");// and reprompt
            directoryPath = scanner.nextLine();// take new input
            directory = new File(directoryPath);// and look for new folder
        }

        File[] files = directory.listFiles();// make an arry of all files in the folder
        if (files != null) {// if not empty
            long totalSize = 0;// set size 0
            for (File file : files) {// for each file
                System.out.println("File: " + file.getName() + ", Size: " + file.length() + " bytes");// print name and size
                totalSize += file.length();// and add size to the total
            }
            System.out.println("Total size of all files: " + totalSize + " bytes");// print total
        } else {
            System.out.println("The directory is empty.");// print is empty
            scanner.close();// close scanner
        }
    }
}