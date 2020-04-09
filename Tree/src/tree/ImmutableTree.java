package tree;

import java.util.*;
import java.util.function.BinaryOperator;
import java.util.function.Function;

class ImmutableTree<T extends Number> extends AbstractTree {
    @Override
    AbstractTree removeSubtree(Node rootSubTree) {
        return null;
    }


    ImmutableTree(T val, BinaryOperator<T> adder, Comparator<T> comparator, T zero,
                  Function<ImmutableNode<T>, Collection<? extends Node<T>>> func) {
        this.root = new ImmutableNode(val, null, func);
        this.adder = adder;
        this.comparator = comparator;
        this.zero = zero;
    }

    @Override
    public AbstractTree maximize() {
        return null;
    }

    @Override
    AbstractTree maximize(int k) {
        return null;
    }
}
