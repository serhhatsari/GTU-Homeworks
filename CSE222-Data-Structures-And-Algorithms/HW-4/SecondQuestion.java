/**
 * Second Question class implementations.
 * 
 * @author Serhat Sarı
 * @since 1-04-2022
 * 
 */

public class SecondQuestion {

    /**
     * Recursive algorithm to find the number of itemsin the arraybetweentwo given
     * integer
     * values.
     * 
     * @param arr      the array to search
     * @param smallNum The smallest number in the array.
     * @param bigNum   The largest number in the array.
     * @return The number of elements in the interval.
     */
    public static int findInterval(int[] arr, int smallNum, int bigNum) {
        if (arr == null)
            return 0;
        return findInterval(arr, smallNum, bigNum, 0, arr.length - 1);
    }

    /**
     * Given an array of integers, find the number of intervals that are contained
     * within the given range.
     * 
     * @param arr      the array of integers
     * @param first    the first element of the interval
     * @param second   the value of the second element in the interval
     * @param firstInd the index of the first element in the array
     * @param lastInd  The last index of the array.
     * @return The number of intervals that are between the first and second
     *         numbers.
     */
    public static int findInterval(int[] arr, int first, int second, int firstInd, int lastInd) {
        if (firstInd > lastInd)
            return 0;
        else {
            int middle = (firstInd + lastInd) / 2;
            int compResult = (arr[middle] >= first && arr[middle] <= second) ? 1 : 0;

            if (compResult == 1) {

                return 1 + findInterval(arr, first, second, firstInd, middle - 1)
                        + findInterval(arr, first, second, middle + 1, lastInd);

            } else {

                return findInterval(arr, first, second, firstInd, middle - 1)
                        + findInterval(arr, first, second, middle + 1, lastInd);
            }

        }

    }

}
