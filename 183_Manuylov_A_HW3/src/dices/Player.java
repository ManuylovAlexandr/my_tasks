package dices;

public class Player implements Runnable, Comparable<Player> {

    private GameTable table;
    private int score;
    private int victories;
    private boolean is_played = false;

    public void IncrementVictories() {
        victories++;
    }

    public int getVictories() {
        return victories;
    }

    public void setPlayed(boolean played) {
        is_played = played;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }

    public Player(GameTable table) {
        this.table = table;
    }


    @Override
    public void run() {
        while (!table.IsFinished()) {
            if (table.isRoundGoes() && !is_played) {
                while (!is_played) {
                    table.RollOfTheDice(this);
                }
            }
        }
    }

    @Override
    public int compareTo(Player player) {
        return Integer.compare(player.getVictories(), this.victories);
    }
}
