package src;

public class Q2 {

  /**
   * It calculates the distance between the start node and all other nodes in the graph.
   *
   * @param graph The graph to be searched
   * @param start the starting vertex
   */
  public static void calculateDistance(MyGraph graph, int start) {
    DepthFirstSearch dfs = new DepthFirstSearch(graph);
    int[] dfsDistance, bfsDistance;
    int[] dfsParent = dfs.getParent();
    System.out.println("DFS PARENT ARRAY:");
    printArray(dfsParent);
    int[] bfsParent = BreadthFirstSearch.breadthFirstSearch(graph, start);
    System.out.println("BFS PARENT ARRAY:");
    printArray(bfsParent);
    dfsDistance = calculateDistance(dfsParent, graph);
    bfsDistance = calculateDistance(bfsParent, graph);
    System.out.println(
      "Total Difference " + printArrayDifferences(dfsDistance, bfsDistance)
    );
  }

  /**
   * It takes the parent array and the graph as input and returns an array of distances from the source
   * vertex to all other vertices
   *
   * @param parentArr This is the array that contains the parent of each vertex.
   * @param graph The graph to be searched.
   * @return The distance array is being returned.
   */
  private static int[] calculateDistance(int[] parentArr, MyGraph graph) {
    int[] distanceArr = new int[parentArr.length];
    for (int i = 0; i < parentArr.length; i++) {
      int weight = 0;
      int j = parentArr[i];
      while (j != -1) {
        Double tempWeight = graph.getEdge(j, i).getWeight();
        if (tempWeight != Double.POSITIVE_INFINITY) {
          weight += tempWeight;
        }
        j = parentArr[j];
      }
      distanceArr[i] = weight;
    }
    return distanceArr;
  }

  /**
   * It prints out the contents of an array
   *
   * @param arr The array to be sorted.
   */
  private static void printArray(int[] arr) {
    for (int i = 0; i < arr.length; i++) {
      System.out.print(arr[i] + " ");
    }
    System.out.println();
  }

  /**
   * It takes two arrays of integers, sums them, and returns the absolute value of the difference between
   * the two sums
   *
   * @param dfsDist The distance array from the DFS traversal
   * @param bfsDist The array of distances from the source node to each node in the graph, using BFS.
   * @return The difference between the total distances of the DFS and BFS traversals.
   */
  private static int printArrayDifferences(int[] dfsDist, int[] bfsDist) {
    int dfsTotal = 0;
    int bfsTotal = 0;
    for (int i = 0; i < dfsDist.length; i++) {
      dfsTotal += dfsDist[i];
    }
    System.out.println("DFS Total: " + dfsTotal);
    for (int i = 0; i < bfsDist.length; i++) {
      bfsTotal += bfsDist[i];
    }
    System.out.println("BFS Total: " + bfsTotal);
    return Math.abs(dfsTotal - bfsTotal);
  }
}
