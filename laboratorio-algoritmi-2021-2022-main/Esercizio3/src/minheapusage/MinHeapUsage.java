package minheapusage;

import java.util.Comparator;
import minheap.MinHeap;
import minheap.MinHeapException;

public class MinHeapUsage {

  public static void main(String[] args) throws MinHeapException {
    Comparator<Float> comparator = new FloatComparator();
    MinHeap<Float> minheap = new MinHeap<>(comparator);
    System.out.print("HEAP:\t");
    for (int i = 0; i <= 20; i++) {
      minheap.heapInsert((float) (Math.random() * 10));
    }
    minheap.print();
    System.out.println();
  }
}
