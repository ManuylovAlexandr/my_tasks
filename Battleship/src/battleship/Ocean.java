package battleship;

import java.util.Random;

public class Ocean {

    Ship[][] ships = new Ship[10][10];
    private int shotsFired;
    private int hitCount;
    private int shipsSunk;

    /**
     * ocean constructor
     */
    Ocean() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                ships[i][j] = new EmptySea();
            }
        }
        shotsFired = 0;
        hitCount = 0;
        shipsSunk = 0;
    }

    /**
     * Additional method for placing ship at ships[][] array.
     *
     * @param ship
     */
    private void placeShip(Ship ship) {
        Random rnd = new Random();
        boolean hor;
        int r, c;
        do {
            hor = rnd.nextBoolean();
            r = rnd.nextInt(10);
            c = rnd.nextInt(10);
        } while (!ship.okToPlaceShipAt(r, c, hor, this));
        ship.placeShipAt(r, c, hor, this);
    }

    /**
     * Places all 10 ships on the field at random.
     */
    void placeAllShipsRandomly() {
        Battleship bs = new Battleship();
        placeShip(bs);
        for (int i = 0; i < 2; i++) {
            Cruiser cruiser = new Cruiser();
            placeShip(cruiser);
        }
        for (int i = 0; i < 3; i++) {
            Destroyer des = new Destroyer();
            placeShip(des);
        }
        for (int i = 0; i < 4; i++) {
            Submarine sub = new Submarine();
            placeShip(sub);
        }
    }

    /**
     * @param row
     * @param column
     * @return Returns true if the given location contains a ship, false if it does not.
     */
    boolean isOccupied(int row, int column) {
        return !ships[row][column].getShipType().equals("abc");
    }

    /**
     * @param row
     * @param column
     * @return Returns true if the given location contains a "real" ship, still afloat, (not an EmptySea), false if it does not.
     */
    boolean shootAt(int row, int column) {
        boolean shot = this.ships[row][column].shootAt(row, column);
        if (shot) {
            shotsFired++;
            hitCount++;
        } else shotsFired++;
        if (this.ships[row][column].isSunk() && shot) shipsSunk++;
        return shot;
    }

    /**
     * getter
     *
     * @return number of shots
     */
    int getShotsFired() {
        return shotsFired;
    }

    /**
     * getter
     *
     * @return number of hits
     */
    int getHitCount() {
        return hitCount;
    }

    /**
     * getter
     *
     * @return number of sunk ships
     */
    int getShipsSunk() {
        return shipsSunk;
    }

    /**
     * @return true if all ships sunk, and false if not
     */
    boolean isGameOver() {
        return shipsSunk == 10;
    }

    /**
     * getter
     *
     * @return ships array
     */
    Ship[][] getShipArray() {
        return ships;
    }

    /**
     * Prints the ocean on console.
     */
    void print() {
        System.out.print(" ");
        for (int i = 0; i < 10; i++) {
            System.out.print(" " + i);
        }
        System.out.println();
        for (int i = 0; i < 10; i++) {
            System.out.print(i + " ");
            for (int j = 0; j < 10; j++) {
                if (!this.isOccupied(i, j)) System.out.print(ships[i][j].toString() + " ");
                else {
                    if (ships[i][j].isHorizontal()) {
                        if (this.ships[i][j].hit[j - ships[i][j].getBowColumn()])
                            System.out.print(ships[i][j].toString() + " ");
                        else
                            System.out.print(". ");
                    } else {
                        if (this.ships[i][j].hit[i - ships[i][j].getBowRow()])
                            System.out.print(ships[i][j].toString() + " ");
                        else
                            System.out.print(". ");
                    }
                }
            }
            System.out.println();
        }
    }
}
