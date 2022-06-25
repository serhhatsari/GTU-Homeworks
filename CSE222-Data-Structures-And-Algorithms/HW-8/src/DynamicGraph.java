package src;

import java.util.HashMap;

public interface DynamicGraph extends Graph {
  /**
   * It creates a new vertex with the given label and weight.
   *
   * @param label The label of the vertex.
   * @param weight The weight of the vertex.
   * @return A new vertex with the given label and weight.
   */
  public Vertex newVertex(String label, double weight);

  /*
   * Adds an edge to the vertex
   *
   */
  public void addVertex(Vertex new_vertex);

  /**
   * Adds an edge between two vertices
   *
   * @param vertexID1 The ID of the first vertex.
   * @param vertexID2 The ID of the vertex that the edge is going to.
   * @param weight The weight of the edge.
   */
  public void addEdge(int vertexID1, int vertexID2, double weight);

  /**
   * Removes the edge between the two vertices with the given IDs
   *
   * @param vertexID1 The ID of the first vertex.
   * @param vertexID2 The ID of the second vertex.
   */
  public void removeEdge(int vertexID1, int vertexID2);

  /**
   * Removes the vertex with the given ID from the graph
   *
   * @param vertexID The ID of the vertex to be removed.
   */
  public void removeVertex(int vertexID);

  /**
   * Removes the vertices with label from the graph
   *
   * @param vertexID The label of the vertices
   */
  public void removeVertex(String label);

  /**
   * It returns a new graph that contains only the vertices that pass the filter.
   *
   * @param key The key of the vertex attribute to filter on.
   * @param filter a string that contains the filter to be applied to the vertices.
   * @return A new graph with the vertices that match the filter.
   */
  public MyGraph filterVertices(String key, String filter);

  /*
   * it returns a VxV matrix
   */
  public double[][] exportMatrix();

  /**
   * Prints the graph to the console.
   */
  public void printGraph();

  public static class Vertex implements Comparable<Vertex> {

    private int ID;
    private String label;
    private double weight;
    private HashMap<String, String> otherProperties;

    // This is a constructor for the Vertex class.
    public Vertex(int ID) {
      this.ID = ID;
      this.label = "";
      weight = 1.0;
      otherProperties = null;
    }

    // A constructor for the Vertex class.
    public Vertex(int ID, String label) {
      this.ID = ID;
      this.label = label;
      weight = 1.0;
      otherProperties = null;
    }

    // A constructor for the Vertex class.
    public Vertex(int ID, String label, double weight) {
      this.ID = ID;
      this.label = label;
      this.weight = weight;
      this.otherProperties = null;
    }

    // A constructor for the Vertex class.
    public Vertex(
      int ID,
      String label,
      HashMap<String, String> otherProperties
    ) {
      this.ID = ID;
      this.label = label;
      this.weight = 1.0;
      this.otherProperties = otherProperties;
    }

    // A constructor for the Vertex class.
    public Vertex(
      int ID,
      String label,
      double weight,
      HashMap<String, String> otherProperties
    ) {
      this.ID = ID;
      this.label = label;
      this.weight = weight;
      this.otherProperties = otherProperties;
    }

    /**
     * This function returns the value of the ID variable.
     *
     * @return The ID of the student.
     */
    public int getID() {
      return ID;
    }

    /**
     * This function returns the label of the current node.
     *
     * @return The label of the enum.
     */
    public String getLabel() {
      return label;
    }

    /**
     * This function returns the weight of the object.
     *
     * @return The weight of the object.
     */
    public double getWeight() {
      return weight;
    }

    /**
     * This function returns a HashMap of String keys and String values that contains all the properties
     * that are not explicitly defined in the class.
     *
     * @return A HashMap of String keys and String values.
     */
    public HashMap<String, String> getOtherProperties() {
      return otherProperties;
    }

    /**
     * If the object passed in is a vertex, then return true if the vertex's ID is the same as this
     * vertex's ID. Otherwise, return false
     *
     * @param obj The object to compare to.
     * @return The hashcode of the vertex.
     */
    @Override
    public boolean equals(Object obj) {
      if (obj instanceof Vertex) {
        Vertex v = (Vertex) obj;
        return v.getID() == this.getID();
      }
      return false;
    }

    /**
     * If two objects are equal, their hash codes must be equal.
     *
     * @return The hashCode() method returns a hash code value for the object.
     */
    @Override
    public int hashCode() {
      return ID;
    }

    /**
     * If the ID of the current vertex is less than the ID of the vertex passed in, return -1. If the ID of
     * the current vertex is greater than the ID of the vertex passed in, return 1. Otherwise, return 0
     *
     * @param o The vertex to compare to
     * @return The difference between the two IDs.
     */
    @Override
    public int compareTo(Vertex o) {
      if (this.getID() < o.getID()) {
        return -1;
      } else if (this.getID() > o.getID()) {
        return 1;
      } else {
        return 0;
      }
    }
  }
}
