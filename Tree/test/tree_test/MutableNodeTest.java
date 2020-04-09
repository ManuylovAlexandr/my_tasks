package tree_test;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import tree.MutableNode;

import static org.junit.jupiter.api.Assertions.*;

class MutableNodeTest {

    @Test
    void setValue() {
        MutableNode<Integer> node = new MutableNode<>(10, null, null);
        node.setValue(20);

        Assertions.assertEquals(20, node.getValue());
    }

    @Test
    void setParent() {
        MutableNode<Integer> node = new MutableNode<>(10, null, null);
        MutableNode<Integer> a = new MutableNode<>(20, null, null);

        node.setParent(a);

        Assertions.assertEquals(a, node.getParent());
    }

    @Test
    void setChildren() {

    }

    @Test
    void addChild() {
        MutableNode<Integer> node = new MutableNode<>(10, null, null);
        MutableNode<Integer> a = new MutableNode<>(20, null, null);
        node.addChild(a);

        assertTrue(node.getChildren().contains(a));
    }

    @Test
    void removeChild() {
        MutableNode<Integer> node = new MutableNode<>(10, null, null);
        MutableNode<Integer> a = new MutableNode<>(20, null, null);
        node.addChild(a);
        node.removeChild(a);

        assertFalse(node.getChildren().contains(a));

    }
}