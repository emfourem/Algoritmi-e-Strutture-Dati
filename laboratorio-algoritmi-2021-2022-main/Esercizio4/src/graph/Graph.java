package graph;

import java.util.*;

/**
 * This class implements Graph Data Structure
 */
//garantisce la presenza di un compareTo per confrontare due oggetti di tipo T
public class Graph<T extends Comparable<T>> {

  private final HashMap<T, List<Edge<T>>> map;
  private final boolean direct;

  /**
   * Allows to initialize a direct graph if argument direct is true, not direct
   * otherwise
   * 
   * @param direct determines graphs orientation
   */
  public Graph(boolean direct) {
    map = new HashMap<>();
    this.direct = direct;
  }

  /**
   * This method allows to add a generic node to the Data Structure
   * 
   * @param value to added to the data structure
   * @throws GraphException
   */
  public void addNode(T value) throws GraphException {
    if (value == null) {
      throw new GraphException("addNode : null node cannot be added in the Graph");
    }
    if (checkNode(value)) {
      throw new GraphException("addNode: node already exists in this Graph");
    }
    map.put(value, new LinkedList<>());
  }

  /**
   * This method allows to create an edge between two present nodes
   * 
   * @param begin  is a start point of the edge
   * @param end    is an end point of the edge
   * @param weight of the edge
   * @throws GraphException
   */
  public void addEdge(T begin, T end, double weight) throws GraphException {
    if (begin == null || end == null || weight < 0) {
      throw new GraphException("addEdge : begin or end cannot be null and weight cannot be < 0");
    }

    if (!(map.containsKey(begin))) {
      addNode(begin);
    }
    if (!(map.containsKey(end))) {
      addNode(end);
    }
    map.get(begin).add(new Edge<>(begin, end, weight));
    if (!(isDirect())) {
      map.get(end).add(new Edge<>(end, begin, weight));
    }
  }

  /**
   * This method allows to create an edge between two present nodes
   * 
   * @param begin is a start point of the edge
   * @param end   is an end point of the edge
   * @throws GraphException
   */
  public void addEdge(T begin, T end) throws GraphException {
    this.addEdge(begin, end, 0);
  }

  /**
   * This method checks if given as parameter generic node is present
   * 
   * @param node to be checked
   * @return true if exists, false otherwise
   * @throws GraphException
   */
  public boolean checkNode(T node) throws GraphException {
    if (node == null) {
      throw new GraphException("checkNode : node cannot be null");
    }
    return map.containsKey(node);
  }

  /**
   * This method checks if an edge exist between given nodes as parameters
   * 
   * @param begin node
   * @param end   node
   * @return true if exists, false otherwise
   * @throws GraphException
   */
  public boolean checkEdge(T begin, T end) throws GraphException {
    if (begin == null || end == null) {
      throw new GraphException("checkEdge : begin and end cannot be null");
    }

    if (map.containsKey(begin) == true) {
      return map.get(begin).contains(new Edge<>(begin, end));
    }

    return false;
  }

  /**
   * This method removes node if present, otherwise an exception is thrown
   * 
   * @param value represents the node to be removed
   * @throws GraphException
   */
  public void removeNode(T value) throws GraphException {
    if (value == null) {
      throw new GraphException("removeNode : value to remove cannot be null");
    }
    if (!(map.containsKey(value))) {
      throw new GraphException("removeNode : node not present. ");
    }
    for (T k : map.keySet()) {
      if (checkEdge(k, value)) {
        removeEdge(k, value);
      }
    }
    map.remove(value);
  }

  /**
   * This method removes the edge between two nodes if exists, otherwise an
   * exception is thrown
   * 
   * @param begin of the edge
   * @param end   of the edge
   * @throws GraphException
   */
  public void removeEdge(T begin, T end) throws GraphException {
    if (begin == null || end == null) {
      throw new GraphException("removeEdge : begin or end cannot be null");
    }
    if (!(map.containsKey(begin)) || !(map.containsKey(end))) {
      throw new GraphException("removeEdge : begin or end not in map");
    }
    if (checkEdge(begin, end)) {
      map.get(begin).remove(new Edge<>(begin, end));
    }
    if (!(isDirect()))
      map.get(end).remove(new Edge<>(end, begin));
  }

