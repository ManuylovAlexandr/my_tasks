package dices;

import javafx.css.CssParser;

import java.util.Scanner;

public class Game {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        if (Integer.parseInt(args[0]) < 2 || Integer.parseInt(args[0]) > 6) {
            System.out.println("Input count of players in the border from 2 to 6");
            return;
        }
        if (Integer.parseInt(args[1]) < 2 || Integer.parseInt(args[1]) > 5) {
            System.out.println("Input count of dice in the border from 2 to 5");
            return;
        }
        if (Integer.parseInt(args[2]) < 1 || Integer.parseInt(args[2]) > 100) {
            System.out.println("Input count of victories in the border from 1 to 100");
            return;
        }

        Player[] players = new Player[Integer.parseInt(args[0])];
        Thread[] players_thread = new Thread[Integer.parseInt(args[0])];
        GameTable table = new GameTable(Integer.parseInt(args[1]), Integer.parseInt(args[2]));
        Commentator commentator = new Commentator(table);

        for (int i = 0; i < players.length; i++) {
            players[i] = new Player(table);
            players_thread[i] = new Thread(players[i]);
        }

        table.setPlayers(players);

        ThreadsStart(players_thread);
        new Thread(commentator).start();
    }

    private static void ThreadsStart(Thread[] players) {
        for (int i = 0; i < players.length; i++) {
            players[i].start();
        }
    }
}
