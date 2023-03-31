package graphusage;

import graph.Graph;
import graph.GraphException;
import graphutils.GraphUtils;
import graphutils.Node;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.HashMap;

/**
 * This class represents main features of the Graph API
 */
public class GraphUsage {

  private static final Charset ENCODING = StandardCharsets.UTF_8;

  // this private method allows to parse dataset
  private static void loadGraph(String filepath, Graph<String> g)
      throws IOException, GraphException {
    System.out.println("Loading data from file...");

    Path inputFilePath = Paths.get(filepath);
    try (BufferedReader fileInputReader = Files.newBufferedReader(inputFilePath, ENCODING)) {
      String line = null;
      while ((line = fileInputReader.readLine()) != null) {
        String[] lineElements = line.split(",");
        g.addEdge(lineElements[0], lineElements[1], Double.parseDouble(lineElements[2]));
      }
    }
    System.out.println("Data loaded");
  }

  /**
   * This method retreives the minimum distance between source and destination
   * passed by parameters
   * 
   * @param map         represents graph with minimum paths
   * @param destination point
   * @param trace       if true prints the path
   * @return the distance between source and destination points
   * @throws GraphException
   */
  public static double pathMin(HashMap<String, Node<String>> map, String destination, boolean trace)
      throws GraphException {
    if (map == null || destination.isEmpty() || destination.isBlank()) {
      throw new GraphException("pathMin : destinations is undefined for destination [" + destination + "]");
    }

    Node<String> temp = map.get(destination);

    if (temp == null) {
      throw new GraphException("pathMin : destination cannot be found");
    }

    if (trace) {
      printPath(temp);
      System.out.println("End travel...\n");
    }

    return temp.getCost();
  }

  // this method prints the path
  private static void printPath(Node<String> node) {
    if (node == null) {
      System.out.println("\nStart travel...\n");
      System.out.println(
          "\n______//  ||\\ \\\n_____//___||_\\ \\___\n)   _          _    |\n|__/ \\________/ \\___|\n___\\_/________\\_/______\n");
    } else {
      printPath(node.getParent());
      System.out.println("City: " + node.getValue());
      System.out.println("  \u2193");
    }
  }

  public static void main(String[] args) throws IOException, GraphException, Exception {
    if (args.length < 1) {
      throw new Exception("Main usage: GraphUsage <filename>");
    }

    Graph<String> graph = new Graph<>(false);
    loadGraph(args[0], graph);

    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter Source : ");
    String source = (scanner.nextLine()).toLowerCase();
    System.out.print("Enter Destination : ");
    String dest = (scanner.nextLine()).toLowerCase();
    System.out.println("Print Trace? Enter true or false : ");
    boolean trace = (scanner.nextBoolean());
    scanner.close();

    GraphUtils<String> g = new GraphUtils<>();
    HashMap<String, Node<String>> r = g.DijkstraAlgorithm(source, graph);
    double min = pathMin(r, dest, trace);
    System.out.print("Min path from " + source + " to " + dest + " is : ");
    System.out.println(Math.floor(min) / 1000.0 + "km");
  }
}