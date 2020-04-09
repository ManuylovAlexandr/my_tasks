package tree;

import java.util.*;

public class MutableNode<T extends Number> implements Node {

    public MutableNode(T val, MutableNode par, Collection<Node<T>> chil) {
        value = val;
        parent = par;
        children = Objects.requireNonNullElseGet(chil, ArrayList::new);
    }

    //methods
    public void setValue(T value) {
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

    public void setParent(MutableNode<T> parent) {
        if (parent == null) {
            return;
        }
        if (this.getParent() != null) {
            this.parent.removeChild(this);
            if (this.getParent().getParent() != null) {
                this.getParent().getChildren().add(parent);
            }
            this.parent = parent;
        }
        else {
            this.parent = parent;
        }
        if (!parent.children.contains(this)) {
            parent.getChildren().add(this);
        }
    }

    void setChildren(Collection<MutableNode<T>> children) {
        for (MutableNode<T> item : children) { // задаем новым детям текущего родителя
            item.setParent((MutableNode) this.getParent());
        }

        for (Node<T> item : this.getChildren()) { // задаем старым детям родителя null чтобы их собрал сборщик мусора
            ((MutableNode) item).setParent(null);
        }

        this.children = null; // забывам о старых детях

        for (Node item : children) { // заполняем массив детей новыми детями
            this.children.add(item);
        }
    }

    public void addChild(MutableNode<T> child) {
        children.add(child);
        child.setParent(this);
    }

    public void removeChild(MutableNode<T> child) {
        if (children != null && child != null) {
            children.remove(child);
        }
    }

    //fields
    private T value;
    private MutableNode<T> parent;
    private Collection<Node<T>> children;
}
