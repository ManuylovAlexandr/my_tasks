package battleship;

public class Battleship extends Ship {

    /**
     * constructor
     */
    Battleship() {
        length = 4;
        for (int i = 0; i < length; i++) {
            hit[i] = false;
        }
    }

    /**
     * @return string with type of ship
     */
    @Override
    String getShipType() {
        return "battleship";
    }

    /**
     * @return "x" if ship is sunk, "S" otherwise
     */
    @Override
    public String toString() {
        if (isSunk()) return "x";
        else return "S";
    }
}
