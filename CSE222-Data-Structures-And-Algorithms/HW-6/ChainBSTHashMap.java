import java.util.ArrayList;

public class ChainBSTHashMap<K extends Comparable<K>, V extends Comparable<V>>
  implements KWHashMap<K, V> {

  private BinarySearchTree<Entry<K, V>>[] table;

  private int numKeys;

  private static final int CAPACITY = 101;

  private static final double LOAD_THRESHOLD = 3.0;

  public ChainBSTHashMap() {
    table = new BinarySearchTree[CAPACITY];
  }

  /**
   * If the key is in the table, return the value associated with it. Otherwise, return null
   *
   * @param key The key to be searched in the HashMap
   * @return The value of the key.
   */
  @Override
  public V get(Object key) {
    int hash = Math.abs(key.hashCode()) % CAPACITY;
    if (table[hash] == null) {
      return null;
    }
    Entry<K, V> entry = table[hash].find(new Entry<K, V>((K) key, null));
    if (entry == null) {
      return null;
    }
    return entry.getValue();
  }

  /**
   * If the key is not in the table, add it. If it is, replace the value
   *
   * @param key the key to be inserted
   * @param value the value to be added to the map
   * @return The old value of the key.
   */
  @Override
  public V put(K key, V value) {
    int hash = Math.abs(key.hashCode()) % CAPACITY;
    if (table[hash] == null) {
      table[hash] = new BinarySearchTree<Entry<K, V>>();
    }
    Entry<K, V> entry = table[hash].find(new Entry<K, V>(key, null));
    if (entry == null) {
      table[hash].add(new Entry<K, V>(key, value));
      numKeys++;
      if (numKeys / CAPACITY >= LOAD_THRESHOLD) {
        rehash();
      }
      return null;
    }
    V oldValue = entry.getValue();
    entry.setValue(value);
    return oldValue;
  }

  /**
   * If the key is found, remove it and return its value. Otherwise, return null
   *
   * @param key The key of the entry to remove.
   * @return The value of the key that was removed.
   */
  @Override
  public V remove(Object key) {
    int hash = Math.abs(key.hashCode()) % CAPACITY;
    if (table[hash] == null) {
      return null;
    }
    Entry<K, V> entry = table[hash].find(new Entry<K, V>((K) key, null));
    if (entry == null) {
      return null;
    }
    V oldValue = entry.getValue();
    table[hash].remove(entry);
    numKeys--;
    return oldValue;
  }

  /**
   * If the number of keys is 0, then the tree is empty.
   *
   * @return The number of keys in the tree.
   */
  @Override
  public boolean isEmpty() {
    return numKeys == 0;
  }

  /**
   * Return the number of keys in the tree.
   *
   * @return The number of keys in the table.
   */
  @Override
  public int size() {
    return numKeys;
  }

  /**
   * It prints out the contents of the hash table.
   *
   * @return A string representation of the hash table.
   */
  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append("[");
    for (int i = 0; i < CAPACITY; i++) {
      if (table[i] != null) {
        sb.append(table[i].toString());
      }
    }
    sb.append("]");
    return sb.toString();
  }

  /**
   * It creates a new table that is twice the size of the old table. It then iterates through the old
   * table and adds all the entries to the new table.
   */
  private void rehash() {
    BinarySearchTree<Entry<K, V>>[] oldTable = table;
    table = new BinarySearchTree[CAPACITY * 2];
    numKeys = 0;
    for (int i = 0; i < oldTable.length; i++) {
      if (oldTable[i] != null) {
        ArrayList<Entry<K, V>> list = oldTable[i].getNodes();
        for (int j = 0; j < list.size(); j++) {
          put(list.get(j).getKey(), list.get(j).getValue());
        }
      }
    }
  }

  /**
   * The Entry class is a generic class that implements the Comparable interface
   */
  private static class Entry<K, V> implements Comparable<Entry<K, V>> {

    private K key;
    private V value;

    // A constructor for the Entry class.
    public Entry(K key, V value) {
      this.key = key;
      this.value = value;
    }

    /**
     * Returns the key stored in this entry.
     *
     * @return The key of the entry.
     */
    public K getKey() {
      return key;
    }

    public V getValue() {
      return value;
    }

    /**
     * This function sets the value of the node to the value passed in.
     *
     * @param value The value of the node.
     */
    public void setValue(V value) {
      this.value = value;
    }

    /**
     * It compares the current object with the specified object for order.
     *
     * @param o The object to be compared.
     * @return The value of the entry.
     */
    @Override
    public int compareTo(Entry<K, V> o) {
      return 0;
    }

    /**
     * The toString() function returns a string representation of the key-value pair.
     *
     * @return The key and value of the node.
     */
    public String toString() {
      return "(" + key + ", " + value + ")";
    }
  }
}
