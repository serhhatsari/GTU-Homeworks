import ArrBST.BinarySearchTree;
import NodeBH.BinaryHeap;

public class Driver {

  public static void main(String[] args) {
    testBSTMethods();
    testBHMethods();
  }

  public static void testBHMethods() {
    System.out.println("\n\n\nTESTING HEAP SEARCH TREE\n\n");
    testBHOfferMethod();
    testBHRemoveMethod();
    testBHPollMethod();
    testBHPeekMethod();
    testBHElementMethod();
    testBHMergeMethod();
    testBHIncrementMethod();
  }

  public static void testBSTMethods() {
    System.out.println("\n\n\nTESTING BINARY SEARCH TREE\n\n");
    testBSTAddMethod();
    testBSTContainsMethod();
    testBSTFindMethod();
    testBSTRemoveMethod();
    testBSTDeleteMethod();
  }

  public static void testBSTAddMethod() {
    BinarySearchTree<Integer> test = new BinarySearchTree<>();

    System.out.println("Testing add() method of the BST\n");
    System.out.println("First lets create an empty BST");
    System.out.println("Then lets add 5 , 3 and 12 to the BST");
    test.add(5);
    test.add(3);
    test.add(12);
    System.out.println("Lets see the BST after insertion:");
    System.out.println(test);

    System.out.println("\nLets add 23 and 2 to the BST\n");
    test.add(23);
    test.add(2);
    System.out.println("Lets see the BST after insertion:");
    System.out.println(test);

    System.out.println("\nAs you can see, add method works correctly.\n");
  }

  public static void testBSTContainsMethod() {
    BinarySearchTree<Integer> test = new BinarySearchTree<>();

    System.out.println("\n\nTesting contains() method of the BST\n");
    System.out.println("First lets create an empty BST");
    System.out.println("Then lets add 5, 23, 33, 17 and 7 to the BST");
    test.add(5);
    test.add(23);
    test.add(33);
    test.add(17);
    test.add(7);
    System.out.println("Lets see the BST after insertion:");
    System.out.println(test);

    System.out.println("\nLets check if the BST contains 33:");
    System.out.println(test.contains(33));

    System.out.println("\nLets check if the BST contains 132:");
    System.out.println(test.contains(132));

    System.out.println("\nLets check if the BST contains 17:");
    System.out.println(test.contains(17));

    System.out.println("\nLets check if the BST contains 1:");
    System.out.println(test.contains(1));

    System.out.println("\nLets check if the BST contains 9:");
    System.out.println(test.contains(9));

    System.out.println("\nLets check if the BST contains 23:");
    System.out.println(test.contains(23));

    System.out.println("\nLets check if the BST contains 1024:");
    System.out.println(test.contains(1024));

    System.out.println("\nLets check if the BST contains 7:");
    System.out.println(test.contains(7));

    System.out.println("\nAs you can see, contains method works correctly.\n");
  }

  public static void testBSTFindMethod() {
    BinarySearchTree<Integer> test = new BinarySearchTree<>();

    System.out.println("\n\nTesting find() method of the BST\n");
    System.out.println("First lets create an empty BST");
    System.out.println("Then lets add 12, 66, 52, 84 and 5 to the BST");
    test.add(12);
    test.add(66);
    test.add(52);
    test.add(84);
    test.add(5);

    System.out.println("Lets see the BST after insertion:");
    System.out.println(test);

    System.out.println("\nLets find the node with value 12:");
    System.out.println(test.find(12));

    System.out.println("\nLets find the node with value 23:");
    System.out.println(test.find(23));

    System.out.println("\nLets find the node with value 84:");
    System.out.println(test.find(84));

    System.out.println("\nLets find the node with value 36:");
    System.out.println(test.find(36));

    System.out.println("\nLets find the node with value 52:");
    System.out.println(test.find(52));

    System.out.println("\nLets find the node with value 66:");
    System.out.println(test.find(66));

    System.out.println("\nAs you can see, find method works correctly.\n");
  }

