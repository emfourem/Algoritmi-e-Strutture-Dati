package graphutils;

import graph.Graph;
import graph.GraphException;
import minheap.MinHeap;
import minheap.MinHeapException;
import graphusage.NodeComparator;
import java.util.HashMap;

/**
 * This class contains Dijkstra algorithm
 */
public class GraphUtils<T extends Comparable<T>> {

  /**
   * This methods calculates all minimum path in graph g starting from source
   * parameter
   * 
   * @param source is the source node of all paths
   * @param g      is the graph on which algorithm is executed
   * @return all minimum path
   * @throws GraphException
   * @throws MinHeapException
   */
  public HashMap<T, Node<T>> DijkstraAlgorithm(T source, Graph<T> g) throws GraphException, MinHeapException {
    if (g == null || source == null) {
      throw new GraphException("Dijkstra Algorithm: parameters cannot be null");
    }
    MinHeap<Node<T>> minHeap = new MinHeap<>(new NodeComparator<>());
    HashMap<T, Node<T>> mapTtoNodes = new HashMap<>();
    Node<T> tmp, min;
    for (T key : g.getMap().keySet()) {
      tmp = new Node<>(key);
      tmp.setParent(null);
      tmp.setCost(key.equals(source) ? 0 : Double.MAX_VALUE);
      minHeap.heapInsert(tmp);
      mapTtoNodes.put(key, tmp);
    }

    while (!minHeap.isEmpty()) {
      min = minHeap.heapExtractMin();
      for (T adj : g.getNearNode(min.getValue())) {
        Node<T> node = mapTtoNodes.get(adj);
        if (node.getCost() > min.getCost() + g.getEdgeWeight(min.getValue(), node.getValue())) {
          node.setCost(min.getCost() + g.getEdgeWeight(min.getValue(), node.getValue()));
          node.setParent(min);
          //il minheap contiene il nodo perciò si inserisce il nodo e sarà la decrease a verificare le proprietà
          minHeap.decreaseKey(minHeap.getByKey(node), node);
        }
      }
    }

    return mapTtoNodes;
  }
}
