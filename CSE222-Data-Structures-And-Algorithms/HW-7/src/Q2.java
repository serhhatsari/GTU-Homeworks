package src;

import src.tree.BinarySearchTree;

public class Q2 {

  /**
   * The function takes a BST as input and converts it to an AVL tree by performing a post-order
   * traversal of the BST and then returning the AVL tree
   *
   * @param tree The BinarySearchTree to be converted to an AVL tree.
   * @return The tree itself.
   */
  public static <E extends Comparable<E>> BinarySearchTree<E> convertBSTtoAVL(
    BinarySearchTree<E> tree
  ) {
    tree.postOrderTraverseForConverting();
    return tree;
  }
}
