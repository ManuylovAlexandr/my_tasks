package dices;

public class Commentator implements Runnable {

    GameTable table;

    public Commentator(GameTable table) {
        this.table = table;
    }

    @Override
    public void run() {
        while (!table.IsFinished()) {
            table.Say();
        }
    }
}
