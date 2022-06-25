package ArrBST;

import java.util.Arrays;

/**
 * Array based binary search tree (implements the SearchTree interface) class.
 * Array to represent the binary tree
 *
 * @author Serhat Sarı
 * @version 1.0
 * @since 2022-04-10
 */

/**
 * Binary search tree class that uses an array to store its data
 */
public class BinarySearchTree<E> implements SearchTree<E> {

  // Data Fields
  public E[] data;
  private int size;
  private int capacity;

  // Constructors

  /**
   * Construct an empty binary search tree.
   */
  public BinarySearchTree() {
    data = (E[]) new Object[10];
    capacity = 10;
    size = 0;
  }

  // Methods

  /***
   * Inserts item where it belongs in the tree. Returns true if item is inserted;
   * false if it isn't (already in tree)
   *
   * @param item The item to be added
   * @return True if item is inserted; false if not
   */
  @Override
  public boolean add(E item) {
    int parent = 0;
    int leftChild = parent * 2 + 1;
    int rightChild = parent * 2 + 2;

    // If the tree is empty, set the root to the item
    if (size == 0) {
      setRoot(item);
      return true;
    }

    int comparison = compareItemWithParent(item, parent);

    while (comparison != 0) {
      comparison = compareItemWithParent(item, parent);

      // if item is bigger than the current parent
      // we should check the left
      if (comparison < 0) {
        if (isNodeNull(leftChild)) {
          addNode(item, leftChild);
          return true;
        } else {
          parent = leftChild;
          leftChild = parent * 2 + 1;
          rightChild = parent * 2 + 2;
        }
      } else if (comparison > 0) {
        if (isNodeNull(rightChild)) {
          addNode(item, rightChild);
          return true;
        } else {
          parent = rightChild;
          leftChild = parent * 2 + 1;
          rightChild = parent * 2 + 2;
        }
      }
    }

    return false;
  }

  /**
   * Returns true if the target is found in the tree
   *
   * @param target The item searched for
   * @return True if target is found; false if not
   */
  @Override
  public boolean contains(E target) {
    int parent = 0;
    int leftChild = parent * 2 + 1;
    int rightChild = parent * 2 + 2;

    while (data[parent] != null) {
      int comparison = ((Comparable<E>) target).compareTo(data[parent]);

      if (comparison < 0) {
        if (isNodeNull(leftChild)) {
          return false;
        } else {
          parent = leftChild;
          leftChild = parent * 2 + 1;
          rightChild = parent * 2 + 2;
        }
      } else if (comparison > 0) {
        if (isNodeNull(rightChild)) {
          return false;
        } else {
          parent = rightChild;
          leftChild = parent * 2 + 1;
          rightChild = parent * 2 + 2;
        }
      } else {
        return true;
      }
    }

    return false;
  }

  /**
   * Returns a reference to the data in the node that is equal o target. If no
   * such node is found, returns null
   *
   * @param target The data we are searching for
   * @return The data if we find it; null otherwise
   */
  @Override
  public E find(E target) {
    int parent = 0;
    int leftChild = parent * 2 + 1;
    int rightChild = parent * 2 + 2;
    E targetValue;

    while (data[parent] != null) {
      int comparison = ((Comparable<E>) target).compareTo(data[parent]);

      if (comparison < 0) {
        if (isNodeNull(leftChild)) {
          return null;
        } else {
          parent = leftChild;
          leftChild = parent * 2 + 1;
          rightChild = parent * 2 + 2;
        }
      } else if (comparison > 0) {
        if (isNodeNull(rightChild)) {
          return null;
        } else {
          parent = rightChild;
          leftChild = parent * 2 + 1;
          rightChild = parent * 2 + 2;
        }
      } else {
        targetValue = data[parent];
        return targetValue;
      }
    }

    return null;
  }

  /**
   * Removes target (if found) from tree and returns true; otherwise returns false
   *
   * @param target The target we want to remove
   * @return True if removed; false otherwise
   */
  @Override
  public boolean remove(E target) {
    int targetIndex = findNode(target);

    // check if target exists in the tree
    if (targetIndex == -1) return false;

    deleteNode(targetIndex);
    size--;
    return true;
  }

  /**
   * Removes target (if found) from tree and returns the reference of the target;
   * otherwise returns null
   *
   * @param target The target we want to remove
   * @return target if removed; null otherwise
   */
  @Override
  public E delete(E target) {
    int targetIndex = findNode(target);

    // check if target exists in the tree
    if (targetIndex == -1) return null;

    E targetValue = data[targetIndex];

    deleteNode(targetIndex);
    size--;
    return targetValue;
  }

  /**
   * Returns a tring representation of the tree
   *
   * @return The string representation of the tree.
   */
  @Override
  public String toString() {
    StringBuilder treeContent = new StringBuilder();
    toString(0, 1, treeContent);
    return treeContent.toString();
  }

  /**
   * If the target is less than the parent, go left. If the target is greater than
   * the parent, go right.
   * If the target is equal to the parent, return the parent. If the target is not
   * found, return -1
   *
   * @param target the element we're looking for
   * @return The index of the node that contains the target.
   */
  private int findNode(E target) {
    int parent = 0;
    int leftChild = parent * 2 + 1;
    int rightChild = parent * 2 + 2;

    int comparison = ((Comparable<E>) target).compareTo(data[parent]);

    while (comparison != 0) {
      comparison = ((Comparable<E>) target).compareTo(data[parent]);

      if (comparison < 0) {
        if (data[leftChild] == null) {
          return -1;
        } else {
          parent = leftChild;
          leftChild = parent * 2 + 1;
          rightChild = parent * 2 + 2;
        }
      } else if (comparison > 0) {
        if (data[rightChild] == null) {
          return -1;
        } else {
          parent = rightChild;
          leftChild = parent * 2 + 1;
          rightChild = parent * 2 + 2;
        }
      }
    }

    return parent;
  }

