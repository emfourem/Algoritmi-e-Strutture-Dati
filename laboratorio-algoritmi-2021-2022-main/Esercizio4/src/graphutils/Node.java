package graphutils;

/**
 * This class represents node entity of a graph
 */
public class Node<T extends Comparable<T>> implements Comparable<Node<T>> {

  private T value;
  private double cost;
  private Node<T> parent;

  /**
   * Constructor of a node
   * 
   * @param value is the value of the node
   */
  public Node(T value) {
    this.value = value;
    this.cost = Double.POSITIVE_INFINITY;
    this.parent = null;
  }

  /**
   * Allows to set the value of a node
   * 
   * @param value to be setted
   */
  public void setValue(T value) {
    this.value = value;
  }

  /**
   * Allows to set the parent of a node
   * 
   * @param parent to be setted
   */
  public void setParent(Node<T> parent) {
    this.parent = parent;
  }

  /**
   * Allows to set the cost of a node
   * 
   * @param cost to be setted
   */
  public void setCost(double cost) {
    this.cost = cost;
  }

  /**
   * Allows to get the value of a node
   * 
   * @return generic value to get
   */
  public T getValue() {
    return value;
  }

  /**
   * Allows to get the parent of a node
   * 
   * @return the parent to get
   */
  public Node<T> getParent() {
    return parent;
  }

  /**
   * Allows to get the cost of a node
   * 
   * @return the cost to get
   */
  public double getCost() {
    return cost;
  }

  @Override
  public int compareTo(Node<T> o) {
    if (this.getCost() < o.getCost()) {
      return -1;
    } else if (this.getCost() > o.getCost()) {
      return +1;
    } else {
      return this.value.compareTo(o.value);
    }
  }

  @Override
  public String toString() {
    return "Node{" +
        "value=" + value +
        ", cost=" + cost
        + '}';
  }
}
