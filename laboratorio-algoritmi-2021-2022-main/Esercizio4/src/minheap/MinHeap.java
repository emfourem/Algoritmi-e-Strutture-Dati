package minheap;

import java.util.*;

/**
 * This Class represents minheap data structure. Tha main scope of this
 * API is to provide a better functionality to maintain priority queues
 */
public class MinHeap<T> {
  ArrayList<T> heap = null;
  Comparator<? super T> comparator = null;
  int heapSize;
  private HashMap<T, Integer> hashmap = null;

  public MinHeap(Comparator<? super T> comparator) throws MinHeapException {
    if (comparator == null)
      throw new MinHeapException("MinHeap constructor: comparator parameter cannot be null");
    this.heap = new ArrayList<T>();
    this.comparator = comparator;
    this.heapSize = 0;
    this.hashmap = new HashMap<T, Integer>();

  }

  /**
   * Checks if heap is empty
   * 
   * @return a boolean true if heap is empty, false otherwise
   */
  public boolean isEmpty() {
    return this.heap.isEmpty();
  }

  /**
   * This method returns heap length
   * 
   * @return actual size of the heap
   */
  public int sizeHeap() {
    return this.heap.size();
  }

  /**
   * This methods allows to add a element to the heap
   * 
   * @param element – represents the reference to the element that has to be added
   *                to heap data structure
   * @throws MinHeapException
   */
  private void addElement(T element) throws MinHeapException {
    if (element == null) {
      throw new MinHeapException("addElement: element cannot be null");
    }
    this.hashmap.put(element, this.heapSize++);
    this.heap.add(element);
  }

  /**
   * 
   * @param i – represents i-th element to be retreived
   * @return a reference to object stored under i-th index
   * @throws MinHeapException
   */
  public T getByIndex(int i) throws MinHeapException {
    if (i < 0 || i >= this.heap.size())
      throw new MinHeapException("getByIndex : index " + i + "is out of array bounds");
    return this.heap.get(i);
  }

  /**
   * 
   * @param elem of which we want to return the left item
   * @return left child if element is present and is not a leaf, else returns the
   *         same elem
   * @throws MinHeapException
   */
  public T getLeft(T elem) throws MinHeapException {
    if (elem == null) {
      throw new MinHeapException("getLeft : elem cannot be NULL");
    }
    int i = this.getLeftIndex(elem);
    if (i >= this.heap.size()) {
      return elem;
    }
    return (this.heap).get(i);
  }

  /**
   * Provided the elements, retrieves its left child actual position
   * 
   * @param elem of which we want to return the index of the left element
   * @return the actual index position of the left child of the given element
   * @throws MinHeapException
   */
  private int getLeftIndex(T elem) throws MinHeapException {
    Integer i = this.hashmap.get(elem);
    if (i == null) {
      throw new MinHeapException("getLeftIndex : elem not present");
    }
    return (2 * i) + 1;
  }

  /**
   * 
   * @param elem of which we want to return the right item
   * @return right child if element is present and is not a leaf, else returns the
   *         same elem
   * @throws MinHeapException
   */
  public T getRight(T elem) throws MinHeapException {
    if (elem == null) {
      throw new MinHeapException("getRight : key cannot be NULL");
    }
    int i = this.getRightIndex(elem);
    if (i >= this.heap.size()) {
      return elem;
    }
    return (this.heap).get(i);
  }

  /**
   * Provided the elements, retreives its right child actual position
   * 
   * @param elem of which we want to return the index of the left element
   * @return the actual index position of the right child of the given element
   * @throws MinHeapException
   */
  private int getRightIndex(T elem) throws MinHeapException {
    Integer i = this.hashmap.get(elem);
    if (i == null) {
      throw new MinHeapException("getRightIndex : elem not present");
    }
    return (2 * i) + 2;

  }

  /**
   * 
   * @param elem of which we want to return the parent item
   * @return a reference to elem's parent
   * @throws MinHeapException
   */
  public T getParent(T elem) throws MinHeapException {
    if (elem == null) {
      throw new MinHeapException("getParent : key cannot be NULL");
    }
    int i = this.getParentIndex(elem);
    return this.heap.get(i);
  }

  /**
   * 
   * Provided the element, retreives its father actual position
   * 
   * @param elem of which we want to return the index of the parent element
   * @return index of parent element
   * @throws MinHeapException
   */
  private int getParentIndex(T elem) throws MinHeapException {
    Integer i = this.hashmap.get(elem);
    if (i == null) {
      throw new MinHeapException("elem not present");
    }
    return (i - 1) / 2;
  }

  /**
   * 
   * @return minimum element contained in the heap according to compare criteria
   */
  public T minElement() {
    return this.heap.get(0);
  }

  /**
   * 
   * Provided the key, retreives the index associated to the given key
   * 
   * @param elem of which we want to return the index of the element
   * @return index of element
   * @throws MinHeapException
   */

  public int getByKey(T key) throws MinHeapException {
    if (key == null) {
      throw new MinHeapException("getByKey : key cannot be NULL");
    }
    Integer i = this.hashmap.get(key);
    if (i == null) {
      throw new MinHeapException("getByKey : elem not present for key + " + key);
    }
    return i;
  }
  
  private void swap(int a, int b) {
    T temp1 = this.heap.get(a);
    T temp2 = this.heap.get(b);
    this.heap.set(a, temp2);
    this.heap.set(b, temp1);
    this.hashmap.put(temp1, b);
    this.hashmap.put(temp2, a);
  }

  /**
   * This method is used to retreive left child position in the heap
   * 
   * @param i- position of the element of which left element index will be return
   * @return index of left child in the heap
   * @throws MinHeapException
   */
  private int left(int i) throws MinHeapException {
    if (i < 0 || i >= this.heap.size()) {
      throw new MinHeapException("left : left " + i + "is out of array bounds");
    }
    return (2 * i) + 1;
  }