  public static void testBSTRemoveMethod() {
    BinarySearchTree<Integer> test = new BinarySearchTree<>();

    System.out.println("\n\nTesting remove() method of the BST\n");
    System.out.println("First lets create an empty BST");
    System.out.println("Then lets add 12, 66, 52, 84 and 5 to the BST");
    test.add(12);
    test.add(66);
    test.add(52);
    test.add(84);
    test.add(5);

    System.out.println("Lets see the BST after insertion:");
    System.out.println(test);

    System.out.println("\nLets remove the node with value 12:");
    System.out.println("Result " + test.remove(12));
    System.out.println("Lets see the BST after removal:");
    System.out.println(test);

    System.out.println("\nLets remove the node with value 66:");
    System.out.println("Result " + test.remove(66));
    System.out.println("Lets see the BST after removal:");
    System.out.println(test);

    System.out.println("\nLets remove the node with value 52:");
    System.out.println("Result " + test.remove(52));
    System.out.println("Lets see the BST after removal:");
    System.out.println(test);

    System.out.println("\nLets remove the node with value 13:");
    System.out.println("Result " + test.remove(13));
    System.out.println("Lets see the BST after removal:");
    System.out.println(test);
    System.out.println(
      "It couldnt delete 13, and returned false, because 13 doesnt exist.\n"
    );

    System.out.println("\nLets remove the node with value 32:");
    System.out.println("Result " + test.remove(32));
    System.out.println("Lets see the BST after removal:");
    System.out.println(test);
    System.out.println(
      "It couldnt delete 32, and returned false, because 32 doesnt exist.\n"
    );

    System.out.println("\nLets remove the node with value 5:");
    System.out.println("Result " + test.remove(5));
    System.out.println("Lets see the BST after removal:");
    System.out.println(test);

    System.out.println("\nAs you can see, remove method works correctly.\n");
  }

  public static void testBSTDeleteMethod() {
    BinarySearchTree<Integer> test = new BinarySearchTree<>();

    System.out.println("\n\nTesting delete() method of the BST\n");
    System.out.println("First lets create an empty BST");
    System.out.println("Then lets add 12, 66, 52, 84 and 5 to the BST");
    test.add(12);
    test.add(66);
    test.add(52);
    test.add(84);
    test.add(5);

    System.out.println("Lets see the BST after insertion:");
    System.out.println(test);

    System.out.println("\nLets delete the node with value 12:");
    System.out.println("Result " + test.delete(12));
    System.out.println("Lets see the BST after deletion:");
    System.out.println(test);

    System.out.println("\nLets delete the node with value 66:");
    System.out.println("Result " + test.delete(66));
    System.out.println("Lets see the BST after deletion:");
    System.out.println(test);

    System.out.println("\nLets deletion the node with value 52:");
    System.out.println("Result " + test.delete(52));
    System.out.println("Lets see the BST after deletion:");
    System.out.println(test);

    System.out.println("\nLets delete the node with value 13:");
    System.out.println("Result " + test.delete(13));
    System.out.println("Lets see the BST after deletion:");
    System.out.println(test);
    System.out.println(
      "It couldnt delete 13, and returned null, because 13 doesnt exist.\n"
    );

    System.out.println("\nLets delete the node with value 32:");
    System.out.println("Result " + test.delete(32));
    System.out.println("Lets see the BST after deletion:");
    System.out.println(test);
    System.out.println(
      "It couldnt delete 32, and returned null, because 32 doesnt exist.\n"
    );

    System.out.println("\nLets delete the node with value 5:");
    System.out.println("Result " + test.delete(5));
    System.out.println("Lets see the BST after deletion:");
    System.out.println(test);

    System.out.println("\nAs you can see, delete method works correctly.\n");
  }

  public static void testBHOfferMethod() {
    BinaryHeap<Integer> test = new BinaryHeap<>();

    System.out.println("\n\nTesting offer() method of the BH\n");
    System.out.println("First lets create an empty BH");

    System.out.println("Then lets add 5 , 3 and 12 to the BH");

    test.offer(5);
    test.offer(3);
    test.offer(12);
    System.out.println("Lets see the BH after insertion:");
    System.out.println(test);

    System.out.println("\nLets add 23 and 2 to the BH\n");
    test.offer(23);
    test.offer(2);
    System.out.println("Lets see the BH after insertion:");
    System.out.println(test);

    System.out.println("\nAs you can see, offer method works correctly.\n");
  }

  public static void testBHPollMethod() {
    BinaryHeap<Integer> test = new BinaryHeap<>();

    System.out.println("\n\nTesting poll() method of the BH\n");
    System.out.println("First lets create an empty BH");
    System.out.println("Then lets add 5 , 3 , 12 , 1 , 60 and 30 to the BH");
    test.offer(5);
    test.offer(3);
    test.offer(12);
    test.offer(1);
    test.offer(60);
    test.offer(30);

    System.out.println("Lets see the BH after insertion:");
    System.out.println(test);

    System.out.println("\nLets poll the root of the BH\n");
    System.out.println("The root of the BH is: " + test.poll());
    System.out.println("Lets see the BH after poll operation:");
    System.out.println(test);

    System.out.println("\nLets poll the root of the BH\n");
    System.out.println("The root of the BH is: " + test.poll());
    System.out.println("Lets see the BH after poll operation:");
    System.out.println(test);

    System.out.println("\nLets poll the root of the BH\n");
    System.out.println("The root of the BH is: " + test.poll());
    System.out.println("Lets see the BH after poll operation:");
    System.out.println(test);

    System.out.println("\nAs you can see, poll method works correctly.\n");
  }