  /**
   * delete the node in the given index
   *
   * @param parent the index of the node to be deleted
   */
  private void deleteNode(int parent) {
    int leftChild = parent * 2 + 1;
    int rightChild = parent * 2 + 2;

    if (isNodeNull(leftChild) && isNodeNull(rightChild)) {
      deleteNodeWithZeroChild(parent);
    } else if (isNodeNull(leftChild)) {
      deleteNodeWithOneChild(parent, rightChild, 1);
    } else if (isNodeNull(rightChild)) {
      deleteNodeWithOneChild(parent, leftChild, 2);
    } else {
      deleteNodeWithTwoChild(parent, leftChild, 2);
    }
  }

  /**
   * It deletes the node with zero child.
   *
   * @param parent the index of the parent node
   */
  private void deleteNodeWithZeroChild(int parent) {
    data[parent] = null;
  }

  /**
   * Replace the parent node with the right most child of the child node
   *
   * @param parent the index of the parent node
   * @param child  the node that is being deleted
   */
  private void deleteNodeWithOneChild(int parent, int child, int childType) {
    if (childType == 1) {
      int rightMost = findRightMostChild(child);
      data[parent] = data[rightMost];
      arrangeTree(rightMost);
    } else {
      int leftMost = findLeftMostChild(child);
      data[parent] = data[leftMost];
      arrangeTree(leftMost);
    }
  }

  /**
   * It deletes a node with two children.
   *
   * @param parent the index of the parent node
   * @param child  the node to be deleted
   */
  private void deleteNodeWithTwoChild(int parent, int child, int childType) {
    deleteNodeWithOneChild(parent, child, childType);
  }

  /**
   * If the item is less than the parent, return -1. If the item is greater than
   * the parent, return 1. If
   * the item is equal to the parent, return 0
   *
   * @param item   the item to be compared with the parent
   * @param parent the index of the parent node
   * @return The compareItemWithParent method is returning the result of the
   *         comparison between the item
   *         and the parent.
   */
  private int compareItemWithParent(E item, int parent) {
    return ((Comparable<E>) item).compareTo(data[parent]);
  }

  /**
   * If the node at the given index is null, return true, otherwise return false.
   *
   * @param index the index of the node in the array
   * @return The value of the node at the given index.
   */
  private boolean isNodeNull(int index) {
    return data[index] == null;
  }

  /**
   * If the tree is empty, set the root to the item
   *
   * @param item the item to be added to the tree
   */
  private void setRoot(E item) {
    data[0] = item;
    data[1] = null;
    data[2] = null;
    size++;
  }

  /**
   * It adds a node to the tree.
   *
   * @param item   the item to be added to the tree
   * @param parent index of the node which item to be added
   */
  private void addNode(E item, int parent) {
    data[parent] = item;
    int leftChild = parent * 2 + 1;
    int rightChild = parent * 2 + 2;

    // Checking if the array is full. If it is full, it calls the reallocation
    // method.
    while (rightChild >= capacity) reallocation();

    data[leftChild] = null;
    data[rightChild] = null;

    size++;
  }

  /**
   * It prints the tree in a human-readable format.
   *
   * @param head        the index of the node to be printed
   * @param depth       the depth of the current node in the tree
   * @param treeContent The StringBuilder object that will be used to build the
   *                    string representation of
   *                    the tree.
   */
  private void toString(int head, int depth, StringBuilder treeContent) {
    for (int i = 1; i < depth; i++) {
      treeContent.append(" ");
    }
    if (data[head] == null) {
      treeContent.append("null\n");
    } else {
      treeContent.append(data[head]);
      treeContent.append("\n");
      toString(head * 2 + 1, depth + 1, treeContent);
      toString(head * 2 + 2, depth + 1, treeContent);
    }
  }

  /**
   * Find the leftmost node of the right sub tree
   *
   * @param parent the index of the parent node
   * @return The index of the right most child of the parent.
   */
  private int findRightMostChild(int parent) {
    int leftChild = parent * 2 + 1;

    if (data[leftChild] == null) {
      return parent;
    } else {
      return findRightMostChild(leftChild);
    }
  }

  /**
   * Find the rightmost node of the left sub tree
   *
   * @param parent the index of the parent node
   * @return The index of the left most child of the parent.
   */
  private int findLeftMostChild(int parent) {
    int rightChild = parent * 2 + 2;

    if (data[rightChild] == null) {
      return parent;
    } else {
      return findLeftMostChild(rightChild);
    }
  }

  /**
   * edit the tree after insertion and deletion
   *
   * @param parent the index of the parent node
   */
  private void arrangeTree(int parent) {
    int leftChild = parent * 2 + 1;
    int rightChild = parent * 2 + 2;

    if (data[leftChild] == null && data[rightChild] == null) {
      data[parent] = null;
      return;
    }

    if (data[leftChild] != null) {
      data[parent] = data[leftChild];
      data[leftChild] = null;
      arrangeTree(leftChild);
    }
    if (data[rightChild] != null) {
      data[parent] = data[rightChild];
      data[rightChild] = null;
      arrangeTree(rightChild);
    }
  }

  /**
   * If the array is full, double the size of the array and copy the old array
   * into the new array.
   */
  private void reallocation() {
    capacity *= 2;
    data = Arrays.copyOf(data, capacity);
  }
}
