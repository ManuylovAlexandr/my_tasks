package tree_test;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import tree.AbstractTree;
import tree.MutableNode;
import tree.MutableTree;

import java.util.Comparator;
import java.util.function.BinaryOperator;

import static org.junit.jupiter.api.Assertions.*;

class AbstractTreeTest {

    private AbstractTree<Integer> CreateTree() {
        BinaryOperator<Integer> adder = Integer::sum;
        Comparator<Integer> comparator = (x, y) -> x.compareTo(y);

        MutableTree<Integer> tree = new MutableTree(new MutableNode<Integer>(10, null, null),
                adder, comparator, 0);

        MutableNode a = new MutableNode(20, null, null);
        MutableNode b = new MutableNode(30, null, null);

        ((MutableNode) tree.getRoot()).addChild(a);
        ((MutableNode) tree.getRoot()).addChild(b);

        a.addChild(new MutableNode(40, null, null));
        a.addChild(new MutableNode(50, null, null));

        b.addChild(new MutableNode(60, null, null));
        b.addChild(new MutableNode(70, null, null));

        return tree;
    }

    @Test
    void getSize() {
        AbstractTree<Integer> tree = CreateTree();

        Assertions.assertEquals(280, tree.getSum());
    }

    @Test
    void getSum() {
        AbstractTree<Integer> tree = CreateTree();

        Assertions.assertEquals(7, tree.getSize());
    }
}