package tree;

import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.function.BinaryOperator;


public class MutableTree<T extends Number> extends AbstractTree {

    public MutableTree(MutableNode<T> root, BinaryOperator<T> adder, Comparator<T> comparator, T zero){
        this.zero = zero;
        this.comparator = comparator;
        this.adder = adder;
        this.root = root;
    }

    @Override
    public AbstractTree removeSubtree(Node rootSubTree) {
        if (rootSubTree == null) {
            return this;
        }
        Queue<MutableNode<T>> queue = new LinkedList<>(); // очередь для поиска в ширину
        queue.offer((MutableNode) root);
        MutableNode<T> tmp;
        while (queue.peek() != null) {
            tmp = queue.remove();

            if (tmp.getChildren().contains(rootSubTree)) {
                tmp.removeChild((MutableNode) rootSubTree);
                return this;
            }

            for (Node<T> item : tmp.getChildren()) {
                queue.offer((MutableNode) item);
            }
        }
        return null;
    }

    @Override
    public AbstractTree maximize() {
        Queue<MutableNode<T>> queue = new LinkedList<>(); // очередь для поиска в ширину
        Stack<MutableNode<T>> stack = new Stack<>();
        queue.offer((MutableNode) root);
        MutableNode<T> tmp;
        while (queue.peek() != null) {
            tmp = queue.remove();
            stack.push(tmp);
            for (Node<T> item : tmp.getChildren()) {
                queue.offer((MutableNode) item);
            }
        }

        while (!stack.empty()) {
            tmp = stack.pop();
            if (sumSubTree(tmp)){
                ((MutableNode<T>)tmp.getParent()).removeChild(tmp);
            }
        }

        return this;
    }


    private boolean sumSubTree(Node rootSubTree) { // возвращает true если сумма поддерева отрицательна
        T sumSubTree = (T) zero;
        Queue<MutableNode<T>> queue = new LinkedList<>(); // очередь для поиска в ширину
        queue.offer((MutableNode) rootSubTree);
        MutableNode<T> tmp;
        while (queue.peek() != null) {
            tmp = queue.remove();
            sumSubTree = (T) adder.apply(sumSubTree, (T) tmp.getValue());
            for (Node<T> item : tmp.getChildren()) {
                queue.offer((MutableNode) item);
            }
        }
        return comparator.compare(sumSubTree, zero) < 0;
    }

    @Override
    AbstractTree maximize(int k) {
        return null;
    }

}
