package tree;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.function.BinaryOperator;

public class MainClassMutable {
    public static void main(String[] args) {
        BinaryOperator<Integer> adder = Integer::sum;
        Comparator<Integer> comparator = (x, y) -> x.compareTo(y);

        MutableTree<Integer> tree = new MutableTree(new MutableNode<Integer>(10, null, null),
                adder, comparator, 0);

        MutableNode a = new MutableNode(-200, null, null);
        MutableNode b = new MutableNode(30, null, null);

        ((MutableNode)tree.root).addChild(a);
        ((MutableNode)tree.root).addChild(b);

        a.addChild(new MutableNode(40, null, null));
        a.addChild(new MutableNode(50, null, null));

        b.addChild(new MutableNode(-60, null, null));
        b.addChild(new MutableNode(70, null, null));

        //tree.removeSubtree(a);
        System.out.println(tree.getSum());
        tree.removeSubtree(a);
        System.out.println(tree.getSum());
        System.out.println(tree.getSize());



    }
}
