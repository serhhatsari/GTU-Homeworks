import SortingAlgorithms.MergeSort;
import SortingAlgorithms.NewSort;
import SortingAlgorithms.QuickSort;

public class Driver {

  public static void main(String[] args) {
    testChainBSTHashMap();
  }

  private static void testChainBSTHashMap() {
    ChainBSTHashMap<Integer, Integer> map = new ChainBSTHashMap<>();
    ChainBSTHashMap<Integer, Integer> map1 = new ChainBSTHashMap<>();

    System.out.println("100 random integers adding to map");
    double mapTime = 0;
    long startTime = 0;
    long endTime = 0;
    long seconds = 0;

    startTime = System.currentTimeMillis();

    for (int i = 0; i < 1000; i++) {
      Integer[] table = new Integer[100];

      for (int j = 0; j < table.length; j++) {
        table[j] = (int) (Math.random() * 100);
        map.put(table[j], 10);
      }
    }

    endTime = System.currentTimeMillis();
    seconds = (endTime - startTime);
    mapTime += seconds;

    System.out.println(
      "ChainBSTHashMap Put Method: " + seconds + " milliseconds"
    );

    System.out.println("1000 random integers adding to map");

    startTime = System.currentTimeMillis();

    for (int i = 0; i < 1000; i++) {
      Integer[] table = new Integer[1000];

      for (int j = 0; j < table.length; j++) {
        table[j] = (int) (Math.random() * 100);
        map.put(table[j], 10);
      }
    }

    endTime = System.currentTimeMillis();
    seconds = (endTime - startTime);
    mapTime += seconds;

    System.out.println(
      "ChainBSTHashMap Put Method: " + seconds + " milliseconds"
    );

    System.out.println("1000 random integers adding to map");

    startTime = System.currentTimeMillis();

    for (int i = 0; i < 1000; i++) {
      Integer[] table = new Integer[10000];

      for (int j = 0; j < table.length; j++) {
        table[j] = (int) (Math.random() * 100);
        map.put(table[j], 10);
      }
    }

    endTime = System.currentTimeMillis();
    seconds = (endTime - startTime);
    mapTime += seconds;

    System.out.println(
      "ChainBSTHashMap Put Method: " + seconds + " milliseconds"
    );

    System.out.println("\n\nChainBSTHashMap Get Method");
    System.out.println("Lets add [1,1], [2,5], [123,3] to the map");
    map1.put(1, 1);
    map1.put(2, 5);
    map1.put(123, 3);
    System.out.println("Lets print the map");
    System.out.println(map1);
    System.out.println("Lets get the value of key 2");
    System.out.println("Lets print the map");
    System.out.println(map1.get(2));
    System.out.println("Lets get the value of key 123");
    System.out.println("Lets print the map");
    System.out.println(map1.get(123));
    System.out.println("Lets get the value of key 1");
    System.out.println("Lets print the map");
    System.out.println(map1.get(1));
    System.out.println("As you can see it works");

    System.out.println("\n\nChainBSTHashMap Remove Method");
    System.out.println("Lets add [1,1], [2,5], [123,3] to the map");
    System.out.println("Lets print the map");
    System.out.println(map1);
    System.out.println("Lets remove the entry of key 2");
    System.out.println("Lets print the map");
    map1.remove(2);
    System.out.println(map1);
    System.out.println("Lets remove the entry of key 123");
    System.out.println("Lets print the map");
    map1.remove(123);
    System.out.println(map1);
    System.out.println("Lets remove the entry of key 1");
    System.out.println("Lets print the map");
    map1.remove(1);
    System.out.println(map1);
    System.out.println("As you can see it works");
    System.out.println("Lets print the map");
  }

  private static void testSortingAlgorithms() {
    System.out.println("\n\nTESTING SORTING ALGORITHMS\n");
    System.out.println("100 random integers");
    double quickSortTime = 0;
    double mergeSortTime = 0;
    double newSortTime = 0;
    long startTime = 0;
    long endTime = 0;
    long seconds = 0;

    for (int i = 0; i < 1000; i++) {
      Integer[] table = new Integer[100];

      for (int j = 0; j < table.length; j++) {
        table[j] = (int) (Math.random() * 100);
      }
      Integer[] table1 = table;
      Integer[] table2 = table;

      startTime = System.currentTimeMillis();
      QuickSort.sort(table);
      endTime = System.currentTimeMillis();
      seconds = (endTime - startTime);
      quickSortTime += seconds;

      startTime = System.currentTimeMillis();
      MergeSort.sort(table1);
      endTime = System.currentTimeMillis();
      seconds = (endTime - startTime);
      mergeSortTime += seconds;

      startTime = System.currentTimeMillis();
      NewSort.sort(table2);
      endTime = System.currentTimeMillis();
      seconds = (endTime - startTime);
      newSortTime += seconds;
    }

    System.out.println("QuickSort: " + quickSortTime / 1000);
    System.out.println("MergeSort: " + mergeSortTime / 1000);
    System.out.println("NewSort: " + newSortTime / 1000);

    quickSortTime = 0;
    mergeSortTime = 0;
    newSortTime = 0;

    System.out.println("\n1000 random integers");

    for (int i = 0; i < 1000; i++) {
      Integer[] table = new Integer[1000];

      for (int j = 0; j < table.length; j++) {
        table[j] = (int) (Math.random() * 100);
      }
      Integer[] table1 = table;
      Integer[] table2 = table;

      startTime = System.currentTimeMillis();
      QuickSort.sort(table);
      endTime = System.currentTimeMillis();
      seconds = (endTime - startTime);
      quickSortTime += seconds;

      startTime = System.currentTimeMillis();
      MergeSort.sort(table1);
      endTime = System.currentTimeMillis();
      seconds = (endTime - startTime);
      mergeSortTime += seconds;

      startTime = System.currentTimeMillis();
      NewSort.sort(table2);
      endTime = System.currentTimeMillis();
      seconds = (endTime - startTime);
      newSortTime += seconds;
    }

    System.out.println("QuickSort: " + quickSortTime / 1000);
    System.out.println("MergeSort: " + mergeSortTime / 1000);
    System.out.println("NewSort: " + newSortTime / 1000);

    quickSortTime = 0;
    mergeSortTime = 0;
    newSortTime = 0;

    System.out.println("\n10000 random integers");

    for (int i = 0; i < 1000; i++) {
      Integer[] table = new Integer[10000];

      for (int j = 0; j < table.length; j++) {
        table[j] = (int) (Math.random() * 100);
      }
      Integer[] table1 = table;
      Integer[] table2 = table;

      startTime = System.currentTimeMillis();
      QuickSort.sort(table);
      endTime = System.currentTimeMillis();
      seconds = (endTime - startTime);
      quickSortTime += seconds;

      startTime = System.currentTimeMillis();
      MergeSort.sort(table1);
      endTime = System.currentTimeMillis();
      seconds = (endTime - startTime);
      mergeSortTime += seconds;

      startTime = System.currentTimeMillis();
      NewSort.sort(table2);
      endTime = System.currentTimeMillis();
      seconds = (endTime - startTime);
      newSortTime += seconds;
    }

    System.out.println("QuickSort: " + quickSortTime / 1000);
    System.out.println("MergeSort: " + mergeSortTime / 1000);
    System.out.println("NewSort: " + newSortTime / 1000);
  }
}
