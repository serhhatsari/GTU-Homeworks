package src;

import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map.Entry;

/**
 * It's a class that represents
 */
public class MyGraph implements DynamicGraph {

  private HashMap<Vertex, List<Edge>> edges;
  private int numV;
  private boolean directed;

  /**
   *  Construct a graph.
   * @param numV The number of vertices
   * @param directed True if the graph is directed
   */
  public MyGraph(int numV, boolean directed) {
    this.numV = numV;
    this.directed = directed;
    edges = new HashMap<>();
    for (int i = 0; i < numV; i++) {
      edges.put(new Vertex(i, "default"), new LinkedList<>());
    }
  }

  /**
   *  Construct a graph with vertices and edges.
   * @param numV The number of vertices
   * @param directed True if the graph is directed
   * @param edges The edges
   */
  public MyGraph(
    int numV,
    boolean directed,
    HashMap<Vertex, List<Edge>> edges
  ) {
    this.numV = numV;
    this.directed = directed;
    this.edges = edges;
  }

  /**
   *  returns the number of vertices in the graph
   *
   * @return The number of vertices in the graph.
   */
  @Override
  public int getNumV() {
    return numV;
  }

  /**
   * Returns true if the graph is directed, false otherwise.
   *
   * @return The boolean value of the directed variable.
   */
  @Override
  public boolean isDirected() {
    return directed;
  }

  /**
   * We add the edge to the list of edges for the source vertex. If the graph is undirected, we also add
   * the edge to the list of edges for the destination vertex
   *
   * @param edge The edge to be inserted into the graph.
   */
  @Override
  public void insert(Edge edge) {
    edges.get(new Vertex(edge.getSource())).add(edge);

    if (!directed) {
      edges
        .get(new Vertex(edge.getDest()))
        .add(new Edge(edge.getDest(), edge.getSource(), edge.getWeight()));
    }
  }

  /**
   * If the source vertex has any edges, then return true if the source vertex has an edge to the
   * destination vertex.
   *
   * @param source The source vertex of the edge.
   * @param dest The destination vertex of the edge.
   * @return A boolean value indicating whether or not there is an edge between the source and
   * destination vertices.
   */
  @Override
  public boolean isEdge(int source, int dest) {
    List<Edge> sourceEdges = edges.get(new Vertex(source));
    if (sourceEdges != null) {
      return sourceEdges.contains(new Edge(source, dest));
    }
    return false;
  }

  /**
   * > Given a source and destination of the vertex, return the edge connecting them
   *
   * @param source The source vertex of the edge.
   * @param dest The destination vertex.
   * @return The edge with the given source and destination.
   */
  public Edge getEdge(int source, int dest) {
    Edge target = new Edge(source, dest, Double.POSITIVE_INFINITY);
    for (Edge edge : edges.get(new Vertex(source))) {
      if (edge.equals(target)) return edge;
    }

    return target;
  }

  /**
   * Return an iterator over the edges of the graph that have the given source vertex.
   *
   * @param source The source vertex.
   * @return An iterator over the edges of the graph.
   */
  @Override
  public Iterator<Edge> edgeIterator(int source) {
    return edges.get(new Vertex(source)).iterator();
  }

  /**
   * It creates a new vertex with the given label and weight.
   *
   * @param label The label of the vertex.
   * @param weight the weight of the vertex
   * @return A new vertex with the given label and weight.
   */
  @Override
  public Vertex newVertex(String label, double weight) {
    return new Vertex(numV - 1, label, weight);
  }

  /**
   * It adds a new vertex to the graph
   *
   * @param new_vertex The vertex to be added to the graph.
   */
  @Override
  public void addVertex(DynamicGraph.Vertex new_vertex) {
    numV++;
    edges.put(new_vertex, new LinkedList<>());
  }

