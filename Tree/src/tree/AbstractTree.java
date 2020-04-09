package tree;

import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.function.BinaryOperator;

public abstract class AbstractTree<T extends Number> {

    //methods
    public Node<T> getRoot() {
        return root;
    }

    public int getSize() {
        if (root == null) {
            return 0;
        }
        int size = 0;
        Queue<Node<T>> queue = new LinkedList<>(); // очередь для поиска в ширину
        queue.offer(root);
        Node<T> tmp;
        while (queue.peek() != null) {
            tmp = queue.remove();
            size++;
            for (Node<T> item : tmp.getChildren()) {
                queue.offer(item);
            }
        }
        return size;
    }

    public T getSum() {
        sum = zero;
        Queue<Node<T>> queue = new LinkedList<>(); // очередь для поиска в ширину
        queue.offer(root);
        Node<T> tmp;
        while (queue.peek() != null) {
            tmp = queue.remove();
            sum = adder.apply(sum, (T) tmp.getValue());
            for (Node<T> item : tmp.getChildren()) {
                queue.offer(item);
            }
        }
        return sum;
    }

    abstract AbstractTree<T> removeSubtree(Node<T> rootSubTree);

    abstract AbstractTree<T> maximize(int k);

    public abstract AbstractTree<T> maximize();

    //fields
    Node<T> root;
    BinaryOperator<T> adder;
    T sum;
    Comparator<T> comparator;
    T zero;
}
