package NodeBH;

import java.util.NoSuchElementException;

/**
 * BinaryHeap is a BinaryTree that extends Binary Tree class
 *
 * @author Serhat Sarı
 * @version 1.0
 * @since 2022-04-10
 */

/**
 * BinaryHeap is a BinaryTree that extends Binary Tree class
 */
public class BinaryHeap<E extends Comparable<E>> extends BinaryTree<E> {

  // Data Fields
  private int nextNodeNumber;

  // Constructors
  public BinaryHeap() {
    super();
    nextNodeNumber = 0;
  }

  // Methods
  /**
   * If the tree is empty, create a new root node. Otherwise, find the parent node of the next node to be
   * added, and add the new node as the left child of the parent node if the parent node doesn't have a
   * left child, or as the right child of the parent node if the parent node doesn't have a right child
   *
   * @param item the item to be added to the heap
   * @return The root node of the tree.
   */
  public boolean offer(E item) {
    if (nextNodeNumber == 0) {
      root = new BinaryTree.Node<>(item, nextNodeNumber, null);
      nextNodeNumber++;
      return true;
    }

    int parentIndex = (nextNodeNumber - 1) / 2;
    Node<E> parentNode = findNodeFromNumber(root, parentIndex);

    if (parentNode.left == null) {
      parentNode.left = new BinaryTree.Node<>(item, nextNodeNumber, parentNode);
      nextNodeNumber++;
      reheapBottomToTop(parentNode.left);
    } else {
      parentNode.right =
        new BinaryTree.Node<>(item, nextNodeNumber, parentNode);
      nextNodeNumber++;
      reheapBottomToTop(parentNode.right);
    }

    return true;
  }

  /**
   * We find the last node in the heap, swap it with the root, then delete the last node and reheap the
   * tree
   *
   * @return The data of the root node.
   */
  public E remove() {
    if (root == null) {
      throw new NoSuchElementException();
    }

    if (root.left == null && root.right == null) {
      E returnedData = root.data;
      root = null;
      nextNodeNumber--;
      return returnedData;
    }

    E returnedVal = root.data;

    Node<E> lastNode = findNodeFromNumber(root, nextNodeNumber - 1);
    swap(root, lastNode);

    if (
      lastNode.parent.left != null &&
      lastNode.parent.left.nodeNumber == nextNodeNumber - 1
    ) {
      lastNode.parent.left = null;
    } else if (
      lastNode.parent.right != null &&
      lastNode.parent.right.nodeNumber == nextNodeNumber - 1
    ) {
      lastNode.parent.right = null;
    }

    reheapTopToBottom(root);

    nextNodeNumber--;

    return returnedVal;
  }

  /**
   * We remove the root node, swap it with the last node, and then reheapify the tree
   *
   * @return The data of the root node.
   */
  public E poll() {
    if (root == null) {
      throw null;
    }

    if (root.left == null && root.right == null) {
      E returnedData = root.data;
      root = null;
      nextNodeNumber--;
      return returnedData;
    }

    E returnedVal = root.data;

    Node<E> lastNode = findNodeFromNumber(root, nextNodeNumber - 1);
    swap(root, lastNode);

    if (
      lastNode.parent.left != null &&
      lastNode.parent.left.nodeNumber == nextNodeNumber - 1
    ) {
      lastNode.parent.left = null;
    } else if (
      lastNode.parent.right != null &&
      lastNode.parent.right.nodeNumber == nextNodeNumber - 1
    ) {
      lastNode.parent.right = null;
    }

    reheapTopToBottom(root);

    nextNodeNumber--;

    return returnedVal;
  }

  /**
   * If the root is null, return null, otherwise return the data of the root
   *
   * @return The data of the root node.
   */
  public E peek() {
    if (root == null) return null;

    return root.data;
  }

  /**
   * If the root is null, throw an exception. Otherwise, return the data of the root
   *
   * @return The data of the root node.
   */
  public E element() {
    if (root == null) throw new NoSuchElementException();

    return root.data;
  }

  /**
   * We create a new heap, and then we traverse both heaps in order, adding each element to the new heap
   *
   * @param otherHeap the other heap to merge with this heap
   * @return A new BinaryHeap with the elements of both this and otherHeap.
   */
  public BinaryHeap<E> merge(BinaryHeap<E> otherHeap) {
    BinaryHeap<E> newHeap = new BinaryHeap<>();

    Node<E> thisNode = root;
    Node<E> otherNode = otherHeap.root;

    inorderTraverse(thisNode, newHeap);
    inorderTraverse(otherNode, newHeap);

    return newHeap;
  }