  /**
   * It adds an edge to the graph
   *
   * @param vertexID1 The ID of the first vertex.
   * @param vertexID2 The ID of the vertex that the edge is going to.
   * @param weight The weight of the edge.
   */
  @Override
  public void addEdge(int vertexID1, int vertexID2, double weight) {
    edges
      .get(new Vertex(vertexID1))
      .add(new Edge(vertexID1, vertexID2, weight));
    if (!directed) {
      edges
        .get(new Vertex(vertexID2))
        .add(new Edge(vertexID2, vertexID1, weight));
    }
  }

  /**
   * Remove the edge from the graph
   *
   * @param vertexID1 The ID of the first vertex.
   * @param vertexID2 The ID of the second vertex.
   */
  @Override
  public void removeEdge(int vertexID1, int vertexID2) {
    edges.get(new Vertex(vertexID1)).remove(new Edge(vertexID1, vertexID2));

    if (!directed) {
      edges.get(new Vertex(vertexID2)).remove(new Edge(vertexID2, vertexID1));
    }
  }

  /**
   * Remove the vertex from the graph
   *
   * @param vertexID The ID of the vertex to remove.
   */
  @Override
  public void removeVertex(int vertexID) {
    numV--;
    edges.remove(new Vertex(vertexID));
    for (List<Edge> entry : edges.values()) {
      for (Edge e : entry) {
        if (e.getSource() == vertexID || e.getDest() == vertexID) {
          entry.remove(e);
        }
      }
    }
  }

  /**
   * Return the vertex with the given ID, or null if no such vertex exists.
   *
   * @param vertexID The ID of the vertex you want to get.
   * @return The vertex with the given ID.
   */
  public Vertex getVertex(int vertexID) {
    for (Vertex key : edges.keySet()) {
      if (key.getID() == vertexID) return key;
    }
    return null;
  }

  /**
   * Remove all edges that have the given vertex as a source or destination.
   *
   * @param label The label of the vertex to remove.
   */
  @Override
  public void removeVertex(String label) {
    int deletedID;
    for (Entry<Vertex, List<Edge>> entry : edges.entrySet()) {
      if (entry.getKey().getLabel().equals(label)) {
        deletedID = entry.getKey().getID();
        edges.remove(entry);
        for (List<Edge> edg : edges.values()) {
          for (Edge e : edg) {
            if (e.getSource() == deletedID || e.getDest() == deletedID) {
              edg.remove(e);
            }
          }
        }
      }
    }
  }

  /**
   * It creates a new graph with only the vertices that have a certain property
   *
   * @param key the key of the property to filter on
   * @param filter the value of the property to filter by
   * @return A new graph with the vertices that have the given key and value.
   */
  @Override
  public MyGraph filterVertices(String key, String filter) {
    HashMap<Vertex, List<Edge>> vertices = new HashMap<>();
    int vertNum = 0;
    for (Entry<Vertex, List<Edge>> entry : edges.entrySet()) {
      if (entry.getKey().getOtherProperties().containsKey(key)) {
        String value = entry.getKey().getOtherProperties().get(key);
        if (value.equals(filter)) {
          vertices.put(entry.getKey(), entry.getValue());
        }
      }
    }

    return new MyGraph(vertNum, directed, vertices);
  }

  /* Creating a matrix representation of the graph. */
  @Override
  public double[][] exportMatrix() {
    double matrixEdges[][] = new double[numV][numV];
    for (int i = 0; i < numV; i++) {
      for (int k = 0; k < numV; k++) {
        if (edges.get(new Vertex(i)).contains(new Edge(i, k))) {
          matrixEdges[i][k] = 1.0;
        } else {
          matrixEdges[i][k] = 0;
        }
      }
    }
    return matrixEdges;
  }

  /**
   * It prints out the graph
   */
  @Override
  public void printGraph() {
    System.out.println("Graph: ");
    for (Entry<Vertex, List<Edge>> entry : edges.entrySet()) {
      System.out.print(entry.getKey().getID() + ": ");
      for (Edge edge : entry.getValue()) {
        System.out.print(edge);
      }
      System.out.println();
    }
  }
}
