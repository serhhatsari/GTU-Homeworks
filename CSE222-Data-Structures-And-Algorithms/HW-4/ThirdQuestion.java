import java.util.ArrayList;

/**
 * Third Question class implementations.
 * 
 * @author Serhat Sarı
 * @since 1-04-2022
 * 
 */

public class ThirdQuestion {

    /**
     * Given an array of integers, find all subarrays that sum to a given integer
     * 
     * @param arr      the array to search
     * @param givenInt The integer we're looking for.
     */
    public static void findSubs(int[] arr, int givenInt) {

        findSubArrays(arr, givenInt, 0, 0, 0, new ArrayList<>());

    }

    /**
     * Given an array of integers, find all subarrays that sum to a given integer
     * 
     * @param arr         the array to search
     * @param givenInt    The sum we are looking for
     * @param index       The index of the first element in the array.
     * @param secondIndex The index of the second element in the subarray.
     * @param sum         The sum of the subarray.
     * @param sub         the subarray that is being built
     */
    private static void findSubArrays(int[] arr, int givenInt, int index, int secondIndex,
            int sum,
            ArrayList<Integer> sub) {

        if (arr == null) {
            System.out.println("");
            return;
        } else if (index == arr.length || secondIndex == arr.length) {

            if (sum == givenInt) {
                System.out.println(sub);
                sub.clear();
                sum = 0;
                findSubArrays(arr, givenInt, index + 1, index + 1, sum, sub);
            } else {
                return;
            }
        } else if (sum == givenInt) {
            System.out.println(sub);
            sub.clear();
            sum = 0;
            findSubArrays(arr, givenInt, index + 1, index + 1, sum, sub);
        } else if (sum > givenInt) {
            sub.clear();
            sum = 0;
            findSubArrays(arr, givenInt, index + 1, index + 1, sum, sub);
        } else {
            int num = arr[secondIndex];

            sub.add(num);

            sum = sum + num;

            findSubArrays(arr, givenInt, index, secondIndex + 1, sum, sub);
        }

    }

}
