import java.util.HashMap;
import src.DijkstrasAlgorithm;
import src.DynamicGraph.Vertex;
import src.Edge;
import src.MyGraph;
import src.Q2;

public class Driver {

  public static void main(String[] args) {
    System.out.println("TESTING Q1\n\n");
    testQ1();
    System.out.println("\n\nTESTING Q2");
    testQ2();
    System.out.println("\n\nTESTING Q3");
    testQ3();
  }

  private static void testQ1() {
    MyGraph graph = new MyGraph(0, false);
    System.out.println("addVertex() TEST");
    graph.addVertex(new Vertex(0, "A"));
    graph.addVertex(new Vertex(1, "B"));
    graph.addVertex(new Vertex(2, "C"));
    System.out.println("getNumV() TEST");
    System.out.println("Number of vertices in the graph: " + graph.getNumV());
    System.out.println("isDirected() TEST");
    System.out.println("Is graph directed: " + graph.isDirected());
    System.out.println("printGraph() TEST");
    graph.printGraph();
    System.out.println("addEdge() TEST");
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 3);
    graph.printGraph();
    System.out.println("insert() TEST");
    graph.insert(new Edge(0, 1, 1));
    graph.printGraph();
    System.out.println("isEdge() TEST");
    System.out.println("isEdge 0 - 2 : " + graph.isEdge(0, 2));
    System.out.println("getEdge() TEST");
    System.out.println("getEdge 0 - 2: " + graph.getEdge(0, 2));
    System.out.println("newVertex() TEST");
    System.out.println("newVertex method: " + graph.newVertex("t", 3));
    System.out.println("exportMatrix() TEST");
    System.out.println("exportMatrix: ");
    print2DArray(graph.exportMatrix());
    System.out.println("removeVertex() TEST");
    graph.removeVertex(2);
    graph.printGraph();
    System.out.println("removeEdge() TEST");
    graph.removeEdge(0, 1);
    graph.printGraph();
    System.out.println("filterVertices() TEST");
    MyGraph graph1 = new MyGraph(0, false);
    HashMap<String, String> test = new HashMap<>();
    test.put("ky", "0A");
    HashMap<String, String> test1 = new HashMap<>();
    test1.put("ky", "0A");
    graph1.addVertex(new Vertex(0, "a", test));
    graph1.addVertex(new Vertex(1, "b", test1));
    graph1.addEdge(0, 1, 3);
    graph1.filterVertices("ky", "0A").printGraph();
    System.out.println("AS YOU CAN SEE ALL METHODS WORKS CORRECTLY!");
  }

  private static void testQ2() {
    MyGraph graph = new MyGraph(5, false);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 4, 2);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 3, 6);
    graph.addEdge(3, 4, 4);
    graph.addEdge(2, 4, 7);
    graph.addEdge(0, 2, 2);
    Q2.calculateDistance(graph, 0);
  }

  private static void testQ3() {
    MyGraph graph = new MyGraph(0, false);
    System.out.println("For this problem, ");
    System.out.println("I used the exact example in the PDF");
    HashMap<String, String> firstAdditional = new HashMap<>();
    firstAdditional.put("boosting", "2.0");
    HashMap<String, String> secondAdditional = new HashMap<>();
    secondAdditional.put("boosting", "3.0");
    HashMap<String, String> thirdAdditional = new HashMap<>();
    int[] pred = new int[3];
    double[] dist = new double[3];
    thirdAdditional.put("boosting", "0.0");
    graph.addVertex(new Vertex(0, "A", firstAdditional));
    graph.addVertex(new Vertex(1, "B", secondAdditional));
    graph.addVertex(new Vertex(2, "C", thirdAdditional));

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 8);
    graph.addEdge(1, 2, 6);
    DijkstrasAlgorithm.dijkstrasAlgorithm(graph, 0, pred, dist);
    System.out.println("PRED ARRAY:");
    printArray(pred);
    System.out.println("DIST ARRAY:");
    printArray(dist);
  }

  private static void printArray(int[] arr) {
    for (int i = 0; i < arr.length; i++) {
      System.out.print(arr[i] + " ");
    }
    System.out.println();
  }

  private static void printArray(double[] arr) {
    for (int i = 0; i < arr.length; i++) {
      System.out.print(arr[i] + " ");
    }
    System.out.println();
  }

  private static void print2DArray(double[][] arr) {
    for (int i = 0; i < arr.length; i++) {
      for (int j = 0; j < arr[i].length; j++) {
        System.out.print(arr[i][j] + " ");
      }
      System.out.println();
    }
  }

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
}