  public static void testBHRemoveMethod() {
    BinaryHeap<Integer> test = new BinaryHeap<>();

    System.out.println("\n\nTesting remove() method of the BH\n");
    System.out.println("First lets create an empty BH");
    System.out.println("Then lets add 5 , 3 , 12 , 32 , 122 and 323 to the BH");
    test.offer(5);
    test.offer(3);
    test.offer(12);
    test.offer(32);
    test.offer(122);
    test.offer(323);

    System.out.println("Lets see the BH after insertion:");
    System.out.println(test);

    System.out.println("\nLets remove the root of the BH\n");
    test.remove();
    System.out.println("Lets see the BH after removal:");
    System.out.println(test);

    System.out.println("\nLets remove the root of the BH\n");
    test.remove();
    System.out.println("Lets see the BH after removal:");
    System.out.println(test);

    System.out.println("\nLets remove the root of the BH\n");
    test.remove();
    System.out.println("Lets see the BH after removal:");
    System.out.println(test);

    System.out.println("\nAs you can see, remove method works correctly.\n");
  }

  public static void testBHPeekMethod() {
    BinaryHeap<Integer> test = new BinaryHeap<>();

    System.out.println("\n\nTesting peek() method of the BH\n");
    System.out.println("First lets create an empty BH");
    System.out.println("Then lets add 5 , 3 ,  12 to the BH");
    test.offer(5);
    test.offer(3);
    test.offer(12);
    System.out.println("Lets see the BH after insertion:");
    System.out.println(test);

    System.out.println("\nLets peek the root of the BH\n");
    System.out.println("The root of the BH is: " + test.peek());

    System.out.println("\nAs you can see, peek method works correctly.\n");
  }

  public static void testBHElementMethod() {
    BinaryHeap<Integer> test = new BinaryHeap<>();

    System.out.println("\n\nTesting element() method of the BH\n");
    System.out.println("First lets create an empty BH");
    System.out.println("Then lets add 5 , 3 and 12 to the BH");
    test.offer(5);
    test.offer(3);
    test.offer(12);
    System.out.println("Lets see the BH after insertion:");
    System.out.println(test);

    System.out.println("\nLets get the root of the BH\n");
    System.out.println("The root of the BH is: " + test.element());

    System.out.println("\nAs you can see, element method works correctly.\n");
  }

  public static void testBHMergeMethod() {
    BinaryHeap<Integer> test = new BinaryHeap<>();
    BinaryHeap<Integer> test2 = new BinaryHeap<>();
    BinaryHeap<Integer> result = new BinaryHeap<>();

    System.out.println("\n\nTesting merge() method of the BH\n");
    System.out.println("First lets create an empty BH");
    System.out.println("Then lets add 5 , 3 and 12 to the BH");
    test.offer(5);
    test.offer(3);
    test.offer(12);
    System.out.println("Lets see the BH after insertion:");
    System.out.println(test);

    System.out.println("\nLets create another empty BH");
    System.out.println("Then lets add 23 and 2 to the BH");
    test2.offer(23);
    test2.offer(2);
    System.out.println("Lets see the BH after insertion:");
    System.out.println(test2);

    System.out.println("\nLets merge the two BHs\n");
    result = test.merge(test2);
    System.out.println("Lets see the BH after merge:");
    System.out.println(result);

    System.out.println("\nAs you can see, merge method works correctly.\n");
  }

  public static void testBHIncrementMethod() {
    BinaryHeap<Integer> test = new BinaryHeap<>();

    System.out.println("\n\nTesting increment() method of the BH\n");
    System.out.println("First lets create an empty BH");
    System.out.println("Then lets add 5 , 3 and 12 to the BH");
    test.offer(5);
    test.offer(3);
    test.offer(12);
    System.out.println("Lets see the BH after insertion:");
    System.out.println(test);

    System.out.println("\nLets increment the root of the BH 3 to 20\n");
    test.incrementKey(3, 20);
    System.out.println("Lets see the BH after increment:");
    System.out.println(test);

    System.out.println("\nAs you can see, increment method works correctly.\n");
  }
}
