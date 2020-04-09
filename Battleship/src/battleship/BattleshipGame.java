package battleship;

import java.util.Scanner;

public class BattleshipGame {
    public static void main(String[] args) {
        System.out.println("enter \"exit\" if you want to exit");
        do {
            boolean isHit;
            String line;
            Scanner in = new Scanner(System.in);
            Ocean ocean = new Ocean();
            int shipsSunk = ocean.getShipsSunk();
            ocean.placeAllShipsRandomly();
            ocean.print();
            int row, col;
            while (!ocean.isGameOver()) {
                do {
                    System.out.print("Set row: ");
                    line = in.nextLine();
                    if (line.equals("exit")) return;
                    try {
                        row = Integer.parseInt(line);
                        if (row < 0 || row > 9) throw new Exception();
                        break;
                    } catch (Exception ex) {
                        System.out.println("you must enter an integer between 0 and 9");
                    }
                } while (true);

                do {
                    System.out.print("Set column: ");
                    line = in.nextLine();
                    if (line.equals("exit")) return;
                    try {
                        col = Integer.parseInt(line);
                        if (col < 0 || col > 9) throw new Exception();
                        break;
                    } catch (Exception ex) {
                        System.out.println("you must enter an integer between 0 and 9");
                    }
                } while (true);

                isHit = ocean.shootAt(row, col);
                if (isHit)
                    System.out.println("hit");
                else
                    System.out.println("miss");
                if (shipsSunk != ocean.getShipsSunk()) {
                    shipsSunk++;
                    System.out.println("You just sank a " + ocean.getShipArray()[row][col].getShipType() + ".");
                }
                ocean.print();
            }
            System.out.println("Game over.\nYou fired " + ocean.getShotsFired() + " shots.\nYou hit the ships " + ocean.getHitCount() + " times.");
        } while (true);
    }
}
