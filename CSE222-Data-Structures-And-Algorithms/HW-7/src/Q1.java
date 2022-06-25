package src;

import java.util.Arrays;
import src.tree.BinaryTree;

public class Q1 {

  public static <E extends Comparable<E>> void sortArray(E[] arr) {}

  /**
   * > We sort the array, then we traverse the tree in order, and we insert the elements of the array
   * into the tree
   *
   * @param tree The tree to build.
   * @param arr The array of elements to be inserted into the tree.
   * @return A BinaryTree<E>
   */
  public static <E extends Comparable<E>> BinaryTree<E> buildBinarySearchTree(
    BinaryTree<E> tree,
    E[] arr
  ) {
    Arrays.sort(arr);
    tree.inOrderTraverseWithSortedArray(arr);
    return tree;
  }
}
