package minheap;

import java.util.Comparator;
import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import org.junit.Before;
import org.junit.Test;

public class MinHeapTests {
  class IntegerComparator implements Comparator<Integer> {
    @Override
    public int compare(Integer i1, Integer i2) {
      return i1.compareTo(i2);
    }
  }

  private Integer i1, i2, i3;
  private MinHeap<Integer> minheap;

  @Before
  public void MinHeap() throws MinHeapException {
    i1 = 12;
    i2 = 0;
    i3 = 4;
    minheap = new MinHeap<>(new IntegerComparator());
  }

  @Test
  public void testIsEmpty() {
    assertTrue(minheap.isEmpty());
  }

  @Test
  public void testIsEmpty_oneEl() throws Exception {
    minheap.heapInsert(i1);
    assertFalse(minheap.isEmpty());
  }

  @Test
  public void testSize_zeroEl() throws Exception {
    assertEquals(0, minheap.sizeHeap());
  }

  @Test
  public void testSize_oneEl() throws Exception {
    minheap.heapInsert(i1);
    assertEquals(1, minheap.sizeHeap());
  }

  @Test
  public void testSize_twoEl() throws Exception {
    minheap.heapInsert(i1);
    minheap.heapInsert(i2);
    assertEquals(2, minheap.sizeHeap());
  }

  @Test
  public void testGet_oneEl() throws Exception {
    minheap.heapInsert(i1);
    assertTrue(i1 == minheap.getByIndex(0));
  }

  @Test
  public void testAdd_threeEl_1() throws Exception {

    Integer[] arrExpected = { i2, i1, i3 };

    minheap.heapInsert(i1);
    minheap.heapInsert(i2);
    minheap.heapInsert(i3);

    assertArrayEquals(arrExpected, minheap.toArray());
  }

  public void testAdd_threeEl_2() throws Exception {

    Integer[] arrExpected = { i1, i3, i2 };

    minheap.heapInsert(i1);
    minheap.heapInsert(i2);
    minheap.heapInsert(i3);
    minheap.heapsort();

    assertArrayEquals(arrExpected, minheap.toArray());
  }

  public void testAdd_threeEl_MinElement() throws Exception {
    minheap.heapInsert(i1);
    minheap.heapInsert(i2);
    minheap.heapInsert(i3);

    assertEquals(i2, minheap.heapExtractMin());

  }

  public void testAdd_threeEl_3() throws Exception {

    Integer[] arrExpected = { i3, i1 };

    minheap.heapInsert(i1);
    minheap.heapInsert(i2);
    minheap.heapInsert(i3);
    minheap.heapExtractMin();

    assertArrayEquals(arrExpected, minheap.toArray());

  }

}
