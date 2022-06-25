package SortingAlgorithms;

import java.util.ArrayList;

public class NewSort {

  // A recursive function that finds the min and max of the array and swaps them with the first and last
  // elements of the array.
  public static <T extends Comparable<T>> void sort(T[] table) {
    sort(table, 0, table.length - 1);
  }

  private static <T extends Comparable<T>> T[] sort(
    T[] table,
    int head,
    int tail
  ) {
    if (head > tail) return table;

    int[] min_max = new int[2];
    recursive_min_max_finder(table, head, tail, min_max);
    swap(table[head], table[min_max[0]]);
    swap(table[tail], table[min_max[1]]);
    return sort(table, head + 1, tail - 1);
  }

  /**
   * "If the array is of length 1, return the first and last indices. Otherwise, find the minimum and
   * maximum of the first half and the second half, and return the minimum of the two minimums and the
   * maximum of the two maximums."
   *
   * The function is recursive, and it takes in the array, the first index, the last index, and an array
   * of two elements. The first element of the array is the minimum index, and the second element is the
   * maximum index
   *
   * @param table the array to be searched
   * @param head the index of the first element in the array
   * @param tail the index of the last element in the array
   * @param min_max an array of two integers, the first one is the index of the minimum element, the
   * second one is the index of the maximum element.
   */
  private static void recursive_min_max_finder(
    Comparable[] table,
    int head,
    int tail,
    int[] min_max
  ) {
    if (head == tail) {
      min_max[0] = head;
      min_max[1] = tail;
      return;
    }

    int mid = (head + tail) / 2;
    recursive_min_max_finder(table, head, mid, min_max);
    recursive_min_max_finder(table, mid + 1, tail, min_max);

    if (table[min_max[0]].compareTo(table[mid + 1]) > 0) {
      min_max[0] = mid + 1;
    }
    if (table[min_max[1]].compareTo(table[mid]) > 0) {
      min_max[1] = mid;
    }
  }

  /**
   * "Swap the values of two variables."
   *
   * The function takes two parameters, a and b, and swaps their values
   *
   * @param a The first element to compare.
   * @param b the array to be sorted
   */
  private static <T extends Comparable<T>> void swap(T a, T b) {
    T temp = a;
    a = b;
    b = temp;
  }
}
