package tree;

import java.util.Collection;
import java.util.function.Function;

class ImmutableNode<T extends Number> implements Node {

    ImmutableNode(T value,
                  ImmutableNode<T> parent,
                  Function<ImmutableNode<T>, Collection<? extends Node<T>>> childrenConstructor
    ){
        this.children = (Collection<Node<T>>)childrenConstructor.apply(this);
        this.parent = parent;
        this.value = value;
    }

    @Override
    public Node getParent() {
        return parent;
    }

    @Override
    public Collection<Node<T>> getChildren() {
        return children;
    }

    @Override
    public void print(int indents) {
        String res = " ".repeat(Math.max(0, indents)) +
                value.toString();
        System.out.print(res);
    }

    @Override
    public Number getValue() {
        return value;
    }

    private T value;
    private ImmutableNode<T> parent;
    private Collection<Node<T>> children;
}
