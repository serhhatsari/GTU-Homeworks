package ldlinkedlisttown;

import java.util.AbstractList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.NoSuchElementException;

/**
 * LDLLStreet class implementations.
 * 
 * @author Serhat Sarı
 * @since 20-03-2022
 * 
 */

/**
 * Custom LinkedList Implementation
 */
public class LDLinkedList<T> extends AbstractList<T> {

    private int theSize;
    private Node<T> head;
    private Node<T> tail;
    private LinkedList<Node<T>> deletedNodes = new LinkedList<>();

    /**
     * Default Constructer of the LDLinkedList
     */
    public LDLinkedList() {
        clear();
    }

    /**
     * Remove all nodes of the list.
     */
    @Override
    public void clear() {

        // connect head and tail to null
        head = new Node<>(null, null, null);
        tail = new Node<>(null, head, null);

        head.next = tail;
        theSize = 0;

    }

    /**
     * Return number of nodes in the list.
     * 
     * @return the number of nodes in the list.
     */
    @Override
    public int size() {
        return theSize;
    }

    /**
     * Check wheter list is empty or net
     * 
     * @return true or false
     */
    @Override
    public boolean isEmpty() {
        return size() == 0;
    }

    /**
     * Adds a new node(data) to the end of the list.
     * 
     * @param newData node(data) to be added.
     * @return true.
     */
    @Override
    public boolean add(T newData) {
        add(size(), newData);
        return true;
    }

    /**
     * Adds a data at specified position in the list.
     * 
     * @param newData data to be added.
     * @param index   position of the be added to.
     * @throws IndexOutOfBoundsException if index is not between 0 and size(), throw
     *                                   an exception
     */
    @Override
    public void add(int index, T newData) {
        addBefore(getNode(index, 0, size()), newData);
    }

    /**
     * Adds a data at specified position in the list
     * 
     * @param curNode node to add before
     * @param newData data to be added.
     * @throws IndexOutOfBoundsException if index is not between 0 and size(), throw
     *                                   an exception
     */
    private void addBefore(Node<T> curNode, T newData) {

        ListIterator<Node<T>> it = deletedNodes.listIterator();

        while (it.hasNext()) {
            Node<T> nextNode = it.next();
            nextNode.prev = curNode.prev;
            nextNode.next = curNode;
            nextNode.prev.next = nextNode;
            curNode.prev = nextNode;
            theSize++;
            deletedNodes.removeFirst();
            return;
        }

        Node<T> newNode = new Node<T>(newData, curNode.prev, curNode);
        newNode.prev.next = newNode;
        curNode.prev = newNode;
        theSize++;
    }

    /**
     * Returns the data at given index
     * 
     * @param index the index of the node
     * @throws IndexOutOfBoundsException if index is out of range.
     */
    @Override
    public T get(int index) {
        return getNode(index).data;
    }

    /**
     * Changes the item at the given position.
     * 
     * @param index   index of the node to be changed
     * @param newData the new data of the node.
     * @return the old value.
     * @throws IndexOutOfBoundsException if index is out of range. throw an
     *                                   exception
     */
    @Override
    public T set(int index, T newData) {

        Node<T> targetNode = getNode(index);
        T oldVal = targetNode.data;
        targetNode.data = newData;
        return oldVal;
    }

    /**
     * Gets the Node at position index
     * 
     * @param index position of the node to be returned
     * @return node of the given index
     * @throws IndexOutOfBoundsException check the boundaries of the list
     */
    private Node<T> getNode(int idx) {
        return getNode(idx, 0, size() - 1);
    }

    /**
     * Gets the Node at the given index
     * 
     * @param index      index of the node
     * @param lowerBound lowest valid index
     * @param upperBound highest valid index
     * @return node of the given index
     * @throws IndexOutOfBoundsException if index is not in the boundaries
     */
    private Node<T> getNode(int index, int lowerBound, int upperBound) {

        Node<T> targetNode;

        if (index < lowerBound || index > upperBound)
            throw new IndexOutOfBoundsException("getNode index: " + index + "; size: " + size());

        if (index < size() / 2) {
            targetNode = head.next;
            for (int i = 0; i < index; i++)
                targetNode = targetNode.next;
        } else {
            targetNode = tail;
            for (int i = size(); i > index; i--)
                targetNode = targetNode.prev;
        }

        return targetNode;
    }

