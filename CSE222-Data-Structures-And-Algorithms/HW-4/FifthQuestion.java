/**
 * Fifth Question class implementations.
 * 
 * @author Serhat Sarı
 * @since 1-04-2022
 * 
 */

/**
 * Given an array of integers, find all possible configurations of the array
 */
public class FifthQuestion {

    /**
     * Given an array of integers, find all possible configurations of the array
     * 
     * @param arr the array of integers
     */
    public static void findPossibleConfigs(int[] arr) {

        findPossibleConfigs(arr, 0);

    }

    /**
     * Find all possible configurations of the given array
     * 
     * @param arr   the array of bits that represent the possible configurations
     * @param index The index of the current element in the array.
     */
    private static void findPossibleConfigs(int[] arr, int index) {
        if (arr == null) {
            return;

        } else if (arr.length < 3) {
            return;

        } else if (index == arr.length) {

            checkAndPrint(arr, 0, 0);
            return;

        } else {

            arr[index] = 0;
            findPossibleConfigs(arr, index + 1);

            arr[index] = 1;
            findPossibleConfigs(arr, index + 1);

        }

    }

    /**
     * 
     * @param arr       the array to check
     * @param index     The current index of the array we're looking at.
     * @param consecNum the number of consecutive ones in the current subarray.
     */
    private static void checkAndPrint(int[] arr, int index, int consecNum) {

        if (index == arr.length) {
            printArr(arr, 0);
            return;
        } else if (arr[index] == 1) {
            if (index + 3 > arr.length && consecNum == 0) {
                return;
            }
            consecNum++;
            checkAndPrint(arr, index + 1, consecNum);
        } else if (arr[index] == 0) {
            if (consecNum > 0 && consecNum < 3) {
                return;
            }
            consecNum = 0;
            checkAndPrint(arr, index + 1, consecNum);
        }
    }

    /**
     * Prints the array in a format that is easy to read
     * 
     * @param arr   the array to be printed
     * @param index The current index of the array that we're printing.
     */
    private static void printArr(int[] arr, int index) {
        if (index == arr.length) {
            System.out.println("");
            return;
        } else if (arr[index] == 1) {
            System.out.print("X");
            printArr(arr, index + 1);

        } else if (arr[index] == 0) {
            System.out.print("O");
            printArr(arr, index + 1);
        }
    }

}