  /**
   * Allows to retreive the number of nodes present in graph Data Structure
   * 
   * @return the number of nodes present in DS
   */
  public int getNodeNumber() {
    return map.keySet().size();
  }

  /**
   * Allows to retreive the number of edges present in graph Data Structure
   * 
   * @return the number of edges present in DS
   */
  public int getEdgeNumber() {
    int numberEdge = 0;
    for (T key : map.keySet()) {
      numberEdge += map.get(key).size();
    }
    return (this.isDirect() == true ? numberEdge : numberEdge / 2);
  }

  /**
   * This method returns an array list which contains all the nodes present in the
   * graph
   * 
   * @return an array list with all the nodes
   */
  public List<T> getNodes() {
    List<T> result = new ArrayList<>();
    for (T k : map.keySet()) {
      result.add(k);
    }
    return result;
  }

  /**
   * This method allows to retreive all the edges presented in the graph Data
   * Structure
   * 
   * @return an array list containing all the edges
   */
  //la map.get restituisce la lista collegata alla chiave k
  public List<Edge<T>> getEdge() {
    List<Edge<T>> list = new ArrayList<>();
    for (T k : map.keySet()) {
      list.addAll(map.get(k));
    }
    return list;
  }

  /**
   * This method allows to retreive all the adjacent of the node given as
   * parameter
   * 
   * @param node which adjacents have to be found
   * @return an array list of all adjacent nodes
   * @throws GraphException
   */
  public List<T> getNearNode(T node) throws GraphException {

    if (node == null) {
      throw new GraphException("getNearNode : node cannot be null");
    }

    if (!(map.containsKey(node))) {
      throw new GraphException("getNearNode : node not in map");
    }

    List<T> list = new ArrayList<>();
    List<Edge<T>> temp = map.get(node); //O(1)
    //recupero lista delle adiacenze del nodo node

    for (Edge<T> el : temp) {
      list.add(el.getEnd());
    }
    //O(1) per la distribuzione uniforme

    return list;
  }

  /**
   * Allows to retreive a weight associated to an edge
   * 
   * @param begin of the edge
   * @param end   of the edge
   * @return the weight of the edge
   * @throws GraphException
   */
  public double getEdgeWeight(T begin, T end) throws GraphException {

    if (begin == null || end == null) {
      throw new GraphException("getEdgeWeight : begin and end cannot be null");
    }

    if (!(checkEdge(begin, end))) {
      throw new GraphException("getEdgeWeight : edge " + begin + "--->" + end + " doesn't exist");
    }

    for (Edge<T> el : map.get(begin)) {
      if (el.getEnd().equals(end)) {
        return el.getWeight();
      }
    }

    return -1;
  }

  /**
   * Allows to retreive the graph
   * 
   * @return
   */
  public HashMap<T, List<Edge<T>>> getMap() {
    return map;
  }

  /**
   * Checks if graph DS is empty
   * 
   * @return true is graph is empty, false otherwise
   */
  public boolean isEmpty() {
    return this.getNodeNumber() == 0;
  }

  /**
   * Checks if graph is direct or not
   * 
   * @return true if is direct, false otherwise
   */
  public boolean isDirect() {
    return this.direct;
  }

  /**
   * This utility method allows to print the graph Data Structure
   */
  public void printGraph() {
    System.out.println("key\t|\tbegin\t|\tend\t|\tweight\t|");
    System.out.println("+--------------------------------------------------------+");
    for (T key : map.keySet()) {
      List<Edge<T>> temp = map.get(key);

      for (int i = 0; i < temp.size(); i++) {
        System.out.print(key + " \t|\t " + temp.get(i).getBegin() + " \t|\t "
            + temp.get(i).getEnd() + " \t|\t " + temp.get(i).getWeight() + " \t|");
        System.out.println();
        System.out.println("+------------------------------------------------------+");
      }

      System.out.println();
    }
    System.out.println();
  }
}
