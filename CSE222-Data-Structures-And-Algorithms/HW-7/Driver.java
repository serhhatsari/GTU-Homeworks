import java.lang.reflect.Array;
import src.Q1;
import src.Q2;
import src.tree.BinarySearchTree;
import src.tree.BinaryTree;

public class Driver {

  public static void main(String[] args) {
    System.out.println("TESTING THE FIRST QUESTION");
    Integer[] arr = { 12, 32, 5, 2, 14, 4, 3 };
    BinaryTree<Integer> bt = new BinaryTree<Integer>(
      2,
      new BinaryTree<Integer>(
        1,
        new BinaryTree<Integer>(30, null, null),
        new BinaryTree<Integer>(3, null, null)
      ),
      new BinaryTree<Integer>(
        6,
        new BinaryTree<Integer>(10, null, null),
        new BinaryTree<Integer>(5, null, null)
      )
    );

    System.out.println(Q1.buildBinarySearchTree(bt, arr));

    System.out.println("TESTING THE SECOND QUESTION");
    BinarySearchTree<Integer> bst = new BinarySearchTree<>();
    bst.add(12);
    bst.add(15);
    bst.add(20);
    bst.add(17);
    bst.add(22);
    bst.add(19);
    System.out.println(Q2.convertBSTtoAVL(bst));
    System.out.println("AS YOU CAN SEE IT IS CORRECT.");
  }
}
