package dices;

import java.util.Arrays;
import java.util.Collections;
import java.util.Random;

public class GameTable {
    private int dices_count;
    private Random rnd = new Random();
    private boolean is_say = true;
    private int victory_score;
    private Player[] players;
    private Player leader = null, current_player = null;
    private int played_count = 0;

    public GameTable(int K, int vict_score) {
        dices_count = K;
        victory_score = vict_score;
    }

    public void setPlayers(Player[] players) {
        this.players = players;
    }

    public synchronized boolean getIsSay() {
        return is_say;
    }

    public synchronized void setIsSay(boolean say) {
        is_say = say;
    }

    synchronized void Say() {
        while (is_say) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Player " + current_player.toString() + " got " + current_player.getScore() + " points");
        if (!isRoundGoes()) {
            leader.IncrementVictories();
            System.out.println("======round end======");
            FinishRound();
        } else {
            System.out.println("Leader is " + leader.toString());
        }
        System.out.println();

        if (IsFinished()) {
            System.out.println("============");
            System.out.println("Congratulations to the winner " + leader.toString());
            System.out.println("Score table: ");
            Arrays.sort(players);
            for (Player player : players) {
                System.out.println(player.getVictories() + " " + player.toString());
            }
        }
        is_say = true;
        notifyAll();
    }

    public synchronized void RollOfTheDice(Player player) {
        while (!is_say) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        int local_score = rnd.nextInt(5 * dices_count + 1) + dices_count;
        current_player = player;
        player.setScore(local_score);
        player.setPlayed(true);
        if (leader == null) {
            leader = player;
        }
        if (local_score > leader.getScore()) {
            leader = player;
        }
        is_say = false;
        played_count++;
        notifyAll();
    }

    public synchronized boolean IsFinished() {
        for (Player player : players) {
            if (player.getVictories() == victory_score) {
                return true;
            }
        }
        return false;
    }

    public synchronized boolean isRoundGoes() {
        return played_count != players.length;
    }

    public void FinishRound() {
        played_count = 0;
        for (Player player : players) {
            player.setPlayed(false);
            player.setScore(0);
        }
    }
}