  /**
   * It takes an item and increments its key.
   *
   * @param item the item to be incremented
   */
  public void incrementKey(E item, E newValue) {
    Node<E> node = findNodeFromData(root, item);
    if (node.data.compareTo(newValue) > 0) {
      System.out.println("The new value is smaller than the old value");
      return;
    }
    node.data = newValue;
    reheapTopToBottom(node);
  }

  /**
   * If the node is null, return. Otherwise, traverse the left subtree, add the node's data to the new
   * heap, and traverse the right subtree.
   *
   * @param node the node we're currently at
   * @param newHeap the new heap that we are building
   */
  private void inorderTraverse(Node<E> node, BinaryHeap<E> newHeap) {
    if (node == null) return;

    inorderTraverse(node.left, newHeap);
    newHeap.offer(node.data);
    inorderTraverse(node.right, newHeap);
  }

  /**
   * If the node is null, return null. If the node is the node we're looking for, return it. Otherwise,
   * return the result of calling this function on the left and right children
   *
   * @param node the node to start searching from
   * @param nodeNumber The node number of the node you want to find.
   * @return The node with the given nodeNumber.
   */
  private Node<E> findNodeFromNumber(Node<E> node, int nodeNumber) {
    if (node == null) {
      return null;
    }
    if (node.nodeNumber == nodeNumber) {
      return node;
    }
    Node<E> left = findNodeFromNumber(node.left, nodeNumber);
    if (left != null) {
      return left;
    }
    Node<E> right = findNodeFromNumber(node.right, nodeNumber);
    if (right != null) {
      return right;
    }
    return null;
  }

  /**
   * If the node is null, return null. If the node's data is the data we're looking for, return the node.
   * Otherwise, recursively search the left and right subtrees for the data
   *
   * @param node The node to start searching from.
   * @param data The data to search for.
   * @return The node that contains the data.
   */
  private Node<E> findNodeFromData(Node<E> node, E data) {
    if (node == null) {
      return null;
    }
    if (node.data == data) {
      return node;
    }
    Node<E> left = findNodeFromData(node.left, data);
    if (left != null) {
      return left;
    }
    Node<E> right = findNodeFromData(node.right, data);
    if (right != null) {
      return right;
    }
    return null;
  }

  /**
   * If the new node is smaller than its parent, swap the two nodes and recursively call
   * reheapBottomToTop on the parent
   *
   * @param newNode The node that was just added to the heap.
   */
  private void reheapBottomToTop(Node<E> newNode) {
    if (newNode == null) {
      return;
    }
    Node<E> parent = findNodeFromNumber(root, (newNode.nodeNumber - 1) / 2);

    if (parent == null) {
      return;
    }
    if (parent.data.compareTo(newNode.data) > 0) {
      swap(parent, newNode);
      reheapBottomToTop(parent);
    }
  }

  /**
   * If the new node has children, swap it with the smaller of the two children, and then recursively
   * reheap the child
   *
   * @param newNode the node that was just added to the heap
   */
  private void reheapTopToBottom(Node<E> newNode) {
    if (newNode == null) {
      return;
    }
    Node<E> firstChild = findNodeFromNumber(root, newNode.nodeNumber * 2 + 1);
    Node<E> secondChild = findNodeFromNumber(root, newNode.nodeNumber * 2 + 2);

    if (firstChild == null && secondChild == null) {
      return;
    }

    if (firstChild != null && secondChild != null) {
      if (firstChild.data.compareTo(secondChild.data) < 0) {
        swap(firstChild, newNode);
        reheapTopToBottom(firstChild);
      } else {
        swap(secondChild, newNode);
        reheapTopToBottom(secondChild);
      }
    } else if (firstChild != null) {
      if (firstChild.data.compareTo(newNode.data) < 0) {
        swap(firstChild, newNode);
        reheapTopToBottom(firstChild);
      }
    } else {
      if (secondChild.data.compareTo(newNode.data) < 0) {
        swap(secondChild, newNode);
        reheapTopToBottom(secondChild);
      }
    }
  }

  /**
   * Swap the data of two nodes
   *
   * @param node1 the first node to swap
   * @param node2 the node that is to be swapped with node1
   */
  private void swap(Node<E> node1, Node<E> node2) {
    E temp = node2.data;
    node2.data = node1.data;
    node1.data = temp;
  }
}
