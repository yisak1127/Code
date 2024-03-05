// Yisak Worku Yxw190038

public class BubbleSort {

    public static void main(String[] args) {
        // Initialize an unsorted array of size 10
        int[] unsortedArray = {64, 34, 25, 12, 22, 11, 90, 88, 45, 67};

        // Print the unsorted array
        System.out.println("Unsorted Array:");
        for (int value : unsortedArray) {
            System.out.print(value + " ");
        }
        System.out.println();

        // Perform Bubble Sort
        bubbleSort(unsortedArray);

        // Print the sorted array
        System.out.println("\nSorted Array:");
        for (int value : unsortedArray) {
            System.out.print(value + " ");
        }
        System.out.println();
    }

    // Function to perform Bubble Sort
    static void bubbleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap arr[j] and arr[j+1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

}