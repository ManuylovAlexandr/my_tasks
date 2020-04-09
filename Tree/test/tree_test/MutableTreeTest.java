package tree_test;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import tree.MutableNode;
import tree.MutableTree;

import java.util.Comparator;
import java.util.function.BinaryOperator;

class MutableTreeTest {

    @Test
    void removeSubtree() {
        BinaryOperator<Integer> adder = Integer::sum;
        Comparator<Integer> comparator = (x, y) -> x.compareTo(y);

        MutableTree tree = new MutableTree(new MutableNode<>(10, null, null),
                adder, comparator, 0);

        MutableNode a = new MutableNode(20, null, null);
        MutableNode b = new MutableNode(-300, null, null);

        ((MutableNode) tree.getRoot()).addChild(a);
        ((MutableNode) tree.getRoot()).addChild(b);

        a.addChild(new MutableNode(40, null, null));
        a.addChild(new MutableNode(-50, null, null));

        b.addChild(new MutableNode(60, null, null));
        b.addChild(new MutableNode(70, null, null));

        tree.removeSubtree(a);

        Assertions.assertEquals(-160, tree.getSum());
        Assertions.assertEquals(4, tree.getSize());
    }

    @Test
    void maximize() {
        BinaryOperator<Integer> adder = Integer::sum;
        Comparator<Integer> comparator = (x, y) -> x.compareTo(y);

        MutableTree tree = new MutableTree(new MutableNode<>(10, null, null),
                adder, comparator, 0);

        MutableNode a = new MutableNode(20, null, null);
        MutableNode b = new MutableNode(-300, null, null);

        ((MutableNode) tree.getRoot()).addChild(a);
        ((MutableNode) tree.getRoot()).addChild(b);

        a.addChild(new MutableNode(40, null, null));
        a.addChild(new MutableNode(-50, null, null));

        b.addChild(new MutableNode(60, null, null));
        b.addChild(new MutableNode(70, null, null));

        tree.maximize();

        Assertions.assertEquals(70, tree.getSum());
        Assertions.assertEquals(3, tree.getSize());
    }
}