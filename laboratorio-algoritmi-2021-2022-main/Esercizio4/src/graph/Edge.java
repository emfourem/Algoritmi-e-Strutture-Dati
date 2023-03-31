package graph;

import java.util.*;

/**
 * This class represents Edge entity of Graph Data Structure
 */
public class Edge<T> {
  private T begin;
  private T end;
  private double weight;

  /**
   * Edge constructor allows to initialize generic edge object used by Graph DS
   * 
   * @param begin
   * @param end
   * @param weight
   */
  public Edge(T begin, T end, double weight) {
    this.begin = begin;
    this.end = end;
    this.weight = weight;
  }

  /**
   * Edge constructor allows to initialize generic edge object without weight
   * component used by Graph DS
   * 
   * @param begin
   * @param end
   */
  public Edge(T begin, T end) {
    this(begin, end, 0);
  }

  /**
   * Getter for edge source
   * 
   * @return item of generic type T
   */
  public T getBegin() {
    return begin;
  }

  /**
   * Getter for edge destination
   * 
   * @return item of generic type T
   */
  public T getEnd() {
    return end;
  }

  /**
   * Getter for weight component of the edge
   * 
   * @return weight of the given edge
   */
  public double getWeight() {
    return weight;
  }

  /**
   * Allows to set the generic value of the edge source
   * 
   * @param begin which value has to be setted
   */
  public void setBegin(T begin) {
    this.begin = begin;
  }

  /**
   * Allows to set the generic value of the edge destination
   * 
   * @param end which value has to be setted
   */
  public void setEnd(T end) {
    this.end = end;
  }

  /**
   * Allows to set the value of the weight component of the edge
   * 
   * @param weight which value has to be setted
   */
  public void setWeight(double weight) {
    this.weight = weight;
  }

  @Override
  public boolean equals(Object obj) {
    if (this == obj) {
      return true;
    }
    if (!(obj instanceof Edge) || obj == null) {
      return false;
    }
    Edge<?> temp = (Edge<?>) obj;
    return Objects.equals(this.begin, temp.begin) && Objects.equals(this.end, temp.end);
  }

  @Override
  public String toString() {
    return "begin : " + begin + "\t end : " + end + "\t weight : " + weight;
  }

}