  /**
   * This method is used to retreive right child position in the heap
   * 
   * @param i- position of the element of which right element index will be return
   * @return left child position in the heap
   * @throws MinHeapException
   */
  private int right(int i) throws MinHeapException {
    if (i < 0 || i >= this.heap.size()) {
      throw new MinHeapException("right : right " + i + "is out of array bounds");
    }
    return (2 * i) + 2;
  }

  /**
   * This method is used to retreive parent position in the heap
   * 
   * @param i- position of the element of which parent element index will be
   *           return
   * @return parent position in the heap
   * @throws MinHeapException
   */
  private int parent(int i) throws MinHeapException {
    if (i < 0 || i >= this.heap.size()) {
      throw new MinHeapException("parent : parent " + i + "is out of array bounds");
    }
    return (i - 1) / 2;
  }

  /**
   * This private method guarantee minheap property of the data structure,
   * is also guarantee the invariant of the data structure
   * 
   * @param index – position where to start the process of heapify
   * @throws MinHeapException
   */
  private void minHeapify(int index) throws MinHeapException {
    if (this.sizeHeap() == 0) {
      return;
    }
    if (index < 0 || index >= this.sizeHeap()) {
      throw new MinHeapException("minHeapify : index " + index + " is out of array bounds");
    }
    int minimo = min(index);

    if (minimo != index) {
      this.swap(minimo, index);
      this.minHeapify(minimo);
    }
  }

  /**
   * This private auxiliary method is used to find the minimum between left ,right
   * and parent element
   * 
   * @param index – of the parent node
   * @return index of the minimum node
   * @throws MinHeapException
   */
  private int min(int index) throws MinHeapException {
    T elem = this.getByIndex(index);
    T left = this.getLeft(elem);
    T right = this.getRight(elem);
    T min = elem;

    if ((this.left(index) < this.heapSize) && ((this.comparator).compare(left, elem) < 0)) { // left < A[i]
      min = left;
    }
    if ((this.right(index) < this.heapSize) && ((this.comparator).compare(right, min) < 0)) { // right < min
      min = right;
    }

    return this.hashmap.get(min);
  }

  /**
   * This method builds min heap from data structure containing all the elements
   * 
   * @throws MinHeapException
   */
  private void buildMinHeap() throws MinHeapException {
    this.heapSize = this.heap.size();
    int i = this.heap.size() / 2;
    for (; i >= 0; i--) {
      this.minHeapify(i);
    }
  }

  /**
   * This additional method represents the main functionality of the API,
   * it executes sorting of the heap.
   * 
   * @throws MinHeapException
   */
  public void heapsort() throws MinHeapException {
    this.buildMinHeap();
    int i = (this.heap).size() - 1;
    for (; i > 0; i--) {
      this.swap(0, i);
      this.heapSize -= 1;
      this.minHeapify(0);
    }
    this.heapSize = this.sizeHeap();
  }

  /**
   * Typical function when priority queues is used,
   * this method decreases key of element given as parameter that must be present
   * in heap
   * 
   * @param i    - th index of the element which key have to be decreased
   * @param elem which will represent new key, must be less than i-th element
   * @throws MinHeapException
   */
  public void decreaseKey(int i, T elem) throws MinHeapException {
    if ((i < 0 || i >= this.sizeHeap()) || elem == null) {
      throw new MinHeapException("decreaseKey : index out of bounds or elem is null");
    }
    T tmp = this.heap.get(i);
    if (this.comparator.compare(elem, tmp) > 0) {
      throw new MinHeapException("decreaseKey : key elem cannot be biggest then previous key");
    }
    this.heap.set(i, elem);
    this.hashmap.remove(tmp);
    this.hashmap.put(elem, i);
    while (i > 0 && this.comparator.compare(this.getParent(elem), elem) > 0) {
      swap(i, this.parent(i));
      i = this.parent(i);
    }
  }

  /**
   * Represents insert function into the heap
   * 
   * @param elem to be insert
   * @throws MinHeapException
   */
  public void heapInsert(T elem) throws MinHeapException {
    if (this.hashmap.containsKey(elem)) {
      throw new MinHeapException("heapInsert : elem " + elem + " is already present");
    }
    this.addElement(elem);
    this.decreaseKey(--this.heapSize, elem);
    this.heapSize += 1;
  }

  /**
   * Executes extraction of the minimum element present in the heap
   * and restore minheap property after extraction
   * 
   * @return exctracted element from the heap
   * @throws MinHeapException
   */
  public T heapExtractMin() throws MinHeapException {
    if (this.sizeHeap() == 1) {
      T min = this.getByIndex(0);
      this.heap.remove(this.heap.get(this.heapSize - 1));
      this.hashmap.remove(min);
      this.heapSize -= 1;
      this.minHeapify(0);
      return min;
    }
    T min = this.getByIndex(0);
    T temp = this.heap.get(this.heapSize - 1);
    this.heap.remove(this.heap.get(this.heapSize - 1));
    this.hashmap.remove(temp);
    this.hashmap.put(temp, 0);
    this.heapSize -= 1;
    this.heap.set(0, temp);
    this.minHeapify(0);
    return min;
  }

  /**
   * This utility method is used to print on standard output the content of the
   * heap as it stored
   */
  public void print() {
    Iterator<T> it = heap.iterator();
    System.out.print("[\t");
    while (it.hasNext()) {
      System.out.print(it.next() + "\t");
    }
    System.out.println("]");
  }

  /**
   * Transfroms inner data structure into an array of generic elements
   * 
   * @return a pointer to the datastructure seen as an array
   */
  public Object[] toArray() {
    return this.heap.toArray();
  }
}
