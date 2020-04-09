package tree;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.function.BinaryOperator;
import java.util.function.Function;

public class MainClassImmutable {
    public static void main(String args[]) {
        BinaryOperator<Integer> adder = Integer::sum;
        Comparator<Integer> comparator = (x, y) -> x.compareTo(y);

        Function<ImmutableNode<Integer>, Collection<? extends Node<Integer>>> func = node -> {
            Collection<Node<Integer>> mas = new ArrayList<>();

            mas.add(new ImmutableNode<>(20, node, nd->{
                Collection<Node<Integer>> m = new ArrayList<>();
                m.add(new ImmutableNode<>(40, nd, n -> new ArrayList<>()));
                m.add(new ImmutableNode<>(50, nd, n -> new ArrayList<>()));
                return m;
            }));

            mas.add(new ImmutableNode<>(30, node, nd->new ArrayList<>()));


            return (Collection<? extends Node<Integer>>) mas;
        };

        ImmutableTree<Integer> tree = new ImmutableTree<>(10, adder, comparator, 0, func);

        System.out.println(tree.getSize());
        System.out.println(tree.getSum());

    }
}
