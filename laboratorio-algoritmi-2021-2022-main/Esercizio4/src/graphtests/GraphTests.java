package graphtests;

import java.util.*;
import graph.Edge;
import graph.Graph;
import graph.GraphException;

import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertFalse;

public class GraphTests {
  Map<Integer, List<Edge<Integer>>> map;
  Graph<Integer> graph;

  @Before
  public void newGraph() throws GraphException {
    graph = new Graph<Integer>(true);
    map = new HashMap<>();
  }

  @Test
  public void testIsEmpty() throws GraphException {
    assertTrue(graph.isEmpty());
  }

  @Test
  public void testIsNotEmpty() throws GraphException {
    graph.addNode(10);
    assertFalse(graph.isEmpty());
  }

  @Test
  public void testIsDirect() throws GraphException {
    assertTrue(graph.isDirect());
  }

  @Test
  public void testOneNode() throws GraphException {
    graph.addNode(10);
    map.put(10, new LinkedList<Edge<Integer>>());
    assertEquals(graph.getMap(), map);
  }

  @Test
  public void testTwoNode() throws GraphException {
    graph.addNode(1);
    graph.addNode(2);
    map.put(1, new LinkedList<Edge<Integer>>());
    map.put(2, new LinkedList<Edge<Integer>>());
    assertEquals(graph.getMap(), map);
  }

  @Test
  public void testThreeNode() throws GraphException {
    graph.addNode(10);
    graph.addNode(5);
    graph.addNode(1);
    map.put(10, new LinkedList<Edge<Integer>>());
    map.put(5, new LinkedList<Edge<Integer>>());
    map.put(1, new LinkedList<Edge<Integer>>());
    assertEquals(graph.getMap(), map);
  }

  @Test
  public void testOneEdge() throws GraphException {
    graph.addEdge(10, 5);
    assertEquals(1, graph.getEdgeNumber());
  }

  @Test
  public void testTwoEdge() throws GraphException {
    graph.addEdge(10, 5);
    graph.addEdge(7, 5);
    assertEquals(2, graph.getEdgeNumber());
  }

  @Test
  public void testThreeEdge() throws GraphException {
    graph.addEdge(10, 5);
    graph.addEdge(7, 5);
    graph.addEdge(5, 7);
    graph.addEdge(5, 10);
    graph.printGraph();
    assertEquals(4, graph.getEdgeNumber());
  }

}