    /**
     * Removes an node of the given position
     * 
     * @param index the index of the node
     * @return the data of the node that was removed from the list.
     */
    @Override
    public T remove(int index) {
        return remove(getNode(index));
    }

    /**
     * Removes the given node from the list
     * 
     * @param delNode node to be deleted
     * @return data of the node that was deleted
     */
    private T remove(Node<T> delNode) {

        deletedNodes.add(delNode);
        delNode.next.prev = delNode.prev;
        delNode.prev.next = delNode.next;
        theSize--;

        return delNode.data;
    }

    /**
     * List Iterator to traverse list
     * 
     * @return an iterator positioned to first element
     */
    @Override
    public ListIterator<T> listIterator() {
        return new LinkedListIterator();
    }

    /**
     * List Iterator to traverse list
     * 
     * @return an iterator positioned to first element
     */
    @Override
    public Iterator<T> iterator() {
        return new LinkedListIterator();
    }

    /**
     * This is the doubly-linked list node.
     */
    private static class Node<T> {

        public T data;
        public Node<T> prev;
        public Node<T> next;

        /***
         * This is the constructor of the Node class. It creates a new node with the
         * given data, previous node
         * and next node.
         */
        public Node(T nodeData, Node<T> previousNode, Node<T> nextNode) {
            data = nodeData;
            prev = previousNode;
            next = nextNode;
        }

    }

    /**
     * This is the implementation of the LinkedListIterator.
     */
    private class LinkedListIterator implements ListIterator<T> {

        private Node<T> nextNode = head.next;
        private Node<T> lastReturned = null;
        private boolean isRemovable = false;
        private int nextNodeIndex = 0;

        /**
         * Return true if the next node is not the tail
         * 
         * @return The next node in the list.
         */
        public boolean hasNext() {
            return nextNode != tail;
        }

        /**
         * Return the next element in the iteration
         * 
         * @return The data of the next node.
         */
        public T next() {
            if (!hasNext())
                throw new NoSuchElementException();

            T nextNodeData = nextNode.data;
            lastReturned = nextNode;
            nextNode = nextNode.next;
            isRemovable = true;
            nextNodeIndex++;
            return nextNodeData;
        }

        /**
         * Remove the last node from the list and decrement the nextNodeIndex
         */
        public void remove() {
            if (!isRemovable)
                throw new IllegalStateException();

            LDLinkedList.this.remove(nextNode.prev);
            nextNodeIndex--;
            isRemovable = false;
        }

        /**
         * Adds an element to the end of the list
         * 
         * @param e The element to be added to the list.
         */
        @Override
        public void add(T e) {

            LDLinkedList.this.add(nextNodeIndex, e);
            isRemovable = false;
            nextNodeIndex++;

        }

        /**
         * Returns true if there is a previous element in the list
         * 
         * @return Boolean
         */
        @Override
        public boolean hasPrevious() {
            return nextNode != head;
        }

        /**
         * Return the index of the next node in the list
         * 
         * @return The next index of the node.
         */
        @Override
        public int nextIndex() {
            return nextNodeIndex;
        }

        /**
         * Return the previous item in the list, and update the internal state to
         * reflect that the next item is
         * now the previous item
         * 
         * @return The item that was returned by the previous() method.
         */
        @Override
        public T previous() {
            if (!hasPrevious())
                throw new NoSuchElementException();

            T previousItem = nextNode.prev.data;
            lastReturned = nextNode.prev;
            nextNode = nextNode.prev;
            isRemovable = true;
            nextNodeIndex--;
            return previousItem;
        }

        /**
         * Return the index of the previous node
         * 
         * @return The index of the previous node.
         */
        @Override
        public int previousIndex() {
            return nextNodeIndex - 1;
        }

        /**
         * The function sets the data in the last returned node to the new data
         * 
         * @param newData The new data to be set.
         */
        @Override
        public void set(T newData) {
            if (!isRemovable)
                throw new IllegalStateException();

            lastReturned.data = newData;
        }
    }

}
