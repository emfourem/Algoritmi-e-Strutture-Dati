package graph;

/**
 * This simply class represents GraphException used by Graph API
 */

public class GraphException extends Exception {
  public GraphException(String errorMsg) {
    super(errorMsg);
  }
}